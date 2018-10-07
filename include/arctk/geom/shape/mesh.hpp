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
#include <arctk/utl.hpp>



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
                inline std::vector<double>   init_areas() const noexcept;
                inline Box                   init_box() const noexcept;
                inline size_t                init_num_verts(size_t num_poss_, const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) const noexcept;
                inline size_t                init_num_norms(size_t num_norms_, const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) const noexcept;
                inline size_t                init_num_edges(const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const Triangle& tri(size_t index_) const noexcept;
                inline const Box&      box() const noexcept;
                inline size_t          num_verts() const noexcept;
                inline size_t          num_norms() const noexcept;
                inline size_t          num_edges() const noexcept;
                inline size_t          num_faces() const noexcept;
                inline bool            closed() const noexcept;

                //  -- Sampling --
                inline vec3                  random_pos(random::Generator* rng_) const noexcept;
                inline std::pair<vec3, vec3> random_pos_and_norm(random::Generator* rng_) const noexcept;

                //  -- Intersection --
                inline bool intersect(const Triangle& tri_) const noexcept;
                inline bool intersect(const Mesh& mesh_) const noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Mesh::Mesh(const std::vector<vec3>& poss_, const std::vector<vec3>& norms_, const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) noexcept
              : _tris(init_tris(poss_, norms_, faces_))
              , _areas(init_areas())
              , _box(init_box())
              , _num_verts(init_num_verts(poss_.size(), faces_))
              , _num_norms(init_num_norms(norms_.size(), faces_))
              , _num_edges(init_num_edges(faces_))
              , _num_faces(faces_.size())
              , _closed((_num_verts + _num_faces - _num_edges) == 2)
            {
                PRE(poss_.size() >= 3);
                PRE(!norms_.empty());
                PRE(!faces_.empty());

                POST(!_tris.empty());
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

            inline std::vector<double> Mesh::init_areas() const noexcept
            {
                std::vector<double> areas(_tris.size() + 1);

                areas[0] = 0.0;
                for (size_t i = 1; i < areas.size(); ++i)
                {
                    areas[i] = areas[i - 1] + _tris[i - 1].area();
                }

                for (size_t i = 0; i < areas.size(); ++i)
                {
                    areas[i] /= areas.back();
                }

                POST(math::compare::unity(areas.back()));

                return (areas);
            }

            inline Box Mesh::init_box() const noexcept
            {
                vec3 min(std::numeric_limits<double>::max(), std::numeric_limits<double>::max(), std::numeric_limits<double>::max());
                vec3 max(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());

                for (size_t i = 0; i < _tris.size(); ++i)
                {
                    for (size_t j = 0; j < 3; ++j)
                    {
                        for (size_t k = 0; k < 3; ++k)
                        {
                            if (_tris[i].poss()[j][k] < min[k])
                            {
                                min[k] = _tris[i].poss()[j][k];
                            }

                            if (_tris[i].poss()[j][k] > max[k])
                            {
                                max[k] = _tris[i].poss()[j][k];
                            }
                        }
                    }
                }

                return (Box(min, max));
            }

            inline size_t Mesh::init_num_verts(const size_t num_poss_, const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) const noexcept
            {
                std::vector<bool> used(num_poss_, false);

                for (size_t i = 0; i < faces_.size(); ++i)
                {
                    const std::array<size_t, 3>& pos_indices = faces_[i].first;

                    for (size_t j = 0; j < 3; ++j)
                    {
                        used[pos_indices[j]] = true;
                    }
                }

                size_t num_verts = 0;
                for (size_t i = 0; i < used.size(); ++i)
                {
                    if (used[i])
                    {
                        ++num_verts;
                    }
                }

                return (num_verts);
            }

            inline size_t Mesh::init_num_norms(const size_t num_norms_, const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) const noexcept
            {
                std::vector<bool> used(num_norms_, false);

                for (size_t i = 0; i < faces_.size(); ++i)
                {
                    const std::array<size_t, 3>& norm_indices = faces_[i].second;

                    for (size_t j = 0; j < 3; ++j)
                    {
                        used[norm_indices[j]] = true;
                    }
                }

                size_t num_norms = 0;
                for (size_t i = 0; i < used.size(); ++i)
                {
                    if (used[i])
                    {
                        ++num_norms;
                    }
                }

                return (num_norms);
            }

            inline size_t Mesh::init_num_edges(const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) const noexcept
            {
                std::vector<std::pair<size_t, size_t>> edges;

                for (size_t i = 0; i < faces_.size(); ++i)
                {
                    std::array<size_t, 3> pos_indices = faces_[i].first;

                    if (pos_indices[0] > pos_indices[1])
                    {
                        std::swap(pos_indices[0], pos_indices[1]);
                    }
                    if (pos_indices[0] > pos_indices[2])
                    {
                        std::swap(pos_indices[0], pos_indices[2]);
                    }
                    if (pos_indices[1] > pos_indices[2])
                    {
                        std::swap(pos_indices[1], pos_indices[2]);
                    }

                    const std::array<std::pair<size_t, size_t>, 3> edge_indices(
                      {{std::pair<size_t, size_t>(pos_indices[0], pos_indices[1]), std::pair<size_t, size_t>(pos_indices[1], pos_indices[2]), std::pair<size_t, size_t>(pos_indices[0], pos_indices[2])}});

                    for (size_t j = 0; j < 3; ++j)
                    {
                        if (!utl::properties::contains(edges, edge_indices[j]))
                        {
                            edges.emplace_back(edge_indices[j]);
                        }
                    }
                }

                return (edges.size());
            }



            //  == METHODS ==
            //  -- Getters --
            inline const Triangle& Mesh::tri(const size_t index_) const noexcept
            {
                PRE(index_ < _tris.size());

                return (_tris[index_]);
            }

            inline const Box& Mesh::box() const noexcept
            {
                return (_box);
            }

            inline size_t Mesh::num_verts() const noexcept
            {
                return (_num_verts);
            }

            inline size_t Mesh::num_norms() const noexcept
            {
                return (_num_norms);
            }

            inline size_t Mesh::num_edges() const noexcept
            {
                return (_num_edges);
            }

            inline size_t Mesh::num_faces() const noexcept
            {
                return (_num_faces);
            }

            inline bool Mesh::closed() const noexcept
            {
                return (_closed);
            }


            //  -- Sampling --
            inline vec3 Mesh::random_pos(random::Generator* rng_) const noexcept
            {
                PRE(rng_ != nullptr);

                return (_tris[utl::search::lower(_areas, rng_->gen())].random_pos(rng_));
            }

            inline std::pair<vec3, vec3> Mesh::random_pos_and_norm(random::Generator* rng_) const noexcept
            {
                PRE(rng_ != nullptr);

                return (_tris[utl::search::lower(_areas, rng_->gen())].random_pos_and_norm(rng_));
            }


            //  -- Intersection --
            inline bool Mesh::intersect(const Triangle& tri_) const noexcept
            {
                if (!_box.intersect(tri_))
                {
                    return (false);
                }

                for (size_t i = 0; i < _tris.size(); ++i)
                {
                    if (_tris[i].intersect(tri_))
                    {
                        return (true);
                    }
                }

                return (false);
            }

            inline bool Mesh::intersect(const Mesh& mesh_) const noexcept
            {
                if (!_box.intersect(mesh_.box()))
                {
                    return (false);
                }

                for (size_t i = 0; i < _tris.size(); ++i)
                {
                    for (size_t j = 0; j < mesh_.num_faces(); ++j)
                    {
                        if (_tris[i].intersect(mesh_.tri(j)))
                        {
                            return (true);
                        }
                    }
                }

                return (false);
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_MESH_HPP
