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



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <optional>

//  -- Arctk --
#include <arctk/geom/collision.hpp>
#include <arctk/geom/shape.hpp>
#include <arctk/index.hpp>
#include <arctk/lib/tri_collision.h>
#include <arctk/math.hpp>
#include <arctk/random.hpp>



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
                inline vec3                  random_pos(random::Generator* rng_) const noexcept override;
                inline std::pair<vec3, vec3> random_pos_and_norm(random::Generator* rng_) const noexcept override;

                //  -- Intersection --
                inline bool intersect(const Triangle& tri_) const noexcept;

                //  -- Collision --
                inline std::optional<double>    collision(const vec3& pos_, const vec3& dir_) const noexcept override;
                inline std::optional<Collision> collision_info(const vec3& pos_, const vec3& dir_) const noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a triangle from three vertex positions and three corresponding vertex normals.
             *
             *  @param  poss_   Positions of the vertices.
             *  @param  norms_  Normals of the vertices.
             *
             *  @pre    norms_ vecs must be normalised.
             *
             *  @post   _plane_norm must be normalised.
             */
            inline Triangle::Triangle(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) noexcept
              : _poss(poss_)
              , _norms(norms_)
              , _plane_norm(((poss_[index::vertex::BETA] - poss_[index::vertex::ALPHA]) ^ (poss_[index::vertex::GAMMA] - poss_[index::vertex::ALPHA])).normal())
            {
                PRE(norms_[index::vertex::ALPHA].normalised());
                PRE(norms_[index::vertex::BETA].normalised());
                PRE(norms_[index::vertex::GAMMA].normalised());

                POST(_plane_norm.normalised());
            }



            //  == METHODS ==
            //  -- Getters --
            inline const std::array<vec3, 3>& Triangle::poss() const noexcept
            {
                return (_poss);
            }

            inline const std::array<vec3, 3>& Triangle::norms() const noexcept
            {
                return (_norms);
            }

            inline const vec3& Triangle::plane_norm() const noexcept
            {
                return (_plane_norm);
            }

            inline double Triangle::area() const noexcept
            {
                return (math::geom::area(_poss));
            }


            //  -- Sampling --
            inline vec3 Triangle::random_pos(random::Generator* rng_) const noexcept
            {
                PRE(rng_ != nullptr);

                double a = rng_->gen();
                double b = rng_->gen();

                if ((a + b) > 1.0)
                {
                    a = 1.0 - a;
                    b = 1.0 - b;
                }

                return (_poss[index::vertex::GAMMA] + ((_poss[index::vertex::ALPHA] - _poss[index::vertex::GAMMA]) * a) + ((_poss[index::vertex::BETA] - _poss[index::vertex::GAMMA]) * b));
            }

            inline std::pair<vec3, vec3> Triangle::random_pos_and_norm(random::Generator* rng_) const noexcept
            {
                PRE(rng_ != nullptr);

                double a = rng_->gen();
                double b = rng_->gen();

                if ((a + b) > 1.0)
                {
                    a = 1.0 - a;
                    b = 1.0 - b;
                }

                const vec3 pos  = _poss[index::vertex::GAMMA] + ((_poss[index::vertex::ALPHA] - _poss[index::vertex::GAMMA]) * a) + ((_poss[index::vertex::BETA] - _poss[index::vertex::GAMMA]) * b);
                const vec3 norm = ((_norms[index::vertex::ALPHA] * a) + (_norms[index::vertex::BETA] * b) + (_norms[index::vertex::GAMMA] * (1.0 - a - b))).normal();

                POST(norm.normalised());

                return (std::pair<vec3, vec3>(pos, norm));
            }


            //  -- Intersection --
            inline bool Triangle::intersect(const Triangle& tri_) const noexcept
            {
                return (collision::tri_tri_overlap_test_3d(std::array<double, 3>({{_poss[index::vertex::ALPHA].x, _poss[index::vertex::ALPHA].y, _poss[index::vertex::ALPHA].z}}).data(),
                                                           std::array<double, 3>({{_poss[index::vertex::BETA].x, _poss[index::vertex::BETA].y, _poss[index::vertex::BETA].z}}).data(),
                                                           std::array<double, 3>({{_poss[index::vertex::GAMMA].x, _poss[index::vertex::GAMMA].y, _poss[index::vertex::GAMMA].z}}).data(),
                                                           std::array<double, 3>({{tri_._poss[index::vertex::ALPHA].x, tri_._poss[index::vertex::ALPHA].y, tri_._poss[index::vertex::ALPHA].z}}).data(),
                                                           std::array<double, 3>({{tri_._poss[index::vertex::BETA].x, tri_._poss[index::vertex::BETA].y, tri_._poss[index::vertex::BETA].z}}).data(),
                                                           std::array<double, 3>({{tri_._poss[index::vertex::GAMMA].x, tri_._poss[index::vertex::GAMMA].y, tri_._poss[index::vertex::GAMMA].z}}).data()));
            }


            //  -- Collision --
            inline std::optional<double> Triangle::collision(const vec3& pos_, const vec3& dir_) const noexcept
            {
                PRE(dir_.normalised());

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

            inline std::optional<Collision> Triangle::collision_info(const vec3& pos_, const vec3& dir_) const noexcept
            {
                PRE(dir_.normalised());

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
#endif // ARCTK_GEOM_SHAPE_TRIANGLE_HPP
