/**
 *  @file   arctk/torus/sim.inl
 *  @date   07/11/2018
 *  @author Freddy Wordingham
 *
 *  Radiative transfer simulation class.
 */



//  == GUARD ==
#ifndef ARCTK_TORUS_SIM_INL
#define ARCTK_TORUS_SIM_INL



//  == MACROS ==
#ifdef RENDER
#define TRACK paths.back().emplace_back(gui::Point(glm::vec3(phot.pos().x, phot.pos().y, phot.pos().z), static_cast<float>(phot.time()), static_cast<float>(phot.wavelength()), static_cast<float>(phot.phase())));
#elif
#define TRACK ;
#endif



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <future>
#include <thread>
#include <type_traits>

//  -- Arctk --
#include <arctk/config/build.hpp>
#include <arctk/config/version.hpp>
#include <arctk/consts/num.hpp>
#include <arctk/data/obj.hpp>
#include <arctk/dom/region.hpp>
#include <arctk/equip/entity.hpp>
#include <arctk/equip/entity/detector.hpp>
#include <arctk/equip/entity/light.hpp>
#include <arctk/exit/error.hpp>
#include <arctk/gui/point.hpp>
#include <arctk/math/container.hpp>
#include <arctk/opt/mat.hpp>
#include <arctk/opt/sop.hpp>
#include <arctk/parse/print.hpp>
#include <arctk/parse/write.hpp>
#include <arctk/random/generator/quality.hpp>
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



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Sim::Sim(const vec3& min_, const vec3& max_) noexcept
          : _min(min_)
          , _max(max_)
          , _update_delta(60)
          , _num_threads(1)
          , _output_dir("output/")
          , _res({{25, 25, 25}})
          , _max_depth(6)
          , _tar_tris(10)
          , _pre_render(false)
          , _post_render(false)
          , _entities(0)
          , _lights(0)
          , _detectors(0)
        {
            assert(min_.x < max_.x);
            assert(min_.y < max_.y);
            assert(min_.z < max_.z);
        }



        //  == METHODS ==
        //  -- Setters --
        inline void Sim::set_update_delta(const unsigned int update_delta_) noexcept
        {
            assert(update_delta_ > 0);

            _update_delta = update_delta_;
        }

        inline void Sim::set_num_threads(const size_t num_threads_) noexcept
        {
            assert(num_threads_ > 0);

            if (num_threads_ > std::thread::hardware_concurrency())
            {
                std::cout << "Warning! Number of threads can not exceed the value supported by hardware concurrency: `" << std::thread::hardware_concurrency() << "`.\n";

                _num_threads = std::thread::hardware_concurrency();

                return;
            }

            _num_threads = num_threads_;
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

        inline void Sim::set_res(const size_t res_) noexcept
        {
            if ((res_ % 2) == 0)
            {
                std::cout << "Warning! The resolution of the domain should be odd in all dimensions.\n";

                return;
            }

            _res = std::array<size_t, 3>({{res_, res_, res_}});
        }

        inline void Sim::set_res(const std::array<size_t, 3>& res_) noexcept
        {
            for (size_t i = 0; i < res_.size(); ++i)
            {
                if ((res_[i] % 2) == 0)
                {
                    std::cout << "Warning! The resolution of the domain should be odd in all dimensions.\n";

                    return;
                }
            }

            _res = res_;
        }

        inline void Sim::set_max_depth(const size_t max_depth_) noexcept
        {
            assert(max_depth_ > 0);

            _max_depth = max_depth_;
        }

        inline void Sim::set_tar_tris(const size_t tar_tris_) noexcept
        {
            assert(tar_tris_ > 0);

            _tar_tris = tar_tris_;
        }

        inline void Sim::set_pre_render(const bool pre_render_) noexcept
        {
            _pre_render = pre_render_;
        }

        inline void Sim::set_post_render(const bool post_render_) noexcept
        {
            _post_render = post_render_;
        }


        //  -- Pre-flight --
        inline void Sim::create_output_dir() const noexcept
        {
            if (!std::filesystem::exists(_output_dir))
            {
                if (!std::filesystem::create_directory(_output_dir))
                {
                    std::cerr << "Unable to create output directory at: `" << _output_dir << "`.\n";

                    std::exit(exit::error::DIR_CREATION_FAILED);
                }
            }
        }

        inline void Sim::pre_flight_info_write() const noexcept
        {
            std::ofstream file(_output_dir + INFO_FILENAME);

            file << "Built using the Arctk library.\n\n";

            file << "Arctk version          : " << config::version::MAJOR << '.' << config::version::MINOR << '.' << config::version::PATCH << '\n'
                 << "Arctk directory        : " << config::build::DIR << '\n'
                 << "Arctk branch           : " << config::build::BRANCH << '\n'
                 << "Arctk build hash       : " << config::build::HASH << '\n'
                 << "Arctk compiler         : " << config::build::COMPILER << '\n'
                 << "Arctk build type       : " << config::build::TYPE << '\n'
                 << "Arctk build date       : " << config::build::DATE << "\n\n";

            file << "================================================================\n\n";

            file << "Working directory      : " << std::filesystem::current_path() << '\n' << "Output directory       : " << _output_dir << "\n\n";

            file << "Threads used           : " << _num_threads << "\n\n";

            file << "Total entities         : " << _entities.size() << '\n' << "Of which are lights    : " << _lights.size() << '\n' << "Of which are detectors : " << _detectors.size() << "\n\n";

            file << "Total photons          : " << total_phot() << '\n' << "Total light power      : " << total_power() << "W\n\n";
        }

        inline unsigned long int Sim::total_phot() const noexcept
        {
            unsigned long int total_phot = 0;

            for (size_t i = 0; i < _lights.size(); ++i)
            {
                total_phot += _lights[i]->num_phot();
            }

            return (total_phot);
        }

        inline double Sim::total_power() const noexcept
        {
            double total_power = 0.0;

            for (size_t i = 0; i < _lights.size(); ++i)
            {
                total_power += _lights[i]->power();
            }

            return (total_power);
        }



        //  -- Post-flight --
        inline void Sim::post_flight_info_write() const noexcept
        {
            std::ofstream file(_output_dir + INFO_FILENAME, std::ofstream::app);

            file << "================================================================\n\n";

            file << "Simulation complete.\n";
        }


        //  -- Additions --
        template <typename T>
        inline void Sim::add_entity(T&& ent_) noexcept
        {
            static_assert(std::is_base_of<equip::Entity, T>::value);

            _entities.emplace_back(std::make_unique<T>(ent_));
        }

        template <typename T>
        inline void Sim::add_light(T&& light_) noexcept
        {
            static_assert(std::is_base_of<equip::entity::Light, T>::value);

            _entities.emplace_back(std::make_unique<T>(light_));

            _lights.emplace_back(dynamic_cast<equip::entity::Light*>(_entities.back().get()));
        }

        template <typename T>
        inline void Sim::add_detector(T&& det_, const std::string& path_) noexcept
        {
            static_assert(std::is_base_of<equip::entity::Detector, T>::value);

            _entities.emplace_back(std::make_unique<T>(det_));

            _detectors.emplace_back(std::make_pair(dynamic_cast<equip::entity::Detector*>(_entities.back().get()), path_));
        }


        //  -- Simulate --
        inline void Sim::run() const noexcept
        {
            run_pre_flight();

            simulate();

            run_post_flight();
        }

        inline void Sim::run_pre_flight() const noexcept
        {
            create_output_dir();
            pre_flight_info_write();
        }

        inline void Sim::run_post_flight() const noexcept
        {
            post_flight_info_write();
        }

        inline void Sim::simulate() const noexcept
        {
            dom::Region dom(_min, _max, _res);
            tree::Root  tree(_min, _max, _entities, _max_depth, _tar_tris);

#ifdef RENDER
            if (_pre_render)
            {
                render(dom, tree);
            }
#endif

            std::vector<std::vector<std::vector<gui::Point>>>  paths;
            std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();

            for (size_t i = 0; i < _lights.size(); ++i)
            {
                std::cout << "Simulating light " << i << " of " << _lights.size() << ".\n";

                std::vector<unsigned long int> thread_phot(_num_threads);
                std::thread                    reporter(&Sim::report, this, _lights[i]->num_phot(), &thread_phot, i);

                std::vector<std::future<std::vector<std::vector<gui::Point>>>> threads;
                for (size_t t = 0; t < _num_threads; ++t)
                {
                    threads.emplace_back(std::async(&Sim::simulate_thread, this, t, _lights[i]->num_phot(), &thread_phot, i, &dom, std::cref(tree)));
                }

                for (size_t t = 0; t < threads.size(); ++t)
                {
                    paths.emplace_back(threads[t].get());
                }

                reporter.join();
            }

            std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();

            std::ofstream file(_output_dir + INFO_FILENAME, std::ofstream::app);

            file << "================================================================\n\n";

            file << "Simulation run time    : " << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << "\n\n";

            file << "Domain min             : " << _min << '\n'
                 << "Domain max             : " << _max << '\n'
                 << "Domain resolution      : " << _res << '\n'
                 << "Domain cell count      : " << dom.num_cells() << '\n'
                 << "Domain cell size       : " << dom.cell_size() << "\n\n";

            file << "Tree max depth         : " << tree.max_depth() << '\n' << "Tree max triangles     : " << tree.max_tris() << '\n' << "Tree nodes             : " << tree.num_nodes() << "\n\n";

            dom.save(_output_dir + "domain");

#ifdef RENDER
            if (_post_render)
            {
                render(dom, tree, paths);
            }
#endif
        }

        inline std::vector<std::vector<gui::Point>> Sim::simulate_thread(const size_t thread_index_, const unsigned long int num_phot_, std::vector<unsigned long int>* thread_phot_, const size_t light_index_, dom::Region* dom_,
                                                                         const tree::Root& tree_) const noexcept
        {
#ifdef RENDER
            std::vector<std::vector<gui::Point>> paths;
#endif

            random::generator::Quality rng;

            while (math::container::sum(*thread_phot_) < num_phot_)
            {
                ++(*thread_phot_)[thread_index_];
#ifdef RENDER
                paths.emplace_back(std::vector<gui::Point>());
#endif

                auto [phot, mat, sop]        = _lights[light_index_]->emit(&rng, 0.0);
                const tree::node::Leaf* leaf = tree_.leaf(phot.pos());
                dom::Cell*              cell = dom_->cell(phot.pos());

                phot.move(consts::num::BUMP, sop->ref_index());

                double energy_debt = 0.0;
                bool   loop        = true;

                while (loop)
                {
                    TRACK;

                    leaf = tree_.leaf(phot.pos()); // TODO Test removal
                    cell = dom_->cell(phot.pos()); // TODO Test removal

                    const double                                                    inter_dist = sop->interact_dist(&rng, cell);
                    const std::optional<std::pair<equip::Entity*, geom::Collision>> ent_dist   = leaf->ent_collision_info(phot.pos(), phot.dir());
                    const std::optional<double>                                     leaf_dist  = leaf->collision(phot.pos(), phot.dir());
                    const std::optional<double>                                     cell_dist  = cell->collision(phot.pos(), phot.dir());
                    const std::optional<double>                                     dom_dist   = dom_->collision(phot.pos(), phot.dir());

                    switch (collide(inter_dist, ent_dist, leaf_dist, cell_dist, dom_dist))
                    {
                        case type::collision::INTER:
                            if (sop->interact(&rng, &phot, cell, inter_dist))
                            {
                                sop = mat->gen(phot);
                            }
                            break;
                        case type::collision::ENT:
                            loop = ent_dist.value().first->hit(&rng, &phot, &mat, &sop, cell, ent_dist.value().second);
                            break;
                        case type::collision::LEAF:
                            phot.move(leaf_dist.value() + consts::num::BUMP, sop->ref_index());
                            energy_debt += leaf_dist.value() * phot.energy() * phot.weight();
                            leaf = tree_.leaf(phot.pos());
                            break;
                        case type::collision::CELL:
                            phot.move(cell_dist.value() + consts::num::BUMP, sop->ref_index());
                            energy_debt += cell_dist.value() * phot.energy() * phot.weight();
                            cell->add_energy(energy_debt);
                            energy_debt = 0.0;
                            cell        = dom_->cell(phot.pos());
                            break;
                        case type::collision::DOM:
                            phot.move(dom_dist.value(), sop->ref_index());
                            energy_debt += dom_dist.value() * phot.energy() * phot.weight();
                            loop = false;
                            break;
                    }
                }

                TRACK;
            }

            return (paths);
        }

        inline type::collision Sim::collide(const double inter_, const std::optional<std::pair<equip::Entity*, geom::Collision>>& ent_, const std::optional<double>& leaf_, const std::optional<double>& cell_, const std::optional<double>& dom_) const
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

            if (cell_ && (cell_.value() <= dist))
            {
                type = type::collision::CELL;
                dist = cell_.value();
            }

            if (dom_ && ((dom_.value() - consts::num::BUMP) <= dist))
            {
                type = type::collision::DOM;
                dist = dom_.value();
            }

            return (type);
        }

        inline void Sim::report(const unsigned long int num_phot_, std::vector<unsigned long int>* thread_phot_, const size_t light_index_) const noexcept
        {
            unsigned long int total = 0;

            while (total < num_phot_)
            {

                total = math::container::sum(*thread_phot_);

                std::cout << "Light " << light_index_ << " : " << total << '/' << num_phot_ << " (" << (total * 100.0 / num_phot_) << "%)\n";

                std::this_thread::sleep_for(std::chrono::milliseconds(_update_delta));
            }
        }


        //  -- Rendering --
        inline void Sim::render(const dom::Region& dom_, const tree::Root& tree_, const std::vector<std::vector<std::vector<gui::Point>>>& paths_) const noexcept
        {
#ifdef RENDER
            gui::Window win("Arctorus", 1600, 1200, 4);
            win.set_clear_col(glm::vec4(0.0f, 0.1f, 0.2f, 0.0f));

            gui::lens::Perspective lens(70.0f, 1600.0f / 1200.0f);

            const float scale = powf(10.0f, floorf(log10f(static_cast<float>((_max - _min).mag()) / 10.0f)));
            std::cout << "Graphical scale unit: " << scale << "m\n";

            gui::camera::Fly cam(glm::vec3((_max.x * 2) - _min.x, (_max.y * 2) - _min.y, (_max.z * 2) - _min.z), glm::vec3(_min.x - _max.x, _min.y - _max.y, _min.z - _max.z), glm::vec3(0.0f, 0.0f, 1.0f), scale / 10.0f);

            gui::Keymap map;
            map.use_fly_controls(&cam);

            gui::shader::Ambient  amb_shader;
            gui::shader::Normal   norm_shader;
            gui::shader::Specular spec_shader;
            gui::shader::Ray      ray_shader;

            gui::Actor grid = gui::actor::grid(glm::vec2(_min.x, _min.y), glm::vec2(_max.x, _max.y), glm::vec2(scale, scale));
            grid.set_col(glm::vec3(0.5f, 0.0f, 0.5f));

            gui::Actor axis_helper_x = gui::actor::axis_helper_x(scale, scale / 10.0f);
            gui::Actor axis_helper_y = gui::actor::axis_helper_y(scale, scale / 10.0f);
            gui::Actor axis_helper_z = gui::actor::axis_helper_z(scale, scale / 10.0f);

            gui::Actor dom_act = gui::actor::shape(dom_);
            dom_act.set_col(glm::vec3(1.0f, 1.0f, 0.0f));

            gui::Actor cell_act = gui::actor::domain(dom_);
            cell_act.set_col(glm::vec3(1.0f, 0.8f, 0.0f));

            std::vector<gui::Actor> ent_acts;
            for (size_t i = 0; i < _entities.size(); ++i)
            {
                ent_acts.emplace_back(gui::actor::shape(_entities[i]->surf()));
            }

            gui::Actor tree_act = gui::actor::tree(tree_);
            tree_act.set_col(glm::vec3(0.0, 1.0, 0.0));

            std::vector<gui::Actor> paths;
            size_t                  num_paths = 0;
            for (size_t i = 0; i < paths_.size(); ++i)
            {
                num_paths += paths_[i].size();
            }
            paths.reserve(num_paths);

            std::cout << "Creating path actors...\n";
            float max_time = 0.0;
            for (size_t i = 0; i < paths_.size(); ++i)
            {
                std::cout << "Processing path batch " << i << " of " << paths_.size() << '\n';
                for (size_t j = 0; j < paths_[i].size(); ++j)
                {
                    if (paths_[i][j].back().time > max_time)
                    {
                        max_time = paths_[i][j].back().time;
                    }
                    paths.emplace_back(gui::actor::path(paths_[i][j]));
                }
            }
            float       render_time       = 0.0f;
            const float render_time_delta = max_time / 10000.0f;
            const float render_time_step  = render_time_delta / 10.0f;
            std::cout << "Creating path actors complete!\n";

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
                    render_time = 0.0f;
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
