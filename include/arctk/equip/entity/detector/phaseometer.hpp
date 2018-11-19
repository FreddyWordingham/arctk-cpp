/**
 *  @file   arctk/equip/entity/detector/phaseometer.hpp
 *  @date   19/11/2018
 *  @author Freddy Wordingham
 *
 *  Phaseometer detector class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_DETECTOR_PHASEOMETER_HPP
#define ARCTK_EQUIP_ENTITY_DETECTOR_PHASEOMETER_HPP



//  == BASE ==
#include <arctk/equip/entity/detector.hpp>



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



                //  == CLASS ==
                /**
                 *  Phaseometer detector class.
                 */
                class Phaseometer : public Detector
                {
                    //  == FIELDS ==
                  private:
                    //  -- Detector --
                    const bool _double_sided;

                    //  -- Data --
                    vec2 _total_phase;


                    //  == INSTANTIATION ==
                  public:
                    //  -- Constructors --
                    inline Phaseometer(const geom::shape::Mesh& surf_) noexcept;


                    //  == METHODS ==
                  public:
                };



            } // namespace detector
        }     // namespace entity
    }         // namespace equip
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/equip/entity/detector/phaseometer.inl>



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_DETECTOR_PHASEOMETER_HPP
