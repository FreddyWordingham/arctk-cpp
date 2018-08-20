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
                vec3 _pos;  //!< Position of the plane.
                vec3 _norm; //!< Normal of the plane.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Plane(const vec3& pos_, const vec3& norm_) noexcept;


                //  == METHODS ==
              public:
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
