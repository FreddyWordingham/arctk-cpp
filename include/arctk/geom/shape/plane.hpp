/**
 *  @file   arctk/geom/shape/plane.hpp
 *  @date   06/06/2018
 *  @author Freddy Wordingham
 *
 *  Geometric plane shape class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_SHAPE_PLANE_HPP
#define ARCTK_GEOM_SHAPE_PLANE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/geom/shape.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {
        namespace shape //! shape namespace
        {



            //  == CLASS ==
            /**
             */
            class Plane
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Plane(const math::Vec3<double>& centre_ = {0.0, 0.0, 0.0}, const math::Vec3<double>& dir_ = {0.0, 0.0, 1.0}) noexcept;


                //  == METHODS ==
              public:
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Plane::Plane(const math::Vec3<double>& centre_, const math::Vec3<double>& dir_) noexcept
              : Shape(centre_, dir_)
            {
            }



            //  == METHODS ==



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_PLANE_HPP
