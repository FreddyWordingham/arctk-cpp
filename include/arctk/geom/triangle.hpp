/**
 *  @file   arctk/geom/triangle.hpp
 *  @date   29/08/2018
 *  @author Freddy Wordingham
 *
 *  Geometric triangle class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_TRIANGLE_HPP
#define ARCTK_GEOM_TRIANGLE_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <optional>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/index.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {



        //  == CLASS ==
        /**
         *  Geometric triangle.
         */
        class Triangle
        {
            //  == FIELDS ==
          private:
            //  -- Positioning --
            const std::array<vec3, 3> _poss;  //!< Vertex positions.
            const std::array<vec3, 3> _norms; //!< Vertex normals.

            //  -- Properties --
            const vec3 _norm; //!< Normal of the triangle's plane.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Triangle(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) noexcept;

          private:
            //  -- Initialisation --
            inline vec3 init_norm(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const vec3&                min() const noexcept;
            inline const vec3&                max() const noexcept;
            inline double                     area() const noexcept;
            inline double                     vol() const noexcept;
            inline const std::array<vec3, 3>& poss() const noexcept;
            inline const std::array<vec3, 3>& norms() const noexcept;
            inline const vec3&                norm() const noexcept;

            //  -- Collision --
            inline std::optional<double>                  plane_collision(const vec3& pos_, const vec3& dir_) const;
            inline std::optional<double>                  collision(const vec3& pos_, const vec3& dir_) const noexcept;
            inline std::optional<std::pair<double, vec3>> collision_norm(const vec3& pos_, const vec3& dir_) const noexcept;

            //  -- Emission --
            inline vec3                  random_pos(random::Generator* rng_) const noexcept;
            inline std::pair<vec3, vec3> random_pos_and_norm(random::Generator* rng_) const noexcept;
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
         *  @post   _norm must be normalised.
         *  @post   _norm dot product with each norms_ vec must be non-negative.
         */
        inline Triangle::Triangle(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) noexcept
          : _poss(poss_)
          , _norms(norms_)
          , _norm(init_norm(poss_, norms_))
        {
            PRE(norms_[index::vertex::ALPHA].normalised());
            PRE(norms_[index::vertex::BETA].normalised());
            PRE(norms_[index::vertex::GAMMA].normalised());

            POST(_norm.normalised());
            POST((_norm * norms_[index::vertex::ALPHA]) >= 0.0);
            POST((_norm * norms_[index::vertex::BETA]) >= 0.0);
            POST((_norm * norms_[index::vertex::GAMMA]) >= 0.0);
        }


        //  -- Initialisation --
        inline vec3 Triangle::init_norm(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) const noexcept
        {
            vec3 norm = ((poss_[index::vertex::BETA] - poss_[index::vertex::ALPHA]) ^ (poss_[index::vertex::GAMMA] - poss_[index::vertex::ALPHA])).normal();

            if ((norm * norms_[index::vertex::ALPHA]) < 0.0)
            {
                norm = -norm;
            }

            POST(_norm.normalised());
            POST((norm * norms_[index::vertex::ALPHA]) >= 0.0);
            POST((norm * norms_[index::vertex::BETA]) >= 0.0);
            POST((norm * norms_[index::vertex::GAMMA]) >= 0.0);
        }



        //  == METHODS ==
        //  -- Getters --
        inline const vec3& Triangle::min() const noexcept
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

        inline const vec3& Triangle::max() const noexcept
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

        inline double Triangle::area() const noexcept
        {
            return (math::geom::area(_poss));
        }

        inline double Triangle::vol() const noexcept
        {
            return (0.0);
        }

        inline const std::array<vec3, 3>& Triangle::poss() const noexcept
        {
            return (_poss);
        }

        inline const std::array<vec3, 3>& Triangle::norms() const noexcept
        {
            return (_norms);
        }

        inline const vec3& Triangle::norm() const noexcept
        {
            return (_norm);
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
            const double denom = _plane_norm * dir_;

            if (math::compare::zero(denom))
            {
                return (std::nullopt);
            }

            const double dist = ((_pos[index::vertex::ALPHA] - pos_) * _plane_norm) / denom;

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

            const vec3 edge_ab = _pos[index::vertex::BETA] - _pos[index::vertex::ALPHA];
            const vec3 edge_ac = _pos[index::vertex::GAMMA] - _pos[index::vertex::ALPHA];

            const vec3   p   = dir_ ^ edge_ac;
            const double det = edge_ab * p;

            if (math::compare::zero(det))
            {
                return (std::nullopt);
            }

            const vec3   t = pos_ - _pos[index::vertex::ALPHA];
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

            const vec3 edge_ab = _pos[index::vertex::BETA] - _pos[index::vertex::ALPHA];
            const vec3 edge_ac = _pos[index::vertex::GAMMA] - _pos[index::vertex::ALPHA];

            const vec3   p   = dir_ ^ edge_ac;
            const double det = edge_ab * p;

            if (math::compare::zero(det))
            {
                return (std::nullopt);
            }

            const vec3   t = pos_ - _pos[index::vertex::ALPHA];
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

            return (std::pair(dist, ((_norm[index::vertex::ALPHA] * (1.0 - u - v)) + (_norm[index::vertex::BETA] * u) + (_norm[index::vertex::GAMMA] * v)).normal()));
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

            return (_pos[index::vertex::GAMMA] + ((_pos[index::vertex::ALPHA] - _pos[index::vertex::GAMMA]) * a) + ((_pos[index::vertex::BETA] - _pos[index::vertex::GAMMA]) * b));
        }

        /**
         *  Generate a random position, and corresponding normal, on the surface of the triangle.
         *
         *  @param  rng_    Random number generator.
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

            const vec3 pos  = _pos[index::vertex::GAMMA] + ((_pos[index::vertex::ALPHA] - _pos[index::vertex::GAMMA]) * a) + ((_pos[index::vertex::BETA] - _pos[index::vertex::GAMMA]) * b);
            const vec3 norm = ((_norm[index::vertex::ALPHA] * a) + (_norm[index::vertex::BETA] * b) + (_norm[index::vertex::GAMMA] * (1.0 - a - b))).normal();

            return (std::pair<vec3, vec3>(pos, norm));
        }



    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_TRIANGLE_HPP
