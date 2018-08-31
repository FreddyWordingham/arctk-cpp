/**
 *  @file   arctk/geom/shape.hpp
 *  @date   16/07/2018
 *  @author Freddy Wordingham
 *
 *  Geometric shape class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_SHAPE_HPP
#define ARCTK_GEOM_SHAPE_HPP



//  == IMPORTS ==
//  -- Std --
#include <optional>

//  -- Arctk --
#include <arctk/math.hpp>
#include <arctk/random.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {



        //  == CLASS ==
        /**
         *  Geometric shape.
         */
        class Shape
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Shape()                      = default;
            inline Shape(const Shape&) noexcept = default; //!< Defaulted copy constructor.
            inline Shape(Shape&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Shape() noexcept = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Shape& operator=(const Shape&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Shape& operator=(Shape&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            virtual vec3          min() const noexcept  = 0; //!<    Get the minimum vec of the smallest bounding box containing the shape.  @return Minimum vec of the smallest bounding box containing the shape.
            virtual vec3          max() const noexcept  = 0;
            virtual inline double area() const noexcept = 0;
            virtual inline double vol() const noexcept  = 0;

            //  -- Emission --
            virtual inline vec3 random_pos(random::Generator* rng_) const noexcept = 0; //!< Generate a random position on the surface of the shape. @param  rng_    Random number generator.    @return Randomly generated point on the surface of the shape.
            virtual inline std::pair<vec3, vec3> random_pos_and_norm(random::Generator* rng_) const
              noexcept = 0; //!< Generate a random position, and corresponding normal, on the surface of the shape. @param  rng_    Random number generator.    @return Randomly generated point, and corresponding normal, on the surface of the shape.

            //  -- Collision --
            virtual inline std::optional<double> collision(const vec3& pos_, const vec3& dir_) const
              noexcept = 0; //!< Get the collision distance (if one occurs) of a ray.    @param  pos_    Initial position of the ray.    @param  dir_    Direction of ray travel.    @return Optional distance to collision event
            virtual inline std::optional<std::pair<double, vec3>> collision_norm(const vec3& pos_, const vec3& dir_) const
              noexcept = 0; //!< Get the collision distance (if one occurs) and the normal of the intersection point of a ray.   @param  pos_    Initial position of the ray.    @param  dir_    Direction of ray travel.    @return Optional distance and
                            //!< normal pair to collision event.
        };



        //  == INSTANTIATION ==
        //  -- Destructors --
        inline Shape::~Shape() noexcept = default;



    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_HPP
