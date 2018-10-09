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
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/equip.hpp>
#include <arctk/math.hpp>
#include <arctk/tree/node.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace tree //! tree namespace
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
                const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>> _ents;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Leaf(const vec3& min_, const vec3& max_, const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>>& ents_, size_t cur_depth_) noexcept;

              private:
                //  -- Initialisation --
                inline std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>> init_ents(const vec3& min_, const vec3& max_, const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>>& ents_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Retrieval --
                const node::Leaf& leaf(const vec3& pos_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Leaf::Leaf(const vec3& min_, const vec3& max_, const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>>& ents_, const size_t cur_depth_) noexcept
              : Node(min_, max_, cur_depth_)
              , _ents(init_ents(min_, max_, ents_))
            {
                PRE(min_.x <= max_.x);
                PRE(min_.y <= max_.y);
                PRE(min_.z <= max_.z);
                PRE(cur_depth_ > 1);

                for (size_t i = 0; i < _ents.size(); ++i)
                {
                    POST(intersect(_ents[i].second));
                }
            }


            //  -- Initialisation --
            inline std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>> Leaf::init_ents(const vec3& min_, const vec3& max_, const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>>& ents_) const noexcept
            {
                std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>> ents;

                const Box box(min_, max_);
                for (size_t i = 0; i < ents_.size(); ++i)
                {
                    if (box.intersect(ents_[i].second))
                    {
                        ents.emplace_back(ents_[i]);
                    }
                }

                return (ents);
            }



            //  == METHODS ==
            //  -- Retrieval --
            const node::Leaf& Leaf::leaf(const vec3& pos_) const noexcept
            {
                return (*this);
            }



        } // namespace node
    }     // namespace tree
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_NODE_LEAF_HPP
