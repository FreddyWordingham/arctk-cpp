/**
 *  @file   arctk/geom/shape/circle.hpp
 *  @date   22/08/2018
 *  @author Freddy Wordingham
 *
 *  Geometric circle shape class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_SHAPE_CIRCLE_HPP
#define ARCTK_GEOM_SHAPE_CIRCLE_HPP



//  == IMPORTS ==
//  -- Std --
#include <cmath>
#include <optional>

//  -- Arctk --
#include <arctk/consts.hpp>
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
             *  Geometric circle shape.
             */
            class Circle : public Shape
            {
                //  == FIELDS ==
              private:
                //  -- Positioning --
                const vec3 _pos;  //!< Position of the plane.
                const vec3 _norm; //!< Normal of the plane.

                //  -- Properties --
                const double _rad;      //!< Radius of the circle.
                const double _aperture; //!< Numerical aperture of the circle.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Circle(const vec3& pos_ = arc::vec3(0.0, 0.0, 0.0), const vec3& norm_ = arc::vec3(0.0, 0.0, 1.0), double rad_ = 1.0, double aperture_ = 0.0) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double      rad() const noexcept;
                inline double      aperture() const noexcept;
                inline const vec3& pos() const noexcept;
                inline const vec3& norm() const noexcept;

                //  -- Properties --
                inline vec3   min() const noexcept override;
                inline vec3   max() const noexcept override;
                inline double area() const noexcept override;
                inline double vol() const noexcept override;

                //  -- Emission --
                inline vec3                  random_pos(random::Generator* rng_) const noexcept override;
                inline std::pair<vec3, vec3> random_pos_and_norm(random::Generator* rng_) const noexcept override;

                //  -- Collision --
                inline std::optional<double>                  collision(const vec3& pos_, const vec3& dir_) const noexcept override;
                inline std::optional<std::pair<double, vec3>> collision_norm(const vec3& pos_, const vec3& dir_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a circle at a given location with a normal direction, radius and numerical aperture.
             *
             *  @param  pos_        Position of the circle.
             *  @param  norm_       Normal of the circle.
             *  @param  rad_        Radius of the circle.
             *  @param  aperture_   Numerical aperture of the circle.
             *
             *  @pre    norm_ must be normalised.
             *  @pre    rad_ must be positive.
             *  @pre    aperture_ must be between zero and half-Pi.
             */
            inline Circle::Circle(const vec3& pos_, const vec3& norm_, const double rad_, const double aperture_) noexcept
              : _pos(pos_)
              , _norm(norm_)
              , _rad(rad_)
              , _aperture(aperture_)
            {
                PRE(norm_.normalised());
                PRE(rad_ > 0.0);
                PRE((aperture_ >= 0.0) && (aperture_ <= consts::math::HALF_PI));
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the radius of the circle.
             *
             *  @return Radius of the circle.
             */
            inline double Circle::rad() const noexcept
            {
                return (_rad);
            }

            inline double Circle::aperture() const noexcept
            {
                return (_aperture);
            }

            inline const vec3& Circle::pos() const noexcept
            {
                return (_pos);
            }

            inline const vec3& Circle::norm() const noexcept
            {
                return (_norm);
            }


            //  -- Properties --
            /**
             *  Get the minimum vec of the smallest bounding box containing the circle.
             *
             *  @return Minimum vec of the smallest bounding box containing the circle.
             */
            inline vec3 Circle::min() const noexcept
            {
                vec3 norm_xy = vec3(_norm.x, _norm.y, 0.0).normal();

                vec3 delta;

                delta.x = std::abs(std::sin(std::acos(_norm.x)) * _rad);
                delta.y = std::abs(std::sin(std::acos(_norm.y)) * _rad);
                delta.z = std::abs(std::sin(std::acos(_norm.z)) * _rad);

                return (_pos - delta);
            }

            /**
             *  Get the maximum vec of the smallest bounding box containing the circle.
             *
             *  @return Maximum vec of the smallest bounding box containing the circle.
             */
            inline vec3 Circle::max() const noexcept
            {
                vec3 norm_xy = vec3(_norm.x, _norm.y, 0.0).normal();

                vec3 delta;

                delta.x = std::abs(std::sin(std::acos(_norm.x)) * _rad);
                delta.y = std::abs(std::sin(std::acos(_norm.y)) * _rad);
                delta.z = std::abs(std::sin(std::acos(_norm.z)) * _rad);

                return (_pos + delta);
            }

            /**
             *  Get the total surface area of the circle.
             *
             *  @post   area must be positive.
             *
             *  @return Total surface area of the circle.
             */
            inline double Circle::area() const noexcept
            {
                const double area = consts::math::PI * _rad * _rad;

                POST(area > 0.0);

                return (area);
            }

            /**
             *  Get the total volume of the circle.
             *
             *  @return Total volume of the circle.
             */
            inline double Circle::vol() const noexcept
            {
                return (0.0);
            }


            //  -- Emission --
            /**
             *  Generate a random position on the surface of the circle.
             *
             *  @param  rng_    Random number generator.
             *
             *  @return Random position on the surface of the circle.
             */
            inline vec3 Circle::random_pos(random::Generator* const rng_) const noexcept
            {
                vec3 pos(std::sqrt(random::distribution::uniform(rng_, _rad * _rad)), arc::consts::math::HALF_PI, random::distribution::uniform(rng_, consts::math::TWO_PI));
                pos = math::convert::polar_to_cart(pos);

                if (!math::compare::unity(std::fabs(_norm.z)))
                {
                    const double theta = std::acos(_norm[index::dim::cartesian::Z]);

                    pos.rotate((math::vec::axis<double, 3>(index::dim::cartesian::Z) ^ _norm).normal(), theta);
                }

                return (pos + _pos);
            }

            /**
             *  Generate a random position, and corresponding normal, on the surface of the circle.
             *
             *  @param  rng_    Random number generator.
             *
             *  @return Random position, and corresponding normal, on the surface of the circle.
             */
            inline std::pair<vec3, vec3> Circle::random_pos_and_norm(random::Generator* const rng_) const noexcept
            {
                vec3 pos(std::sqrt(random::distribution::uniform(rng_, _rad * _rad)), arc::consts::math::HALF_PI, random::distribution::uniform(rng_, consts::math::TWO_PI));

                const double alpha = _aperture * (pos.rho / _rad);
                vec3         norm  = vec3(std::sin(alpha), 0.0, std::cos(alpha));
                norm.rotate(math::vec::axis<double, 3>(index::dim::cartesian::Z), pos.phi);

                pos = math::convert::polar_to_cart(pos);

                if (!math::compare::unity(std::fabs(_norm.z)))
                {
                    const double theta = std::acos(_norm[index::dim::cartesian::Z]);

                    pos.rotate((math::vec::axis<double, 3>(index::dim::cartesian::Z) ^ _norm).normal(), theta);
                    norm.rotate((math::vec::axis<double, 3>(index::dim::cartesian::Z) ^ _norm).normal(), theta);
                }

                return (std::pair<vec3, vec3>(pos + _pos, norm));
            }


            //  -- Collision --
            /**
             *  Determine if a collision event occurs between the circle and a ray.
             *  If a collision does occur, return the distance to the collision point.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional collision distance.
             */
            inline std::optional<double> Circle::collision(const vec3& pos_, const vec3& dir_) const noexcept
            {
                const double denom = _norm * dir_;

                if (math::compare::zero(denom))
                {
                    return (std::nullopt);
                }

                const double dist = ((_pos - pos_) * _norm) / denom;

                if ((dist < 0.0) || (math::geom::distance(_pos, pos_ + (dir_ * dist)) > _rad))
                {
                    return (std::nullopt);
                }

                return (dist);
            }

            /**
             *  Determine if a collision event occurs between the circle and a ray.
             *  If a collision does occur, return the distance to the collision point and the normal of the circle at the collision point.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional collision distance and intersection normal.
             */
            inline std::optional<std::pair<double, vec3>> Circle::collision_norm(const vec3& pos_, const vec3& dir_) const noexcept
            {
                const double denom = _norm * dir_;

                if (math::compare::zero(denom))
                {
                    return (std::nullopt);
                }

                const double dist = ((_pos - pos_) * _norm) / denom;

                if (dist < 0.0)
                {
                    return (std::nullopt);
                }

                const vec3 hit  = pos_ + (dir_ * dist);
                const vec3 axis = (_norm ^ (hit - _pos)).normal();
                vec3       norm = _norm;
                norm.rotate(axis, _aperture * (math::geom::distance(_pos, hit) / _rad));

                return (std::pair<double, vec3>(dist, _norm));
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_CIRCLE_HPP
