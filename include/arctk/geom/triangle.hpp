/**
 *  @file   arctk/geom/triangle.hpp
 *  @date   29/08/2018
 *  @author Freddy Wordingham
 *
 *  Geometric triangle class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_TRIANGLE_HPP
#define ARCTK_GEOM_TRIANGLE_HPP



//  == IMPORTS ==
//  -- Std --
#include <optional>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {



        //  == CLASS ==
        /**
         *  Geometric triangle.
         */
        class Triangle
        {
            //  == FIELDS ==
          private:
            //  -- Positioning --
            const std::array<vec3, 3> _poss;  //!< Vertex positions.
            const std::array<vec3, 3> _norms; //!< Vertex normals.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
            //  -- Getters --

            //  -- Collision --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



        //  == METHODS ==



    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_TRIANGLE_HPP
