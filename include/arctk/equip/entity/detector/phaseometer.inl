/**
 *  @file   arctk/equip/entity/detector/phaseometer.inl
 *  @date   19/11/2018
 *  @author Freddy Wordingham
 *
 *  Phaseometer detector clas
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_DETECTOR_PHASEOMETER_INL
#define ARCTK_EQUIP_ENTITY_DETECTOR_PHASEOMETER_INL



//  == IMPORTS ==
//  -- Arctk --



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
                inline Phaseometer::Phaseometer(const geom::shape::Mesh& surf_, const bool double_sided_) noexcept
                  : Detector(surf_)
                  , _double_sided(double_sided_)
                  , _total_phase(0.0, 0.0)
                {
                }



                //  == METHODS ==
                //  -- Collision --
                bool Phaseometer::hit_front(random::Generator* rng_, phys::Photon* phot_, const opt::Mat** mat_, std::unique_ptr<opt::Sop>* sop_, dom::Cell* cell_, const geom::Collision& coll_) noexcept
                {
                    return (false);
                }

                bool Phaseometer::hit_back(random::Generator* rng_, phys::Photon* phot_, const opt::Mat** mat_, std::unique_ptr<opt::Sop>* sop_, dom::Cell* cell_, const geom::Collision& coll_) noexcept
                {
                    if (_double_sided)
                    {
                        return (hit_front());
                    }

                    return (false);
                }



            } // namespace detector
        }     // namespace entity
    }         // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_DETECTOR_PHASEOMETER_INL
