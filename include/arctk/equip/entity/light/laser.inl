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
#include <arctk/disc/block.hpp>
#include <arctk/disc/domain.hpp>
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
                inline Laser::Laser(const geom::shape::Mesh& surf_, const std::string& mat_id_, const double power_, const bool kill_, const double wavelength_) noexcept
                  : Light(surf_, mat_id_, power_, kill_)
                  , _wavelength(wavelength_)
                {
                    assert(!mat_id_.empty());
                    assert(power_ > 0.0);
                    assert(wavelength_ > 0.0);
                }



                //  == METHODS ==
                //  -- Emission --
                inline phys::Photon Laser::emit(random::Generator* const rng_, disc::Domain* const dom_, const double time_, const unsigned long int num_phot_) const noexcept
                {
                    assert(rng_ != nullptr);
                    assert(dom_ != nullptr);
                    assert(num_phot_ > 0);

                    const std::pair<vec3, vec3> pos_norm = _surf.random_pos_and_norm(rng_);

                    return (phys::Photon(pos_norm.first, pos_norm.second, _power / num_phot_, _wavelength, time_, _mat_id, dom_->block(pos_norm.first)->mat(_mat_id)));
                }



            } // namespace light
        }     // namespace entity
    }         // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_LIGHT_LASER_INL
