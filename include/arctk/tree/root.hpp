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
            inline Root(const vec3& min_, const vec3& max_, const std::vector<const equip::Entity*>& ents_, size_t max_depth_, size_t tar_tris_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Root::Root(const vec3& min_, const vec3& max_, const std::vector<const equip::Entity*>& ents_, const size_t max_depth_, const size_t tar_tris_) noexcept
          : _trunk(init_trunk())
        {
            PRE(min_.x <= max_.x);
            PRE(min_.y <= max_.y);
            PRE(min_.z <= max_.z);
            PRE(max_depth_ > 0);
            PRE(tar_tris_ > 0);
        }



        //  == METHODS ==
        //  -- Getters --



    } // namespace tree
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_ROOT_HPP
