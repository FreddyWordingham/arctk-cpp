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
#include <arctk/math/vec2.hpp>



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
                    double _total_weight; //!< Total statistical weight of photons hitting the detector.
                    vec2   _total_phase;


                    //  == INSTANTIATION ==
                  public:
                    //  -- Constructors --
                    inline Phaseometer(const geom::shape::Mesh& surf_, bool double_sided_) noexcept;


                    //  == METHODS ==
                  public:
                    //  -- Saving --
                    void save(const std::string& path_) const noexcept override;

                  private:
                    //  -- Collision --
                    bool hit_front(random::Generator* /*unused*/, phys::Photon* phot_, const opt::Mat** /*unused*/, std::unique_ptr<opt::Sop>* sop_, dom::Cell* cell_, const geom::Collision& coll_) noexcept override;
                    bool hit_back(random::Generator* /*unused*/, phys::Photon* phot_, const opt::Mat** /*unused*/, std::unique_ptr<opt::Sop>* sop_, dom::Cell* cell_, const geom::Collision& coll_) noexcept override;
                };



            } // namespace detector
        }     // namespace entity
    }         // namespace equip
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/equip/entity/detector/phaseometer.inl>



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_DETECTOR_PHASEOMETER_HPP
