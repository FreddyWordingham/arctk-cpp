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
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <thread>

//  -- Arctk --
#include <arctk/data/obj.hpp>
#include <arctk/exit/error.hpp>



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
        {
            assert(min_.x < max_.x);
            assert(min_.y < max_.y);
            assert(min_.z < max_.z);
        }



        //  == OPERATORS ==



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

            file << "Threads used: " << _num_threads << '\n';
        }



    } // namespace torus
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TORUS_SIM_INL
