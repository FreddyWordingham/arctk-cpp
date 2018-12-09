/**
 *  @file   arctk/torus/sim.hpp
 *  @date   09/12/2018
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
#include <memory>
#include <string>
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/equip/entity.hpp>
#include <arctk/equip/entity/light.hpp>
#include <arctk/math/vec.hpp>



//  == CLASS PROTOTYPES ==



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
            std::vector<std::unique_ptr<equip::Entity>>                         _entities;
            std::vector<equip::entity::Light* const>                            _lights;
            std::vector<std::pair<const equip::entity::Detector*, std::string>> _detectors;

            //  -- Domain --
            const vec3            _min;
            const vec3            _max;
            std::array<size_t, 3> _res;

            //  -- Tree --
            size_t _max_depth;
            size_t _tar_tris;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
        };



    } // namespace torus
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/torus/sim.inl>



//  == GUARD END ==
#endif // ARCTK_TORUS_SIM_HPP
