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
                inline explicit Mesh(const std::string& serial_, const vec3& scale_ = vec3(1.0, 1.0, 1.0), const vec3& rot_ = vec3(0.0, 0.0, 0.0), const vec3& trans_ = vec3(0.0, 0.0, 0.0)) noexcept;

              private:
                //  -- Initialisation --
                inline std::vector<Triangle> init_tris(const std::string& serial_, const mat4& transform_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
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
                std::vector<Triangle> tris;



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
                        line_stream >> face[ALPHA] >> face[BETA] >> face[GAMMA];

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
                                ERROR("Unable to construct geom::Mesh object.", "Unable to parse serialised wavefront object line: '" << line << "'.");
                            }
                        }

                        r_tri.push_back(Triangle({{vert_pos[pos_index[ALPHA]], vert_pos[pos_index[BETA]], vert_pos[pos_index[GAMMA]]}}, {{vert_norm[norm_index[ALPHA]], vert_norm[norm_index[BETA]], vert_norm[norm_index[GAMMA]]}}));
                    }

                    if (line_stream.fail())
                    {
                        ERROR("Unable to construct geom::Mesh object.", "Unable to parse serial line: '" << line << "'.");
                    }
                }



                return (tris);
            }



            //  == METHODS ==
            //  -- Getters --
            inline const Triangle& Mesh::tri(const size_t index_) const noexcept
            {
                PRE(index_ < _tris.size());

                return (_tris[index_]);
            }


            //  -- Collision --
            inline std::optional<double> Mesh::collision(const vec3& pos_, const vec3& dir_) const noexcept
            {
                return (std::optional<double>(std::nullopt));
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_MESH_HPP
