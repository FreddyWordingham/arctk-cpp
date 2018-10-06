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
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/geom/shape/triangle.hpp>
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
              private:
                //  -- Triangles --
                const std::vector<Triangle> _tris;  //!< List of triangles forming the mesh.
                const std::vector<double>   _areas; //!< Normalised relative area of each triangle forming the mesh.

                //  -- Bounds --
                const Box _box; //!< Bounding box of the mesh.

                //  -- Properties --
                const size_t _num_verts; //!< Number of unique vertex positions forming the mesh.
                const size_t _num_norms; //!< Number of unique vertex normals forming the mesh.
                const size_t _num_edges; //!< Number of unique edges forming the mesh.
                const size_t _num_faces; //!< Number of unique triangle faces forming the mesh.
                const bool   _closed;    //!< True if the surface of the mesh forms a closed surface.



                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Mesh(const std::vector<vec3>& poss_, const std::vector<vec3>& norms_, const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Mesh::Mesh(const std::vector<vec3>& poss_, const std::vector<vec3>& norms_, const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) noexcept
            {
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_MESH_HPP
