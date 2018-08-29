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
        inline const vec3& Aabb::min() const noexcept
        {
            return (_min);
        }

        inline const vec3& Aabb::max() const noexcept
        {
            return (_max);
        }

        inline double Aabb::area() const noexcept
        {
            const vec3 lengths = _max - _min;

            return (2.0 * ((lengths.x * lengths.y) + (lengths.y * lengths.z) + (lengths.z * lengths.x)));
        }

        inline double Aabb::vol() const noexcept
        {
            const vec3 lengths = _max - _min;

            return (lengths.x * lengths.y * lengths.z);
        }


    } // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_AABB_HPP
