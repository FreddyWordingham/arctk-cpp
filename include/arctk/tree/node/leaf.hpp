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



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/math.hpp>
#include <arctk/tree/node.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace mesh //! mesh namespace
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


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              public:
                //  -- Getters --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



            //  == METHODS ==
            //  -- Getters --



        } // namespace node
    }     // namespace mesh
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_NODE_LEAF_HPP
