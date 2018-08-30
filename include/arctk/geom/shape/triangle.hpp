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



//  == IMPORTS ==
//  -- Std --
#include <cmath>
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
              private:
                //  -- Positioning --
                const std::array<vec3, 3> _poss;  //!< Vertex positions.
                const std::array<vec3, 3> _norms; //!< Vertex normals.

                //  -- Properties --
                const double _area; //!< Area of the triangle.
                const vec3   _norm; //!< Normal of the triangle's plane.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Triangle(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) noexcept;

                //  -- Initialisation --
                inline vec3 init_norm(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const std::array<vec3, 3>& poss() const noexcept;
                inline const std::array<vec3, 3>& norms() const noexcept;
                inline const vec3&                norm() const noexcept;
                inline vec3                       min() const noexcept override;
                inline vec3                       max() const noexcept override;
                inline double                     area() const noexcept override;
                inline double                     vol() const noexcept override;

                //  -- Emission --
                inline vec3                  random_pos(random::Generator* rng_) const noexcept override;
                inline std::pair<vec3, vec3> random_pos_and_norm(random::Generator* rng_) const noexcept override;

                //  -- Collision --
                inline std::optional<double>                  plane_collision(const vec3& pos_, const vec3& dir_) const noexcept;
                inline std::optional<double>                  collision(const vec3& pos_, const vec3& dir_) const noexcept override;
                inline std::optional<std::pair<double, vec3>> collision_norm(const vec3& pos_, const vec3& dir_) const noexcept override;
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
             *  @post   _area must be positive.
             *  @post   _norm must be normalised.
             */
            inline Triangle::Triangle(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) noexcept
              : _poss(poss_)
              , _norms(norms_)
              , _area(math::geom::area(poss_))
              , _norm(init_norm(poss_, norms_))
            {
                PRE(norms_[index::vertex::ALPHA].normalised());
                PRE(norms_[index::vertex::BETA].normalised());
                PRE(norms_[index::vertex::GAMMA].normalised());

                POST(_area > 0.0);
                POST(_norm.normalised());
            }


            //  -- Initialisation --
            /**
             *  Initialise the normal vector of the triangle by determining the cross-product of two of the triangles edges.
             *  Normal must be normalised after determining the cross-product.
             *
             *  @param  poss_   Positions of the vertices.
             *  @param  norms_  Normals of the vertices.
             *
             *  @post   norm must be normalised.
             *
             *  @return The normal vector of the triangle's plane.
             */
            inline vec3 Triangle::init_norm(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) const noexcept
            {
                vec3 norm = ((poss_[index::vertex::BETA] - poss_[index::vertex::ALPHA]) ^ (poss_[index::vertex::GAMMA] - poss_[index::vertex::ALPHA])).normal();

                if ((norm * (norms_[index::vertex::ALPHA] + norms_[index::vertex::BETA] + norms_[index::vertex::GAMMA])) < 0.0)
                {
                    norm *= -1.0;
                }

                POST(norm.normalised());

                return (norm);
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the minimum bound of the triangle.
             *
             *  @return Minimum bound of the triangle.
             */
            inline vec3 Triangle::min() const noexcept
            {
                vec3 min(std::numeric_limits<double>::max(), std::numeric_limits<double>::max(), std::numeric_limits<double>::max());

                for (size_t i = 0; i < 3; ++i)
                {
                    for (size_t j = 0; j < 3; ++j)
                    {
                        if (_poss[i][j] < min[j])
                        {
                            min[j] = _poss[i][j];
                        }
                    }
                }

                return (min);
            }

            /**
             *  Get the maximum bound of the triangle.
             *
             *  @return Maximum bound of the triangle.
             */
            inline vec3 Triangle::max() const noexcept
            {
                vec3 max(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest(), std::numeric_limits<double>::lowest());

                for (size_t i = 0; i < 3; ++i)
                {
                    for (size_t j = 0; j < 3; ++j)
                    {
                        if (_poss[i][j] > max[j])
                        {
                            max[j] = _poss[i][j];
                        }
                    }
                }

                return (max);
            }

            /**
             *  Get the array of triangle vertices.
             *
             *  @return Array of triangle vertices.
             */
            inline const std::array<vec3, 3>& Triangle::poss() const noexcept
            {
                return (_poss);
            }

            /**
             *  Get the array of triangle normals.
             *
             *  @return Array of triangle normals.
             */
            inline const std::array<vec3, 3>& Triangle::norms() const noexcept
            {
                return (_norms);
            }

            /**
             *  Get the normal of triangles plane.
             *
             *  @return Normal of triangles plane.
             */
            inline const vec3& Triangle::norm() const noexcept
            {
                return (_norm);
            }

            /**
             *  Get the area of the triangle.
             *
             *  @return Area of the triangle.
             */
            inline double Triangle::area() const noexcept
            {
                return (_area);
            }

            /**
             *  Calculate the bounding volume of a tetrahedron formed of the triangle vertex positions and the origin.
             *  Note that volume is negative if the normal of the triangle faces to towards the origin.
             *
             *  @return Volume of the bound tetrahedron.
             */
            inline double Triangle::vol() const noexcept
            {
                const double vol = std::fabs(((_poss[index::vertex::ALPHA] ^ _poss[index::vertex::BETA]) * _poss[index::vertex::GAMMA]) / 6.0);

                const vec3 centre = (_poss[index::vertex::ALPHA] + _poss[index::vertex::BETA] + _poss[index::vertex::GAMMA]) / 3.0;

                if ((centre * _norm) < 0.0)
                {
                    return (-vol);
                }

                return (vol);
            }


            //  -- Emission --
            /**
             *  Generate a random position on the surface of the triangle.
             *
             *  @param  rng_    Random number generator.
             *
             *  @return Random position on the surface of the triangle.
             */
            inline vec3 Triangle::random_pos(random::Generator* const rng_) const noexcept
            {
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
             *  Generate a random position, and corresponding normal, on the surface of the triangle.
             *
             *  @param  rng_    Random number generator.
             *
             *  @post   norm must be normalised.
             *
             *  @return Random position, and corresponding normal, on the surface of the triangle.
             */
            inline std::pair<vec3, vec3> Triangle::random_pos_and_norm(random::Generator* rng_) const noexcept
            {
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


            //  -- Collision --
            /**
             *  Determine if a collision event occurs between the plane the triangle rests in and a ray.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional collision distance.
             */
            inline std::optional<double> Triangle::plane_collision(const vec3& pos_, const vec3& dir_) const noexcept
            {
                PRE(dir_.normalised());

                const double denom = _norm * dir_;

                if (math::compare::zero(denom))
                {
                    return (std::nullopt);
                }

                const double dist = ((_poss[index::vertex::ALPHA] - pos_) * _norm) / denom;

                return ((dist < 0.0) ? std::nullopt : std::optional<double>(dist));
            }

            /**
             *  Determine if a collision event occurs between the triangle and a ray.
             *  If a collision does occur, return the distance to the collision point.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional collision distance.
             */
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

            /**
             *  Determine if a collision event occurs between the triangle and a ray.
             *  If a collision does occur, return the distance to the collision point and the normal of the triangle at the collision point.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional collision distance and intersection normal.
             */
            inline std::optional<std::pair<double, vec3>> Triangle::collision_norm(const vec3& pos_, const vec3& dir_) const noexcept
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

                return (std::pair(dist, ((_norms[index::vertex::ALPHA] * (1.0 - u - v)) + (_norms[index::vertex::BETA] * u) + (_norms[index::vertex::GAMMA] * v)).normal()));
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_TRIANGLE_HPP
