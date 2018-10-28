/**
 *  @file   arctk/tree/node/leaf.hpp
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Leaf node class.
 */



//  == GUARD ==
#ifndef ARCTK_TREE_NODE_LEAF_HPP
#define ARCTK_TREE_NODE_LEAF_HPP



//  == BASE ==
#include <arctk/tree/node.hpp>



//  == IMPORTS ==
//  -- Std --
#include <cstddef>
#include <optional>
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/geom/collision.hpp>
#include <arctk/geom/shape/box.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace equip //! equipment namespace
    {
        class Entity;
    }              // namespace equip
    namespace geom //! geometry namespace
    {
        namespace shape //! shape namespace
        {
            class Triangle;
        }          // namespace shape
    }              // namespace geom
    namespace math //! mathematical namespace
    {
        template <typename T, size_t N>
        class Vec;
    }                                  // namespace math
    using vec3 = math::Vec<double, 3>; //!< Three-dimensional double precision vec.
    namespace tree                     //! tree namespace
    {
        namespace node //! node namespace
        {
            class Leaf;
        } // namespace node
    }     // namespace tree
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace tree //! tree namespace
    {
        namespace node //! node namespace
        {



            //  == CLASS ==
            /**
             *  Leaf node class.
             */
            class Leaf : public Node
            {
                //  == FIELDS ==
              private:
                //  -- Content --
                const std::vector<std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>> _ent_tris; //!< Vector of entity triangle list pairings that intersect this node.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Leaf(const vec3& min_, const vec3& max_, const std::vector<std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>>& ent_tris_, size_t cur_depth_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline size_t                        max_depth() const noexcept override;
                inline size_t                        max_tris() const noexcept override;
                inline size_t                        num_nodes() const noexcept override;
                inline std::vector<geom::shape::Box> boxes() const noexcept override;

                //  -- Retrieval --
                inline const node::Leaf* leaf(const vec3& pos_) const noexcept override;

                //  -- Collision --
                inline std::optional<std::pair<equip::Entity*, double>>          ent_collision(const vec3& pos_, const vec3& dir_) const noexcept; // NOLINT
                inline std::optional<std::pair<equip::Entity*, geom::Collision>> ent_collision_info(const vec3& pos_, const vec3& dir_) const noexcept;
            };



        } // namespace node
    }     // namespace tree
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/tree/node/leaf.inl>



//  == GUARD END ==
#endif // ARCTK_TREE_NODE_LEAF_HPP
