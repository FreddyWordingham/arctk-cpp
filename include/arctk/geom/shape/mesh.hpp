/**
 *  @file   arctk/geom/shape/mesh.hpp
 *  @date   09/08/2018
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
#include <arctk/geom/shape.hpp>
#include <arctk/geom/shape/triangle.hpp>
#include <arctk/index.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {
        namespace shape //! shape namespace
        {



            //  == SETTINGS ==
            //  -- Wavefront Keywords --
            constexpr const char* POS_KEYWORD  = "v";  //! Wavefront file keyword identifying vertex positions.
            constexpr const char* NORM_KEYWORD = "vn"; //! Wavefront file keyword identifying vertex normals.
            constexpr const char* FACE_KEYWORD = "f";  //! Wavefront file keyword identifying a face.



            //  == CLASS ==
            /**
             *  Geometric triangle mesh shape.
             */
            class Mesh : public Shape
            {
                //  == FIELDS ==
              private:
                //  -- Triangle Data --
                const std::vector<Triangle> _tris; //! List of triangles forming the mesh.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const Triangle& tri(const size_t index_) const noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



            //  == METHODS ==
            //  -- Getters --
            inline const Triangle& Mesh::tri(const size_t index_) const noexcept
            {
                PRE(index_ < _tris.size());

                return (_tris[index_]);
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_MESH_HPP
