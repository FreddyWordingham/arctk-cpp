/**
 *  @file   arctk/geom/shape/triangle.hpp
 *  @date   06/10/2018
 *  @author Freddy Wordingham
 *
 *  Geometric triangle shape class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_SHAPE_TRIANGLE_HPP
#define ARCTK_GEOM_SHAPE_TRIANGLE_HPP



//  == BASE ==
#include <arctk/geom/shape.hpp>



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <optional>
#include <utility>

//  -- Arctk --
#include <arctk/geom/collision.hpp>
#include <arctk/math/vec3.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
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
             *  Geometric triangle shape.
             */
            class Triangle : public Shape
            {
                //  == FIELDS ==
              private:
                //  -- Vertices --
                const std::array<vec3, 3> _poss;  //!< Vertex positions.
                const std::array<vec3, 3> _norms; //!< Vertex normals.

                //  -- Normals --
                const vec3 _plane_norm; //!< Triangle plane normal.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Triangle(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const std::array<vec3, 3>& poss() const noexcept;
                inline const std::array<vec3, 3>& norms() const noexcept;
                inline const vec3&                plane_norm() const noexcept;
                inline double                     area() const noexcept;

                //  -- Sampling --
                inline vec3                  random_pos(random::Generator* rng_) const noexcept;
                inline std::pair<vec3, vec3> random_pos_and_norm(random::Generator* rng_) const noexcept;

                //  -- Collision --
                inline std::optional<double>    collision(const vec3& pos_, const vec3& dir_) const noexcept override;
                inline std::optional<Collision> collision_info(const vec3& pos_, const vec3& dir_) const noexcept;
            };



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/geom/shape/triangle.inl>



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_TRIANGLE_HPP
