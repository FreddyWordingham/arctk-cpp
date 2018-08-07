/**
 *  @file   arctk/geom/shape/aabb.hpp
 *  @date   07/08/2018
 *  @author Freddy Wordingham
 *
 *  Geometric axis-aligned bounding box shape class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_SHAPE_AABB_HPP
#define ARCTK_GEOM_SHAPE_AABB_HPP



//  == IMPORTS ==
//  -- Std --
#include <optional>

//  -- Arctk --
#include <arctk/geom/shape.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {
        namespace shape //! shape namespace
        {



            //  == CLASS ==
            /**
             *  Axis-aligned bounding box shape.
             */
            class Aabb : public Shape
            {
                //  == FIELDS ==
              protected:
                //  -- Positioning --
                vec3 _min; //!< Minimum vertex of the aabb.
                vec3 _max; //!< Maximum vertex of the aabb.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Aabb(const vec3& min_, const vec3& max_) noexcept;


                //  == METHODS ==
              public:
                //  -- Collision --
                inline std::optional<double> collision(const vec3& pos_, const vec3& dir_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct an axis-aligned bounding box with given minimum and maximum vertex positions.
             *
             *  @param  min_    Vertex position of the aabb.
             *  @param  max_    Vertex position of the aabb.
             */
            inline Aabb::Aabb(const vec3& min_, const vec3& max_) noexcept
              : _min(min_)
              , _max(max_)
            {
                PRE(min_.x < max_.x);
                PRE(min_.y < max_.y);
                PRE(min_.z < max_.z);
            }



            //  == METHODS ==
            //  -- Collision --
            inline std::optional<double> Aabb::collision(const vec3& pos_, const vec3& dir_) const noexcept
            {
                return (std::optional<double>(1.0));
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_AABB_HPP
