/**
 *  @file   arctk/equip/entity/detector/photometer.hpp
 *  @date   20/11/2018
 *  @author Freddy Wordingham
 *
 *  Photometer detector class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_DETECTOR_PHOTOMETER_HPP
#define ARCTK_EQUIP_ENTITY_DETECTOR_PHOTOMETER_HPP



//  == BASE ==
#include <arctk/equip/entity/detector.hpp>



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
                 *  Photometer detector class.
                 */
                class Photometer : public Detector
                {
                    //  == FIELDS ==
                  private:
                    //  -- Detector --
                    const bool _double_sided; //!< True if back hits are counted.

                    //  -- Data --
                    double _total_weight; //!< Total statistical weight of photons hitting the detector.


                    //  == INSTANTIATION ==
                  public:
                    //  -- Constructors --
                    inline Photometer(const geom::shape::Mesh& surf_, bool double_sided_) noexcept;


                    //  == METHODS ==
                  public:
                    //  -- Saving --
                    void save(const std::string& path_) const noexcept override; // NOLINT

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
#include <arctk/equip/entity/detector/photometer.inl>



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_DETECTOR_PHOTOMETER_HPP
