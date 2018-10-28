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
#include <cstddef>
#include <memory>
#include <vector>

//  -- Arctk --
#include <arctk/equip/entity.hpp>
#include <arctk/geom/shape/box.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        template <typename T, size_t N>
        class Vec;
    }                                  // namespace math
    using vec3 = math::Vec<double, 3>; //!< Three-dimensional double precision vec.
    namespace tree                     //! tree namespace
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



        //  == CLASS ==
        /**
         *  Tree node base class.
         */
        class Root
        {
            //  == FIELDS ==
          protected:
            //  -- Depth --
            const std::unique_ptr<Node> _trunk; //!< Unique pointer to the trunk node.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Root(const vec3& min_, const vec3& max_, const std::vector<std::unique_ptr<equip::Entity>>& ents_, size_t max_depth_, size_t tar_tris_) noexcept;

          private:
            //  -- Initialsation --
            inline std::unique_ptr<Node> init_trunk(const vec3& min_, const vec3& max_, const std::vector<std::unique_ptr<equip::Entity>>& ents_, size_t max_depth_, size_t tar_tris_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const vec3&                   min() const noexcept;
            inline const vec3&                   max() const noexcept;
            inline size_t                        max_depth() const noexcept;
            inline size_t                        max_tris() const noexcept;
            inline size_t                        num_nodes() const noexcept;
            inline std::vector<geom::shape::Box> boxes() const noexcept;

            //  -- Retrieval --
            inline const node::Leaf* leaf(const vec3& pos_) const noexcept;
        };



    } // namespace tree
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/tree/root.inl>



//  == GUARD END ==
#endif // ARCTK_TREE_ROOT_HPP
