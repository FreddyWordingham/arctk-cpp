/**
 *  @file   arctk/equip/light/laser.hpp
 *  @date   03/10/2018
 *  @author Freddy Wordingham
 *
 *  Laser light source equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_LIGHT_LASER_HPP
#define ARCTK_EQUIP_LIGHT_LASER_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/equip/light.hpp>
#include <arctk/math.hpp>
#include <arctk/phys.hpp>
#include <arctk/random.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {
        namespace light //! light source namespace
        {



            //  == CLASS ==
            /**
             *  Laser light source class.
             */
            class Laser : public Light
            {
                //  == FIELDS ==
              private:
                //  -- Structure --
                const double _wavelength;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Laser(double power_, const geom::shape::Mesh& surf_, double wavelength_) noexcept;


                //  == METHODS ==
              public:
                //  -- Emission --
                inline phys::particle::Photon emit(random::Generator* rng_, equip::Entity* const cur_ent_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Laser::Laser(const double power_, const geom::shape::Mesh& surf_, const double wavelength_) noexcept
              : Light(power_, surf_)
              , _wavelength(wavelength_)
            {
                PRE(wavelength_ > 0.0);
            }



            //  == METHODS ==
            //  -- Emission --
            inline phys::particle::Photon Laser::emit(random::Generator* rng_, equip::Entity* const cur_ent_) const noexcept
            {
                const std::pair<vec3, vec3> pos_norm = _surf.random_pos_and_norm(rng_);

                return (phys::particle::Photon(pos_norm.first, pos_norm.second, _wavelength, cur_ent_));
            }



        } // namespace light
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_LIGHT_LASER_HPP
