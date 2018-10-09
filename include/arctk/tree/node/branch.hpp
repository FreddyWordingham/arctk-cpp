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



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <functional>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/equip.hpp>
#include <arctk/geom.hpp>
#include <arctk/math.hpp>
#include <arctk/tree/node.hpp>
#include <arctk/tree/node/leaf.hpp>
#include <arctk/utl.hpp>



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
                const std::array<std::array<std::array<std::reference_wrapper<Node>, 2>, 2>, 2> _childs;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Branch(const vec3& min_, const vec3& max_, const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>>& ents_, size_t cur_depth_, size_t max_depth_, size_t tar_tris_) noexcept;


                //  == METHODS ==
              public:
                //  -- Retrieval --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Branch::Branch(const vec3& min_, const vec3& max_, const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>>& ents_, const size_t cur_depth_, const size_t max_depth_, const size_t tar_tris_) noexcept
              : Node(min_, max_, cur_depth_)
              , _centre((min_ + max_) / 2.0)
              , _childs(init_childs(min_, max_, ents_, cur_depth_, max_depth_, tar_tris_))
            {
                PRE(min_.x <= max_.x);
                PRE(min_.y <= max_.y);
                PRE(min_.z <= max_.z);
                PRE(cur_depth_ > 0);
            }

            //  -- Initialisation --



            //  == METHODS ==
            //  -- Retrieval --



        } // namespace node
    }     // namespace tree
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_NODE_BRANCH_HPP
