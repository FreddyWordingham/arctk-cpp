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
#include <arctk/geom.hpp>
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
                const std::vector<std::pair<const equip::Entity&, std::vector<const geom::shape::Triangle*>>> _ent_tris;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Leaf(const vec3& min_, const vec3& max_, const std::vector<std::pair<const equip::Entity&, std::vector<const geom::shape::Triangle*>>>& ent_tris_, size_t cur_depth_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline size_t                        max_depth() const noexcept override;
                inline size_t                        max_tris() const noexcept override;
                inline size_t                        num_nodes() const noexcept override;
                inline std::vector<geom::shape::Box> boxes() const noexcept override;

                //  -- Retrieval --
                inline const node::Leaf& leaf(const vec3& pos_) const noexcept override;

                //  -- Collision --
                inline std::optional<std::pair<std::reference_wrapper<const equip::Entity>, double>>          ent_collision(const vec3& pos_, const vec3& dir_) const noexcept;
                inline std::optional<std::pair<std::reference_wrapper<const equip::Entity>, geom::Collision>> ent_collision_info(const vec3& pos_, const vec3& dir_) const noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Leaf::Leaf(const vec3& min_, const vec3& max_, const std::vector<std::pair<const equip::Entity&, std::vector<const geom::shape::Triangle*>>>& ent_tris_, const size_t cur_depth_) noexcept
              : Node(min_, max_, cur_depth_)
              , _ent_tris(ent_tris_)
            {
                PRE(min_.x <= max_.x);
                PRE(min_.y <= max_.y);
                PRE(min_.z <= max_.z);
                PRE(cur_depth_ > 1);

                // TODO
            }



            //  == METHODS ==
            //  -- Getters --
            inline size_t Leaf::max_depth() const noexcept
            {
                return (_depth);
            }

            inline size_t Leaf::max_tris() const noexcept
            {
                size_t tris = 0;
                for (size_t i = 0; i < _ent_tris.size(); ++i)
                {
                    tris += _ent_tris[i].second.size();
                }

                return (tris);
            }

            inline size_t Leaf::num_nodes() const noexcept
            {
                return (1);
            }

            inline std::vector<geom::shape::Box> Leaf::boxes() const noexcept
            {
                return (std::vector<geom::shape::Box>({geom::shape::Box(_min, _max)}));
            }


            //  -- Retrieval --
            inline const node::Leaf& Leaf::leaf(const vec3& pos_) const noexcept
            {
                return (*this);
            }


            //  -- Collision --
            inline std::optional<std::pair<std::reference_wrapper<const equip::Entity>, double>> Leaf::ent_collision(const vec3& pos_, const vec3& dir_) const noexcept
            {
                std::optional<std::pair<std::reference_wrapper<const equip::Entity>, double>> coll(std::nullopt);

                return (coll);
            }

            inline std::optional<std::pair<std::reference_wrapper<const equip::Entity>, geom::Collision>> Leaf::ent_collision_info(const vec3& pos_, const vec3& dir_) const noexcept
            {
                std::optional<std::pair<std::reference_wrapper<const equip::Entity>, geom::Collision>> coll(std::nullopt);

                return (coll);
            }



        } // namespace node
    }     // namespace tree
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_NODE_LEAF_HPP
