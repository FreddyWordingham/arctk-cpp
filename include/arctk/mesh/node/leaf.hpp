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
                            const std::vector<std::pair<const geom::Shape&, const equip::Detector&>>& detectors_, const size_t cur_depth_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline size_t                         max_depth() const noexcept override;
                inline size_t                         max_shapes() const noexcept override;
                inline size_t                         num_nodes() const noexcept override;
                inline std::vector<geom::shape::Aabb> boxes() const noexcept override;

                //  -- Retrieval --
                inline Leaf const* leaf(const vec3& pos_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *
             * @param min_
             * @param max_
             * @param lights_
             * @param entities_
             * @param detectors_
             * @param cur_depth_
             * @return
             */

            /**
             *  Construct a branch node.
             *
             *  @param  min_            Minimum bound of the mesh.
             *  @param  max_            Maximum bound of the mesh.
             *  @param  lights_         Vector of lights that may be found within the mesh's bounds.
             *  @param  entities_       Vector of entities that may be found within the mesh's bounds.
             *  @param  detectors_      Vector of detectors that may be found within the mesh's bounds.
             *  @param  cur_depth_      Current depth of the node.
             *  @param  max_depth_      Maximum depth the mesh may reach.
             *  @param  target_shapes_  Target maximum number of shapes to find within each leaf cell of the mesh.
             *
             *  @pre    min_.x must be less than max_.x.
             *  @pre    min_.y must be less than max_.y.
             *  @pre    min_.z must be less than max_.z.
             *  @pre    lights_ shapes must intersect the node.
             *  @pre    entities_ shapes must intersect the node.
             *  @pre    detectors_ shapes must intersect the node.
             *  @pre    cur_depth_ must be positive.
             *  @pre    max_depth_ must be greater than, or equal to, cur_depth_.
             */
            inline Leaf::Leaf(const vec3& min_, const vec3& max_, const std::vector<std::pair<const geom::Shape&, const equip::Light&>>& lights_, const std::vector<std::pair<const geom::Shape&, const equip::Entity&>>& entities_,
                              const std::vector<std::pair<const geom::Shape&, const equip::Detector&>>& detectors_, const size_t cur_depth_) noexcept
              : Node(min_, max_, cur_depth_)
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
            inline size_t Leaf::max_depth() const noexcept
            {
                return (_depth);
            }

            inline size_t Leaf::max_shapes() const noexcept
            {
                return (_lights.size() + _entities.size() + _detectors.size());
            }

            inline size_t Leaf::num_nodes() const noexcept
            {
                return (1);
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
