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
                const std::array<vec3, 3> _poss; //!< Vertex positions.
                const std::array<vec3, 3> _norm; //!< Vertex normals.

                //  -- Properties --
                const double _area;       //!< Area of the triangle.
                const vec3   _plane_norm; //!< Normal of the triangle's plane.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Triangle(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norm_) noexcept;

                //  -- Initialisation --
                inline vec3 init_plane_norm(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norm_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const std::array<vec3, 3>& pos() const noexcept;
                inline const std::array<vec3, 3>& norm() const noexcept;
                inline const vec3&                plane_norm() const noexcept;
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
             *  @param  norm_   Normals of the vertices.
             *
             *  @pre    norm_ vecs must be normalised.
             *
             *  @post   _area must be positive.
             *  @post   _plane_norm must be normalised.
             */
            inline Triangle::Triangle(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norm_) noexcept
              : _poss(poss_)
              , _norm(norm_)
              , _area(math::geom::area(poss_))
              , _plane_norm(init_plane_norm(poss_, norm_))
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
             *  @param  poss_   Positions of the vertices.
             *  @param  norm_   Normals of the vertices.
             *
             *  @post   plane_norm must be normalised.
             *
             *  @return The normal vector of the triangle's plane.
             */
            inline vec3 Triangle::init_plane_norm(const std::array<vec3, 3>& poss_, const std::array<vec3, 3>& norm_) const noexcept
            {
                vec3 plane_norm = ((poss_[index::vertex::BETA] - poss_[index::vertex::ALPHA]) ^ (poss_[index::vertex::GAMMA] - poss_[index::vertex::ALPHA])).normal();

                if ((plane_norm * (norm_[index::vertex::ALPHA] + norm_[index::vertex::BETA] + norm_[index::vertex::GAMMA])) < 0.0)
                {
                    plane_norm *= -1.0;
                }

                POST(plane_norm.normalised());

                return (plane_norm);
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the array of triangle vertices.
             *
             *  @return Array of triangle vertices.
             */
            inline const std::array<vec3, 3>& Triangle::pos() const noexcept
            {
                return (_poss);
            }

            /**
             *  Get the array of triangle normals.
             *
             *  @return Array of triangle normals.
             */
            inline const std::array<vec3, 3>& Triangle::norm() const noexcept
            {
                return (_norm);
            }

            /**
             *  Get the normal of triangles plane.
             *
             *  @return Normal of triangles plane.
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
                const double tri_vol = std::fabs(((_tris[i].poss()[index::vertex::ALPHA] ^ _tris[i].poss()[index::vertex::BETA]) * _tris[i].poss()[index::vertex::GAMMA]) / 6.0);

                const vec3 centre = (_tris[i].poss()[index::vertex::ALPHA] + _tris[i].poss()[index::vertex::BETA] + _tris[i].poss()[index::vertex::GAMMA]) / 3.0;

                if ((centre * _tris[i].norm()) < 0.0)
                {
                    vol -= tri_vol;
                }
                else
                {
                    vol += tri_vol;
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
                const vec3 norm = ((_norm[index::vertex::ALPHA] * a) + (_norm[index::vertex::BETA] * b) + (_norm[index::vertex::GAMMA] * (1.0 - a - b))).normal();

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

                const double denom = _plane_norm * dir_;

                if (math::compare::zero(denom))
                {
                    return (std::nullopt);
                }

                const double dist = ((_poss[index::vertex::ALPHA] - pos_) * _plane_norm) / denom;

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

                return (std::pair(dist, ((_norm[index::vertex::ALPHA] * (1.0 - u - v)) + (_norm[index::vertex::BETA] * u) + (_norm[index::vertex::GAMMA] * v)).normal()));
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_TRIANGLE_HPP
