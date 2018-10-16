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
#include <arctk/geom/collision.hpp>
#include <arctk/geom/shape/box.hpp>
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
                inline explicit Mesh(const std::string& serial_) noexcept;
                inline Mesh(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_) noexcept;
                inline Mesh(const std::vector<vec3>& poss_, const std::vector<vec3>& norms_, const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_, const vec3& scale_, const vec3& rot_, const vec3& trans_) noexcept;
                inline Mesh(const std::vector<vec3>& poss_, const std::vector<vec3>& norms_, const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) noexcept;

              private:
                //  -- Initialisation --
                inline std::vector<vec3>                                                    parse_poss(const std::string& serial_) const noexcept;
                inline std::vector<vec3>                                                    parse_norms(const std::string& serial_) const noexcept;
                inline std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>> parse_faces(const std::string& serial_) const noexcept;
                inline std::vector<vec3>                                                    transform_poss(const std::vector<vec3>& poss_, const mat4& transform_) const noexcept;
                inline std::vector<vec3>                                                    transform_norms(const std::vector<vec3>& norms_, const mat4& transform_) const noexcept;
                inline std::vector<Triangle> init_tris(const std::vector<vec3>& poss_, const std::vector<vec3>& norms_, const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) const noexcept;
                inline std::vector<double>   init_areas() const noexcept;
                inline Box                   init_box() const noexcept;
                inline size_t                init_num_verts(size_t num_poss_, const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) const noexcept;
                inline size_t                init_num_norms(size_t num_norms_, const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) const noexcept;
                inline size_t                init_num_edges(const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const Triangle&              tri(size_t index_) const noexcept;
                inline std::vector<const Triangle*> tri_list() const noexcept;
                inline const Box&                   box() const noexcept;
                inline size_t                       num_verts() const noexcept;
                inline size_t                       num_norms() const noexcept;
                inline size_t                       num_edges() const noexcept;
                inline size_t                       num_faces() const noexcept;
                inline bool                         closed() const noexcept;

                //  -- Sampling --
                inline vec3                  random_pos(random::Generator* rng_) const noexcept;
                inline std::pair<vec3, vec3> random_pos_and_norm(random::Generator* rng_) const noexcept;

                //  -- Intersection --
                inline bool intersect(const Triangle& tri_) const noexcept;
                inline bool intersect(const Mesh& mesh_) const noexcept;

                //  -- Collision --
                inline std::optional<double>    collision(const vec3& pos_, const vec3& dir_) const noexcept override; // NOLINT
                inline std::optional<Collision> collision_info(const vec3& pos_, const vec3& dir_) const noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a mesh from a serialised wavefront file.
             *
             *  @param  serial_ Serialised wavefront file.
             *
             *  @pre    serial_ may not be empty.
             */
            inline Mesh::Mesh(const std::string& serial_) noexcept
              : Mesh(parse_poss(serial_), parse_norms(serial_), parse_faces(serial_))
            {
                PRE(!serial_.empty());
            }

            /**
             *  Construct a mesh from a serialised wavefront file and additional transformations.
             *
             *  @param  serial_ Serialised wavefront file.
             *  @param  scale_  Scaling transformation.
             *  @param  rot_    Rotation transformation.
             *  @param  trans_  Translation transformation.
             *
             *  @pre    serial_ may not be empty.
             */
            inline Mesh::Mesh(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_) noexcept
              : Mesh(parse_poss(serial_), parse_norms(serial_), parse_faces(serial_), scale_, rot_, trans_)
            {
                PRE(!serial_.empty());
            }

            /**
             *  Construct a list of vertex positions, normals and face indicies, and additional transformations.
             *
             *  @param  poss_   List of vertex positions.
             *  @param  norms_  List of vertex normals.
             *  @param  faces_  List of indices forming triangular faces.
             *  @param  scale_  Scaling transformation.
             *  @param  rot_    Rotation transformation.
             *  @param  trans_  Translation transformation.
             *
             *  @pre    poss_ must contain at least three entries.
             *  @pre    norms_ may not be empty.
             *  @pre    faces_ may not be empty.
             *
             *  @post   _tris may not be empty.
             */
            inline Mesh::Mesh(const std::vector<vec3>& poss_, const std::vector<vec3>& norms_, const std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>>& faces_, const vec3& scale_, const vec3& rot_, const vec3& trans_) noexcept
              : Mesh(transform_poss(poss_, math::mat::transform(scale_, rot_, trans_)), transform_norms(norms_, math::mat::transform(scale_, rot_, trans_)), faces_)
            {
                PRE(poss_.size() >= 3);
                PRE(!norms_.empty());
                PRE(!faces_.empty());

                POST(!_tris.empty());
            }

            /**
             *  Construct a list of vertex positions, normals and face indicies.
             *
             *  @param  poss_   List of vertex positions.
             *  @param  norms_  List of vertex normals.
             *  @param  faces_  List of indices forming triangular faces.
             *
             *  @pre    poss_ must contain at least three entries.
             *  @pre    norms_ may not be empty.
             *  @pre    faces_ may not be empty.
             *
             *  @post   _tris may not be empty.
             */
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
            /**
             *  Parse the list of vertex position from a serialised wavefront file.
             *
             *  @param  serial_ Serialised wavefront file.
             *
             *  @pre    serial_ may not be empty.
             *
             *  @post   poss must contain at least three entries.
             *
             *  @return List of vertex position forming the mesh.
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
             *  Parse the list of vertex normals from a serialised wavefront file.
             *
             *  @param  serial_ Serialised wavefront file.
             *
             *  @pre    serial_ may not be empty.
             *
             *  @post   norms may not be empty.
             *
             *  @return List of vertex normals forming the mesh.
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
             *  Parse the list of face forming indices from a serialised wavefront file.
             *
             *  @param  serial_ Serialised wavefront file.
             *
             *  @pre    serial_ may not be empty.
             *
             *  @post   faces may not be empty.
             *
             *  @return List of face forming indices forming the mesh.
             */
            inline std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>> Mesh::parse_faces(const std::string& serial_) const noexcept // NOLINT
            {
                PRE(!serial_.empty());

                std::vector<std::pair<std::array<size_t, 3>, std::array<size_t, 3>>> faces;

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

                        faces.emplace_back(std::pair<std::array<size_t, 3>, std::array<size_t, 3>>(pos_index, norm_index));
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
             *  @param  poss_   Vertex positions.
             *  @param  norms_  Vertex normals.
             *  @param  faces_  Indices forming the triangles.
             *
             *  @pre    poss_ must contain at least three elements.
             *  @pre    norms_ may not empty.
             *  @pre    faces_ may not empty.
             *
             *  @post   tris may not be empty.
             *
             *  @return Vector of triangles forming the mesh.
             */
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

            /**
             *  Initialise the vector of relative triangle areas.
             *
             *  @return Initialised vector of relative triangle areas.
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
             *  @return Bounding box of the mesh.
             */
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

            /**
             *  Initialise the number of vertex positions used by the mesh
             *
             *  @param  num_poss_   Maximum number of vertex positions.
             *  @param  faces_      List of indices forming triangular faces.
             *
             *  @return Number of vertex positions used by the mesh.
             */
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

            /**
             *  Initialise the number of vertex normals used by the mesh
             *
             *  @param  num_norms_  Maximum number of vertex normals.
             *  @param  faces_      List of indices forming triangular faces.
             *
             *  @return Number of vertex normals used by the mesh.
             */
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

            /**
             *  Initialise the number of edges used by the mesh
             *
             *  @param  faces_  List of indices forming triangular faces.
             *
             *  @return Number of edges used by the mesh.
             */
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
            /**
             *  Get a const reference to a triangle forming the mesh.
             *
             *  @param  index_  Index of the triangle to retrieve.
             *
             *  @pre    index_ must be less than the size of _tris.
             *
             *  @return Const reference to a triangle forming the mesh.
             */
            inline const Triangle& Mesh::tri(const size_t index_) const noexcept
            {
                PRE(index_ < _tris.size());

                return (_tris[index_]);
            }

            /**
             *  Get a vector of pointers to each triangle forming the mesh.
             *
             *  @return Vector of pointers to each triangle forming the mesh.
             */
            inline std::vector<const Triangle*> Mesh::tri_list() const noexcept
            {
                std::vector<const Triangle*> tris;
                tris.reserve(_tris.size());

                for (size_t i = 0; i < _tris.size(); ++i)
                {
                    tris.emplace_back(&_tris[i]);
                }

                return (tris);
            }

            /**
             *  Get a const reference to the bounding box of the mesh.
             *
             *  @return Const reference to the bounding box of the mesh.
             */
            inline const Box& Mesh::box() const noexcept
            {
                return (_box);
            }

            /**
             *  Get the number of vertex positions used by the mesh.
             *
             *  @return Number of vertex positions used by the mesh.
             */
            inline size_t Mesh::num_verts() const noexcept
            {
                return (_num_verts);
            }

            /**
             *  Get the number of vertex normals used by the mesh.
             *
             *  @return Number of vertex normals used by the mesh.
             */
            inline size_t Mesh::num_norms() const noexcept
            {
                return (_num_norms);
            }

            /**
             *  Get the number of edges used by the mesh.
             *
             *  @return Number of edges used by the mesh.
             */
            inline size_t Mesh::num_edges() const noexcept
            {
                return (_num_edges);
            }

            /**
             *  Get the number of triangle faces used by the mesh.
             *
             *  @return Number of triangle faces used by the mesh.
             */
            inline size_t Mesh::num_faces() const noexcept
            {
                return (_num_faces);
            }

            /**
             *  Get the topology of the mesh.
             *
             *  @return True if the mesh is closed with no handles.
             */
            inline bool Mesh::closed() const noexcept
            {
                return (_closed);
            }


            //  -- Sampling --
            /**
             *  Get a random position on the surface of the mesh.
             *
             *  @param  rng_    Random number generator.
             *
             *  @pre    rng_ may not be nullptr.
             *
             *  @return Random position on the surface of the mesh.
             */
            inline vec3 Mesh::random_pos(random::Generator* rng_) const noexcept
            {
                PRE(rng_ != nullptr);

                return (_tris[utl::search::lower(_areas, rng_->gen())].random_pos(rng_));
            }

            /**
             *  Get a random position, and corresponding normal, on the surface of the mesh.
             *
             *  @param  rng_    Random number generator.
             *
             *  @pre    rng_ may not be nullptr.
             *
             *  @return Random position, and corresponding normal, on the surface of the mesh.
             */
            inline std::pair<vec3, vec3> Mesh::random_pos_and_norm(random::Generator* rng_) const noexcept
            {
                PRE(rng_ != nullptr);

                return (_tris[utl::search::lower(_areas, rng_->gen())].random_pos_and_norm(rng_));
            }


            //  -- Intersection --
            /**
             *  Determine if an intersection ocurres between the mesh and a triangle.
             *
             *  @param  tri_    Triangle to test.
             *
             *  @return True if an intersection ocurres.
             */
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

            /**
             *  Determine if an intersection ocurres between the mesh and another mesh.
             *
             *  @param  mesh_   Mesh to test.
             *
             *  @return True if an intersection ocurres.
             */
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
                        if (_box.intersect(mesh_.tri(j)) && _tris[i].intersect(mesh_.tri(j)))
                        {
                            return (true);
                        }
                    }
                }

                return (false);
            }


            //  -- Collision --
            /**
             *  Get the collision distance (if one occurs) of a ray.
             *
             *  @param  pos_    Initial position of the ray.
             *  @param  dir_    Direction of ray travel.
             *
             *  @return Optional distance to collision event.
             */
            inline std::optional<double> Mesh::collision(const vec3& pos_, const vec3& dir_) const noexcept // NOLINT
            {
                PRE(dir_.normalised());

                if (!_box.intersect(pos_) && !_box.collision(pos_, dir_))
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
             *  Get the collision information (if one occurs) of a ray.
             *
             *  @param  pos_    Initial position of the ray.
             *  @param  dir_    Direction of ray travel.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional information of a collision event.
             */
            inline std::optional<Collision> Mesh::collision_info(const vec3& pos_, const vec3& dir_) const noexcept
            {
                PRE(dir_.normalised());

                if (!_box.intersect(pos_) && !_box.collision(pos_, dir_))
                {
                    return (std::nullopt);
                }

                std::optional<Collision> dist(std::nullopt);
                for (size_t i = 0; i < _tris.size(); ++i)
                {
                    const std::optional<Collision> tri_dist(_tris[i].collision_info(pos_, dir_));
                    if (tri_dist && (!dist || (tri_dist.value().dist() < dist.value().dist())))
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
