/**
 *  @file   arctk/geom/shape/sphere.hpp
 *  @date   06/06/2018
 *  @author Freddy Wordingham
 *
 *  Geometric sphere shape class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_SHAPE_SPHERE_HPP
#define ARCTK_GEOM_SHAPE_SPHERE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == BASE ==
//  -- Std --
#include <optional>

//  -- Arctk --
#include <arctk/geom/shape.hpp>



//  == IMPORTS ==
//  -- Std --
#include <cmath>
#include <limits>

//  -- Arctk --
#include <arctk/geom/collision.hpp>
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
                //  -- Bounds --
                const double _radius; //!< Radius of the sphere.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Sphere(double radius_, const vec3& pos_ = {0.0, 0.0, 0.0}) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double radius() const noexcept;

                //  -- Collision --
                inline std::optional<double> collision(const vec3& pos_, const vec3& dir_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a sphere with a radius at a location.
             *
             *  @param  radius_ Radius of the sphere.
             *  @param  pos_    Position of the sphere.
             *
             *  @pre    radius_ must be positive.
             */
            inline Sphere::Sphere(const double radius_, const vec3& pos_) noexcept
              : Shape(pos_)
              , _radius(radius_)
            {
                assert(radius_ > 0.0);
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the radius of the sphere.
             *
             *  @return Radius of the sphere.
             */
            inline double Sphere::radius() const noexcept
            {
                return (_radius);
            }


            //  -- Collision --
            /**
             *  Determine if a collision event occurs between the sphere and a ray.
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
                assert(dir_.normalised());

                const double b = 2.0 * (dir_ * (pos_ - _pos));
                const double c = (pos_ - _pos).mag_sq() - math::sq(_radius);

                const double delta = math::sq(b) - (4.0 * c);

                if (delta < 0.0)
                {
                    return (std::nullopt);
                }

                if (delta == 0.0)
                {
                    const double dist = -b / 2.0;

                    if (dist >= 0.0)
                    {
                        return (std::optional<double>(dist));
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
                    return (std::optional<double>(dist_0));
                }

                if ((dist_1 >= 0.0) && (dist_0 < 0.0))
                {
                    return (std::optional<double>(dist_1));
                }

                return (std::optional<double>(std::min(dist_0, dist_1)));
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_SPHERE_HPP
