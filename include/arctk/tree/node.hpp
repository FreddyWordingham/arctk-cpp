/**
 *  @file   arctk/tree/node.hpp
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Tree node base class.
 */



//  == GUARD ==
#ifndef ARCTK_TREE_NODE_HPP
#define ARCTK_TREE_NODE_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/geom.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace mesh //! mesh namespace
    {
        namespace node //! node namespace
        {



            //  == CLASS PROTOTYPES ==
            class Leaf;



        } // namespace node



        //  == CLASS ==
        /**
         *  Tree node base class.
         */
        class Node : public geom::shape::Aabb
        {
            //  == FIELDS ==
          private:
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



    } // namespace mesh
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_NODE_HPP
