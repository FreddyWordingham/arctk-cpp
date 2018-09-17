/**
 *  @file   arctk/data/node/branch.hpp
 *  @date   17/09/2018
 *  @author Freddy Wordingham
 *
 *  Branch node class.
 */



//  == GUARD ==
#ifndef ARCTK_GRID_NODE_BRANCH_HPP
#define ARCTK_GRID_NODE_BRANCH_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <memory>

//  -- Arctk --
#include <arctk/array.hpp>
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
             *  Branch node class.
             */
            class Branch : public Node
            {
                //  == FIELDS ==
              private:
                //  -- Positioning --
                const vec3 _centre;

                //  -- Children --
                const std::array<std::unique_ptr<Node>, 8> _childs;



                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



        } // namespace node
    }     // namespace grid
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GRID_NODE_BRANCH_HPP
