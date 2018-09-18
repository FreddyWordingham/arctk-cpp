/**
 *  @file   arctk/data/node/branch.hpp
 *  @date   17/09/2018
 *  @author Freddy Wordingham
 *
 *  Branch node class.
 */



//  == GUARD ==
#ifndef ARCTK_GRID_NODE_BRANCH_HPP
#define ARCTK_GRID_NODE_BRANCH_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <memory>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/geom.hpp>
#include <arctk/grid/node/leaf.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace grid //! grid namespace
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
                const vec3 _centre;

                //  -- Children --
                const std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> _childs;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Branch(const vec3& min_, const vec3& max_, const std::vector<std::pair<const geom::Shape&, const equip::Light&>>& lights_, const std::vector<std::pair<const geom::Shape&, const equip::Entity&>>& entities_,
                              const std::vector<std::pair<const geom::Shape&, const equip::Detector&>>& detectors_) noexcept;


                //  == METHODS ==
              public:
                //  -- Retrieval --
                inline Leaf const* leaf(const vec3& pos_) const noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Branch::Branch(const vec3& min_, const vec3& max_, const std::vector<std::pair<const geom::Shape&, const equip::Light&>>& lights_, const std::vector<std::pair<const geom::Shape&, const equip::Entity&>>& entities_,
                                  const std::vector<std::pair<const geom::Shape&, const equip::Detector&>>& detectors_) noexcept
              : Node(min_, max_)
              , _centre(min_.x + max_.x / 2.0, min_.y + max_.y / 2.0, min_.z + max_.z / 2.0)
            {
                PRE(min_.x < max_.x);
                PRE(min_.y < max_.y);
                PRE(min_.z < max_.z);
                for (size_t i = 0; i < lights_.size(); ++i)
                {
                    PRE(lights_[i].first.intersect_vol(*this));
                }
                for (size_t i = 0; i < entities_.size(); ++i)
                {
                    PRE(entities_[i].first.intersect_vol(*this));
                }
                for (size_t i = 0; i < detectors_.size(); ++i)
                {
                    PRE(detectors_[i].first.intersect_vol(*this));
                }
            }



            //  == METHODS ==
            //  -- Retrieval --
            inline Leaf const* Branch::leaf(const vec3& pos_) const noexcept
            {
                PRE(contains(pos_));

                return (_childs[(pos_.x < _centre.x) ? 0 : 1][(pos_.y < _centre.y) ? 0 : 1][(pos_.z < _centre.z) ? 0 : 1]->leaf(pos_));
            }



        } // namespace node
    }     // namespace grid
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GRID_NODE_BRANCH_HPP
