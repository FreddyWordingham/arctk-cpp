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
                //  -- Emission --
                inline vec3                  random_pos(random::Generator* const rng_) const noexcept override;
                inline std::pair<vec3, vec3> random_pos_and_norm(random::Generator* const rng_) const noexcept;

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
            //  -- Emission --
            inline vec3 Circle::random_pos(random::Generator* const rng_) const noexcept
            {
                vec3 pos(std::sqrt(random::distribution::uniform(rng_, _rad * _rad)), arc::consts::math::HALF_PI, random::distribution::uniform(rng_, consts::math::TWO_PI));
                pos = math::convert::polar_to_cart(pos);

                const size_t axis  = !math::compare::unity(_norm.z) ? index::dim::cartesian::Z : index::dim::cartesian::X;
                const double theta = std::acos(_norm[axis]);

                pos.rotate((math::vec::axis<double, 3>(axis) ^ _norm).normal(), theta);

                return (pos + _pos);
            }

            inline std::pair<vec3, vec3> Circle::random_pos_and_norm(random::Generator* const rng_) const noexcept
            {
                vec3 pos(std::sqrt(random::distribution::uniform(rng_, _rad * _rad)), arc::consts::math::HALF_PI, random::distribution::uniform(rng_, consts::math::TWO_PI));
                pos = math::convert::polar_to_cart(pos);

                const size_t axis  = !math::compare::unity(_norm.z) ? index::dim::cartesian::Z : index::dim::cartesian::X;
                const double theta = std::acos(_norm[axis]);

                pos.rotate((math::vec::axis<double, 3>(axis) ^ _norm).normal(), theta);

                return (std::pair<vec3, vec3>(pos + _pos, _norm));
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

                return (std::pair<double, vec3>(dist, _norm));
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_CIRCLE_HPP
