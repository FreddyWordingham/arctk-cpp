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

            //  -- Roulette --
            bool   _roulette;
            double _roulette_limit;
            double _roulette_chance;

            //  -- Parallelisation --
            unsigned int _update_delta;
            size_t       _num_threads;

            //  -- Rendering --
            bool _pre_render;
            bool _post_render;

            //  -- Output --
            std::string _output_dir;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Sim(const vec3& min_, const vec3& max_) noexcept;


            //  == METHODS ==
          public:
            //  -- Setters --
            inline void set_res(size_t res_) noexcept;
            inline void set_res(const std::array<size_t, 3>& res_) noexcept;
        };



    } // namespace torus
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/torus/sim.inl>



//  == GUARD END ==
#endif // ARCTK_TORUS_SIM_HPP
