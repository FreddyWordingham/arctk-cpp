/**
 *  @file   arctk/tree/root.inl
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Tree root class.
 */



//  == GUARD ==
#ifndef ARCTK_TREE_ROOT_INL
#define ARCTK_TREE_ROOT_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <utility>

//  -- Arctk --
#include <arctk/equip/entity.hpp>
#include <arctk/geom/shape/triangle.hpp>
#include <arctk/math/vec3.hpp>
#include <arctk/tree/node.hpp>
#include <arctk/tree/node/branch.hpp>
#include <arctk/tree/node/leaf.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace tree //! tree namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct the root node of a tree.
         *
         *  @param  min_        Minimum bound of the cell.
         *  @param  max_        Maximum bound of the cell.
         *  @param  ents_       Vector of entities.
         *  @param  max_depth_  Maximum depth of the tree.
         *  @param  tar_tris_   Target number of triangles for each leaf node.
         *
         *  @pre    min_.x must be less than, or equal to, max_.x.
         *  @pre    min_.y must be less than, or equal to, max_.y.
         *  @pre    min_.z must be less than, or equal to, max_.z.
         *  @pre    tar_tris_ must be positive.
         */
        inline Root::Root(const vec3& min_, const vec3& max_, const std::vector<std::unique_ptr<equip::Entity>>& ents_, const size_t max_depth_, const size_t tar_tris_) noexcept
          : _trunk(init_trunk(min_, max_, ents_, max_depth_, tar_tris_))
        {
            assert(min_.x <= max_.x);
            assert(min_.y <= max_.y);
            assert(min_.z <= max_.z);
            assert(tar_tris_ > 0);
        }


        //  -- Initialisation --
        /**
         *  Initialise the trunk node of the tree.
         *
         *  @param  min_        Minimum bound of the cell.
         *  @param  max_        Maximum bound of the cell.
         *  @param  ents_       Vector of entities.
         *  @param  max_depth_  Maximum depth of the tree.
         *  @param  tar_tris_   Target number of triangles for each leaf node.
         *
         *  @pre    min_.x must be less than, or equal to, max_.x.
         *  @pre    min_.y must be less than, or equal to, max_.y.
         *  @pre    min_.z must be less than, or equal to, max_.z.
         *  @pre    tar_tris_ must be positive.
         *
         *  @return Trunk node of the tree.
         */
        inline std::unique_ptr<Node> Root::init_trunk(const vec3& min_, const vec3& max_, const std::vector<std::unique_ptr<equip::Entity>>& ents_, const size_t max_depth_, const size_t tar_tris_) const noexcept
        {
            assert(min_.x <= max_.x);
            assert(min_.y <= max_.y);
            assert(min_.z <= max_.z);
            assert(tar_tris_ > 0);

            std::vector<std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>> ent_tris;
            ent_tris.reserve(ents_.size());

            size_t                 num_tris = 0;
            const geom::shape::Box box(min_, max_);
            for (size_t i = 0; i < ents_.size(); ++i)
            {
                bool entry = false;
                for (size_t j = 0; j < ents_[i]->surf().num_faces(); ++j)
                {
                    if (box.intersect(ents_[i]->surf().tri(j)))
                    {
                        if (!entry)
                        {
                            entry = true;
                            ent_tris.emplace_back(std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>(ents_[i].get(), std::vector<const geom::shape::Triangle*>()));
                        }

                        ent_tris.back().second.emplace_back(&ents_[i]->surf().tri(j));
                        ++num_tris;
                    }
                }
            }

            if ((max_depth_ == 0) || (num_tris <= tar_tris_))
            {
                return (std::make_unique<node::Leaf>(min_, max_, ent_tris, 0));
            }

            return (std::make_unique<node::Branch>(min_, max_, ent_tris, 0, max_depth_, tar_tris_));
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the minimum bound of the root.
         *
         *  @return Minimum bound of the root.
         */
        inline const vec3& Root::min() const noexcept
        {
            return (_trunk->min());
        }

        /**
         *  Get the maximum bound of the root.
         *
         *  @return Maximum bound of the root.
         */
        inline const vec3& Root::max() const noexcept
        {
            return (_trunk->max());
        }

        /**
         *  Get the maximum depth of any cell contained within this cell.
         *
         *  @return Maximum depth of any cell contained within this cell.
         */
        inline size_t Root::max_depth() const noexcept
        {
            return (_trunk->max_depth());
        }

        /**
         *  Get the maximum number of triangles contained within any cell contained within this cell.
         *
         *  @return Maximum number of triangles contained within any cell contained within this cell.
         */
        inline size_t Root::max_tris() const noexcept
        {
            return (_trunk->max_tris());
        }

        /**
         *  Get the number of nodes contained within this node.
         *
         *  @return Number of nodes contained within this node.
         */
        inline size_t Root::num_nodes() const noexcept
        {
            return (_trunk->num_nodes());
        }

        /**
         *  Get a vector of box shapes representing all cells contained within this cell.
         *
         *  @return Vector of box shapes representing all cells contained within this cell.
         */
        inline std::vector<geom::shape::Box> Root::boxes() const noexcept
        {
            return (_trunk->boxes());
        }


        //  -- Retrieval --
        /**
         *  Retrieve a pointer to the leaf cell for the given position.
         *
         *  @param  pos_    Position to retrieve the corresponding leaf cell for.
         *
         *  @return Pointer to the leaf cell for the given position.
         */
        inline const node::Leaf* Root::leaf(const vec3& pos_) const noexcept
        {
            return (_trunk->leaf(pos_));
        }



    } // namespace tree
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_ROOT_INL
