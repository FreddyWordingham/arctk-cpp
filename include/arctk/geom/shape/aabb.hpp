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
#include <arctk/exit.hpp>
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
              private:
                //  -- Positioning --
                vec3 _min; //!< Minimum vertex of the aabb.
                vec3 _max; //!< Maximum vertex of the aabb.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Aabb(const vec3& min_, const vec3& max_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const vec3& min() const noexcept;
                inline const vec3& max() const noexcept;

                //  -- Collision --
                inline std::optional<double>                  collision(const vec3& pos_, const vec3& dir_) const noexcept override;
                inline std::optional<std::pair<double, vec3>> collision_norm(const vec3& pos_, const vec3& dir_) const noexcept override;
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
            //  -- Getters --
            /**
             *  Get the minimum bound of the aabb.
             *
             *  @return Minimum bound of the aabb.
             */
            inline const vec3& Aabb::min() const noexcept
            {
                return (_min);
            }

            /**
             *  Get the maximum bound of the aabb.
             *
             *  @return Maximum bound of the aabb.
             */
            inline const vec3& Aabb::max() const noexcept
            {
                return (_max);
            }


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

                double min_x = ((dir_.x < 0.0 ? _max.x : _min.x) - pos_.x) / dir_.x;
                double max_x = ((dir_.x < 0.0 ? _min.x : _max.x) - pos_.x) / dir_.x;
                double min_y = ((dir_.y < 0.0 ? _max.y : _min.y) - pos_.y) / dir_.y;
                double max_y = ((dir_.y < 0.0 ? _min.y : _max.y) - pos_.y) / dir_.y;

                if ((min_x > max_y) || (min_y > max_x))
                {
                    return (std::nullopt);
                }

                if (min_y > min_x)
                {
                    min_x = min_y;
                }

                if (max_y < max_x)
                {
                    max_x = max_y;
                }

                double min_z = ((dir_.z < 0.0 ? _max.z : _min.z) - pos_.z) / dir_.z;
                double max_z = ((dir_.z < 0.0 ? _min.z : _max.z) - pos_.z) / dir_.z;

                if ((min_x > max_z) || (min_z > max_x))
                {
                    return (std::nullopt);
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

                if (t < 0.0)
                {
                    t = max_x;
                }

                if (t < 0.0)
                {
                    return (std::nullopt);
                }

                return (t);
            }

            /**
             *  Determine if a collision event occurs between the axis-aligned bounding box and a ray.
             *  If a collision does occur, return the distance to the collision point and the normal of the axis-aligned bounding box at the collision point.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional collision distance and intersection normal.
             */
            inline std::optional<std::pair<double, vec3>> Aabb::collision_norm(const vec3& pos_, const vec3& dir_) const noexcept
            {
                PRE(dir_.normalised());

                double min_x = ((dir_.x < 0.0 ? _max.x : _min.x) - pos_.x) / dir_.x;
                double max_x = ((dir_.x < 0.0 ? _min.x : _max.x) - pos_.x) / dir_.x;
                double min_y = ((dir_.y < 0.0 ? _max.y : _min.y) - pos_.y) / dir_.y;
                double max_y = ((dir_.y < 0.0 ? _min.y : _max.y) - pos_.y) / dir_.y;

                size_t index = 0;

                if ((min_x > max_y) || (min_y > max_x))
                {
                    return (std::nullopt);
                }

                if (min_y > min_x)
                {
                    min_x = min_y;
                    index = 1;
                }

                if (max_y < max_x)
                {
                    max_x = max_y;
                }

                double min_z = ((dir_.z < 0.0 ? _max.z : _min.z) - pos_.z) / dir_.z;
                double max_z = ((dir_.z < 0.0 ? _min.z : _max.z) - pos_.z) / dir_.z;

                if ((min_x > max_z) || (min_z > max_x))
                {
                    return (std::nullopt);
                }

                if (min_z > min_x)
                {
                    min_x = min_z;
                    index = 2;
                }

                if (max_z < max_x)
                {
                    max_x = max_z;
                }

                vec3 norm;
                norm[index] = (dir_[index] < 0.0) ? 1.0 : -1.0;

                double t = min_x;

                if (t < 0.0)
                {
                    t = max_x;
                    norm[index] *= -1.0;
                }

                if (t < 0.0)
                {
                    return (std::nullopt);
                }

                return (std::pair<double, vec3>(t, norm));
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_AABB_HPP
