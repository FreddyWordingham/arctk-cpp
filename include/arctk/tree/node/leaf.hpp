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
                const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>> _tris;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Leaf(const vec3& min_, const vec3& max_, const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>>& tris_, size_t cur_depth_) noexcept;


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
                inline std::optional<std::pair<double, const equip::Entity*>>          ent_collision(const vec3& pos_, const vec3& dir_) const noexcept;
                inline std::optional<std::pair<geom::Collision, const equip::Entity*>> ent_collision_info(const vec3& pos_, const vec3& dir_) const noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Leaf::Leaf(const vec3& min_, const vec3& max_, const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>>& tris_, const size_t cur_depth_) noexcept
              : Node(min_, max_, cur_depth_)
              , _tris(tris_)
            {
                PRE(min_.x <= max_.x);
                PRE(min_.y <= max_.y);
                PRE(min_.z <= max_.z);
                PRE(cur_depth_ > 1);

                for (size_t i = 0; i < _tris.size(); ++i)
                {
                    POST(intersect(_tris[i].second));
                }
            }



            //  == METHODS ==
            //  -- Getters --
            inline size_t Leaf::max_depth() const noexcept
            {
                return (_depth);
            }

            inline size_t Leaf::max_tris() const noexcept
            {
                return (_tris.size());
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
            inline std::optional<std::pair<double, const equip::Entity*>> Leaf::ent_collision(const vec3& pos_, const vec3& dir_) const noexcept
            {
                std::optional<std::pair<double, const equip::Entity*>> coll(std::nullopt);

                for (size_t i = 0; i < _tris.size(); ++i)
                {
                    const std::optional<double> tri_col = _tris[i].second.collision(pos_, dir_);

                    if (tri_col && (!coll || (tri_col.value() < coll.value().first)))
                    {
                        coll = std::optional<std::pair<double, const equip::Entity*>>(std::pair<double, const equip::Entity*>(tri_col.value(), &_tris[i].first));
                    }
                }

                return (coll);
            }

            inline std::optional<std::pair<geom::Collision, const equip::Entity*>> Leaf::ent_collision_info(const vec3& pos_, const vec3& dir_) const noexcept
            {
            }



        } // namespace node
    }     // namespace tree
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_NODE_LEAF_HPP
