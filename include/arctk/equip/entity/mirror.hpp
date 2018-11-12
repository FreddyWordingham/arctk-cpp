/**
 *  @file   arctk/equip/entity/mirror.hpp
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Mirror entity equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_MIRROR_HPP
#define ARCTK_EQUIP_ENTITY_MIRROR_HPP



//  == BASE ==
#include <arctk/equip/entity.hpp>



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <string>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {
        class Cell;
    }              // namespace dom
    namespace geom //! geometric namespace
    {
        class Collision;
    }              // namespace geom
    namespace math //! mathematical namespace
    {
        template <typename T, size_t N>
        class Vec;
    } // namespace math
    using vec3 = math::Vec<double, 3>;
    namespace opt //! optical namespace
    {
        class Mat;
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



            //  == CLASS ==
            /**
             *  Mirror entity equipment class.
             */
            class Mirror : public Entity
            {
                //  == FIELDS ==
              private:
                //  -- Reflectance --
                const double _front_ref; //!< Reflectance of the front mirror.
                const double _back_ref;  //!< Reflectance of the back mirror.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Mirror(const geom::shape::Mesh& surf_, double front_ref_, double back_ref_) noexcept;


                //  == METHODS ==
              private:
                //  -- Collision --
                inline bool hit_front(random::Generator* rng_, phys::Photon* phot_, const opt::Mat** /*unused*/, std::unique_ptr<opt::Sop>* sop_, dom::Cell* cell_, const geom::Collision& coll_) noexcept override;
                inline bool hit_back(random::Generator* rng_, phys::Photon* phot_, const opt::Mat** /*unused*/, std::unique_ptr<opt::Sop>* sop_, dom::Cell* cell_, const geom::Collision& coll_) noexcept override;
            };



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/equip/entity/mirror.inl>



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_MIRROR_HPP
