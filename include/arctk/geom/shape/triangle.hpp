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
                inline std::optional<double> plane_collision(const vec3& pos_, const vec3& dir_) const noexcept;
                inline std::optional<double> collision(const vec3& pos_, const vec3& dir_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a triangle from three vertex positions and three corresponding vertex normals.
             *
             *  @param  pos_    Positions of the vertices.
             *  @param  norm_   Normals of the vertices.
             *
             *  @pre    norm_ vecs must be normalised.
             *  @post   _area must be positive.
             *  @post   _plane_norm must be normalised.
             */
            inline Triangle::Triangle(const std::array<vec3, 3> pos_, const std::array<vec3, 3> norm_) noexcept
              : _pos(pos_)
              , _norm(norm_)
              , _area(math::geom::area(pos_))
              , _plane_norm(init_plane_norm(pos_, norm_))
            {
                PRE(norm_[index::vertex::ALPHA].normalised());
                PRE(norm_[index::vertex::BETA].normalised());
                PRE(norm_[index::vertex::GAMMA].normalised());

                POST(_area > 0.0);
                POST(_plane_norm.normalised());
            }


            //  -- Initialisation --
            /**
             *  Initialise the normal vector of the triangle by determining the cross-product of two of the triangles edges.
             *  Normal must be normalised after determining the cross-product.
             *
             *  @param  pos_    Positions of the vertices.
             *  @param  norm_   Normals of the vertices.
             *
             *  @post   plane_norm must be normalised.
             *  @post   plane_norm norm_ dot products must be greater than zero.
             *
             *  @return The normal vector of the triangle's plane.
             */
            inline vec3 Triangle::init_plane_norm(const std::array<vec3, 3> pos_, const std::array<vec3, 3> norm_) noexcept
            {
                vec3 plane_norm = math::vec::normalise((pos_[index::vertex::BETA] - pos_[index::vertex::ALPHA]) ^ (pos_[index::vertex::GAMMA] - pos_[index::vertex::ALPHA]));

                if ((plane_norm * (norm_[index::vertex::ALPHA] + norm_[index::vertex::BETA] + norm_[index::vertex::GAMMA])) < 0.0)
                {
                    plane_norm *= -1.0;
                }

                POST(plane_norm.normalised());
                POST((plane_norm * norm_[index::vertex::ALPHA]) > 0.0);
                POST((plane_norm * norm_[index::vertex::BETA]) > 0.0);
                POST((plane_norm * norm_[index::vertex::GAMMA]) > 0.0);

                return (plane_norm);
            }



            //  == METHODS ==
            //  -- Collision --
            inline std::optional<double> Triangle::plane_collision(const vec3& pos_, const vec3& dir_) const noexcept
            {
                const double denom = _dir * dir_;

                if (math::compare::zero(denom))
                {
                    return (std::nullopt);
                }

                const double dist = ((_pos - pos_) * _dir) / denom;

                return ((dist < 0.0) ? std::nullopt : std::optional<double>(dist));
            }

            inline std::optional<double> Triangle::collision(const vec3& pos_, const vec3& dir_) const noexcept
            {
                PRE(dir_.normalised());

                const vec3 edge_ab = _pos[BETA] - _pos[ALPHA];
                const vec3 edge_ac = _pos[GAMMA] - _pos[ALPHA];

                const vec3   p   = dir_ ^ edge_ac;
                const double det = edge_ab * p;

                if (math::compare::zero(denom))
                {
                    return (std::nullopt);
                }

                const vec3   t = pos_ - _pos[ALPHA];
                const double u = (t * p) / det;

                if ((u < 0.0) || (u > 1.0))
                {
                    return (std::nullopt);
                }

                const vec3   q = t ^ edge_ab;
                const double v = (dir_ * q) / det;

                if ((v < 0.0) || ((u + v) > 1.0))
                {
                    return (std::nullopt);
                }

                const double dist = (edge_ac * q) / det;

                if (dist < 0.0)
                {
                    return (std::nullopt);
                }

                return (std::optional<double>(dist));
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_TRIANGLE_HPP
