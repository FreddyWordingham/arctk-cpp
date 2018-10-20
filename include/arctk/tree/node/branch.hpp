/**
 *  @file   arctk/tree/node/branch.hpp
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Branch node class.
 */



//  == GUARD ==
#ifndef ARCTK_TREE_NODE_BRANCH_HPP
#define ARCTK_TREE_NODE_BRANCH_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cassert>
#include <memory>

//  -- Arctk --
#include <arctk/equip.hpp>
#include <arctk/geom.hpp>
#include <arctk/math.hpp>
#include <arctk/tree/node.hpp>
#include <arctk/tree/node/leaf.hpp>
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace tree //! tree namespace
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
                const vec3 _centre; //!< Centre coordinate of the node.

                //  -- Children --
                const std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> _childs; //!< Three-dimensional array of child nodes.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Branch(const vec3& min_, const vec3& max_, const std::vector<std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>>& ent_tris_, size_t cur_depth_, size_t max_depth_, size_t tar_tris_) noexcept;

              private:
                //  -- Initialisation --
                inline std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> init_childs(const vec3& min_, const vec3& max_, const std::vector<std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>>& ent_tris_, size_t cur_depth_,
                                                                                                      size_t max_depth_, size_t tar_tris_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline size_t                        max_depth() const noexcept override;
                inline size_t                        max_tris() const noexcept override;
                inline size_t                        num_nodes() const noexcept override;
                inline std::vector<geom::shape::Box> boxes() const noexcept override;

                //  -- Retrieval --
                inline const node::Leaf* leaf(const vec3& pos_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a branch tree node.
             *
             *  @param  min_        Minimum bound of the cell.
             *  @param  max_        Maximum bound of the cell.
             *  @param  ent_tris_   Vector of entity triangle list pairings that must intersect this node.
             *  @param  cur_depth_  Depth of this node.
             *  @param  max_depth_  Maximum depth of the tree.
             *  @param  tar_tris_   Target number of triangles for each leaf node.
             *
             *  @pre    min_.x must be less than, or equal to, max_.x.
             *  @pre    min_.y must be less than, or equal to, max_.y.
             *  @pre    min_.z must be less than, or equal to, max_.z.
             *  @pre    tar_tris_ must be positive.
             */
            inline Branch::Branch(const vec3& min_, const vec3& max_, const std::vector<std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>>& ent_tris_, const size_t cur_depth_, const size_t max_depth_, const size_t tar_tris_) noexcept
              : Node(min_, max_, cur_depth_)
              , _centre((min_ + max_) / 2.0)
              , _childs(init_childs(min_, max_, ent_tris_, cur_depth_, max_depth_, tar_tris_))
            {
                assert(min_.x <= max_.x);
                assert(min_.y <= max_.y);
                assert(min_.z <= max_.z);
                assert(cur_depth_ < max_depth_);
            }


            //  -- Initialisation --
            /**
             *  Initialise the three-dimensional array of child nodes.
             *
             *  @param  min_        Minimum bound of the cell.
             *  @param  max_        Maximum bound of the cell.
             *  @param  ent_tris_   Vector of entity triangle list pairings that must intersect this node.
             *  @param  cur_depth_  Depth of this node.
             *  @param  max_depth_  Maximum depth of the tree.
             *  @param  tar_tris_   Target number of triangles for each leaf node.
             *
             *  @pre    min_.x must be less than, or equal to, max_.x.
             *  @pre    min_.y must be less than, or equal to, max_.y.
             *  @pre    min_.z must be less than, or equal to, max_.z.
             *  @pre    tar_tris_ must be positive.
             *
             *  @return Initialised three-dimensional array of child nodes.
             */
            inline std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> Branch::init_childs(const vec3& min_, const vec3& max_, const std::vector<std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>>& ent_tris_, // NOLINT
                                                                                                          const size_t cur_depth_, const size_t max_depth_, const size_t tar_tris_) const noexcept
            {
                assert(min_.x <= max_.x);
                assert(min_.y <= max_.y);
                assert(min_.z <= max_.z);
                assert(cur_depth_ < max_depth_);

                std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> childs;

                const vec3 size                = (max_ - min_) / 2.0;
                const bool depth_limit_reached = cur_depth_ >= (max_depth_ - 1);

                for (size_t i = 0; i < 2; ++i)
                {
                    for (size_t j = 0; j < 2; ++j)
                    {
                        for (size_t k = 0; k < 2; ++k)
                        {
                            const vec3 min(min_.x + (static_cast<double>(i) * size.x), min_.y + (static_cast<double>(j) * size.y), min_.z + (static_cast<double>(k) * size.z));
                            const vec3 max = min + size;

                            const geom::shape::Box                                                            box(min, max);
                            std::vector<std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>> ent_tris;

                            for (size_t l = 0; l < ent_tris_.size(); ++l)
                            {
                                bool ent_intersect = false;

                                for (size_t m = 0; m < ent_tris_[l].second.size(); ++m)
                                {
                                    if (box.intersect(*ent_tris_[l].second[m]))
                                    {
                                        if (!ent_intersect)
                                        {
                                            ent_intersect = true;
                                            ent_tris.emplace_back(std::pair<equip::Entity*, std::vector<const geom::shape::Triangle*>>(ent_tris_[l].first, std::vector<const geom::shape::Triangle*>()));
                                        }

                                        ent_tris.back().second.emplace_back(ent_tris_[l].second[m]);
                                    }
                                }
                            }

                            size_t num_tris = 0;
                            for (size_t l = 0; l < ent_tris.size(); ++l)
                            {
                                num_tris += ent_tris[l].second.size();
                            }

                            if (depth_limit_reached || (num_tris <= tar_tris_))
                            {
                                childs[i][j][k] = std::make_unique<Leaf>(min, max, ent_tris, cur_depth_ + 1);
                            }
                            else
                            {
                                childs[i][j][k] = std::make_unique<Branch>(min, max, ent_tris, cur_depth_ + 1, max_depth_, tar_tris_);
                            }
                        }
                    }
                }

                return (childs);
            }



            //  == METHODS ==
            /**
             *  Get the maximum depth of any cell contained within this cell.
             *
             *  @return Maximum depth of any cell contained within this cell.
             */
            inline size_t Branch::max_depth() const noexcept
            {
                size_t max_depth = 0;

                for (size_t i = 0; i <= 1; ++i)
                {
                    for (size_t j = 0; j <= 1; ++j)
                    {
                        for (size_t k = 0; k <= 1; ++k)
                        {
                            if (_childs[i][j][k]->max_depth() > max_depth)
                            {
                                max_depth = _childs[i][j][k]->max_depth();
                            }
                        }
                    }
                }

                return (max_depth);
            }

            /**
             *  Get the maximum number of triangles contained within any cell contained within this cell.
             *
             *  @return Maximum number of triangles contained within any cell contained within this cell.
             */
            inline size_t Branch::max_tris() const noexcept
            {
                size_t max_tris = 0;

                for (size_t i = 0; i <= 1; ++i)
                {
                    for (size_t j = 0; j <= 1; ++j)
                    {
                        for (size_t k = 0; k <= 1; ++k)
                        {
                            if (_childs[i][j][k]->max_tris() > max_tris)
                            {
                                max_tris = _childs[i][j][k]->max_tris();
                            }
                        }
                    }
                }

                return (max_tris);
            }

            /**
             *  Get the number of nodes contained within this node.
             *
             *  @return Number of nodes contained within this node.
             */
            inline size_t Branch::num_nodes() const noexcept
            {
                size_t num_nodes = 0;

                for (size_t i = 0; i <= 1; ++i)
                {
                    for (size_t j = 0; j <= 1; ++j)
                    {
                        for (size_t k = 0; k <= 1; ++k)
                        {
                            num_nodes += _childs[i][j][k]->num_nodes();
                        }
                    }
                }

                return (num_nodes + 1);
            }

            /**
             *  Get a vector of box shapes representing all cells contained within this cell.
             *
             *  @return Vector of box shapes representing all cells contained within this cell.
             */
            inline std::vector<geom::shape::Box> Branch::boxes() const noexcept
            {
                std::vector<geom::shape::Box> boxes;

                for (size_t i = 0; i <= 1; ++i)
                {
                    for (size_t j = 0; j <= 1; ++j)
                    {
                        for (size_t k = 0; k <= 1; ++k)
                        {
                            std::vector<geom::shape::Box> child_boxes = _childs[i][j][k]->boxes();

                            utl::manip::move_append(boxes, child_boxes);
                        }
                    }
                }

                return (boxes);
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
            inline const node::Leaf* Branch::leaf(const vec3& pos_) const noexcept
            {
                assert(min_.x <= max_.x);
                assert(min_.y <= max_.y);
                assert(min_.z <= max_.z);
                assert(cur_depth_ < max_depth_);
                (intersect(pos_));

                return (_childs[(pos_.x < _centre.x) ? 0 : 1][(pos_.y < _centre.y) ? 0 : 1][(pos_.z < _centre.z) ? 0 : 1]->leaf(pos_));
            }



        } // namespace node
    }     // namespace tree
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_NODE_BRANCH_HPP
