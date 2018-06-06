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
             *  Geometric sphere shape.
             */
            class Sphere
            {
                //  == FIELDS ==
              protected:
                //  -- Bounds --
                const double _radius; //!< Radius of the sphere.

                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Sphere(double radius_, const math::Vec3<double>& centre_) noexcept;


                //  == METHODS ==
              public:
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Sphere::Sphere(const double radius_, const math::Vec3<double>& centre_) noexcept
              : _shape(centre_)
              , _radius(radius_)
            {
            }



            //  == METHODS ==



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_SPHERE_HPP
