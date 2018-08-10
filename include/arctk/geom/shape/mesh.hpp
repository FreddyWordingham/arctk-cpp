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

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/exit.hpp>
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
                const std::vector<Triangle> _tris; //! List of triangles forming the mesh.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Mesh(const std::string& serial_, const vec3& scale_ = vec3(1.0, 1.0, 1.0), const vec3& rot_ = vec3(0.0, 0.0, 0.0), const vec3& trans_ = vec3(0.0, 0.0, 0.0)) noexcept;

              private:
                //  -- Initialisation --
                inline std::vector<Triangle> init_tris(const std::string& serial_, const mat4& transform_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline size_t          num_tri() const noexcept;
                inline const Triangle& tri(const size_t index_) const noexcept;

                //  -- Collision --
                inline std::optional<double> collision(const vec3& pos_, const vec3& dir_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Mesh::Mesh(const std::string& serial_, const vec3& scale_, const vec3& rot_, const vec3& trans_) noexcept
              : _tris(init_tris(serial_, math::mat::transform(scale_, rot_, trans_)))
            {
                PRE(!serial_.empty());
            }


            //  -- Initialisation --
            inline std::vector<Triangle> Mesh::init_tris(const std::string& serial_, const mat4& transform_) const noexcept
            {
                /*                std::vector<Triangle> tris;

                                std::stringstream serial_stream(serial_);
                                std::string       line;

                                std::vector<vec3> vert_pos, vert_norm;
                                mat4              inv_transform_ = math::mat::transpose(math::mat::inverse(transform_));
                                while (std::getline(serial_stream, line))
                                {
                                    std::stringstream line_stream(line);
                                    std::string       word;
                                    line_stream >> word;

                                    if (word == POS_KEYWORD)
                                    {
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
                                        norm.w = 1.0;

                                        norm = inv_transform_ * norm;

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

                                return (tris);*/
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the number of triangles within the mesh.
             *
             *  @return Number of triangles within the mesh.
             */
            inline size_t Mesh::num_tri() const noexcept
            {
                return (_tris.size());
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


            //  -- Collision --
            /**
             *  Determine if a collision event occurs between the mesh and a ray.
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

                return (std::optional<double>(std::nullopt));
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_MESH_HPP
