/**
 *  @file   arctk/torus/sim.inl
 *  @date   09/12/2018
 *  @author Freddy Wordingham
 *
 *  Radiative transfer simulation class.
 */



//  == GUARD ==
#ifndef ARCTK_TORUS_SIM_INL
#define ARCTK_TORUS_SIM_INL



//  == MACROS ==
#ifdef RENDER
#define TRACK paths.back().emplace_back(gui::Point(glm::vec3(phot.pos().x, phot.pos().y, phot.pos().z), static_cast<float>(phot.time()), static_cast<float>(phot.wavelength()), 0.0f)); //!< Photon tracking macro.
#else
#define TRACK ; //!< Photon tracking placeholder macro.
#endif



//  == IMPORTS ==
//  -- Std --
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <future>
#include <iostream>
#include <iterator>
#include <limits>
#include <thread>
#include <type_traits>

//  -- Arctk --
#include <arctk/config/build.hpp>
#include <arctk/config/version.hpp>
#include <arctk/equip/entity/detector.hpp>
#include <arctk/equip/entity/light.hpp>
#include <arctk/exit/error.hpp>
#include <arctk/math/container.hpp>
#include <arctk/parse/print.hpp>
#include <arctk/phys/photon.hpp>
#include <arctk/prop/limits.hpp>
#include <arctk/prop/order.hpp>
#include <arctk/random/generator/quality.hpp>
#include <arctk/sys/file.hpp>
#include <arctk/tree/node/leaf.hpp>
#include <arctk/tree/root.hpp>
#ifdef RENDER
#include <arctk/gui/actor.hpp>
#include <arctk/gui/camera/fly.hpp>
#include <arctk/gui/keymap.hpp>
#include <arctk/gui/lens/perspective.hpp>
#include <arctk/gui/shader/ambient.hpp>
#include <arctk/gui/shader/normal.hpp>
#include <arctk/gui/shader/ray.hpp>
#include <arctk/gui/shader/specular.hpp>
#include <arctk/gui/window.hpp>
#endif

