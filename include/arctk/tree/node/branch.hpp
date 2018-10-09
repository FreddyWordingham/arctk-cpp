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
#include <memory>

//  -- Arctk --
#include <arctk/debug.hpp>
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
                const std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> _childs;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Branch(const vec3& min_, const vec3& max_, const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>>& tris_, size_t cur_depth_, size_t max_depth_, size_t tar_tris_) noexcept;

              private:
                //  -- Initialisation --
                inline std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> init_childs(const vec3& min_, const vec3& max_, const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>>& tris_, size_t cur_depth_,
                                                                                                      size_t max_depth_, size_t tar_tris_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline size_t                        max_depth() const noexcept override;
                inline size_t                        max_shapes() const noexcept override;
                inline size_t                        num_nodes() const noexcept override;
                inline std::vector<geom::shape::Box> boxes() const noexcept override;

                //  -- Retrieval --
                inline const node::Leaf& leaf(const vec3& pos_) const noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Branch::Branch(const vec3& min_, const vec3& max_, const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>>& tris_, const size_t cur_depth_, const size_t max_depth_, const size_t tar_tris_) noexcept
              : Node(min_, max_, cur_depth_)
              , _centre((min_ + max_) / 2.0)
              , _childs(init_childs(min_, max_, tris_, cur_depth_, max_depth_, tar_tris_))
            {
                PRE(min_.x <= max_.x);
                PRE(min_.y <= max_.y);
                PRE(min_.z <= max_.z);
                PRE(cur_depth_ > 0);
            }


            //  -- Initialisation --
            inline std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> Branch::init_childs(const vec3& min_, const vec3& max_, const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>>& tris_, const size_t cur_depth_,
                                                                                                          const size_t max_depth_, const size_t tar_tris_) const noexcept
            {
                std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> childs;

                const vec3 size                = half_width();
                const bool depth_limit_reached = cur_depth_ >= max_depth_;

                for (size_t i = 0; i < 2; ++i)
                {
                    for (size_t j = 0; j < 2; ++j)
                    {
                        for (size_t k = 0; k < 2; ++k)
                        {
                            const vec3 min(min_.x + (i * size.x), min_.y + (j * size.y), min_.z + (k * size.z));
                            const vec3 max = min + size;

                            const geom::shape::Box                                                     box(min, max);
                            std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>> tris;

                            for (size_t l = 0; l < tris_.size(); ++l)
                            {
                                if (box.intersect(tris_[l].second))
                                {
                                    tris.emplace_back(tris_[l]);
                                }
                            }

                            if (depth_limit_reached || (tris.size() <= tar_tris_))
                            {
                                childs[i][j][k] = std::make_unique<Leaf>(min, max, tris, cur_depth_ + 1);
                            }
                            else
                            {
                                childs[i][j][k] = std::make_unique<Branch>(min, max, tris, cur_depth_ + 1, max_depth_, tar_tris_);
                            }
                        }
                    }
                }

                return (childs);
            }



            //  == METHODS ==
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

            inline size_t Branch::max_shapes() const noexcept
            {
            }

            inline size_t Branch::num_nodes() const noexcept
            {
            }

            inline std::vector<geom::shape::Box> Branch::boxes() const noexcept
            {
            }



            //  -- Retrieval --
            inline const node::Leaf& Branch::leaf(const vec3& pos_) const noexcept
            {
                PRE(intersect(pos_));

                return (_childs[(pos_.x < _centre.x) ? 0 : 1][(pos_.y < _centre.y) ? 0 : 1][(pos_.z < _centre.z) ? 0 : 1]->leaf(pos_));
            }



        } // namespace node
    }     // namespace tree
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TREE_NODE_BRANCH_HPP
