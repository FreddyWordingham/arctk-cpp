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
#include <cstdlib>
#include <iostream>
#include <optional>

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



        //  == SETTINGS ==
        //  -- Wavefront Keywords --
        constexpr const char* POS_KEYWORD  = "v";  //!< Wavefront file keyword identifying vertex positions.
        constexpr const char* NORM_KEYWORD = "vn"; //!< Wavefront file keyword identifying vertex normals.
        constexpr const char* FACE_KEYWORD = "f";  //!< Wavefront file keyword identifying a face.



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
            inline vec3                       min() const noexcept;
            inline vec3                       max() const noexcept;
            inline double                     area() const noexcept;
            inline const std::array<vec3, 3>& poss() const noexcept;
            inline const std::array<vec3, 3>& norms() const noexcept;
            inline const vec3&                norm() const noexcept;

            //  -- Collision --
            inline std::optional<double>                  plane_collision(const vec3& pos_, const vec3& dir_) const noexcept;
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
        /**
         *  Initialise the surface normal of the triangle's plane.
         *
         *  @param  poss_   Array of vertex positions forming the triangle.
         *  @param  norms_  Array of vertex normals forming the triangle.
         *
         *  @post   norm must be normalised.
         *
         *  @return Initialised surface normal of the triangle's plane.
         */
        inline vec3 Triangle::init_norm(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norms_) const noexcept
        {
            vec3 norm = ((poss_[index::vertex::BETA] - poss_[index::vertex::ALPHA]) ^ (poss_[index::vertex::GAMMA] - poss_[index::vertex::ALPHA])).normal();

            if ((norm * norms_[index::vertex::ALPHA]) < 0.0)
            {
                norm = -norm;
            }

            if (((norm * norms_[index::vertex::ALPHA]) < 0.0) || ((norm * norms_[index::vertex::BETA]) < 0.0) || ((norm * norms_[index::vertex::GAMMA]) < 0.0))
            {
                std::cerr << "Unable to construct triangle object.\n"
                          << "Normals of triangle vertices must all point one side of the triangle's surface.\n";

                std::exit(exit::error::FAILED_INITIALISATION);
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
         *  Get the surface area of the triangle.
         *
         *  @post   area must be positive.
         *
         *  @return Surface area of the triangle.
         */
        inline double Triangle::area() const noexcept
        {
            const double area = math::geom::area(_poss);

            POST(area > 0.0);

            return (area);
        }

        /**
         *  Access a const reference to the vertex position array forming the triangle.
         *
         *  @return Const reference to the vertex position array forming the triangle.
         */
        inline const std::array<vec3, 3>& Triangle::poss() const noexcept
        {
            return (_poss);
        }

        /**
         *  Access a const reference to the vertex normals array forming the triangle.
         *
         *  @return Const reference to the vertex normals array forming the triangle.
         */
        inline const std::array<vec3, 3>& Triangle::norms() const noexcept
        {
            return (_norms);
        }

        /**
         *  Access a const reference to the normal of the triangle's plane.
         *
         *  @return Const reference to the normal of the triangle's plane.
         */
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

            return (std::pair<vec3, vec3>(pos, norm));
        }



    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_TRIANGLE_HPP
