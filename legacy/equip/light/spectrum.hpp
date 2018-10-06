/**
 *  @file   arctk/equip/light/spectrum.hpp
 *  @date   03/10/2018
 *  @author Freddy Wordingham
 *
 *  Spectrum light source equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_LIGHT_SPECTRUM_HPP
#define ARCTK_EQUIP_LIGHT_SPECTRUM_HPP



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <type_traits>
#include <utility>

//  -- Arctk --
#include <arctk/equip/light.hpp>
#include <arctk/geom.hpp>
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
             *  Spectrum light source class.
             */
            class Spectrum : public Light
            {
                //  == FIELDS ==
              private:
                //  -- Structure --
                const random::distribution::Linear<double> _spec; //!< Spectrum used to draw photon wavelength values from.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Spectrum(const double power_, const geom::shape::Mesh& surf_, const random::distribution::Linear<double>& spec_) noexcept;


                //  == METHODS ==
              public:
                //  -- Emission --
                inline phys::particle::Photon emit(random::Generator* rng_, equip::Entity* const cur_ent_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Spectrum::Spectrum(const double power_, const geom::shape::Mesh& surf_, const random::distribution::Linear<double>& spec_) noexcept
              : Light(power_, surf_)
              , _spec(spec_)
            {
                PRE(power_ > 0.0);
            }



            //  == METHODS ==
            //  -- Emission --
            inline phys::particle::Photon Spectrum::emit(random::Generator* rng_, equip::Entity* const cur_ent_) const noexcept
            {
                const std::pair<vec3, vec3> pos_norm = _surf.random_pos_and_norm(rng_);

                return (phys::particle::Photon(pos_norm.first, pos_norm.second, _spec.sample(rng_), cur_ent_));
            }



        } // namespace light
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_LIGHT_SPECTRUM_HPP
