/**
 *  @file   arctk/geom/shape/box.hpp
 *  @date   06/10/2018
 *  @author Freddy Wordingham
 *
 *  Geometric axis-aligned bounding box shape class.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_SHAPE_BOX_HPP
#define ARCTK_GEOM_SHAPE_BOX_HPP



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
        namespace shape //! shape namespace
        {



            //  == CLASS ==
            /**
             *  Axis-aligned bounding box shape.
             */
            class Box : public Shape
            {
                //  == FIELDS ==
              private:
                //  -- Positioning --
                const vec3 _min; //!< Minimum vertex of the aabb.
                const vec3 _max; //!< Maximum vertex of the aabb.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Box(const vec3& min_, const vec3& max_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const vec3& min() const noexcept;
                inline const vec3& max() const noexcept;
                inline double      vol() const noexcept;

                //  -- Intersection --
                inline bool box_surf_intersect(const Box& box_) const noexcept;

                //  -- Collision --
                inline std::optional<double> collision(const vec3& pos_, const vec3& dir_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct an axis-aligned bounding box with given minimum and maximum vertex positions.
             *
             *  @param  min_    Vertex position of the box.
             *  @param  max_    Vertex position of the box.
             *
             *  @pre    min_.x must be less than max_.x.
             *  @pre    min_.y must be less than max_.y.
             *  @pre    min_.z must be less than max_.z.
             */
            inline Box::Box(const vec3& min_, const vec3& max_) noexcept
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
             *  Get the minimum bound of the box.
             *
             *  @return Minimum bound of the box.
             */
            inline const vec3& Box::min() const noexcept
            {
                return (_min);
            }

            /**
             *  Get the maximum bound of the box.
             *
             *  @return Maximum bound of the box.
             */
            inline const vec3& Box::max() const noexcept
            {
                return (_max);
            }

            inline double Box::vol() const noexcept
            {
                return ((_max.x - _min.x) * (_max.y - _min.y) * (_max.z - _min.z));
            }


            //  -- Intersection --
            inline bool Box::box_surf_intersect(const Box& box_) const noexcept
            {
                for (size_t i = 0; i < 3; ++i)
                {
                    if ((_min[i] > box_.max()[i]) || (_max[i] < box_.min()[i]))
                    {
                        return (false);
                    }
                }

                for (size_t i = 0; i < 3; ++i)
                {
                    if ((box_.min()[i] < _min[i]) || (box_.max()[i] > _max[i]))
                    {
                        return (true);
                    }
                }

                return (false);
            }


            //  -- Collision --
            inline std::optional<double> Box::collision(const vec3& pos_, const vec3& dir_) const noexcept
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

                double dist = min_x;

                if (dist < 0.0)
                {
                    dist = max_x;
                }

                if (dist < 0.0)
                {
                    return (std::nullopt);
                }

                return (dist);
            }



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_BOX_HPP
