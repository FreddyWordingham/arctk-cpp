/**
 *  @file   arctk/equip/entity/detector/photometer.inl
 *  @date   20/11/2018
 *  @author Freddy Wordingham
 *
 *  Photometer detector clas
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_DETECTOR_PHOTOMETER_INL
#define ARCTK_EQUIP_ENTITY_DETECTOR_PHOTOMETER_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <fstream>

//  -- Arctk --
#include <arctk/geom/collision.hpp>
#include <arctk/phys/photon.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {
        namespace entity //! entity namespace
        {
            namespace detector //! detector namespace
            {



                //  == INSTANTIATION ==
                //  -- Constructors --
                /**
                 *  Construct a photometer object.
                 *
                 *  @param  surf_           Surface of the photometer.
                 *  @param  double_sided_   True if detector may record back hits.
                 */
                inline Photometer::Photometer(const geom::shape::Mesh& surf_, const bool double_sided_) noexcept
                  : Detector(surf_)
                  , _double_sided(double_sided_)
                  , _total_hits(0)
                  , _total_weight(0.0)
                {
                }



                //  == METHODS ==
                //  -- Saving --
                void Photometer::save(const std::string& path_) const noexcept
                {
                    assert(!path_.empty());

                    std::ofstream file(path_ + "weight.dat");
                    file << "Total weight : " << _total_weight << '\n';

                    std::ofstream file(path_ + "hit.dat");
                    file << "Total weight : " << _total_hits << '\n';
                }


                //  -- Collision --
                void Photometer::hit_front(random::Generator* const /*unused*/, phys::Photon* const phot_, disc::Block* const /*unused*/, const geom::Collision& coll_) noexcept
                {
                    assert(phot_ != nullptr);

                    phot_->travel(coll_.dist());

                    ++_total_hits;
                    _total_weight += phot_->weight();

                    phot_->kill();
                }

                void Photometer::hit_back(random::Generator* const /*unused*/, phys::Photon* const phot_, disc::Block* const /*unused*/, const geom::Collision& coll_) noexcept
                {
                    assert(phot_ != nullptr);

                    phot_->travel(coll_.dist());

                    if (_double_sided)
                    {
                        ++_total_hits;
                        _total_weight += phot_->weight();
                    }

                    phot_->kill();
                }



            } // namespace detector
        }     // namespace entity
    }         // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_DETECTOR_PHOTOMETER_INL
