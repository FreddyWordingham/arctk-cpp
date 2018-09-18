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
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <utility>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/exit.hpp>
#include <arctk/geom/shape.hpp>
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



            //  == SETTINGS ==
            //  -- Wavefront Keywords --
            constexpr const char* POS_KEYWORD  = "v";  //!< Wavefront file keyword identifying vertex positions.
            constexpr const char* NORM_KEYWORD = "vn"; //!< Wavefront file keyword identifying vertex normals.
            constexpr const char* FACE_KEYWORD = "f";  //!< Wavefront file keyword identifying a face.



            //  == CLASS ==
            /**
             *  Geometric triangle mesh shape.
             */
            class Mesh : public Shape
            {
                //  == FIELDS ==
              private:
                //  -- Triangle Data --
                const std::vector<Triangle> _tris; //!< List of triangles forming the mesh.

                //  -- Properties --
                const size_t _num_verts; //!< Number of unique vertex positions forming the mesh.
                const size_t _num_norms; //!< Number of unique vertex normals forming the mesh.
                const size_t _num_edges; //!< Number of unique edges forming the mesh.
                const size_t _num_faces; //!< Number of unique triangle faces forming the mesh.
                const bool   _closed;    //!< True if the surface of the mesh forms a closed surface.

                //  -- Areas --
                const std::vector<double> _areas; //!< Normalised relative area of each triangle forming the mesh.

                //  -- Bounds --
                const Aabb _box; //!< Bounding box of the mesh.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Mesh(const std::string& serial_, const vec3& scale_ = vec3(1.0, 1.0, 1.0), const vec3& rot_ = vec3(0.0, 0.0, 0.0), const vec3& trans_ = vec3(0.0, 0.0, 0.0)) noexcept;
                inline Mesh(const std::vector<vec3>& poss_, const std::vector<vec3>& norms_, const std::vector<std::array<std::array<size_t, 3>, 2>>& faces_, const vec3& scale_, const vec3& rot_, const vec3& trans_) noexcept;
                inline Mesh(const std::vector<vec3>& poss_, const std::vector<vec3>& norms_, const std::vector<std::array<std::array<size_t, 3>, 2>>& faces_) noexcept;

              private:
                //  -- Initialisation --
                inline std::vector<vec3>                                 parse_poss(const std::string& serial_) const noexcept;
                inline std::vector<vec3>                                 parse_norms(const std::string& serial_) const noexcept;
                inline std::vector<std::array<std::array<size_t, 3>, 2>> parse_faces(const std::string& serial_) const noexcept;
                inline std::vector<vec3>                                 transform_poss(const std::vector<vec3>& poss_, const mat4& transform_) const noexcept;
                inline std::vector<vec3>                                 transform_norms(const std::vector<vec3>& norms_, const mat4& transform_) const noexcept;
                inline std::vector<Triangle>                             init_tris(const std::vector<vec3>& poss_, const std::vector<vec3>& norms_, const std::vector<std::array<std::array<size_t, 3>, 2>>& faces_) const noexcept;
                inline size_t                                            init_num_verts(const std::vector<vec3>& poss_, const std::vector<std::array<std::array<size_t, 3>, 2>>& faces_) const noexcept;
                inline size_t                                            init_num_norms(const std::vector<vec3>& norms_, const std::vector<std::array<std::array<size_t, 3>, 2>>& faces_) const noexcept;
                inline size_t                                            init_num_edges(const std::vector<std::array<std::array<size_t, 3>, 2>>& faces_) const noexcept;
                inline std::vector<double>                               init_areas() const noexcept;
                inline Aabb                                              init_box() const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline std::vector<const Shape*> shape_list() const noexcept override;
                inline const Triangle&           tri(size_t index_) const noexcept;
                inline size_t                    num_verts() const noexcept;
                inline size_t                    num_norms() const noexcept;
                inline size_t                    num_edges() const noexcept;
                inline size_t                    num_faces() const noexcept;

                //  -- Properties --
                inline vec3   min() const noexcept override;
                inline vec3   max() const noexcept override;
                inline double area() const noexcept override;
                inline double vol() const noexcept override;
                inline bool   closed() const noexcept override;

                //  -- Emission --
                inline vec3                  random_pos(random::Generator* rng_) const noexcept override;
                inline std::pair<vec3, vec3> random_pos_and_norm(random::Generator* rng_) const noexcept override;

                //  -- Intersection --
                inline bool intersect_surf(const shape::Aabb& aabb_) const noexcept override;
                inline bool intersect_vol(const shape::Aabb& /**/) const noexcept override;

                //  -- Collision --
                inline std::optional<double>                  collision(const vec3& pos_, const vec3& dir_) const noexcept override;
                inline std::optional<std::pair<double, vec3>> collision_norm(const vec3& pos_, const vec3& dir_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a mesh by parsing a serialised wavefront object.
             *  Additional transformations may be applied to the base mesh.
             *
             *  @param  serial_ String of the serialised wavefront object.
             *  @param  scale_  Scale transformation to apply to the base wavefront object.
             *  @param  rot_    Rotation transformation to apply to the base wavefront object.
             *  @param  trans_  Translation transformation to apply to the base wavefront object.
             *
             *  @pre    serial_ may not be empty.
             */
            inline Mesh::Mesh(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_) noexcept
              : Mesh(parse_poss(serial_), parse_norms(serial_), parse_faces(serial_), scale_, rot_, trans_)
            {
                PRE(!serial_.empty());
            }

            /**
             *  Construct a mesh by transforming a list of vertex positions and normals.
             *
             *  @param  poss_   Vector of vertex positions to be transformed.
             *  @param  norms_  Vector of vertex normals to be transformed.
             *  @param  faces_  Vector of face data used to construct triangle faces.
             *  @param  scale_  Scale transformation to apply to the base wavefront object.
             *  @param  rot_    Rotation transformation to apply to the base wavefront object.
             *  @param  trans_  Translation transformation to apply to the base wavefront object.
             *
             *  @pre    poss_ must contain at least three elements.
             *  @pre    norms_ may not be empty.
             *  @pre    faces_ may not be empty.
             */
            inline Mesh::Mesh(const std::vector<vec3>& poss_, const std::vector<vec3>& norms_, const std::vector<std::array<std::array<size_t, 3>, 2>>& faces_, const vec3& scale_, const vec3& rot_, const vec3& trans_) noexcept
              : Mesh(transform_poss(poss_, math::mat::transform(scale_, rot_, trans_)), transform_norms(norms_, math::mat::transform(scale_, rot_, trans_)), faces_)
            {
                PRE(poss_.size() >= 3);
                PRE(!norms_.empty());
                PRE(!faces_.empty());
            }

            /**
             *  Construct a mesh by from a list of vertex positions and normals.
             *
             *  @param  poss_   Vector of vertex positions.
             *  @param  norms_  Vector of vertex normals.
             *  @param  faces_  Vector of face data used to construct triangle faces.
             *
             *  @pre    poss_ must contain at least three elements.
             *  @pre    norms_ may not be empty.
             *  @pre    faces_ may not be empty.
             */
            inline Mesh::Mesh(const std::vector<vec3>& poss_, const std::vector<vec3>& norms_, const std::vector<std::array<std::array<size_t, 3>, 2>>& faces_) noexcept
              : _tris(init_tris(poss_, norms_, faces_))
              , _num_verts(init_num_verts(poss_, faces_))
              , _num_norms(init_num_norms(norms_, faces_))
              , _num_edges(init_num_edges(faces_))
              , _num_faces(faces_.size())
              , _closed((_num_verts + _num_faces - _num_edges) == 2)
              , _areas(init_areas())
              , _box(init_box())
            {
                PRE(poss_.size() >= 3);
                PRE(!norms_.empty());
                PRE(!faces_.empty());
            }


            //  -- Initialisation --
            /**
             *  Parse the vector of vertex positions from a serialised wavefront object file.
             *
             *  @param  serial_ String of the serialised wavefront object.
             *
             *  @pre    serial_ may not be empty.
             *
             *  @post   poss must contain at least three elements.
             *
             *  @return Parsed vector of vertex positions.
             */
            inline std::vector<vec3> Mesh::parse_poss(const std::string& serial_) const noexcept
            {
                PRE(!serial_.empty());

                std::vector<vec3> poss;

                std::stringstream serial_stream(serial_);
                std::string       line;
                while (std::getline(serial_stream, line))
                {
                    std::stringstream line_stream(line);
                    std::string       word;
                    line_stream >> word;

                    if (word == POS_KEYWORD)
                    {
                        vec3 pos;
                        line_stream >> pos.x >> pos.y >> pos.z;

                        if (line_stream.rdbuf()->in_avail() != 0)
                        {
                            std::cerr << "Unable to construct mesh object.\n"
                                      << "Non-three dimensional vertex position located at line: `" << line << "`.\n";

                            std::exit(exit::error::FAILED_PARSE);
                        }

                        poss.emplace_back(pos);
                    }

                    if (line_stream.fail())
                    {
                        std::cerr << "Unable to construct mesh object.\n"
                                  << "Unable to parse line: `" << line << "`.\n";
                    }
                }

                POST(poss.size() >= 3);

                return (poss);
            }

            /**
             *  Parse the vector of vertex normals from a serialised wavefront object file.
             *
             *  @param  serial_ String of the serialised wavefront object.
             *
             *  @pre    serial_ may not be empty.
             *
             *  @post   norms may not be empty.
             *
             *  @return Parsed vector of vertex normals.
             */
            inline std::vector<vec3> Mesh::parse_norms(const std::string& serial_) const noexcept
            {
                PRE(!serial_.empty());

                std::vector<vec3> norms;

                std::stringstream serial_stream(serial_);
                std::string       line;
                while (std::getline(serial_stream, line))
                {
                    std::stringstream line_stream(line);
                    std::string       word;
                    line_stream >> word;

                    if (word == NORM_KEYWORD)
                    {
                        vec3 norm;
                        line_stream >> norm.x >> norm.y >> norm.z;

                        if (line_stream.rdbuf()->in_avail() != 0)
                        {
                            std::cerr << "Unable to construct mesh object.\n"
                                      << "Non-three dimensional vertex normal located at line: `" << line << "`.\n";

                            std::exit(exit::error::FAILED_PARSE);
                        }

                        norms.emplace_back(norm.normal());
                    }

                    if (line_stream.fail())
                    {
                        std::cerr << "Unable to construct mesh object.\n"
                                  << "Unable to parse line: `" << line << "`.\n";
                    }
                }

                POST(!norms.empty());

                return (norms);
            }

            /**
             *  Parse the vector of triangle face data from a serialised wavefront object file.
             *
             *  @param  serial_ String of the serialised wavefront object.
             *
             *  @pre    serial_ may not be empty.
             *
             *  @post   faces may not be empty.
             *
             *  @return Parsed vector of triangle face data.
             */
            inline std::vector<std::array<std::array<size_t, 3>, 2>> Mesh::parse_faces(const std::string& serial_) const noexcept // NOLINT
            {
                PRE(!serial_.empty());

                std::vector<std::array<std::array<size_t, 3>, 2>> faces;

                std::stringstream serial_stream(serial_);
                std::string       line;
                while (std::getline(serial_stream, line))
                {
                    std::stringstream line_stream(line);
                    std::string       word;
                    line_stream >> word;

                    if (word == FACE_KEYWORD)
                    {
                        std::array<std::string, 3> face;
                        line_stream >> face[index::vertex::ALPHA] >> face[index::vertex::BETA] >> face[index::vertex::GAMMA];

                        if (line_stream.rdbuf()->in_avail() != 0)
                        {
                            std::cerr << "Unable to construct mesh object.\n"
                                      << "Non-triangular face located at line: `" << line << "`.\n";

                            std::exit(exit::error::FAILED_PARSE);
                        }


                        std::array<size_t, 3> pos_index{}, norm_index{};
                        for (size_t i = 0; i < 3; ++i)
                        {
                            const size_t first_slash = face[i].find_first_of('/');
                            const size_t last_slash  = face[i].find_last_of('/');

                            std::stringstream pos(face[i].substr(0, first_slash));
                            pos >> pos_index[i];
                            --pos_index[i];

                            std::stringstream norm(face[i].substr(last_slash + 1));
                            norm >> norm_index[i];
                            --norm_index[i];

                            if (pos.fail() || norm.fail())
                            {
                                std::cerr << "Unable to construct mesh object.\n"
                                          << "Unable to parse line: `" << line << "`.\n";

                                std::exit(exit::error::FAILED_PARSE);
                            }
                        }

                        faces.emplace_back(std::array<std::array<size_t, 3>, 2>({{pos_index, norm_index}}));
                    }

                    if (line_stream.fail())
                    {
                        std::cerr << "Unable to construct mesh object.\n"
                                  << "Unable to parse line: `" << line << "`.\n";
                    }
                }

                POST(!faces.empty());

                return (faces);
            }

            /**
             *  Transform the vector of vertex positions using a transformation matrix.
             *
             *  @param  poss_       Vector of vertex positions to be transformed.
             *  @param  transform_  Transformation matrix to apply to the vertex positions.
             *
             *  @pre    poss_ must contain at least three elements.
             *
             *  @return Vector of transformed vertex positions.
             */
            inline std::vector<vec3> Mesh::transform_poss(const std::vector<vec3>& poss_, const mat4& transform_) const noexcept
            {
                PRE(poss_.size() >= 3);

                std::vector<vec3> poss;
                poss.reserve(poss_.size());

                for (size_t i = 0; i < poss_.size(); ++i)
                {
                    vec4 pos(poss_[i].x, poss_[i].y, poss_[i].z, 1.0);
                    pos = transform_ * pos;

                    poss.emplace_back(pos.x, pos.y, pos.z);
                }

                return (poss);
            }

            /**
             *  Transform the vector of vertex normals using a transformation matrix.
             *
             *  @param  norms_      Vector of vertex normals to be transformed.
             *  @param  transform_  Transformation matrix to apply to the vertex normals.
             *
             *  @pre    norms_ may not be empty.
             *
             *  @return Vector of transformed vertex normals.
             */
            inline std::vector<vec3> Mesh::transform_norms(const std::vector<vec3>& norms_, const mat4& transform_) const noexcept
            {
                PRE(!norms_.empty());

                std::vector<vec3> norms;
                norms.reserve(norms_.size());

                const mat4 transform = transform_.inv().trans();

                for (size_t i = 0; i < norms_.size(); ++i)
                {
                    vec4 norm(norms_[i].x, norms_[i].y, norms_[i].z, 0.0);
                    norm = transform * norm;

                    norms.emplace_back(vec3(norm.x, norm.y, norm.z).normal());
                }

                return (norms);
            }

            /**
             *  Initialise the vector of triangles forming the mesh.
             *
             *  @param  poss_   Vector of vertex positions.
             *  @param  norms_  Vector of vertex normals.
             *  @param  faces_  Vector of face data used to construct triangle faces.
             *
             *  @pre    poss_ must contain at least three elements.
             *  @pre    norms_ may not be empty.
             *  @pre    faces_ may not be empty.
             *
             *  @post   tris may not be empty.
             *
             *  @return Initialised the vector of triangles forming the mesh.
             */
            inline std::vector<Triangle> Mesh::init_tris(const std::vector<vec3>& poss_, const std::vector<vec3>& norms_, const std::vector<std::array<std::array<size_t, 3>, 2>>& faces_) const noexcept
            {
                PRE(poss_.size() >= 3);
                PRE(!norms_.empty());
                PRE(!faces_.empty());

                std::vector<Triangle> tris;
                tris.reserve(faces_.size());

                for (size_t i = 0; i < faces_.size(); ++i)
                {
                    const std::array<size_t, 3>& pos_indices  = faces_[i][0];
                    const std::array<size_t, 3>& norm_indices = faces_[i][1];

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

            /**
             *  Initialise the number of unique vertex positions.
             *
             *  @param  poss_   Vector of vertex positions.
             *  @param  faces_  Vector of face data used to construct triangle faces.
             *
             *  @pre    Indices used by faces must be less than the size of the poss vector.
             *
             *  @return Number of unique vertex positions.
             */
            inline size_t Mesh::init_num_verts(const std::vector<vec3>& poss_, const std::vector<std::array<std::array<size_t, 3>, 2>>& faces_) const noexcept
            {
                std::vector<bool> used(poss_.size(), false);

                for (size_t i = 0; i < faces_.size(); ++i)
                {
                    const std::array<size_t, 3>& pos_indices = faces_[i][0];

                    for (size_t j = 0; j < 3; ++j)
                    {
                        PRE(pos_indices[i] < poss_.size());

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

            /**
             *  Initialise the number of unique vertex normals.
             *
             *  @param  norms_  Vector of vertex normals.
             *  @param  faces_  Vector of face data used to construct triangle faces.
             *
             *  @pre    Indices used by faces must be less than the size of the norms vector.
             *
             *  @return Number of unique vertex normals.
             */
            inline size_t Mesh::init_num_norms(const std::vector<vec3>& norms_, const std::vector<std::array<std::array<size_t, 3>, 2>>& faces_) const noexcept
            {
                std::vector<bool> used(norms_.size(), false);

                for (size_t i = 0; i < faces_.size(); ++i)
                {
                    const std::array<size_t, 3>& norm_indices = faces_[i][1];

                    for (size_t j = 0; j < 3; ++j)
                    {
                        PRE(norm_indices[i] < norms_.size());

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

            /**
             *  Initialise the number of unique edges.
             *
             *  @param  faces_  Vector of face data used to construct triangle faces.
             *
             *  @return Number of unique edges.
             */
            inline size_t Mesh::init_num_edges(const std::vector<std::array<std::array<size_t, 3>, 2>>& faces_) const noexcept
            {
                std::vector<std::array<size_t, 2>> edges;

                for (size_t i = 0; i < faces_.size(); ++i)
                {
                    std::array<size_t, 3> pos_indices = faces_[i][0];

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

                    const std::array<std::array<size_t, 2>, 3> edge_indices({{{{pos_indices[0], pos_indices[1]}}, {{pos_indices[1], pos_indices[2]}}, {{pos_indices[0], pos_indices[2]}}}});

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

            /**
             *  Initialise the vector of normalised relative area of each triangle.
             *
             *  @return Initialise vector of normalised relative area of each triangle.
             */
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

            /**
             *  Initialise the bounding box of the mesh.
             *
             *  @post   min.x must be less than max.x.
             *  @post   min.y must be less than max.y.
             *  @post   min.z must be less than max.z.
             *
             *  @return Initialised bounding box of the mesh.
             */
            inline Aabb Mesh::init_box() const noexcept
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

                POST(min.x < max.x);
                POST(min.y < max.y);
                POST(min.z < max.z);

                return (Aabb(min, max));
            }



            //  == METHODS ==
            //  -- Getters --
            inline std::vector<const Shape*> Mesh::shape_list() const noexcept
            {
                std::vector<const Shape*> list;
                list.reserve(_tris.size());

                for (size_t i = 0; i < _tris.size(); ++i)
                {
                    list.emplace_back(&_tris[i]);
                }

                return (list);
            }

            /**
             *  Get a const reference to a triangle within the mesh.
             *
             *  @param  index_  Index of the triangle to retrieve.
             *
             *  @pre    index_ must be less than _tris.size.
             *
             *  @return Const reference to a triangle within the mesh.
             */
            inline const Triangle& Mesh::tri(const size_t index_) const noexcept
            {
                PRE(index_ < _tris.size());

                return (_tris[index_]);
            }

            /**
             *  Get the number of vertex positions forming the mesh.
             *
             *  @return Number of vertex positions forming the mesh.
             */
            inline size_t Mesh::num_verts() const noexcept
            {
                return (_num_verts);
            }

            /**
             *  Get the number of vertex normals forming the mesh.
             *
             *  @return Number of vertex normals forming the mesh.
             */
            inline size_t Mesh::num_norms() const noexcept
            {
                return (_num_norms);
            }

            /**
             *  Get the number of edges forming the mesh.
             *
             *  @return Number of edges forming the mesh.
             */
            inline size_t Mesh::num_edges() const noexcept
            {
                return (_num_edges);
            }

            /**
             *  Get the number of triangular faces forming the mesh.
             *
             *  @return Number of triangular faces forming the mesh.
             */
            inline size_t Mesh::num_faces() const noexcept
            {
                return (_num_faces);
            }


            //  -- Properties --
            /**
             *  Get the minimum vec of the smallest bounding box containing the mesh.
             *
             *  @return Minimum vec of the smallest bounding box containing the mesh.
             */
            inline vec3 Mesh::min() const noexcept
            {
                vec3 min(std::numeric_limits<double>::max(), std::numeric_limits<double>::max(), std::numeric_limits<double>::max());

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
                        }
                    }
                }

                return (min);
            }

            /**
             *  Get the maximum vec of the smallest bounding box containing the mesh.
             *
             *  @return Maximum vec of the smallest bounding box containing the mesh.
             */
            inline vec3 Mesh::max() const noexcept
            {
                vec3 max(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());

                for (size_t i = 0; i < _tris.size(); ++i)
                {
                    for (size_t j = 0; j < 3; ++j)
                    {
                        for (size_t k = 0; k < 3; ++k)
                        {
                            if (_tris[i].poss()[j][k] > max[k])
                            {
                                max[k] = _tris[i].poss()[j][k];
                            }
                        }
                    }
                }

                return (max);
            }

            /**
             *  Get the total surface area of the mesh.
             *
             *  @post   area must be positive.
             *
             *  @return Total surface area of the mesh.
             */
            inline double Mesh::area() const noexcept
            {
                double area = 0.0;
                for (size_t i = 0; i < _tris.size(); ++i)
                {
                    area += _tris[i].area();
                }

                POST(area > 0.0);

                return (area);
            }

            /**
             *  Get the total volume of the mesh.
             *
             *  @post   vol must be positive.
             *
             *  @return Total volume of the mesh.
             */
            inline double Mesh::vol() const noexcept
            {
                double vol = 0.0;

                for (size_t i = 0; i < _tris.size(); ++i)
                {
                    vol += _tris[i].vol();
                }

                POST(vol > 0.0);

                return (vol);
            }

            /**
             *  Get the topology of the mesh.
             *
             *  @return True if the surface of the mesh forms a bounded volume.
             */
            inline bool Mesh::closed() const noexcept
            {
                return (_closed);
            }


            //  -- Emission --
            /**
             *  Generate a random position on the surface of the mesh.
             *
             *  @param  rng_    Random number generator.
             *
             *  @return Random position on the surface of the mesh.
             */
            inline vec3 Mesh::random_pos(random::Generator* const rng_) const noexcept
            {
                return (_tris[utl::search::lower(_areas, rng_->gen())].random_pos(rng_));
            }

            /**
             *  Generate a random position, and corresponding normal, on the surface of the mesh.
             *
             *  @param  rng_    Random number generator.
             *
             *  @return Random position, and corresponding normal, on the surface of the mesh.
             */
            inline std::pair<vec3, vec3> Mesh::random_pos_and_norm(random::Generator* rng_) const noexcept
            {
                return (_tris[utl::search::lower(_areas, rng_->gen())].random_pos_and_norm(rng_));
            }


            //  -- Intersection --
            /**
             *  Determine if an intersection occurs between the mesh's surface and an axis-aligned bounding box.
             *
             *  @param  aabb_   Axis-aligned bounding box to test.
             *
             *  @return True if the mesh's surface intersects with the axis-aligned bounding box.
             */
            inline bool Mesh::intersect_surf(const shape::Aabb& aabb_) const noexcept
            {
                if (!_box.intersect_vol(aabb_))
                {
                    return (false);
                }

                for (size_t i = 0; i < _tris.size(); ++i)
                {
                    if (_tris[i].intersect_surf(aabb_))
                    {
                        return (true);
                    }
                }

                return (false);
            }

            /**
             *  THIS METHOD IS NOT YET IMPLEMENTED.
             *  Determine if an intersection occurs between the mesh's volume and an axis-aligned bounding box.
             *
             *  @return True if the mesh's volume intersects with the axis-aligned bounding box.
             */
            inline bool Mesh::intersect_vol(const shape::Aabb& /*unused*/) const noexcept
            {
                std::cerr << "WARNING: This method does not yet have a suitable implementation.\n";

                std::exit(exit::error::UNREACHABLE_CODE);
            }


            //  -- Collision --
            /**
             *  Determine if a collision event occurs between the mesh and a ray.
             *  If a collision does occur, return the distance to the collision point.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional collision distance.
             */
            inline std::optional<double> Mesh::collision(const vec3& pos_, const vec3& dir_) const noexcept
            {
                PRE(dir_.normalised());

                if (!_box.contains(pos_) && !_box.collision(pos_, dir_))
                {
                    return (std::nullopt);
                }

                std::optional<double> dist(std::nullopt);
                for (size_t i = 0; i < _tris.size(); ++i)
                {
                    const std::optional<double> tri_dist(_tris[i].collision(pos_, dir_));
                    if (tri_dist && (!dist || (tri_dist.value() < dist.value())))
                    {
                        dist = tri_dist;
                    }
                }

                return (dist);
            }

            /**
             *  Determine if a collision event occurs between the mesh and a ray.
             *  If a collision does occur, return the distance to the collision point and the normal of the mesh at the collision point.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional collision distance and intersection normal.
             */
            inline std::optional<std::pair<double, vec3>> Mesh::collision_norm(const vec3& pos_, const vec3& dir_) const noexcept
            {
                PRE(dir_.normalised());

                if (!_box.contains(pos_) && !_box.collision(pos_, dir_))
                {
                    return (std::nullopt);
                }

                std::optional<std::pair<double, vec3>> dist(std::nullopt);
                for (size_t i = 0; i < _tris.size(); ++i)
                {
                    const std::optional<std::pair<double, vec3>> tri_dist(_tris[i].collision_norm(pos_, dir_));
                    if (tri_dist && (!dist || (tri_dist.value().first < dist.value().first)))
                    {
                        dist = tri_dist;
                    }
                }

                return (dist);
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_MESH_HPP
