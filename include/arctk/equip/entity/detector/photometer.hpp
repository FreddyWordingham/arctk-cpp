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



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace disc //! discretisation namespace
    {
        class Block;
    }              // namespace disc
    namespace geom //! geometric namespace
    {
        class Collision;
    }              // namespace geom
    namespace phys //! physics namespace
    {
        class Photon;
    }                // namespace phys
    namespace random //! random number namespace
    {
        class Generator;
    } // namespace random
} // namespace arc



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
                    unsigned long int _total_hits;   //!< Total number of photons hitting the detector.
                    double            _total_weight; //!< Total statistical weight of photons hitting the detector.


                    //  == INSTANTIATION ==
                  public:
                    //  -- Constructors --
                    inline Photometer(const geom::shape::Mesh& surf_, bool double_sided_) noexcept;


                    //  == METHODS ==
                  public:
                    //  -- Saving --
                    void save(const std::string& path_) const noexcept override;

                  private:
                    //  -- Collision --
                    void hit_front(random::Generator* /*unused*/, phys::Photon* phot_, disc::Block* /*unused*/, const geom::Collision& coll_) noexcept override;
                    void hit_back(random::Generator* /*unused*/, phys::Photon* phot_, disc::Block* /*unused*/, const geom::Collision& coll_) noexcept override;
                };



            } // namespace detector
        }     // namespace entity
    }         // namespace equip
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/equip/entity/detector/photometer.inl>



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_DETECTOR_PHOTOMETER_HPP
