/**
 *  @file   arctk/geom/shape/plane.hpp
 *  @date   17/07/2018
 *  @author Freddy Wordingham
 *
 *  Geometric plane shape class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_SHAPE_PLANE_HPP
#define ARCTK_GEOM_SHAPE_PLANE_HPP



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
             *  Geometric plane shape.
             */
            class Plane : public Shape
            {
                //  == FIELDS ==
              private:
                //  -- Positioning --
                const vec3 _pos;  //!< Position of the plane.
                const vec3 _norm; //!< Normal of the plane.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Plane(const vec3& pos_, const vec3& norm_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const vec3& pos() const noexcept;
                inline const vec3& norm() const noexcept;

                //  -- Properties --
                inline vec3   min() const noexcept override;
                inline vec3   max() const noexcept override;
                inline double area() const noexcept override;
                inline double vol() const noexcept override;

                //  -- Emission --
                inline vec3                  random_pos(random::Generator* rng_) const noexcept override;
                inline vec3                  random_pos(random::Generator* rng_, double rad_) const noexcept;
                inline std::pair<vec3, vec3> random_pos_and_norm(random::Generator* rng_) const noexcept override;
                inline std::pair<vec3, vec3> random_pos_and_norm(random::Generator* rng_, double rad_) const noexcept;

                //  -- Collision --
                inline std::optional<double>                  collision(const vec3& pos_, const vec3& dir_) const noexcept override;
                inline std::optional<std::pair<double, vec3>> collision_norm(const vec3& pos_, const vec3& dir_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a plane at a location with a normal direction.
             *
             *  @param  pos_    Position of the plane.
             *  @param  norm_   Normal of the plane.
             *
             *  @pre    norm_ must be normalised.
             */
            inline Plane::Plane(const vec3& pos_, const vec3& norm_) noexcept
              : _pos(pos_)
              , _norm(norm_)
            {
                PRE(norm_.normalised());
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the position of the plane.
             *
             *  @return Position of the plane.
             */
            inline const vec3& Plane::pos() const noexcept
            {
                return (_pos);
            }

            /**
             *  Get the normal of the circle.
             *
             *  @return Normal of the circle.
             */
            inline const vec3& Plane::norm() const noexcept
            {
                return (_norm);
            }


            //  -- Properties --
            /**
             *  Get the minimum vec of the smallest bounding box containing the plane.
             *
             *  @return Minimum vec of the smallest bounding box containing the plane.
             */
            inline vec3 Plane::min() const noexcept
            {
                return (vec3(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest()));
            }

            /**
             *  Get the maximum vec of the smallest bounding box containing the plane.
             *
             *  @return Maximum vec of the smallest bounding box containing the plane.
             */
            inline vec3 Plane::max() const noexcept
            {
                return (vec3(std::numeric_limits<double>::max(), std::numeric_limits<double>::max(), std::numeric_limits<double>::max()));
            }

            /**
             *  Get the total surface area of the plane.
             *
             *  @post   area must be positive.
             *
             *  @return Total surface area of the plane.
             */
            inline double Plane::area() const noexcept
            {
                const double area = std::numeric_limits<double>::infinity();

                POST(area > 0.0);

                return (area);
            }

            /**
             *  Get the total volume of the plane.
             *
             *  @return Total volume of the plane.
             */
            inline double Plane::vol() const noexcept
            {
                return (0.0);
            }


            //  -- Emission --
            /**
             *  Generate a random position on the surface of the plane within a radius of one from its centre.
             *
             *  @param  rng_    Random number generator.
             *
             *  @return Random position on the surface of the plane.
             */
            inline vec3 Plane::random_pos(random::Generator* const rng_) const noexcept
            {
                return (random_pos(rng_, 1.0));
            }

            /**
             *  Generate a random position on the surface of the plane within a radius from its centre.
             *
             *  @param  rng_    Random number generator.
             *  @param  rad_    Radius of point generation.
             *
             *  @pre    rad_ must be positive.
             *
             *  @return Random position on the surface of the plane.
             */
            inline vec3 Plane::random_pos(random::Generator* const rng_, const double rad_) const noexcept
            {
                PRE(rad_ > 0.0);

                vec3 pos(std::sqrt(random::distribution::uniform(rng_, rad_ * rad_)), arc::consts::math::HALF_PI, random::distribution::uniform(rng_, consts::math::TWO_PI));
                pos = math::convert::polar_to_cart(pos);

                if (!math::compare::unity(std::fabs(_norm.z)))
                {
                    const double theta = std::acos(_norm[index::dim::cartesian::Z]);

                    pos.rotate((math::vec::axis<double, 3>(index::dim::cartesian::Z) ^ _norm).normal(), theta);
                }

                return (pos + _pos);
            }

            /**
             *  Generate a random position, and corresponding normal, on the surface of the plane within a radius of one from its centre.
             *
             *  @param  rng_    Random number generator.
             *
             *  @return Random position, and corresponding normal, on the surface of the plane.
             */
            inline std::pair<vec3, vec3> Plane::random_pos_and_norm(random::Generator* const rng_) const noexcept
            {
                return (std::pair<vec3, vec3>(random_pos(rng_), _norm));
            }

            /**
             *  Generate a random position, and corresponding normal, on the surface of the plane within a radius from its centre.
             *
             *  @param  rng_    Random number generator.
             *  @param  rad_    Radius of point generation.
             *
             *  @pre    rad_ must be positive.
             *
             *  @return Random position, and corresponding normal, on the surface of the plane.
             */
            inline std::pair<vec3, vec3> Plane::random_pos_and_norm(random::Generator* const rng_, const double rad_) const noexcept
            {
                return (std::pair<vec3, vec3>(random_pos(rng_, rad_), _norm));
            }


            //  -- Collision --
            /**
             *  Determine if a collision event occurs between the plane and a ray.
             *  If a collision does occur, return the distance to the collision point.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional collision distance.
             */
            inline std::optional<double> Plane::collision(const vec3& pos_, const vec3& dir_) const noexcept
            {
                const double denom = _norm * dir_;

                if (math::compare::zero(denom))
                {
                    return (std::nullopt);
                }

                const double dist = ((_pos - pos_) * _norm) / denom;

                return ((dist < 0.0) ? std::nullopt : std::optional<double>(dist));
            }

            /**
             *  Determine if a collision event occurs between the plane and a ray.
             *  If a collision does occur, return the distance to the collision point and the normal of the plane at the collision point.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional collision distance and intersection normal.
             */
            inline std::optional<std::pair<double, vec3>> Plane::collision_norm(const vec3& pos_, const vec3& dir_) const noexcept
            {
                std::optional<double> dist(collision(pos_, dir_));

                if (!dist)
                {
                    return (std::nullopt);
                }

                return (std::pair<double, vec3>(dist.value(), _norm));
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_PLANE_HPP
