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
//  -- Arctk --
#include <arctk/data/obj.hpp>



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
            //  -- Data --


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Sim(const data::Obj& param_) noexcept;

          private:
            //  -- Initialisation --


            //  == OPERATORS ==
          public:
            //  -- Access --


            //  == METHODS ==
          public:
        };



    } // namespace torus
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/torus/sim.inl>



//  == GUARD END ==
#endif // ARCTK_TORUS_SIM_HPP
