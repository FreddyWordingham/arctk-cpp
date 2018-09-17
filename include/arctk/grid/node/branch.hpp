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
            inline Branch::Branch(const vec3& min_, const vec& max_) noexcept
              : Node(min_, max_)
              , _centre(min_.x + max_.x / 2.0, min_.y + max_.y / 2.0, min_.z + max_.z / 2.0)
            {
                PRE(min_.x < max_.x);
                PRE(min_.y < max_.y);
                PRE(min_.z < max_.z);
            }



        } // namespace node
    }     // namespace grid
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GRID_NODE_BRANCH_HPP
