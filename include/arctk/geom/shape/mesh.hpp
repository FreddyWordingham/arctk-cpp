/**
 *  @file   arctk/geom/shape/mesh.hpp
 *  @date   06/10/2018
 *  @author Freddy Wordingham
 *
 *  Geometric triangle mesh shape class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_SHAPE_MESH_HPP
#define ARCTK_GEOM_SHAPE_MESH_HPP



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
        namespace shape //! shape namespace
        {



            //  == CLASS ==
            /**
             *  Triangular mesh shape.
             */
            class Mesh : public Shape
            {
                //  == FIELDS ==
              protected:
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              public:
                //  -- Getters --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_MESH_HPP
