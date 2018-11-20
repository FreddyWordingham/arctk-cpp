/**
 *  @file   arctk/tree/node/branch.hpp
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Branch node class.
 */



//  == GUARD ==
#ifndef ARCTK_TREE_NODE_BRANCH_HPP
#define ARCTK_TREE_NODE_BRANCH_HPP



//  == BASE ==
#include <arctk/tree/node.hpp>



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cstddef>
#include <memory>
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/geom/shape/box.hpp>
#include <arctk/math/vec.hpp>



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
    namespace tree //! tree namespace
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
             *  Branch node class.
             */
            class Branch : public Node
            {
                //  == FIELDS ==
              private:
                //  -- Positioning --
                const vec3 _centre; //!< Centre coordinate of the node.

                //  -- Children --
                const std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> _childs; //!< Three-dimensional array of child nodes.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Branch(const vec3& min_, const vec3& max_, const std::vector<std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>>& ent_tris_, size_t cur_depth_, size_t max_depth_, size_t tar_tris_) noexcept;

              private:
                //  -- Initialisation --
                inline std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> init_childs(const vec3& min_, const vec3& max_, const std::vector<std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>>& ent_tris_, size_t cur_depth_,
                                                                                                      size_t max_depth_, size_t tar_tris_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline size_t                        max_depth() const noexcept override;
                inline size_t                        max_tris() const noexcept override;
                inline size_t                        num_nodes() const noexcept override;
                inline std::vector<geom::shape::Box> boxes() const noexcept override;

                //  -- Retrieval --
                inline const node::Leaf* leaf(const vec3& pos_) const noexcept override;
            };



        } // namespace node
    }     // namespace tree
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/tree/node/branch.inl>



//  == GUARD END ==
#endif // ARCTK_TREE_NODE_BRANCH_HPP
