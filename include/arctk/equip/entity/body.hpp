/**
 *  @file   arctk/equip/entity/body.hpp
 *  @date   16/10/2018
 *  @author Freddy Wordingham
 *
 *  Body of material entity equipment class.
 */



//  == GUARD ==
#ifndef ARCTK_EQUIP_ENTITY_BODY_HPP
#define ARCTK_EQUIP_ENTITY_BODY_HPP



//  == IMPORTS ==
//  -- Std --
#include <memory>
#include <string>

//  -- Arctk --
#include <arctk/opt/sop.hpp>



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
        using vec3 = math::Vec<double, 3>;
    }             // namespace math
    namespace opt //! optical namespace
    {
        class Mat;
    }              // namespace opt
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



            //  == CLASS ==
            /**
             *  Body of material entity equipment class.
             */
            class Body : public Entity
            {
                //  == FIELDS ==
              private:
                //  -- Materials --
                const opt::Mat& _front_mat; //!< Front hit material.
                const opt::Mat& _back_mat;  //!< Back hit material.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Body(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_, const opt::Mat& front_mat_, const opt::Mat& back_mat_) noexcept;


                //  == METHODS ==
              private:
                //  -- Collision --
                inline bool hit_front(random::Generator* rng_, phys::Photon* phot_, const opt::Mat** mat_, std::unique_ptr<opt::Sop>* sop_, dom::Cell* cell_, const geom::Collision& coll_) noexcept override;
                inline bool hit_back(random::Generator* rng_, phys::Photon* phot_, const opt::Mat** mat_, std::unique_ptr<opt::Sop>* sop_, dom::Cell* cell_, const geom::Collision& coll_) noexcept override;
            };



        } // namespace entity
    }     // namespace equip
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/equip/entity/body.inl>



//  == GUARD END ==
#endif // ARCTK_EQUIP_ENTITY_BODY_HPP
