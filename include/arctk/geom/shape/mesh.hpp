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



//  == BASE ==
#include <arctk/geom/shape.hpp>



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cstddef>
#include <optional>
#include <string>
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/geom/collision.hpp>
#include <arctk/geom/shape/box.hpp>
#include <arctk/geom/shape/triangle.hpp>
#include <arctk/math/vec3.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        template <typename T, size_t N>
        class Mat;
    }                                  // namespace math
    using mat4 = math::Mat<double, 4>; //!< Four-dimensional double precision mat.
    namespace random                   //! random number namespace
    {
        class Generator;
    } // namespace random
} // namespace arc



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

                //  -- Collision --
                inline std::optional<double>    collision(const vec3& pos_, const vec3& dir_) const noexcept override; // NOLINT
                inline std::optional<Collision> collision_info(const vec3& pos_, const vec3& dir_) const noexcept;
            };



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/geom/shape/mesh.inl>



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_MESH_HPP
