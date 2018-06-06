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
            math::Vec3<double> _centre;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --

            //  == OPERATORS ==
          public:
            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION ==



    } // namespace geom
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_HPP
