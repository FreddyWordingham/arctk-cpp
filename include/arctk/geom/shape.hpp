/**
 *  @file   arctk/geom/shape.hpp
 *  @date   06/06/2018
 *  @author Freddy Wordingham
 *
 *  Geometric shape class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_SHAPE_HPP
#define ARCTK_GEOM_SHAPE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/geom/collision.hpp>
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
            //  == FIELDS ==
          protected:
            //  -- Positioning --
            math::Vec3<double> _pos; //!< Position of the shape.
            math::Vec3<double> _dir; //!< Direction of the shape.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Shape(const math::Vec3<double>& pos_ = {0.0, 0.0, 0.0}, const math::Vec3<double>& dir_ = {0.0, 0.0, 1.0}) noexcept;
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
            inline const math::Vec3<double>& position() const noexcept;
            inline const math::Vec3<double>& dir() const noexcept;

            //  -- Collision --
            virtual inline Collision collision(const math::Vec3<double>& pos_, const math::Vec3<double>& dir_) const
              noexcept = 0; //!< Determine the distance along a ray to the shape's boundaries. @param pos_ Initial position of the ray. @param dir_ Direction of ray. @return Collision properties.
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a shape positioned on a given position.
         *
         *  @param  pos_    Position of the shape.
         *  @param  dir_    Direction of the shape.
         *
         *  @pre    dir_ must be normalised.
         */
        inline Shape::Shape(const math::Vec3<double>& pos_, const math::Vec3<double>& dir_) noexcept
          : _pos(pos_)
          , _dir(dir_)
        {
            assert(dir_.normalised());
        }


        //  -- Destructors --
        inline Shape::~Shape() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the position of the shape.
         *
         *  @return Position of the shape.
         */
        inline const math::Vec3<double>& Shape::position() const noexcept
        {
            return (_pos);
        }

        /**
         *  Get the direction of the shape.
         *
         *  @return Direction of the shape.
         */
        inline const math::Vec3<double>& Shape::dir() const noexcept
        {
            return (_dir);
        }



    } // namespace geom
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_HPP
