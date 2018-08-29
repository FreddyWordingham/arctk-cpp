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
#include <optional>
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/index.hpp>
#include <arctk/math.hpp>
#include <arctk/random.hpp>



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


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Mesh(const std::string& serial_, const vec3& scale_ = vec3(1.0, 1.0, 1.0), const vec3& rot_ = vec3(0.0, 0.0, 0.0), const vec3& trans_ = vec3(0.0, 0.0, 0.0)) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
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
        {
            PRE(!serial_.empty());
        }



        //  == METHODS ==



    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_MESH_HPP
