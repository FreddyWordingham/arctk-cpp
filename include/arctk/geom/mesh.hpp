/**
 *  @file   arctk/geom/mesh.hpp
 *  @date   29/08/2018
 *  @author Freddy Wordingham
 *
 *  Geometric triangle mesh class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_MESH_HPP
#define ARCTK_GEOM_MESH_HPP



//  == IMPORTS ==
//  -- Std --
#include <cstdlib>
#include <optional>
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/exit.hpp>
#include <arctk/geom/aabb.hpp>
#include <arctk/geom/triangle.hpp>
#include <arctk/index.hpp>
#include <arctk/math.hpp>
#include <arctk/random.hpp>
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {



        //  == CLASS ==
        /**
         *  Geometric triangle mesh.
         */
        class Mesh
        {
            //  == FIELDS ==
          private:
            //  -- Triangle Data --
            const std::vector<Triangle> _tris; //!< Vector of triangles forming the mesh.

            //  -- Areas --
            const std::vector<double> _areas; //!< Normalised relative area of each triangle.

            //  -- Bounding --
            const Aabb _box; //!< Bounding box of the mesh.



            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Mesh(const std::string& serial_, const vec3& scale_ = vec3(1.0, 1.0, 1.0), const vec3& rot_ = vec3(0.0, 0.0, 0.0), const vec3& trans_ = vec3(0.0, 0.0, 0.0)) noexcept;

          private:
            //  -- Initialisation --
            inline std::vector<Triangle> init_tris(const std::string& serial_, const mat4& transform_) const noexcept;
            inline std::vector<double>   init_areas() const noexcept;
            inline Aabb                  init_box() const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline vec3            min() const noexcept;
            inline vec3            max() const noexcept;
            inline double          area() const noexcept;
            inline double          vol() const noexcept;
            inline const Triangle& tri(size_t index_) const noexcept;
            inline size_t          num_tri() const noexcept;
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
          : _tris(init_tris(serial_, math::mat::transform(scale_, rot_, trans_)))
          , _areas(init_areas())
          , _box(init_box())
        {
            PRE(!serial_.empty());
        }


        //  -- Initialisation --
        /**
         *  Initialise the vector of triangles that will form the mesh.
         *
         *  @param  serial_ String of the serialised wavefront object.
         *  @param  transform_  Transformation matrix to apply to the base mesh.
         *
         *  @pre    serial_ may not be empty.
         *
         *  @post   tris_ may not be empty.
         *
         *  @return Initialised vector of triangles that will form the mesh.
         */
        inline std::vector<Triangle> Mesh::init_tris(const std::string& serial_, const mat4& transform_) const noexcept // NOLINT
        {
            PRE(!serial_.empty());

            std::vector<Triangle> tris;

            std::stringstream serial_stream(serial_);
            std::string       line;

            std::vector<vec3> vert_pos, vert_norm;
            const mat4        inv_transform = transform_.inv().trans();
            unsigned int      num_verts     = 0;
            unsigned int      num_faces     = 0;
            while (std::getline(serial_stream, line))
            {
                std::stringstream line_stream(line);
                std::string       word;
                line_stream >> word;

                if (word == POS_KEYWORD)
                {
                    ++num_verts;

                    vec4 pos;
                    line_stream >> pos.x >> pos.y >> pos.z;
                    pos.w = 1.0;

                    pos = transform_ * pos;

                    vert_pos.emplace_back(pos.x, pos.y, pos.z);
                }
                else if (word == NORM_KEYWORD)
                {
                    vec4 norm;
                    line_stream >> norm.x >> norm.y >> norm.z;
                    norm.w = 0.0;

                    norm = inv_transform * norm;

                    vert_norm.emplace_back(vec3(norm.x, norm.y, norm.z).normal());
                }

                if (line_stream.fail())
                {
                    std::cerr << "Unable to construct mesh object.\n"
                              << "Unable to parse line: `" << line << "`.\n";
                }
            }

            utl::stream::rewind(serial_stream);
            while (std::getline(serial_stream, line))
            {
                std::stringstream line_stream(line);
                std::string       word;
                line_stream >> word;

                if (word == FACE_KEYWORD)
                {
                    ++num_faces;

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

                    tris.push_back(Triangle({{vert_pos[pos_index[index::vertex::ALPHA]], vert_pos[pos_index[index::vertex::BETA]], vert_pos[pos_index[index::vertex::GAMMA]]}},
                                            {{vert_norm[norm_index[index::vertex::ALPHA]], vert_norm[norm_index[index::vertex::BETA]], vert_norm[norm_index[index::vertex::GAMMA]]}}));
                }

                if (line_stream.fail())
                {
                    std::cerr << "Unable to construct mesh object.\n"
                              << "Unable to parse line: `" << line << "`.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }
            }

            unsigned int num_edges = (num_faces * 3) / 2;
            if (((num_faces % 2) != 0) || (((num_vert + num_faces) - num_edges) != 2))
            {
                std::cerr << "Unable to construct mesh object.\n"
                          << "Triangles of mesh must form a closed surface.\n";

                std::exit(exit::error::FAILED_INITIALISATION);
            }

            POST(!tris.empty());

            return (tris);
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

            POST(math::compare::equal(areas.back(), 1.0));

            return (areas);
        }

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
        inline vec3 Mesh::min() const noexcept
        {
            return (_box.min());
        }

        inline vec3 Mesh::max() const noexcept
        {
            return (_box.max());
        }

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

        inline double Mesh::vol() const noexcept
        {
        }

        inline const Triangle& Mesh::tri(const size_t index_) const noexcept
        {
            PRE(index_ < _tris.size());

            return (_tris[index_]);
        }

        inline size_t Mesh::num_tri() const noexcept
        {
            return (_tris.size());
        }


    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_MESH_HPP
