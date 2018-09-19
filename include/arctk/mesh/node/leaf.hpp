/**
 *  @file   arctk/mesh/node/leaf.hpp
 *  @date   17/09/2018
 *  @author Freddy Wordingham
 *
 *  Leaf node class.
 */



//  == GUARD ==
#ifndef ARCTK_MESH_NODE_LEAF_HPP
#define ARCTK_MESH_NODE_LEAF_HPP



//  == IMPORTS ==
//  -- Std --
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/equip.hpp>
#include <arctk/geom.hpp>
#include <arctk/math.hpp>
#include <arctk/mesh/node.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace mesh //! mesh namespace
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
                const std::vector<std::pair<const geom::Shape&, const equip::Light&>>    _lights;
                const std::vector<std::pair<const geom::Shape&, const equip::Entity&>>   _entities;
                const std::vector<std::pair<const geom::Shape&, const equip::Detector&>> _detectors;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Leaf(const vec3& min_, const vec3& max_, const std::vector<std::pair<const geom::Shape&, const equip::Light&>>& lights_, const std::vector<std::pair<const geom::Shape&, const equip::Entity&>>& entities_,
                            const std::vector<std::pair<const geom::Shape&, const equip::Detector&>>& detectors_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline size_t                         num_nodes() const noexcept override;
                inline size_t                         max_shapes() const noexcept override;
                inline size_t                         max_depth() const noexcept override;
                inline std::vector<geom::shape::Aabb> boxes() const noexcept override;

                //  -- Retrieval --
                inline Leaf const* leaf(const vec3& pos_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Leaf::Leaf(const vec3& min_, const vec3& max_, const std::vector<std::pair<const geom::Shape&, const equip::Light&>>& lights_, const std::vector<std::pair<const geom::Shape&, const equip::Entity&>>& entities_,
                              const std::vector<std::pair<const geom::Shape&, const equip::Detector&>>& detectors_) noexcept
              : Node(min_, max_)
              , _lights(lights_)
              , _entities(entities_)
              , _detectors(detectors_)
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
            //  -- Getters --
            inline size_t Leaf::num_nodes() const noexcept
            {
                return (1);
            }

            inline size_t Leaf::max_shapes() const noexcept
            {
            }

            inline size_t Leaf::max_depth() const noexcept
            {
            }

            inline std::vector<geom::shape::Aabb> Leaf::boxes() const noexcept
            {
                return (std::vector<geom::shape::Aabb>({geom::shape::Aabb(_min, _max)}));
            }


            //  -- Retrieval --
            inline Leaf const* Leaf::leaf(const vec3& pos_) const noexcept
            {
                PRE(contains(pos_));

                return (this);
            }



        } // namespace node
    }     // namespace mesh
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MESH_NODE_LEAF_HPP
