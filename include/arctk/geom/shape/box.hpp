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



//  == BASE ==
#include <arctk/geom/shape.hpp>



//  == IMPORTS ==
//  -- Std --
#include <optional>

//  -- Arctk --
#include <arctk/math/vec.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {
        namespace shape //! shape namespace
        {
            class Triangle;
        } // namespace shape
    }     // namespace geom
} // namespace arc



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
              protected:
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
                inline vec3        centre() const noexcept;
                inline vec3        half_width() const noexcept;

                //  -- Intersection --
                inline bool intersect(const vec3& pos_) const noexcept;
                inline bool intersect(const Box& box_) const noexcept;
                inline bool intersect(const Triangle& tri_) const noexcept;

                //  -- Collision --
                inline std::optional<double> collision(const vec3& pos_, const vec3& dir_) const noexcept override;
            };



        } // namespace shape
    }     // namespace geom
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/geom/shape/box.inl>



//  == GUARD END ==
#endif // ARCTK_GEOM_SHAPE_BOX_HPP
