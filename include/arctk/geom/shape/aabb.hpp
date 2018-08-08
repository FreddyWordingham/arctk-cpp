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
             *
             *  @pre    min_.x must be less than max_.x.
             *  @pre    min_.y must be less than max_.y.
             *  @pre    min_.z must be less than max_.z.
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
            /**
             *  Determine if a collision event occurs between the aabb and a ray.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional collision distance.
             */
            inline std::optional<double> Aabb::collision(const vec3& pos_, const vec3& dir_) const noexcept // NOLINT
            {
                PRE(dir_.normalised());

                std::array<vec3, 2> bounds({{_min, _max}});
                std::array<bool, 3> sign;
                sign[0] = dir_.x < 0.0;
                sign[1] = dir_.y < 0.0;
                sign[2] = dir_.z < 0.0;

                double min_x = (bounds[sign[0]].x - pos_.x) / dir_.x;
                double max_x = (bounds[1 - sign[0]].x - pos_.x) / dir_.x;
                double min_y = (bounds[sign[1]].y - pos_.y) / dir_.y;
                double max_y = (bounds[1 - sign[1]].y - pos_.y) / dir_.y;

                if ((min_x > max_y) || (min_y > max_x))
                {
                    return false;
                }

                if (min_y > min_x)
                {
                    min_x = min_y;
                }

                if (max_y < max_x)
                {
                    max_x = max_y;
                }

                double min_z = (bounds[sign[2]].z - pos_.z) / dir_.z;
                double max_z = (bounds[1 - sign[2]].z - pos_.z) / dir_.z;

                if ((min_x > max_z) || (min_z > max_x))
                {
                    return (std::optional<double>(std::nullopt));
                }

                if (min_z > min_x)
                {
                    min_x = min_z;
                }

                if (max_z < max_x)
                {
                    max_x = max_z;
                }

                double t = min_x;

                if (t < 0)
                {
                    t = max_x;
                }

                if (t < 0)
                {
                    return (std::optional<double>(std::nullopt));
                }

                return (std::optional<double>(t));
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_AABB_HPP
