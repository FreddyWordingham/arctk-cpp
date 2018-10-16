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
#include <arctk/tree/node/branch.hpp>
#include <arctk/tree/node/leaf.hpp>



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
            PRE(min_.x <= max_.x);
            PRE(min_.y <= max_.y);
            PRE(min_.z <= max_.z);
            PRE(tar_tris_ > 0);
        }


        //  -- Initialisation --
        inline std::unique_ptr<Node> Root::init_trunk(const vec3& min_, const vec3& max_, const std::vector<std::unique_ptr<equip::Entity>>& ents_, const size_t max_depth_, const size_t tar_tris_) const noexcept
        {
            std::vector<std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>> ent_tris;
            ent_tris.reserve(ents_.size());

            size_t                 num_tris = 0;
            const geom::shape::Box box(min_, max_);
            for (size_t i = 0; i < ents_.size(); ++i)
            {
                bool entry = false;
                for (size_t j = 0; j < ents_[i]->num_faces(); ++j)
                {
                    if (box.intersect(ents_[i]->tri(j)))
                    {
                        if (!entry)
                        {
                            entry = true;
                            ent_tris.emplace_back(std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>(ents_[i].get(), std::vector<const geom::shape::Triangle*>()));
                        }

                        ent_tris.back().second.emplace_back(&ents_[i]->tri(j));
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
        inline const vec3& Root::min() const noexcept
        {
            return (_trunk->min());
        }

        inline const vec3& Root::max() const noexcept
        {
            return (_trunk->max());
        }

        inline size_t Root::max_depth() const noexcept
        {
            return (_trunk->max_depth());
        }

        inline size_t Root::max_tris() const noexcept
        {
            return (_trunk->max_tris());
        }

        inline size_t Root::num_nodes() const noexcept
        {
            return (_trunk->num_nodes());
        }

        inline std::vector<geom::shape::Box> Root::boxes() const noexcept
        {
            return (_trunk->boxes());
        }


        //  -- Retrieval --
        inline const node::Leaf* Root::leaf(const vec3& pos_) const noexcept
        {
            return (_trunk->leaf(pos_));
        }



    } // namespace tree
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_ROOT_HPP
