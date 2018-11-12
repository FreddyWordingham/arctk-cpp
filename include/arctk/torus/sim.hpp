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
#include <memory>
#include <vector>

//  -- Arctk --
#include <arctk/equip/entity.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        class Obj;
    }               // namespace data
    namespace equip //! equipment namespace
    {
        namespace entity //! entity namespace
        {
            class Light;
        }         // namespace entity
    }             // namespace equip
    namespace opt //! optical namespace
    {
        class Mat;
    } // namespace opt
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
            const size_t _num_threads;


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
        };



    } // namespace torus
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/torus/sim.inl>



//  == GUARD END ==
#endif // ARCTK_TORUS_SIM_HPP
