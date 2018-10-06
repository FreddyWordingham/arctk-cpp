/**
 *  @file   arctk/geom/shape.hpp
 *  @date   06/10/2018
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
            inline Shape()                      = default; //!< Defaulted constructor.
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
            //  -- Collision --
            virtual std::optional<double> collision_dist(const vec3& pos_, const vec3& dir_) const
              noexcept = 0; //!< Get the collision distance (if one occurs) of a ray.    @param  pos_    Initial position of the ray.    @param  dir_    Direction of ray travel.    @return Optional distance to collision event.
            virtual std::optional<std::pair<double, vec3>> collision_norm(const vec3& pos_, const vec3& dir_) const
              noexcept = 0; //!< Get the collision distance (if one occurs) and the normal of the intersection point of a ray.   @param  pos_    Initial position of the ray.    @param  dir_    Direction of ray travel.    @return Optional distance and
                            //!< normal pair to collision event.
        };



        //  == INSTANTIATION ==
        //  -- Destructors --
        /**
         *  Defaulted destructor.
         */
        inline Shape::~Shape() noexcept = default;



    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_HPP
