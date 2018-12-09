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



//  == IMPORTS ==
//  -- Std --
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <iterator>

//  -- Arctk --
#include <arctk/equip/entity/detector.hpp>
#include <arctk/equip/entity/light.hpp>
#include <arctk/exit/error.hpp>



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
        constexpr const char*        DEFAULT_OUTPUT_DIR      = "./";



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Sim::Sim(const vec3& min_, const vec3& max_, const std::array<size_t, 3>& res_, const std::string& aether_id_, const opt::Material& aether_) noexcept
          : _entities(0)
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
          , _output_dir(DEFAULT_OUTPUT_DIR)
        {
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

            std::cout << "================================================================\n\n"
                      << "  ____    _____   ____      ______ _____   _____           ____ \n"
                      << " //__\\\\  ||___)) //   ` o  o  ||  //   \\\\ ||___))  ||  || //___`\n"
                      << "//    \\\\ ||   \\\\ \\\\___, o  o  ||  \\\\___// ||   \\\\  \\\\__// .___//\n"
                      << "\n----------------------------------------------------------------\n";
        }


        inline ~Sim::Sim() noexcept
        {
            std::cout << "----------------------------------------------------------------\n\n"
                      << "                      Simulation Complete\n"
                      << "\n================================================================\n";
        }



        //  == METHODS ==
        //  -- Setters --
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

        inline void Sim::set_pre_render_(const bool pre_render_) noexcept
        {
            _pre_render = pre_render_;
        }

        inline void Sim::set_post_render_(const bool post_render_) noexcept
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
        inline void Sim::add_light(T&& light_) noexcept
        {
            static_assert(std::is_base_of<equip::entity::Light, T>::value);

            _entities.emplace_back(std::make_unique<T>(light_));
            _lights.emplace_back(dynamic_cast<equip::entity::Light*>(_entities.back().get()));
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
        inline void Sim::pre_flight() const noexcept
        {
            std::cout << "Running pre-flight...\n";


            std::cout << "Pre-flight complete.\n";
        }


        //  -- Post-Flight --
        inline void Sim::post_flight() const noexcept
        {
            std::cout << "Running pre-flight...\n";


            std::cout << "Pre-flight complete.\n";
        }


        //  -- Simulation --
        inline void Sim::run() const noexcept
        {
            pre_flight();

            post_flight();
        }



    } // namespace torus
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TORUS_SIM_INL
