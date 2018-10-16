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
                const std::vector<std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>> _ent_tris; //!< Vector of entity triangle list pairings that intersect this node.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Leaf(const vec3& min_, const vec3& max_, const std::vector<std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>>& ent_tris_, size_t cur_depth_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline size_t                        max_depth() const noexcept override;
                inline size_t                        max_tris() const noexcept override;
                inline size_t                        num_nodes() const noexcept override;
                inline std::vector<geom::shape::Box> boxes() const noexcept override;

                //  -- Retrieval --
                inline const node::Leaf* leaf(const vec3& pos_) const noexcept override;

                //  -- Collision --
                inline std::optional<std::pair<equip::Entity*, double>>          ent_collision(const vec3& pos_, const vec3& dir_) const noexcept;
                inline std::optional<std::pair<equip::Entity*, geom::Collision>> ent_collision_info(const vec3& pos_, const vec3& dir_) const noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a leaf tree node.
             *
             *  @param  min_        Minimum bound of the cell.
             *  @param  max_        Maximum bound of the cell.
             *  @param  ent_tris_   Vector of entity triangle list pairings that must intersect this node.
             *  @param  cur_depth_  Depth of this node.
             *
             *  @pre    min_.x must be less than, or equal to, max_.x.
             *  @pre    min_.y must be less than, or equal to, max_.y.
             *  @pre    min_.z must be less than, or equal to, max_.z.
             *  @pre    Each triangle within ent_tris_ must intersec this node.
             */
            inline Leaf::Leaf(const vec3& min_, const vec3& max_, const std::vector<std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>>& ent_tris_, const size_t cur_depth_) noexcept
              : Node(min_, max_, cur_depth_)
              , _ent_tris(ent_tris_)
            {
                PRE(min_.x <= max_.x);
                PRE(min_.y <= max_.y);
                PRE(min_.z <= max_.z);
                for (size_t i = 0; i < ent_tris_.size(); ++i)
                {
                    PRE(!ent_tris_[i].second.empty());

                    for (size_t j = 0; j < ent_tris_[i].second.size(); ++j)
                    {
                        PRE(intersect(*ent_tris_[i].second[j]));
                    }
                }
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the maximum depth of any cell contained within this cell.
             *
             *  @return Maximum depth of any cell contained within this cell.
             */
            inline size_t Leaf::max_depth() const noexcept
            {
                return (_depth);
            }

            /**
             *  Get the maximum number of triangles contained within any cell contained within this cell.
             *
             *  @return Maximum number of triangles contained within any cell contained within this cell.
             */
            inline size_t Leaf::max_tris() const noexcept
            {
                size_t tris = 0;
                for (size_t i = 0; i < _ent_tris.size(); ++i)
                {
                    tris += _ent_tris[i].second.size();
                }

                return (tris);
            }

            /**
             *  Get the number of nodes contained within this node.
             *
             *  @return Number of nodes contained within this node.
             */
            inline size_t Leaf::num_nodes() const noexcept
            {
                return (1);
            }

            /**
             *  Get a vector of box shapes representing all cells contained within this cell.
             *
             *  @return Vector of box shapes representing all cells contained within this cell.
             */
            inline std::vector<geom::shape::Box> Leaf::boxes() const noexcept
            {
                return (std::vector<geom::shape::Box>({geom::shape::Box(_min, _max)}));
            }


            //  -- Retrieval --
            /**
             *  Retrieve a pointer to the leaf cell for the given position.
             *
             *  @param  pos_    Position to retrieve the corresponding leaf cell for.
             *
             *  @pre    pos_ must intersect this node.
             *
             *  @return Pointer to the leaf cell for the given position.
             */
            inline const node::Leaf* Leaf::leaf(const vec3& pos_) const noexcept
            {
                PRE(intersect(pos_));

                return (this);
            }


            //  -- Collision --
            /**
             *  Determine the entity and distance to the collision event (if there is one) of a ray.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Entity and distance to the collision event (if there is one) of a ray.
             */
            inline std::optional<std::pair<equip::Entity*, double>> Leaf::ent_collision(const vec3& pos_, const vec3& dir_) const noexcept // NOLINT
            {
                PRE(dir_.normalised());

                std::optional<std::pair<equip::Entity*, double>> coll(std::nullopt);

                for (size_t i = 0; i < _ent_tris.size(); ++i)
                {
                    for (size_t j = 0; j < _ent_tris[i].second.size(); ++j)
                    {
                        std::optional<double> tri_coll = _ent_tris[i].second[j]->collision(pos_, dir_);

                        if (tri_coll && (!coll || (tri_coll.value() < coll.value().second)))
                        {
                            coll = std::optional<std::pair<equip::Entity*, double>>(std::pair<equip::Entity*, double>(_ent_tris[i].first, tri_coll.value()));
                        }
                    }
                }

                return (coll);
            }

            /**
             *  Determine the entity and information about a collision event (if there is one) of a ray.
             *
             *  @param  pos_    Position of the ray.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    dir_ must be normalised.
             *
             *  @return Entity and information about a collision event (if there is one) of a ray.
             */
            inline std::optional<std::pair<equip::Entity*, geom::Collision>> Leaf::ent_collision_info(const vec3& pos_, const vec3& dir_) const noexcept
            {
                PRE(dir_.normalised());

                std::optional<std::pair<equip::Entity*, geom::Collision>> coll(std::nullopt);

                for (size_t i = 0; i < _ent_tris.size(); ++i)
                {
                    for (size_t j = 0; j < _ent_tris[i].second.size(); ++j)
                    {
                        std::optional<geom::Collision> tri_coll = _ent_tris[i].second[j]->collision_info(pos_, dir_);

                        if (tri_coll && (!coll || (tri_coll.value().dist() < coll.value().second.dist())))
                        {
                            coll = std::optional<std::pair<equip::Entity*, geom::Collision>>(std::pair<equip::Entity*, geom::Collision>(_ent_tris[i].first, tri_coll.value()));
                        }
                    }
                }

                return (coll);
            }



        } // namespace node
    }     // namespace tree
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_NODE_LEAF_HPP
