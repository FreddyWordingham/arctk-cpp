/**
 *  @file   arctk/equip/entity/light/laser.inl
 *  @date   14/10/2018
 *  @author Freddy Wordingham
 *
 *  Laser light source entity class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_LIGHT_LASER_INL
#define ARCTK_EQUIP_ENTITY_LIGHT_LASER_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/math/vec3.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {
        namespace entity //! entity namespace
        {
            namespace light //! light source namespace
            {



                //  == INSTANTIATION ==
                //  -- Constructors --
                /**
                 *  Construct a light source entity which emits monochromatic photons at its surface.
                 *
                 *  @param  serial_     Serialised wavefront file.
                 *  @param  scale_      Scaling transformation.
                 *  @param  rot_        Rotation transformation.
                 *  @param  trans_      Translation transformation.
                 *  @param  mat_        Material to emit photons into.
                 *  @param  power_      Power of the light.
                 *  @param  kill_       Kill photons on collision.
                 *  @param  wavelength_ Wavelength of emitted photons.
                 *
                 *  @pre    serial may not be empty.
                 *  @pre    scale_.x must be positive.
                 *  @pre    scale_.y must be positive.
                 *  @pre    scale_.z must be positive.
                 *  @pre    power_ must be positive.
                 *  @pre    wavelength_ must be positive.
                 */
                inline Laser::Laser(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const opt::Mat& mat_, const double power_, const bool kill_, const double wavelength_) noexcept
                  : Light(serial_, scale_, rot_, trans_, mat_, power_, kill_)
                  , _wavelength(wavelength_)
                {
                    assert(!serial_.empty());
                    assert(scale_.x > 0.0);
                    assert(scale_.y > 0.0);
                    assert(scale_.z > 0.0);
                    assert(power_ > 0.0);
                    assert(wavelength_ > 0.0);
                }



                //  == METHODS ==
                //  -- Emission --
                /** Emit a photon in a given material with specific-optical-properties.
                 *
                 *  @param  rng_    Random number generator.
                 *  @param  energy_ Initial energy of the photon.
                 *  @param  time_   Initial timestamp of the photon.
                 *
                 *  @pre    energy_ must be positive.
                 *
                 *  @return Emitted photon in a material with specific-optical-properties.
                 */
                inline std::tuple<phys::Photon, const opt::Mat*, std::unique_ptr<opt::Sop>> Laser::emit(random::Generator* rng_, const double energy_, const double time_) const noexcept
                {
                    assert(energy_ > 0.0);

                    const std::pair<vec3, vec3> pos_norm = random_pos_and_norm(rng_);

                    phys::Photon phot(pos_norm.first, pos_norm.second, _wavelength, energy_, time_);

                    return (std::tuple<phys::Photon, const opt::Mat*, std::unique_ptr<opt::Sop>>(phot, &_mat, _mat.gen(phot)));
                }



            } // namespace light
        }     // namespace entity
    }         // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_LIGHT_LASER_INL
