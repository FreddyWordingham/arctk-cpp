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
#include <utility>

//  -- Arctk --
#include <arctk/geom/shape/mesh.hpp>
#include <arctk/math/vec.hpp>



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
                inline Laser::Laser(const geom::shape::Mesh& surf_, const std::string& mat_id_, const opt::Material& mat_, const double power_, const unsigned long int num_phot_, const bool kill_, const double wavelength_) noexcept
                  : Light(surf_, mat_id_, mat_, power_, num_phot_, kill_)
                  , _wavelength(wavelength_)
                {
                    assert(!mat_id_.empty());
                    assert(power_ > 0.0);
                    assert(num_phot_ > 0);
                    assert(wavelength_ > 0.0);
                }



                //  == METHODS ==
                //  -- Emission --
                inline phys::Photon Laser::emit(random::Generator* rng_, const double time_) const noexcept
                {
                    const std::pair<vec3, vec3> pos_norm = _surf.random_pos_and_norm(rng_);

                    return (phys::Photon(pos_norm.first, pos_norm.second, _wavelength, _phot_power, time_, _mat_id, _mat));
                }



            } // namespace light
        }     // namespace entity
    }         // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_LIGHT_LASER_INL
