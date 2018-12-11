/**
 *  @file   arctk/geom/shape/triangle.inl
 *  @date   06/10/2018
 *  @author Freddy Wordingham
 *
 *  Geometric triangle shape class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_SHAPE_TRIANGLE_INL
#define ARCTK_GEOM_SHAPE_TRIANGLE_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cmath>


//  -- Arctk --
#include <arctk/index/vertex.hpp>
#include <arctk/math/compare.hpp>
#include <arctk/random/generator.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {
        namespace shape //! shape namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a triangle from three vertex positions and three corresponding vertex normals.
             *
             *  @param  poss_   Positions of the vertices.
             *  @param  norms_  Normals of the vertices.
             *
             *  @pre    norms_[index::vertex::ALPHA] must be normalised.
             *  @pre    norms_[index::vertex::BETA] must be normalised.
             *  @pre    norms_[index::vertex::GAMMA] must be normalised.
             *
             *  @post   _plane_norm must be normalised.
             */
            inline Triangle::Triangle(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) noexcept
              : _poss(poss_)
              , _norms(norms_)
              , _plane_norm(init_plane_norm(poss_, norms_))
            {
                assert(norms_[index::vertex::ALPHA].normalised());
                assert(norms_[index::vertex::BETA].normalised());
                assert(norms_[index::vertex::GAMMA].normalised());

                assert(_plane_norm.normalised());
            }


            inline vec3 init_plane_norm(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) const noexcept
            {
                const vec3 norm  = ((poss_[index::vertex::BETA] - poss_[index::vertex::ALPHA]) ^ (poss_[index::vertex::GAMMA] - poss_[index::vertex::ALPHA])).normal();
                const vec3 norms = norms_[index::vertex::ALPHA] + norms_[index::vertex::BETA] + norms_[index::vertex::GAMMA];

                return (((norm * norms) <= 0.0) ? norm : -norm);
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the vertex positions forming the triangle.
             *
             *  @return Array of vertex positions forming the triangle.
             */
            inline const std::array<vec3, 3>& Triangle::poss() const noexcept
            {
                return (_poss);
            }

            /**
             *  Get the vertex normals forming the triangle.
             *
             *  @return Array of vertex normals forming the triangle.
             */
            inline const std::array<vec3, 3>& Triangle::norms() const noexcept
            {
                return (_norms);
            }

            /**
             *  Get the normal of the plane of the triangle.
             *
             *  @return Normal of the plane of the triangle.
             */
            inline const vec3& Triangle::plane_norm() const noexcept
            {
                return (_plane_norm);
            }

            /**
             *  Get the area of the triangle.
             *
             *  @return Area of the triangle.
             */
            inline double Triangle::area() const noexcept
            {
                const double length_ab = (_poss[index::vertex::ALPHA] - _poss[index::vertex::BETA]).mag();
                const double length_bc = (_poss[index::vertex::BETA] - _poss[index::vertex::GAMMA]).mag();
                const double length_ca = (_poss[index::vertex::GAMMA] - _poss[index::vertex::ALPHA]).mag();

                const double half_perim = (length_ab + length_bc + length_ca) * 0.5;

                return (std::sqrt(half_perim * (half_perim - length_ab) * (half_perim - length_bc) * (half_perim - length_ca)));
            }


            //  -- Sampling --
            /**
             *  Get a random position on the surface of the triangle.
             *
             *  @param  rng_    Random number generator.
             *
             *  @pre    rng_ may not be nullptr.
             *
             *  @return Random position on the surface of the triangle.
             */
            inline vec3 Triangle::random_pos(random::Generator* rng_) const noexcept
            {
                assert(rng_ != nullptr);

                double a = rng_->gen();
                double b = rng_->gen();

                if ((a + b) > 1.0)
                {
                    a = 1.0 - a;
                    b = 1.0 - b;
                }

                return (_poss[index::vertex::GAMMA] + ((_poss[index::vertex::ALPHA] - _poss[index::vertex::GAMMA]) * a) + ((_poss[index::vertex::BETA] - _poss[index::vertex::GAMMA]) * b));
            }

            /**
             *  Get a random position, and corresponding normal, on the surface of the triangle.
             *
             *  @param  rng_    Random number generator.
             *
             *  @pre    rng_ may not be nullptr.
             *
             *  @post   norm must be normalised.
             *
             *  @return Random position, and corresponding normal, on the surface of the triangle.
             */
            inline std::pair<vec3, vec3> Triangle::random_pos_and_norm(random::Generator* rng_) const noexcept
            {
                assert(rng_ != nullptr);

                double a = rng_->gen();
                double b = rng_->gen();

                if ((a + b) > 1.0)
                {
                    a = 1.0 - a;
                    b = 1.0 - b;
                }

                const vec3 pos  = _poss[index::vertex::GAMMA] + ((_poss[index::vertex::ALPHA] - _poss[index::vertex::GAMMA]) * a) + ((_poss[index::vertex::BETA] - _poss[index::vertex::GAMMA]) * b);
                const vec3 norm = ((_norms[index::vertex::ALPHA] * a) + (_norms[index::vertex::BETA] * b) + (_norms[index::vertex::GAMMA] * (1.0 - a - b))).normal();

                assert(norm.normalised());

                return (std::pair<vec3, vec3>(pos, norm));
            }


            //  -- Collision --
            /**
             *  Get the collision distance (if one occurs) of a ray.
             *
             *  @param  pos_    Initial position of the ray.
             *  @param  dir_    Direction of ray travel.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional distance to collision event.
             */
            inline std::optional<double> Triangle::collision(const vec3& pos_, const vec3& dir_) const noexcept
            {
                assert(dir_.normalised());

                const vec3 edge_ab = _poss[index::vertex::BETA] - _poss[index::vertex::ALPHA];
                const vec3 edge_ac = _poss[index::vertex::GAMMA] - _poss[index::vertex::ALPHA];

                const vec3   p   = dir_ ^ edge_ac;
                const double det = edge_ab * p;

                if (math::compare::zero(det))
                {
                    return (std::nullopt);
                }

                const vec3   t = pos_ - _poss[index::vertex::ALPHA];
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
             *  @return Optional information to collision event.
             */
            inline std::optional<Collision> Triangle::collision_info(const vec3& pos_, const vec3& dir_) const noexcept
            {
                assert(dir_.normalised());

                const vec3 edge_ab = _poss[index::vertex::BETA] - _poss[index::vertex::ALPHA];
                const vec3 edge_ac = _poss[index::vertex::GAMMA] - _poss[index::vertex::ALPHA];

                const vec3   p   = dir_ ^ edge_ac;
                const double det = edge_ab * p;

                if (math::compare::zero(det))
                {
                    return (std::nullopt);
                }

                const vec3   t = pos_ - _poss[index::vertex::ALPHA];
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

                return (Collision((dir_ * _plane_norm) < 0.0, dist, ((_norms[index::vertex::ALPHA] * (1.0 - u - v)) + (_norms[index::vertex::BETA] * u) + (_norms[index::vertex::GAMMA] * v)).normal()));
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_TRIANGLE_INL
