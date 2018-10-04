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
                const std::vector<std::pair<const equip::Light&, const geom::shape::Triangle&>>    _lights;    //!< Vector of light triangles that are found within the node's bounds.
                const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>>   _entities;  //!< Vector of entity triangles that are found within the node's bounds.
                const std::vector<std::pair<const equip::Detector&, const geom::shape::Triangle&>> _detectors; //!< Vector of detector triangles that are found within the node's bounds.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Leaf(const vec3& min_, const vec3& max_, const std::vector<std::pair<const equip::Light&, const geom::shape::Triangle&>>& lights_, const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>>& entities_,
                            const std::vector<std::pair<const equip::Detector&, const geom::shape::Triangle&>>& detectors_, size_t cur_depth_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline size_t                                                              max_depth() const noexcept override;
                inline size_t                                                              max_shapes() const noexcept override;
                inline size_t                                                              num_nodes() const noexcept override;
                inline std::vector<geom::shape::Aabb>                                      boxes() const noexcept override;
                inline std::optional<std::tuple<double, vec3, const equip::Entity* const>> intersect_entity(const vec3& pos_, const vec3& dir_) const noexcept;

                //  -- Retrieval --
                inline Leaf const* leaf(const vec3& pos_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a leaf node.
             *
             *  @param  min_            Minimum bound of the node.
             *  @param  max_            Maximum bound of the node.
             *  @param  lights_         Vector of light triangles that are found within the node's bounds.
             *  @param  entities_       Vector of entity triangles that are found within the node's bounds.
             *  @param  detectors_      Vector of detector triangles that are found within the node's bounds.
             *  @param  cur_depth_      Current depth of the node.
             *
             *  @pre    min_.x must be less than max_.x.
             *  @pre    min_.y must be less than max_.y.
             *  @pre    min_.z must be less than max_.z.
             *  @pre    lights_ shapes must intersect the node.
             *  @pre    entities_ shapes must intersect the node.
             *  @pre    detectors_ shapes must intersect the node.
             */
            inline Leaf::Leaf(const vec3& min_, const vec3& max_, const std::vector<std::pair<const equip::Light&, const geom::shape::Triangle&>>& lights_, const std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>>& entities_,
                              const std::vector<std::pair<const equip::Detector&, const geom::shape::Triangle&>>& detectors_, const size_t cur_depth_) noexcept
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
                    PRE(lights_[i].second.intersect_vol(*this));
                }
                for (size_t i = 0; i < entities_.size(); ++i)
                {
                    PRE(entities_[i].second.intersect_vol(*this));
                }
                for (size_t i = 0; i < detectors_.size(); ++i)
                {
                    PRE(detectors_[i].second.intersect_vol(*this));
                }
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the maximum depth of this node and any of its descendents.
             *
             *  @return Maximum depth of this node and any of its descendents.
             */
            inline size_t Leaf::max_depth() const noexcept
            {
                return (_depth);
            }

            /**
             *  Get the maximum number of shapes contained within this node and any of its descendents.
             *
             *  @return Maximum number of shapes contained within this node and any of its descendents.
             */
            inline size_t Leaf::max_shapes() const noexcept
            {
                return (_lights.size() + _entities.size() + _detectors.size());
            }

            /**
             *  Get the total number of nodes related to this node.
             *  Includes this node in the count.
             *
             *  @return Total number of nodes related to this node.
             */
            inline size_t Leaf::num_nodes() const noexcept
            {
                return (1);
            }

            /**
             *  Get a vector of all the axis-aligned bounding boxes of the leaf nodes descended from this node.
             *
             *  @return Vector of all the axis-aligned bounding boxes of the leaf nodes descended from this node.
             */
            inline std::vector<geom::shape::Aabb> Leaf::boxes() const noexcept
            {
                return (std::vector<geom::shape::Aabb>({geom::shape::Aabb(_min, _max)}));
            }

            /**
             *  Determine if a ray intersects any of the entities contained within the cell.
             *  If an intersection does occur return the distance to intersection, the normal of the entity at the point of intersection and a pointer to the intersecting entity.
             *
             *  @param  pos_    Position of the ray start.
             *  @param  dir_    Direction of the ray.
             *
             *  @pre    pos_ must be contained within the leaf.
             *
             *  @return Distance to intersection, normal of intersection point, intersecting entity pointer.
             */
            inline std::optional<std::tuple<double, vec3, const equip::Entity* const>> Leaf::intersect_entity(const vec3& pos_, const vec3& dir_) const noexcept
            {
                PRE(contains(pos_));

                std::optional<std::tuple<double, vec3, const equip::Entity* const>> collision(std::nullopt);
                for (size_t i = 0; i < _entities.size(); ++i)
                {
                    const std::optional<std::pair<double, vec3>> coll = _entities[i].second.collision_norm(pos_, dir_);

                    if (coll && (!collision || (coll.value().first < std::get<0>(collision.value()))))
                    {
                        collision = std::optional<std::tuple<double, vec3, const equip::Entity* const>>(std::tuple<double, vec3, const equip::Entity* const>(coll.value().first, coll.value().second, _entities[i].first));
                    }
                }

                return (collision);
            }


            //  -- Retrieval --
            /**
             *  Get the pointer to the leaf node corresponding to a given position within this node.
             *
             *  @param  pos_    Position to find the corresponding leaf node for.
             *
             *  @pre    pos_ must be contained within this node.
             *
             *  @return Pointer to the leaf node corresponding to a given position within this node.
             */
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
