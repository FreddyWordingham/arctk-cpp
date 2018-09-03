/**
 *  @file   arctk/geom/shape/aabb.hpp
 *  @date   07/08/2018
 *  @author Freddy Wordingham
 *
 *  Geometric axis-aligned bounding box shape class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_SHAPE_AABB_HPP
#define ARCTK_GEOM_SHAPE_AABB_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <optional>

//  -- Arctk --
#include <arctk/exit.hpp>
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
             *  Axis-aligned bounding box shape.
             */
            class Aabb : public Shape
            {
                //  == FIELDS ==
              private:
                //  -- Positioning --
                const vec3 _min; //!< Minimum vertex of the aabb.
                const vec3 _max; //!< Maximum vertex of the aabb.

                //  -- Areas --
                std::array<double, 4> _areas; //!< Normalised relative area of each pair of faces.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Aabb(const vec3& min_, const vec3& max_) noexcept;

              private:
                //  -- Initialisation --
                inline std::array<double, 4> init_areas(const vec3& min_, const vec3& max_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Properties --
                inline vec3   min() const noexcept override;
                inline vec3   max() const noexcept override;
                inline double area() const noexcept override;
                inline double vol() const noexcept override;
                inline vec3   centre() const noexcept;
                inline vec3   half_width() const noexcept;

                //  -- Emission --
                inline vec3                  random_pos(random::Generator* rng_) const noexcept override;
                inline std::pair<vec3, vec3> random_pos_and_norm(random::Generator* rng_) const noexcept override;

                //  -- Intersection --
                inline bool intersect_surf(const shape::Aabb& aabb_) const noexcept override;
                inline bool intersect_vol(const shape::Aabb& aabb_) const noexcept override;
                inline vec3 nearest_point_vol(const vec3& pos_) const noexcept;
                inline bool contains(const vec3& pos_) const noexcept;

                //  -- Collision --
                inline std::optional<double>                  collision(const vec3& pos_, const vec3& dir_) const noexcept override;
                inline std::optional<std::pair<double, vec3>> collision_norm(const vec3& pos_, const vec3& dir_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct an axis-aligned bounding box with given minimum and maximum vertex positions.
             *
             *  @param  min_    Vertex position of the aabb.
             *  @param  max_    Vertex position of the aabb.
             *
             *  @pre    min_.x must be less than max_.x.
             *  @pre    min_.y must be less than max_.y.
             *  @pre    min_.z must be less than max_.z.
             */
            inline Aabb::Aabb(const vec3& min_, const vec3& max_) noexcept
              : _min(min_)
              , _max(max_)
              , _areas(init_areas(min_, max_))
            {
                PRE(min_.x < max_.x);
                PRE(min_.y < max_.y);
                PRE(min_.z < max_.z);
            }


            //  -- Initialisation --
            /**
             *  Initialise the vector of normalised relative area of each pair of faces.
             *
             *  @param  min_    Vertex position of the aabb.
             *  @param  max_    Vertex position of the aabb.
             *
             *  @pre    min_.x must be less than max_.x.
             *  @pre    min_.y must be less than max_.y.
             *  @pre    min_.z must be less than max_.z.
             *
             *  @return Initialise vector of normalised relative area of each pair of faces.
             */
            inline std::array<double, 4> Aabb::init_areas(const vec3& min_, const vec3& max_) const noexcept
            {
                PRE(min_.x < max_.x);
                PRE(min_.y < max_.y);
                PRE(min_.z < max_.z);

                std::array<double, 4> areas{};

                areas[0] = 0.0;
                for (size_t i = 1; i < 4; ++i)
                {
                    const size_t dim_0 = index::rotate::next(i - 1, 3, 1);
                    const size_t dim_1 = index::rotate::next(i - 1, 3, 2);

                    areas[i] = areas[i - 1] + ((max_[dim_0] - min_[dim_0]) * (max_[dim_1] - min_[dim_1]));
                }

                for (size_t i = 0; i < 4; ++i)
                {
                    areas[i] /= areas.back();
                }

                POST(math::compare::equal(areas.back(), 1.0));

                return (areas);
            }



            //  == METHODS ==
            //  -- Properties --
            /**
             *  Get the minimum bound of the aabb.
             *
             *  @return Minimum bound of the aabb.
             */
            inline vec3 Aabb::min() const noexcept
            {
                return (_min);
            }

            /**
             *  Get the maximum bound of the aabb.
             *
             *  @return Maximum bound of the aabb.
             */
            inline vec3 Aabb::max() const noexcept
            {
                return (_max);
            }

            /**
             *  Get the total surface area of the axis-aligned bounding box.
             *
             *  @post   area must be positive.
             *
             *  @return Total surface area of the axis-aligned bounding box.
             */
            inline double Aabb::area() const noexcept
            {
                const vec3 lengths = _max - _min;

                const double area = 2.0 * ((lengths.x * lengths.y) + (lengths.y * lengths.z) + (lengths.z * lengths.x));

                POST(area > 0.0);

                return (area);
            }

            /**
             *  Get the total volume of the axis-aligned bounding box.
             *
             *  @post   vol must be positive.
             *
             *  @return Total volume of the axis-aligned bounding box.
             */
            inline double Aabb::vol() const noexcept
            {
                const vec3 lengths = _max - _min;

                const double vol = lengths.x * lengths.y * lengths.z;

                POST(vol > 0.0);

                return (vol);
            }

            /**
             *  Get the centre position of the axis-aligned bounding box.
             *
             *  @return Centre position of the axis-aligned bounding box.
             */
            inline vec3 Aabb::centre() const noexcept
            {
                return ((_max + _min) * 0.5);
            }

            /**
             *  Get the half widths of the axis-aligned bounding box.
             *
             *  @return Half widths of the axis-aligned bounding box.
             */
            inline vec3 Aabb::half_width() const noexcept
            {
                return ((_max - _min) * 0.5);
            }


            //  -- Emission --
            /**
             *  Generate a random position on the surface of the axis-aligned bounding box.
             *
             *  @param  rng_    Random number generator.
             *
             *  @return Random position on the surface of the axis-aligned bounding box.
             */
            inline vec3 Aabb::random_pos(random::Generator* const rng_) const noexcept
            {
                const size_t face  = utl::search::lower(_areas, rng_->gen());
                const size_t dim_0 = index::rotate::next(face, 3, 1);
                const size_t dim_1 = index::rotate::next(face, 3, 2);

                vec3 pos;

                pos[face]  = (rng_->gen() < 0.5) ? _min[face] : _max[face];
                pos[dim_0] = random::distribution::uniform(rng_, _min[dim_0], _max[dim_0]);
                pos[dim_1] = random::distribution::uniform(rng_, _min[dim_1], _max[dim_1]);

                return (pos);
            }

            /**
             *  Generate a random position, and corresponding normal, on the surface of the axis-aligned bounding box.
             *
             *  @param  rng_    Random number generator.
             *
             *  @return Random position, and corresponding normal, on the surface of the axis-aligned bounding box.
             */
            inline std::pair<vec3, vec3> Aabb::random_pos_and_norm(random::Generator* rng_) const noexcept
            {
                const size_t face  = utl::search::lower(_areas, rng_->gen());
                const size_t dim_0 = index::rotate::next(face, 3, 1);
                const size_t dim_1 = index::rotate::next(face, 3, 2);

                const bool min = rng_->gen() < 0.5;

                vec3 pos;

                pos[face]  = min ? _min[face] : _max[face];
                pos[dim_0] = random::distribution::uniform(rng_, _min[dim_0], _max[dim_0]);
                pos[dim_1] = random::distribution::uniform(rng_, _min[dim_1], _max[dim_1]);

                const vec3 norm = min ? -math::vec::axis<double, 3>(face) : math::vec::axis<double, 3>(face % 3);

                return (std::pair<vec3, vec3>(pos, norm));
            }


            //  -- Intersection --
            inline bool Aabb::intersect_surf(const shape::Aabb& aabb_) const noexcept
            {
                for (size_t i = 0; i < 3; ++i)
                {
                    if ((_min[i] > aabb_.max()[i]) || (_max[i] < aabb_.min()[i]))
                    {
                        return (false);
                    }
                }

                for (size_t i = 0; i < 3; ++i)
                {
                    if ((aabb_.min()[i] < _min[i]) || (aabb_.max()[i] > _max[i]))
                    {
                        return (true);
                    }
                }

                return (false);
            }

            inline bool Aabb::intersect_vol(const shape::Aabb& aabb_) const noexcept
            {
                for (size_t i = 0; i < 3; ++i)
                {
                    if ((_min[i] > aabb_.max()[i]) || (_max[i] < aabb_.min()[i]))
                    {
                        return (false);
                    }
                }

                return (true);
            }

            inline vec3 Aabb::nearest_point_vol(const vec3& pos_) const noexcept
            {
                vec3 pos;

                for (size_t i = 0; i < 3; ++i)
                {
                    if (pos_[i] > _max[i])
                    {
                        pos[i] = _max[i];
                    }
                    else if (pos_[i] < _min[i])
                    {
                        pos[i] = _min[i];
                    }
                    else
                    {
                        pos[i] = pos_[i];
                    }
                }

                return (pos);
            }

            /**
             *  Determine if a position falls within the bounds of the axis-aligned bounding box.
             *
             *  @param  pos_    Position to check.
             *
             *  @return True if the position falls within the axis-aligned bounding box.
             */
            inline bool Aabb::contains(const vec3& pos_) const noexcept
            {
                return (!((pos_.x < _min.x) || (pos_.x > _max.x) || (pos_.y < _min.y) || (pos_.y > _max.y) || (pos_.z < _min.z) || (pos_.z > _max.z)));
            }


            //  -- Collision --
            /**
             *  Determine if a collision event occurs between the axis-aligned bounding box and a ray.
             *  If a collision does occur, return the distance to the collision point.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional collision distance.
             */
            inline std::optional<double> Aabb::collision(const vec3& pos_, const vec3& dir_) const noexcept // NOLINT
            {
                PRE(dir_.normalised());

                double min_x = ((dir_.x < 0.0 ? _max.x : _min.x) - pos_.x) / dir_.x;
                double max_x = ((dir_.x < 0.0 ? _min.x : _max.x) - pos_.x) / dir_.x;
                double min_y = ((dir_.y < 0.0 ? _max.y : _min.y) - pos_.y) / dir_.y;
                double max_y = ((dir_.y < 0.0 ? _min.y : _max.y) - pos_.y) / dir_.y;

                if ((min_x > max_y) || (min_y > max_x))
                {
                    return (std::nullopt);
                }

                if (min_y > min_x)
                {
                    min_x = min_y;
                }

                if (max_y < max_x)
                {
                    max_x = max_y;
                }

                double min_z = ((dir_.z < 0.0 ? _max.z : _min.z) - pos_.z) / dir_.z;
                double max_z = ((dir_.z < 0.0 ? _min.z : _max.z) - pos_.z) / dir_.z;

                if ((min_x > max_z) || (min_z > max_x))
                {
                    return (std::nullopt);
                }

                if (min_z > min_x)
                {
                    min_x = min_z;
                }

                if (max_z < max_x)
                {
                    max_x = max_z;
                }

                double t = min_x;

                if (t < 0.0)
                {
                    t = max_x;
                }

                if (t < 0.0)
                {
                    return (std::nullopt);
                }

                return (t);
            }

            /**
             *  Determine if a collision event occurs between the axis-aligned bounding box and a ray.
             *  If a collision does occur, return the distance to the collision point and the normal of the axis-aligned bounding box at the collision point.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Optional collision distance and intersection normal.
             */
            inline std::optional<std::pair<double, vec3>> Aabb::collision_norm(const vec3& pos_, const vec3& dir_) const noexcept // NOLINT
            {
                PRE(dir_.normalised());

                double min_x = ((dir_.x < 0.0 ? _max.x : _min.x) - pos_.x) / dir_.x;
                double max_x = ((dir_.x < 0.0 ? _min.x : _max.x) - pos_.x) / dir_.x;
                double min_y = ((dir_.y < 0.0 ? _max.y : _min.y) - pos_.y) / dir_.y;
                double max_y = ((dir_.y < 0.0 ? _min.y : _max.y) - pos_.y) / dir_.y;

                size_t index = 0;

                if ((min_x > max_y) || (min_y > max_x))
                {
                    return (std::nullopt);
                }

                if (min_y > min_x)
                {
                    min_x = min_y;
                    index = 1;
                }

                if (max_y < max_x)
                {
                    max_x = max_y;
                }

                double min_z = ((dir_.z < 0.0 ? _max.z : _min.z) - pos_.z) / dir_.z;
                double max_z = ((dir_.z < 0.0 ? _min.z : _max.z) - pos_.z) / dir_.z;

                if ((min_x > max_z) || (min_z > max_x))
                {
                    return (std::nullopt);
                }

                if (min_z > min_x)
                {
                    min_x = min_z;
                    index = 2;
                }

                if (max_z < max_x)
                {
                    max_x = max_z;
                }

                vec3 norm;
                norm[index] = (dir_[index] < 0.0) ? 1.0 : -1.0;

                double t = min_x;

                if (t < 0.0)
                {
                    t = max_x;
                    norm[index] *= -1.0;
                }

                if (t < 0.0)
                {
                    return (std::nullopt);
                }

                return (std::pair<double, vec3>(t, norm));
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_AABB_HPP
