/**
 *  @file   arctk/tree/node.inl
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Tree node base class.
 */



//  == GUARD ==
#ifndef ARCTK_TREE_NODE_INL
#define ARCTK_TREE_NODE_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/math/vec.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace tree //! tree namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a node with given bounds and depth.
         *
         *  @param  min_    Minimum bound of the cell.
         *  @param  max_    Maximum bound of the cell.
         *  @param  depth_  Depth of the cell.
         *
         *  @pre    min_.x must be less than, or equal to, max_.x.
         *  @pre    min_.y must be less than, or equal to, max_.y.
         *  @pre    min_.z must be less than, or equal to, max_.z.
         */
        inline Node::Node(const vec3& min_, const vec3& max_, const size_t depth_) noexcept
          : Box(min_, max_)
          , _depth(depth_)
        {
            assert(min_.x <= max_.x);
            assert(min_.y <= max_.y);
            assert(min_.z <= max_.z);
        }


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Node::~Node() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the depth of the node.
         *
         *  @return Depth of the node.
         */
        inline size_t Node::depth() const noexcept
        {
            return (_depth);
        }



    } // namespace tree
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_NODE_INL