//  -- Graphical --
#ifdef RENDER
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#endif



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace torus //! transport of radiation under skin namespace
    {



        //  == CONSTANTS ==
        //  -- Defaults --
        constexpr const size_t       DEFAULT_MAX_DEPTH       = 6;
        constexpr const size_t       DEFAULT_TAR_TRIS        = 10;
        constexpr const bool         DEFAULT_ROULETTE_STATUS = false;
        constexpr const double       DEFAULT_ROULETTE_LIMIT  = 0.1;
        constexpr const double       DEFAULT_ROULETTE_CHANCE = 0.1;
        constexpr const unsigned int DEFAULT_UPDATE_DELTA    = 60000;
        constexpr const size_t       DEFAULT_NUM_THREADS     = 1;
        constexpr const bool         DEFAULT_PRE_RENDER      = false;
        constexpr const bool         DEFAULT_POST_RENDER     = false;

        //  -- Output --
        constexpr const char* DOMAIN_OUTPUT_DIR    = "domain/";
        constexpr const char* OUTPUT_TIME_FORMAT   = "%Y%m%d_%H%M%S";
        constexpr const char* PRE_FLIGHT_FILENAME  = "pre_flight_data";
        constexpr const char* POST_FLIGHT_FILENAME = "post_flight_data";

        //  -- Printing --
        constexpr const size_t PRINT_WIDTH = 64;



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Sim::Sim(const unsigned long int num_phot_, const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_, const std::string& aether_id_, const opt::Material& aether_) noexcept
          : _num_phot(num_phot_)
          , _entities(0)
          , _lights(0)
          , _detectors(0)
          , _dom(min_, max_, res_, aether_id_, aether_)
          , _max_depth(DEFAULT_MAX_DEPTH)
          , _tar_tris(DEFAULT_TAR_TRIS)
          , _roulette(DEFAULT_ROULETTE_STATUS)
          , _roulette_limit(DEFAULT_ROULETTE_LIMIT)
          , _roulette_chance(DEFAULT_ROULETTE_CHANCE)
          , _update_delta(DEFAULT_UPDATE_DELTA)
          , _num_threads(DEFAULT_NUM_THREADS)
          , _pre_render(DEFAULT_PRE_RENDER)
          , _post_render(DEFAULT_POST_RENDER)
          , _output_dir(init_output_dir())
        {
            assert(num_phot_ > 0);
            assert(min_.x < max_.x);
            assert(min_.y < max_.y);
            assert(min_.z < max_.z);
            for (size_t i = 0; i < res_.size(); ++i)
            {
                assert(res_[i] > 0);
                assert((res_[i] % 2) == 1);
            }
            assert(!aether_id_.empty());

            for (size_t i = 0; i < res_.size(); ++i)
            {
                if ((res_[i] % 2) == 0)
                {
                    std::cout << "Warning! The resolution of the domain should be odd in all dimensions.\n";

                    break;
                }
            }

            std::cout << std::string(PRINT_WIDTH, '=') << '\n'
                      << "  ____    _____   ____      ______ _____   _____           ____ \n"
                      << " //__\\\\  ||___)) //   ` o  o  ||  //   \\\\ ||___))  ||  || //___`\n"
                      << "//    \\\\ ||   \\\\ \\\\___, o  o  ||  \\\\___// ||   \\\\  \\\\__// .___//\n";
        }


        //  -- Destructors --
        inline Sim::~Sim()
        {
            std::cout << '\n' << std::string(PRINT_WIDTH, '-') << "\n\n" << parse::print::section("Simulation Complete.", PRINT_WIDTH, ' ') << "\n\n" << std::string(PRINT_WIDTH, '=') << '\n';
        }


        //  -- Initialisation --
        inline std::string Sim::init_output_dir() const noexcept
        {
            std::string output_dir("output/");
            output_dir += parse::print::timestamp(OUTPUT_TIME_FORMAT);
            output_dir += '/';

            return (output_dir);
        }



        //  == METHODS ==
        //  -- Setters --
        inline void Sim::set_emission_times(const std::vector<double>& emission_times_) noexcept
        {
            assert(!emission_times_.empty());
            assert(prop::limits::always_greater_than_or_equal_to(emission_times_, 0.0));
            assert(prop::order::ascending(emission_times_));

            _emission_times = emission_times_;
        }

        inline void Sim::set_tree_max_depth(const size_t max_depth_) noexcept
        {
            assert(max_depth_ > 0);

            _max_depth = max_depth_;
        }

        inline void Sim::set_tree_tar_tris(const size_t tar_tris_) noexcept
        {
            assert(tar_tris_ > 0);

            _tar_tris = tar_tris_;
        }

        inline void Sim::set_roulette(const bool roulette_) noexcept
        {
            _roulette = roulette_;
        }

        inline void Sim::set_roulette_limit(const double roulette_limit_) noexcept
        {
            assert(roulette_limit_ > 0.0);

            _roulette_limit = roulette_limit_;
        }

        inline void Sim::set_roulette_chance(const double roulette_chance_) noexcept
        {
            assert(roulette_chance_ > 0.0);
            assert(roulette_chance_ < 1.0);

            _roulette_chance = roulette_chance_;
        }

        inline void Sim::set_update_delta(const unsigned int update_delta_) noexcept
        {
            assert(update_delta_ > 0);

            _update_delta = update_delta_;
        }

        inline void Sim::set_num_threads(const size_t num_threads_) noexcept
        {
            assert(num_threads_ > 0);

            _num_threads = num_threads_;
        }

        inline void Sim::set_pre_render(const bool pre_render_) noexcept
        {
            _pre_render = pre_render_;
        }

        inline void Sim::set_post_render(const bool post_render_) noexcept
        {
            _post_render = post_render_;
        }

        inline void Sim::set_output_dir(const std::string& output_dir_) noexcept
        {
            assert(!output_dir_.empty());

            _output_dir = output_dir_;

            if (_output_dir.back() != '/')
            {
                _output_dir += '/';
            }
        }


        //  -- Additions --
        inline void Sim::add_mat(const std::string& mat_id_, const opt::Material& mat_) noexcept
        {
            assert(!mat_id_.empty());

            _dom.add_mat(mat_id_, mat_);
        }

        template <typename T>
        inline void Sim::add_entity(T&& ent_) noexcept
        {
            static_assert(std::is_base_of<equip::Entity, T>::value);

            _entities.emplace_back(std::make_unique<T>(ent_));
        }

        template <typename T>
        inline void Sim::add_light(T&& light_, const double ratio_) noexcept
        {
            static_assert(std::is_base_of<equip::entity::Light, T>::value);

            assert(ratio_ > 0.0);

            _entities.emplace_back(std::make_unique<T>(light_));
            _lights.emplace_back(std::make_pair(dynamic_cast<equip::entity::Light*>(_entities.back().get()), ratio_));
        }

        template <typename T>
        inline void Sim::add_detector(T&& det_, std::string dir_name_) noexcept
        {
            static_assert(std::is_base_of<equip::entity::Detector, T>::value);

            assert(!dir_name_.empty());

            if (dir_name_.back() != '/')
            {
                dir_name_ += '/';
            }

            if (std::count(std::begin(dir_name_), std::end(dir_name_), '/') > 1)
            {
                std::cerr << "Error! Unable to add detector with directory name: `" << dir_name_ << "`, as directory name may not be a path.\n";

                std::exit(exit::error::INVALID_DIR_NAME);
            }

            if (dir_name_ == DOMAIN_OUTPUT_DIR)
            {
                std::cerr << "Error! Unable to add detector with directory name: `" << dir_name_ << "`, as directory name is already in use.\n";

                std::exit(exit::error::INVALID_DIR_NAME);
            }

            for (size_t i = 0; i < _detectors.size(); ++i)
            {
                if (_detectors[i].second == dir_name_)
                {
                    std::cerr << "Error! Unable to add detector with directory name: `" << dir_name_ << "`, as directory name is already in use.\n";

                    std::exit(exit::error::INVALID_DIR_NAME);
                }
            }

            _entities.emplace_back(std::make_unique<T>(det_));
            _detectors.emplace_back(std::make_pair(dynamic_cast<equip::entity::Detector*>(_entities.back().get()), dir_name_));
        }


        //  -- Pre-Flight --
        inline void Sim::pre_flight() noexcept
        {
            std::cout << '\n' << parse::print::section("Pre-Flight", PRINT_WIDTH) << '\n';

            validate_parameters();

            calc_num_phot_per_light();

            create_output_dirs();

            write_pre_flight_data();
        }

        inline void Sim::validate_parameters() const noexcept
        {
            std::cout << "Validating simulation parameters.\n";

            if (_emission_times.empty())
            {
                std::cerr << "Error! Emission times list must contain at least one value.\n";

                std::exit(exit::error::INVALID_SIM_PARAMETER);
            }

            if (_num_phot < _lights.size())
            {
                std::cerr << "Error! Number of photons to simulate must be at least the number of light sources.\n";

                std::exit(exit::error::INVALID_SIM_PARAMETER);
            }
        }

        inline void Sim::calc_num_phot_per_light() noexcept
        {
            assert(_num_phot >= _lights.size());

            _num_phot_per_light = std::vector<unsigned long int>(_lights.size());

            double total_ratio = 0.0;
            for (size_t i = 0; i < _lights.size(); ++i)
            {
                total_ratio += _lights[i].second;
            }

            for (size_t i = 0; i < _lights.size(); ++i)
            {
                _num_phot_per_light[i] = static_cast<unsigned long int>(static_cast<double>(_num_phot) * (_lights[i].second / total_ratio));
            }

            const unsigned long int missing_phot = _num_phot - math::container::sum(_num_phot_per_light);
            for (size_t i = 0; i < missing_phot; ++i)
            {
                ++_num_phot_per_light[i % missing_phot];
            }

            assert(math::container::sum(_num_phot_per_light) == _num_phot);
        }

        inline void Sim::create_output_dirs() const noexcept
        {
            std::cout << "Creating base output directory.\n";
            std::filesystem::create_directories(_output_dir);

            std::cout << "Creating domain output directory.\n";
            std::filesystem::create_directories(_output_dir + DOMAIN_OUTPUT_DIR);

            for (size_t i = 0; i < _detectors.size(); ++i)
            {
                std::cout << "Creating detector output directory " << i << " of " << _detectors.size() << '\n';
                std::filesystem::create_directories(_output_dir + _detectors[i].second);
            }
        }

        inline void Sim::write_pre_flight_data() const noexcept
        {
            std::ofstream file(_output_dir + PRE_FLIGHT_FILENAME + ".txt");

            file << "Built using the Arctk library.\n";

            file << '\n'
                 << parse::print::section("Build", PRINT_WIDTH) << '\n'
                 << "Arctk version          : " << config::version::MAJOR << '.' << config::version::MINOR << '.' << config::version::PATCH << '\n'
                 << "Arctk directory        : " << config::build::DIR << '\n'
                 << "Arctk branch           : " << config::build::BRANCH << '\n'
                 << "Arctk build hash       : " << config::build::HASH << '\n'
                 << "Arctk compiler         : " << config::build::COMPILER << '\n'
                 << "Arctk build type       : " << config::build::TYPE << '\n'
                 << "Arctk build date       : " << config::build::DATE << '\n';

            file << '\n' << parse::print::section("Light Source", PRINT_WIDTH) << '\n' << "Total number of lights  : " << _lights.size() << '\n';
            for (size_t i = 0; i < _lights.size(); ++i)
            {
                file << "Light " << i << "                 : " << _num_phot_per_light[i] << " photons.\n";
            }
        }


        //  -- Post-Flight --
        inline void Sim::post_flight() const noexcept
        {
            std::cout << '\n' << parse::print::section("Post-Flight", PRINT_WIDTH) << '\n';
        }


        //  -- Simulation --
        inline void Sim::run() noexcept
        {
            pre_flight();

            std::cout << '\n' << parse::print::section("Simulation", PRINT_WIDTH) << '\n';

            std::cout << "Constructing tree.\n";
            tree::Root tree(_dom.min(), _dom.max(), _entities, _max_depth, _tar_tris);

            if (_pre_render)
            {
#ifdef RENDER
                render(tree);
#else
                std::cout << "Warning! Can not perform pre-render as rendering is disabled.\n";
#endif
            }

            for (size_t t = 0; t < _emission_times.size(); ++t)
            {
                std::cout << "\nRunning emission timepoint " << t << " of " << _emission_times.size() << ".\n";
                update_time_str(t);

                std::vector<std::vector<std::vector<gui::Point>>> paths;

                for (size_t l = 0; l < _lights.size(); ++l)
                {
                    std::cout << "Running light " << l << " of " << _lights.size() << ".\n";

                    std::vector<unsigned long int> thread_phot(_num_threads);
                    std::thread                    reporter(&Sim::report, this, l, _num_phot_per_light[l], &thread_phot);

                    std::vector<std::future<std::vector<std::vector<gui::Point>>>> threads;
                    for (size_t i = 0; i < _num_threads; ++i)
                    {
                        threads.emplace_back(std::async(&Sim::simulate_thread, this, i, t, l, _num_phot_per_light[l], &thread_phot, std::cref(tree)));
                    }

                    for (size_t i = 0; i < threads.size(); ++i)
                    {
                        paths.emplace_back(threads[i].get());
                    }

                    reporter.join();
                }

                std::cout << "Saving domain datacube.\n";
                _dom.save(_output_dir + DOMAIN_OUTPUT_DIR, _time_str);
                save_detector_data();

                if (_post_render)
                {
#ifdef RENDER
                    render(tree, paths);
#else
                    std::cout << "Warning! Can not perform post-render as rendering is disabled.\n";
#endif
                }
            }

            post_flight();
        }

        inline void Sim::update_time_str(const size_t time_index_) noexcept
        {
            std::stringstream time_str;
            time_str << '_' << _emission_times[time_index_];

            _time_str = time_str.str();
        }

        inline void Sim::save_detector_data() const noexcept
        {
            for (size_t i = 0; i < _detectors.size(); ++i)
            {
                std::cout << "Saving detector output " << i << " of " << _detectors.size() << '\n';

                std::string path = _output_dir + _detectors[i].second;

                _detectors[i].first->save(path, _time_str);
            }
        }

        inline void Sim::report(const size_t light_index_, const unsigned long int num_phot_, std::vector<unsigned long int>* thread_phot_) const noexcept
        {
            unsigned long int total = 0;

            while (total < num_phot_)
            {
                total = math::container::sum(*thread_phot_);

                std::cout << "Light " << light_index_ << " : " << total << '/' << num_phot_ << " (" << (total * 100.0 / num_phot_) << "%)\n";

                std::this_thread::sleep_for(std::chrono::milliseconds(_update_delta));
            }
        }

        inline std::vector<std::vector<gui::Point>> Sim::simulate_thread(const size_t thread_index_, const size_t time_index_, const size_t light_index_, const unsigned long int num_phot_, std::vector<unsigned long int>* thread_phot_,
                                                                         const tree::Root& tree_) noexcept
        {
            std::vector<std::vector<gui::Point>> paths;

            random::generator::Quality rng;

            while (math::container::sum(*thread_phot_) < num_phot_)
            {
                ++(*thread_phot_)[thread_index_];

#ifdef RENDER
                paths.emplace_back(std::vector<gui::Point>());
#endif

                auto [phot, block] = _lights[light_index_].first->emit(&rng, &_dom, _emission_times[time_index_], num_phot_);
                phot.move(consts::num::BUMP);
                const tree::node::Leaf* leaf = tree_.leaf(phot.pos());
                while (phot.alive())
                {
                    if (_roulette && (phot.weight() <= _roulette_limit))
                    {
                        if (rng.gen() > _roulette_chance)
                        {
                            phot.kill();
                            break;
                        }
                        else
                        {
                            phot.multiply_weight(1.0 / _roulette_chance);
                        }
                    }

                    // leaf  = tree_.leaf(phot.pos()); // TEMP
                    // block = _dom.block(phot.pos()); // TEMP

                    TRACK;

                    const double                                                    inter_dist = phot.driver()->interaction_dist(&rng);
                    const std::optional<std::pair<equip::Entity*, geom::Collision>> ent_dist   = leaf->ent_collision_info(phot.pos(), phot.dir());
                    const std::optional<double>                                     leaf_dist  = leaf->collision(phot.pos(), phot.dir());
                    const std::optional<double>                                     block_dist = block->collision(phot.pos(), phot.dir());
                    const std::optional<double>                                     dom_dist   = _dom.collision(phot.pos(), phot.dir());

                    switch (collide(inter_dist, ent_dist, leaf_dist, block_dist, dom_dist))
                    {
                        case type::collision::INTER:
                            phot.travel(inter_dist);
                            phot.driver()->interact(&rng, &phot);
                            break;
                        case type::collision::ENT:
                            ent_dist.value().first->hit(&rng, &phot, block, ent_dist.value().second);
                            break;
                        case type::collision::LEAF:
                            phot.travel(leaf_dist.value() + consts::num::BUMP);
                            leaf = tree_.leaf(phot.pos());
                            break;
                        case type::collision::BLOCK:
                            phot.travel(block_dist.value() + consts::num::BUMP);
                            block = _dom.block(phot.pos());
                            break;
                        case type::collision::DOM:
                            phot.travel(dom_dist.value());
                            phot.kill();
                            break;
                    }
                }

                TRACK;
            }

            return (paths);
        }

        inline type::collision Sim::collide(const double inter_, const std::optional<std::pair<equip::Entity*, geom::Collision>>& ent_, const std::optional<double>& leaf_, const std::optional<double>& block_, const std::optional<double>& dom_) const
          noexcept
        {
            type::collision type = type::collision::INTER;
            double          dist = inter_;

            if (ent_ && (ent_.value().second.dist() <= dist))
            {
                type = type::collision::ENT;
                dist = ent_.value().second.dist();
            }

            if (leaf_ && (leaf_.value() <= dist))
            {
                type = type::collision::LEAF;
                dist = leaf_.value();
            }

            if (block_ && (block_.value() <= dist))
            {
                type = type::collision::BLOCK;
                dist = block_.value();
            }

            if (dom_ && ((dom_.value() - consts::num::BUMP) <= dist))
            {
                type = type::collision::DOM;
            }

            return (type);
        }


        //  -- Rendering --
        inline void Sim::render(const tree::Root& tree_, const std::vector<std::vector<std::vector<gui::Point>>>& paths_) const noexcept
        {
#ifdef RENDER
            gui::Window win("Arc::Torus", 1600, 1200, 4);
            win.set_clear_col(glm::vec4(0.0f, 0.1f, 0.2f, 0.0f));

            gui::lens::Perspective lens(70.0f, 1600.0f / 1200.0f);

            const float scale = powf(10.0f, floorf(log10f(static_cast<float>((_dom.max() - _dom.min()).mag()) / 10.0f)));
            std::cout << "Graphical scale unit: " << scale << "m\n";

            gui::camera::Fly cam(glm::vec3((_dom.max().x * 2.0) - _dom.min().x, (_dom.max().y * 2.0) - _dom.min().y, (_dom.max().z * 2.0) - _dom.min().z), glm::vec3(_dom.min().x - _dom.max().x, _dom.min().y - _dom.max().y, _dom.min().z - _dom.max().z),
                                 glm::vec3(0.0f, 0.0f, 1.0f), scale / 10.0f);

            gui::Keymap map;
            map.use_fly_controls(&cam);

            gui::shader::Ambient  amb_shader;
            gui::shader::Normal   norm_shader;
            gui::shader::Specular spec_shader;
            gui::shader::Ray      ray_shader;

            gui::Actor grid = gui::actor::grid(glm::vec2(_dom.min().x, _dom.min().y), glm::vec2(_dom.max().x, _dom.max().y), glm::vec2(scale, scale));
            grid.set_col(glm::vec3(0.5f, 0.0f, 0.5f));

            gui::Actor axis_helper_x = gui::actor::axis_helper_x(scale, scale / 10.0f);
            gui::Actor axis_helper_y = gui::actor::axis_helper_y(scale, scale / 10.0f);
            gui::Actor axis_helper_z = gui::actor::axis_helper_z(scale, scale / 10.0f);

            gui::Actor dom_act = gui::actor::shape(_dom);
            dom_act.set_col(glm::vec3(1.0f, 1.0f, 0.0f));

            gui::Actor block_act = gui::actor::domain(_dom);
            block_act.set_col(glm::vec3(1.0f, 0.8f, 0.0f));

            std::vector<gui::Actor> ent_acts;
            for (size_t i = 0; i < _entities.size(); ++i)
            {
                ent_acts.emplace_back(gui::actor::shape(_entities[i]->surf()));
            }

            gui::Actor tree_act = gui::actor::tree(tree_);
            tree_act.set_col(glm::vec3(0.0f, 1.0f, 0.0f));

            std::vector<gui::Actor> paths;
            size_t                  num_paths = 0;
            for (size_t i = 0; i < paths_.size(); ++i)
            {
                num_paths += paths_[i].size();
            }
            paths.reserve(num_paths);

            float min_time = std::numeric_limits<float>::max();
            float max_time = std::numeric_limits<float>::min();
            if (num_paths > 0)
            {
                std::cout << "Creating path actors...\n";
                for (size_t i = 0; i < paths_.size(); ++i)
                {
                    std::cout << "Processing path batch " << i << " of " << paths_.size() << '\n';
                    for (size_t j = 0; j < paths_[i].size(); ++j)
                    {
                        if (paths_[i][j].front().time < min_time)
                        {
                            min_time = paths_[i][j].front().time;
                        }
                        if (paths_[i][j].back().time > max_time)
                        {
                            max_time = paths_[i][j].back().time;
                        }
                        paths.emplace_back(gui::actor::path(paths_[i][j]));
                    }
                }
            }

            float       render_time       = min_time;
            const float render_time_delta = (max_time - min_time) / 1000.0f;
            const float render_time_step  = render_time_delta / 10.0f;

            std::cout << "Rendering.\n";
            while (map.poll(win))
            {
                win.clear_buffer();

                amb_shader.activate(lens, cam);
                amb_shader.render(grid);
                amb_shader.render(axis_helper_x);
                amb_shader.render(axis_helper_y);
                amb_shader.render(axis_helper_z);
                amb_shader.render(dom_act);

                spec_shader.activate(lens, cam);
                for (size_t i = 0; i < ent_acts.size(); ++i)
                {
                    spec_shader.render(ent_acts[i]);
                }

                ray_shader.activate(lens, cam);
                render_time += render_time_step;
                ray_shader.set_time_start(render_time);
                ray_shader.set_time_end(render_time + render_time_delta);
                if (render_time > max_time)
                {
                    render_time = min_time;
                }
                for (size_t i = 0; i < paths.size(); ++i)
                {
                    ray_shader.render(paths[i]);
                }

                win.swap_buffer();
            }
#endif
        }



    } // namespace torus
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TORUS_SIM_INL
