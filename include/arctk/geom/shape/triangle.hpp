/**
 *  @file   arctk/geom/shape/triangle.hpp
 *  @date   19/07/2018
 *  @author Freddy Wordingham
 *
 *  Geometric triangle shape class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_SHAPE_TRIANGLE_HPP
#define ARCTK_GEOM_SHAPE_TRIANGLE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <optional>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/geom/shape.hpp>
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
             *  Geometric triangle shape.
             */
            class Triangle : public Shape
            {
                //  == FIELDS ==
              protected:
                //  -- Positioning --
                const std::array<vec3, 3> _pos;  //!< Vertex positions.
                const std::array<vec3, 3> _norm; //!< Vertex normals.

                //  -- Properties --
                const double _area;       //!< Area of the triangle.
                const vec3   _plane_norm; //!< Normal of the triangle's plane.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Triangle(const std::array<vec3, 3> pos_, const std::array<vec3, 3> norm_) noexcept;

                //  -- Initialisation --
                inline vec3 init_plane_norm(const std::array<vec3, 3> pos_, const std::array<vec3, 3> norm_) noexcept;


                //  == METHODS ==
              public:
                //  -- Collision --
                inline std::optional<double> collision(const vec3& pos_, const vec3& dir_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Triangle::Triangle(const std::array<vec3, 3> pos_, const std::array<vec3, 3> norm_) noexcept
              : _pos(pos_)
              , _norm(norm_)
              , _plane_norm(init_plane_norm())
              , _area(math::geom::area(pos_))
            {
                PRE(norm_[ALPHA].normalised());
                PRE(norm_[BETA].normalised());
                PRE(norm_[GAMMA].normalised());

                POST(_area > 0.0);
                POST(_plane_norm.normalised());
            }


            //  -- Initialisation --
            inline vec3 Triangle::init_plane_norm(const std::array<vec3, 3> pos_, const std::array<vec3, 3> norm_) noexcept
            {
                vec3 plane_norm = math::vec::normalise((pos_[BETA] - pos_[ALPHA]) ^ (pos_[GAMMA] - pos_[ALPHA]));

                if ((plane_norm * (norm_[ALPHA] + norm_[BETA] + norm_[GAMMA])) < 0.0)
                {
                    plane_norm *= -1.0;
                }

                PRE(plane_norm.normalised());
                PRE((plane_norm * norm_[ALPHA]) > 0.0);
                PRE((plane_norm * norm_[BETA]) > 0.0);
                PRE((plane_norm * norm_[GAMMA]) > 0.0);

                return (plane_norm);
            }



            //  == METHODS ==



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_TRIANGLE_HPP
