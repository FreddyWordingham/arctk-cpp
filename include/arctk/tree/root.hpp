/**
 *  @file   arctk/tree/root.hpp
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Tree root class.
 */



//  == GUARD ==
#ifndef ARCTK_TREE_ROOT_HPP
#define ARCTK_TREE_ROOT_HPP



//  == IMPORTS ==
//  -- Std --
#include <memory>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/geom.hpp>
#include <arctk/math.hpp>
#include <arctk/tree/node.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace tree //! tree namespace
    {



        //  == CLASS ==
        /**
         *  Tree node base class.
         */
        class Root : public geom::shape::Box
        {
            //  == FIELDS ==
          protected:
            //  -- Depth --
            const std::unique_ptr<Node>& _trunk;


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



    } // namespace tree
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_ROOT_HPP
