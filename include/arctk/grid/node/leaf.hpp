/**
 *  @file   arctk/data/node/leaf.hpp
 *  @date   17/09/2018
 *  @author Freddy Wordingham
 *
 *  Leaf node class.
 */



//  == GUARD ==
#ifndef ARCTK_GRID_NODE_LEAF_HPP
#define ARCTK_GRID_NODE_LEAF_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/geom.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace grid //! grid namespace
    {
        namespace node //! node namespace
        {



            //  == CLASS ==
            /**
             *  Leaf node class.
             */
            class Leaf : public Node
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
                //  -- Retrieval --
                inline Leaf const* leaf(const vec3& pos_) const noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



            //  == METHODS ==
            //  -- Retrieval --
            inline Leaf const* Branch::leaf(const vec3& pos_) const noexcept
            {
                PRE(contains(pos_));

                return (this);
            }



        } // namespace node
    }     // namespace grid
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GRID_NODE_LEAF_HPP
