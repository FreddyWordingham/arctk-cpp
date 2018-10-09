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
        class Root
        {
            //  == FIELDS ==
          protected:
            //  -- Depth --
            const std::unique_ptr<Node> _trunk;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Root(const vec3& min_, const vec3& max_, const std::vector<const equip::Entity*>& ents_, size_t max_depth_, size_t tar_tris_) noexcept;

          private:
            //  -- Initialsation --
            inline std::unique_ptr<Node> init_trunk(const vec3& min_, const vec3& max_, const std::vector<const equip::Entity*>& ents_, size_t max_depth_, size_t tar_tris_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Root::Root(const vec3& min_, const vec3& max_, const std::vector<const equip::Entity*>& ents_, const size_t max_depth_, const size_t tar_tris_) noexcept
          : _trunk(init_trunk(min_, max_, ents_, max_depth_, tar_tris_))
        {
            PRE(min_.x <= max_.x);
            PRE(min_.y <= max_.y);
            PRE(min_.z <= max_.z);
            PRE(max_depth_ > 0);
            PRE(tar_tris_ > 0);
        }


        //  -- Initialisation --
        inline std::unique_ptr<Node> Root::init_trunk(const vec3& min_, const vec3& max_, const std::vector<const equip::Entity*>& ents_, const size_t max_depth_, const size_t tar_tris_) const noexcept
        {
            std::vector<std::pair<const equip::Entity*, std::vector<const geom::shape::Triangle*>>> ent_tris;
            ent_tris.reserve(ents_.size());

            size_t                 num_tris = 0;
            const geom::shape::Box box(min_, max_);
            for (size_t i = 0; i < ent_tris.size(); ++i)
            {
                bool entry = false;
                for (size_t j = 0; j < ents_[i]->num_faces; ++j)
                {
                    if (box.intersect(*ents_[i]->tri[j]))
                    {
                        if (!entry)
                        {
                            entry = true;
                            ent_tris.emplace_back(std::pair<const equip::Entity*, std::vector<const geom::shape::Triangle*>>(ents_[i], std::vector<const geom::shape::Triangle*>()));
                        }

                        ent_tris.back().second.emplace_back(ents_[i]->tri[j]);
                        ++num_tris;
                    }
                }
            }

            if ((max_depth_ == 0) || (num_tris <= tar_tris_))
            {
                return (std::make_unique<Leaf>(min_, max_, ent_tris, 0));
            }

            return (std::make_unique<Branch>(min_, max_, ent_tris, 0, max_depth_, tar_tris_));
        }



        //  == METHODS ==
        //  -- Getters --



    } // namespace tree
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_ROOT_HPP
