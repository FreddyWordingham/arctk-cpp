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
#include <arctk/index.hpp>
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

              private:
                //  -- Initialisation --
                inline std::vector<Triangle> init_tris(const std::vector<vec3>& poss_, const std::vector<vec3>& norms_, const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Mesh::Mesh(const std::vector<vec3>& poss_, const std::vector<vec3>& norms_, const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) noexcept
              : _tris(init_tris(poss_, norms_, faces_))
              , _areas(init_areas())
              , _box(init_box())
              , _num_verts(init_num_verts())
              , _num_norms(init_num_norms())
              , _num_edges(init_num_edges())
              , _num_faces(init_num_faces())
              , _closed((_num_verts + _num_faces - _num_edges) == 2)
            {
            }


            //  -- Initialisation --
            inline std::vector<Triangle> Mesh::init_tris(const std::vector<vec3>& poss_, const std::vector<vec3>& norms_, const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) const noexcept
            {
                PRE(poss_.size() >= 3);
                PRE(!norms_.empty());
                PRE(!faces_.empty());

                std::vector<Triangle> tris;
                tris.reserve(faces_.size());

                for (size_t i = 0; i < faces_.size(); ++i)
                {
                    const std::array<size_t, 3>& pos_indices  = faces_[i].first;
                    const std::array<size_t, 3>& norm_indices = faces_[i].second;

                    for (size_t j = 0; j < 3; ++j)
                    {
                        PRE(pos_indices[j] < poss_.size());
                        PRE(norm_indices[j] < norms_.size());
                    }

                    tris.emplace_back(std::array<vec3, 3>({{poss_[pos_indices[index::dim::cartesian::X]], poss_[pos_indices[index::dim::cartesian::Y]], poss_[pos_indices[index::dim::cartesian::Z]]}}),
                                      std::array<vec3, 3>({{norms_[norm_indices[index::dim::cartesian::X]], norms_[norm_indices[index::dim::cartesian::Y]], norms_[norm_indices[index::dim::cartesian::Z]]}}));
                }

                POST(!tris.empty());

                return (tris);
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_MESH_HPP
