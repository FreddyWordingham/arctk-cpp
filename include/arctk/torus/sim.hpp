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
#include <cstddef>
#include <string>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace torus //! transport of radiation under skin namespace
    {



        //  == CLASS ==
        /**
         *  Radiative transfer simulation class.
         */
        class Sim
        {
            //  == FIELDS ==
          private:
            //  -- Parallelisation --
            size_t _num_threads;

            //  -- Output --
            std::string _output_dir;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --

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

            //  -- Pre-flight --
            inline void create_output_dir() const noexcept;
        };



    } // namespace torus
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/torus/sim.inl>



//  == GUARD END ==
#endif // ARCTK_TORUS_SIM_HPP
