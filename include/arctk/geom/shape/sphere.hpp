/**
 *  @file   arctk/geom/shape/sphere.hpp
 *  @date   17/07/2018
 *  @author Freddy Wordingham
 *
 *  Geometric sphere shape class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_SHAPE_SPHERE_HPP
#define ARCTK_GEOM_SHAPE_SPHERE_HPP



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
             *  Geometric sphere shape.
             */
            class Sphere : public Shape
            {
                //  == FIELDS ==
              private:
                //  -- Positioning --
                const vec3   _pos; //!< Position of the sphere.
                const double _rad; //!< Radius of the sphere.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Sphere(const vec3& pos_, double rad_) noexcept;


                //  == METHODS ==
              public:
                //  -- Collision --
                inline std::optional<double>                  collision(const vec3& pos_, const vec3& dir_) const noexcept override;
                inline std::optional<std::pair<double, vec3>> collision_norm(const vec3& pos_, const vec3& dir_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a sphere at a location with a radius.
             *
             *  @param  pos_    Position of the sphere.
             *  @param  rad_    Radius of the sphere.
             *
             *  @pre    rad_ must be positive.
             */
            inline Sphere::Sphere(const vec3& pos_, const double rad_) noexcept
              : _pos(pos_)
              , _rad(rad_)
            {
                PRE(rad_ > 0.0);
            }



            //  == METHODS ==
            //  -- Collision --
            /**
             *  Determine if a collision event occurs between the sphere and a ray.
             *  If a collision does occur, return the distance to the collision point.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional collision distance.
             */
            inline std::optional<double> Sphere::collision(const vec3& pos_, const vec3& dir_) const noexcept
            {
                PRE(dir_.normalised());

                const double b = 2.0 * (dir_ * (pos_ - _pos));
                const double c = (pos_ - _pos).mag_sq() - (_rad * _rad);

                const double delta = (b * b) - (4.0 * c);

                if (delta < 0.0)
                {
                    return (std::nullopt);
                }

                if (math::compare::zero(delta))
                {
                    const double dist = -b / 2.0;

                    if (dist >= 0.0)
                    {
                        return (dist);
                    }

                    return (std::nullopt);
                }

                const double sqrt_delta = std::sqrt(delta);

                const double dist_0 = (-b + sqrt_delta) / 2.0;
                const double dist_1 = (-b - sqrt_delta) / 2.0;

                if ((dist_0 < 0.0) && (dist_1 < 0.0))
                {
                    return (std::nullopt);
                }

                if ((dist_0 >= 0.0) && (dist_1 < 0.0))
                {
                    return (dist_0);
                }

                if ((dist_1 >= 0.0) && (dist_0 < 0.0))
                {
                    return (dist_1);
                }

                return (std::min(dist_0, dist_1));
            }

            /**
             *  Determine if a collision event occurs between the sphere and a ray.
             *  If a collision does occur, return the distance to the collision point and the normal of the sphere at the collision point.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional collision distance and intersection normal.
             */
            inline std::optional<std::pair<double, vec3>> Sphere::collision_norm(const vec3& pos_, const vec3& dir_) const noexcept
            {
                PRE(dir_.normalised());

                std::optional<double> dist(collision(pos_, dir_));

                if (!dist)
                {
                    return (std::nullopt);
                }

                return (std::pair<double, vec3>(dist.value(), ((pos_ + dir_) - _pos).normal()));
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_SPHERE_HPP
