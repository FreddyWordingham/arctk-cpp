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
        } // namespace entity
    }     // namespace equip
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
            //  -- Entities --
            std::vector<std::unique_ptr<equip::Entity>> _ents;
            std::vector<equip::entity::Light*>          _lights;


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
