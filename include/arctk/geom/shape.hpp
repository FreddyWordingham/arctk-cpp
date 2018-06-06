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
            const math::Vec3<double> _centre; //!< Centre of the shape.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Shape(const math::Vec3<double>& centre_) noexcept;

            //  -- Destructors --
            virtual inline ~Shape() noexcept = 0;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const math::Vec3<double>& centre() const noexcept;

            //  -- Collision --
            virtual inline double distance(const math::Vec3<double>& pos_, const math::Vec3<double>& dir_) const
              noexcept = 0; //!< Determine the distance along a ray to the shape's boundaries. @param pos_ Initial position of the ray. @param dir_ Direction of ray. @return Distance to surface. Inf if no collision.
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a shape centred on a given position.
         *
         *  @param  centre_ Centre of the shape.
         */
        inline Shape::Shape(const math::Vec3<double>& centre_) noexcept
          : _centre(centre_)
        {
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the centre of the shape.
         *
         *  @return Centre of the shape.
         */
        inline const math::Vec3<double>& Shape::centre() const noexcept
        {
            return (_centre);
        }



    } // namespace geom
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_HPP
