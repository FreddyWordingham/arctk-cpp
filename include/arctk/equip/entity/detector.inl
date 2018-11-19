/**
 *  @file   arctk/equip/entity/detector.inl
 *  @date   12/11/2018
 *  @author Freddy Wordingham
 *
 *  Detector entity equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_DETECTOR_INL
#define ARCTK_EQUIP_ENTITY_DETECTOR_INL



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {
        namespace entity //! entity namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a detector with a surface.
             *
             *  @param  surf_   Surface of the detector.
             */
            inline Detector::Detector(const geom::shape::Mesh& surf_) noexcept
              : Entity(surf_)
            {
            }


            //  -- Destructors --
            /**
             *  Default destructor.
             */
            inline Detector::~Detector() noexcept = default;



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_DETECTOR_INL
