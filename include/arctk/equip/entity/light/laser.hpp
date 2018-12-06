/**
 *  @file   arctk/equip/entity/light/laser.hpp
 *  @date   14/10/2018
 *  @author Freddy Wordingham
 *
 *  Laser light source entity class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_LIGHT_LASER_HPP
#define ARCTK_EQUIP_ENTITY_LIGHT_LASER_HPP



//  == BASE ==
#include <arctk/equip/entity/light.hpp>



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <string>
#include <tuple>

//  -- Arctk --
#include <arctk/phys/photon.hpp>



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
        namespace shape //! shape namespace
        {
            class Mesh;
        }         // namespace shape
    }             // namespace geom
    namespace opt //! optical namespace
    {
        class Material;
    }                // namespace opt
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
            namespace light //! light source namespace
            {



                //  == CLASS ==
                /**
                 *  Laser light entity equipment class.
                 */
                class Laser : public Light
                {
                    //  == FIELDS ==
                  private:
                    //  -- Emission --
                    const double _wavelength; //!< Emission wavelength.


                    //  == INSTANTIATION ==
                  public:
                    //  -- Constructors --
                    inline Laser(const geom::shape::Mesh& surf_, const std::string& mat_id_, opt::Material* const mat_, double power_, unsigned long int num_phot_, bool kill_, double wavelength_) noexcept;


                    //  == METHODS ==
                  public:
                    //  -- Emission --
                    inline phys::Photon emit(random::Generator* rng_, double time_) const noexcept override;
                };



            } // namespace light
        }     // namespace entity
    }         // namespace equip
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/equip/entity/light/laser.inl>



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_LIGHT_LASER_HPP
