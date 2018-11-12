/**
 *  @file   arctk/torus/sim.hpp
 *  @date   07/11/2018
 *  @author Freddy Wordingham
 *
 *  Radiative transfer simulation class.
 */



//  == GUARD ==
#ifndef ARCTK_TORUS_SIM_HPP
#define ARCTK_TORUS_SIM_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cstddef>
#include <string>

//  -- Arctk --
#include <arctk/math/vec3.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace torus //! transport of radiation under skin namespace
    {



        //  == SETTINGS ==
        //  -- Filenames --
        constexpr const char* const INFO_FILENAME = "info.txt";



        //  == CLASS ==
        /**
         *  Radiative transfer simulation class.
         */
        class Sim
        {
            //  == FIELDS ==
          private:
            //  -- Bounds --
            const vec3 _min;
            const vec3 _max;

            //  -- Parallelisation --
            size_t _num_threads;

            //  -- Output --
            std::string _output_dir;

            //  -- Domain --
            std::array<size_t, 3> _res;

            //  -- Tree --
            size_t _max_depth;
            size_t _tar_tris;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Sim(const vec3& min_, const vec3& max_) noexcept;

          private:
            //  -- Initialisation --



            //  == OPERATORS ==
          public:
            //  -- Access --


            //  == METHODS ==
          public:
            //  -- Setters --
            inline void set_num_threads(const size_t num_threads_) noexcept;
            inline void set_output_dir(const std::string& output_dir_) noexcept;
            inline void set_res(const size_t res_) noexcept;
            inline void set_res(const std::array<size_t, 3>& res_) noexcept;
            inline void set_max_depth(const size_t max_depth_) noexcept;
            inline void set_tar_tris(const size_t tar_tris_) noexcept;

            //  -- Pre-flight --
          private:
            inline void create_output_dir() const noexcept;
            inline void pre_flight_info_write() const noexcept;

            //  -- Post-flight --
          private:
            inline void post_flight_info_write() const noexcept;

            //  -- Simulate --
            inline void run_pre_flight() const noexcept;
            inline void run_post_flight() const noexcept;

          public:
            inline void run() const noexcept;
        };



    } // namespace torus
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/torus/sim.inl>



//  == GUARD END ==
#endif // ARCTK_TORUS_SIM_HPP
