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



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <thread>
#include <type_traits>

//  -- Arctk --
#include <arctk/config/build.hpp>
#include <arctk/config/version.hpp>
#include <arctk/data/obj.hpp>
#include <arctk/dom/region.hpp>
#include <arctk/equip/entity.hpp>
#include <arctk/equip/entity/detector.hpp>
#include <arctk/equip/entity/light.hpp>
#include <arctk/exit/error.hpp>
#include <arctk/parse/print.hpp>
#include <arctk/parse/write.hpp>
#include <arctk/tree/root.hpp>



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
          , _num_threads(1)
          , _output_dir("output/")
          , _res({{25, 25, 25}})
          , _max_depth(6)
          , _tar_tris(10)
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

            _lights.emplace_back(dynamic_cast<arc::equip::entity::Light*>(_entities.back().get()));
        }

        template <typename T>
        inline void Sim::add_detector(T&& det_, const std::string& path_) noexcept
        {
            static_assert(std::is_base_of<equip::entity::Detector, T>::value);

            _entities.emplace_back(std::make_unique<T>(det_));

            _detectors.emplace_back(std::make_pair(dynamic_cast<arc::equip::entity::Detector*>(_entities.back().get()), path_));
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

            std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
            std::chrono::time_point<std::chrono::system_clock> end   = std::chrono::system_clock::now();

            std::ofstream file(_output_dir + INFO_FILENAME, std::ofstream::app);

            file << "================================================================\n\n";

            file << "Simulation run time    : " << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << "\n\n";

            file << "Domain min             : " << _min << '\n'
                 << "Domain max             : " << _max << '\n'
                 << "Domain resolution      : " << _res << '\n'
                 << "Domain cell count      : " << dom.num_cells() << '\n'
                 << "Domain cell size       : " << dom.cell_size() << "\n\n";

            file << "Tree max depth         : " << tree.max_depth() << '\n' << "Tree max triangles     : " << tree.max_tris() << '\n' << "Tree nodes             : " << tree.num_nodes() << "\n\n";
        }



    } // namespace torus
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TORUS_SIM_INL
