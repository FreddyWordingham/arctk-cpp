/**
 *  @file   arctk/geom/aabb.hpp
 *  @date   29/08/2018
 *  @author Freddy Wordingham
 *
 *  Geometric axis-aligned bounding box class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_AABB_HPP
#define ARCTK_GEOM_AABB_HPP



//  == IMPORTS ==
//  -- Std --
#include <optional>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {



        //  == CLASS ==
        /**
         *  Axis-aligned bounding box.
         */
        class Aabb
        {
            //  == FIELDS ==
          private:
            //  -- Positioning --
            const vec3 _min; //!< Minimum vertex of the aabb.
            const vec3 _max; //!< Maximum vertex of the aabb.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Aabb(const vec3& min_, const vec3& max_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const vec3& min() const noexcept;
            inline const vec3& max() const noexcept;
            inline double      area() const noexcept;
            inline double      vol() const noexcept;

            //  -- Collision --
            inline bool                                   contains(const vec3& pos_) const noexcept;
            inline std::optional<double>                  collision(const vec3& pos_, const vec3& dir_) const noexcept;
            inline std::optional<std::pair<double, vec3>> collision_norm(const vec3& pos_, const vec3& dir_) const noexcept;
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
        {
            PRE(min_.x < max_.x);
            PRE(min_.y < max_.y);
            PRE(min_.z < max_.z);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the minimum bound of the axis-aligned bounding box.
         *
         *  @return Minimum bound of the axis-aligned bounding box.
         */
        inline const vec3& Aabb::min() const noexcept
        {
            return (_min);
        }

        /**
         *  Get the maximum bound of the axis-aligned bounding box.
         *
         *  @return Maximum bound of the axis-aligned bounding box.
         */
        inline const vec3& Aabb::max() const noexcept
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
         *  Get the volume of the axis-aligned bounding box.
         *
         *  @post   vol must be positive.
         *
         *  @return Volume of the axis-aligned bounding box.
         */
        inline double Aabb::vol() const noexcept
        {
            const vec3 lengths = _max - _min;

            const double vol = lengths.x * lengths.y * lengths.z;

            POST(vol > 0.0);

            return (vol);
        }


        //  -- Collision --
        inline bool Aabb::contains(const vec3& pos_) const noexcept
        {
            return (!((pos_.x < _min.x) || (pos_.x > _max.x) || (pos_.y < _min.y) || (pos_.y > _max.y) || (pos_.z < _min.z) || (pos_.z > _max.z)));
        }

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


    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_AABB_HPP
