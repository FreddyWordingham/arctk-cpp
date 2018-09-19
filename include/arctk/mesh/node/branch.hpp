/**
 *  @file   arctk/mesh/node/branch.hpp
 *  @date   17/09/2018
 *  @author Freddy Wordingham
 *
 *  Branch node class.
 */



//  == GUARD ==
#ifndef ARCTK_MESH_NODE_BRANCH_HPP
#define ARCTK_MESH_NODE_BRANCH_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <memory>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/equip.hpp>
#include <arctk/geom.hpp>
#include <arctk/math.hpp>
#include <arctk/mesh/node/leaf.hpp>
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace mesh //! mesh namespace
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
                inline Branch(const vec3& min_, const vec3& max_, const std::vector<std::pair<const geom::Shape&, const equip::Light&>>& lights_, const std::vector<std::pair<const geom::Shape&, const equip::Entity&>>& entities_,
                              const std::vector<std::pair<const geom::Shape&, const equip::Detector&>>& detectors_, const size_t cur_depth_, const size_t max_depth_, const size_t target_shapes_) noexcept;

                //  -- Initialisation --
              private:
                std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> init_childs(const std::vector<std::pair<const geom::Shape&, const equip::Light&>>&    lights_,
                                                                                               const std::vector<std::pair<const geom::Shape&, const equip::Entity&>>&   entities_,
                                                                                               const std::vector<std::pair<const geom::Shape&, const equip::Detector&>>& detectors_, const size_t depth_, const size_t max_depth_,
                                                                                               const size_t target_shapes_) const noexcept;
                std::vector<std::pair<const geom::Shape&, const equip::Light&>>    init_lights_intersect(const geom::shape::Aabb& box_, const std::vector<std::pair<const geom::Shape&, const equip::Light&>>& lights_) const noexcept;
                std::vector<std::pair<const geom::Shape&, const equip::Entity&>>   init_entities_intersect(const geom::shape::Aabb& box_, const std::vector<std::pair<const geom::Shape&, const equip::Entity&>>& entities_) const noexcept;
                std::vector<std::pair<const geom::Shape&, const equip::Detector&>> init_detectors_intersect(const geom::shape::Aabb& box_, const std::vector<std::pair<const geom::Shape&, const equip::Detector&>>& detectors_) const noexcept;


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
             *  Construct a branch node.
             *
             *  @param  min_            Minimum bound of the node.
             *  @param  max_            Maximum bound of the node.
             *  @param  lights_         Vector of lights that are be found within the node's bounds.
             *  @param  entities_       Vector of entities that are be found within the node's bounds.
             *  @param  detectors_      Vector of detectors that are be found within the node's bounds.
             *  @param  cur_depth_      Current depth of the node.
             *  @param  max_depth_      Maximum depth the mesh may reach.
             *  @param  target_shapes_  Target maximum number of shapes to find within each leaf node of the mesh.
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
            inline Branch::Branch(const vec3& min_, const vec3& max_, const std::vector<std::pair<const geom::Shape&, const equip::Light&>>& lights_, const std::vector<std::pair<const geom::Shape&, const equip::Entity&>>& entities_,
                                  const std::vector<std::pair<const geom::Shape&, const equip::Detector&>>& detectors_, const size_t cur_depth_, const size_t max_depth_, const size_t target_shapes_) noexcept
              : Node(min_, max_, cur_depth_)
              , _centre(min_.x + max_.x / 2.0, min_.y + max_.y / 2.0, min_.z + max_.z / 2.0)
              , _childs(init_childs(lights_, entities_, detectors_, cur_depth_, max_depth_, target_shapes_))
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
                PRE(cur_depth_ >= 0);
                PRE(max_depth_ >= cur_depth_);
            }


            //  -- Initialisation --
            /**
             *  Initialise the three-dimensional array of child nodes.
             *
             *  @param  lights_         Vector of lights that may be found within the mesh's bounds.
             *  @param  entities_       Vector of entities that may be found within the mesh's bounds.
             *  @param  detectors_      Vector of detectors that may be found within the mesh's bounds.
             *  @param  cur_depth_      Current depth of the node.
             *  @param  max_depth_      Maximum depth the mesh may reach.
             *  @param  target_shapes_  Target maximum number of shapes to find within each leaf cell of the mesh.
             *
             *  @return Initialised three-dimensional array of child nodes.
             */
            std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> Branch::init_childs(const std::vector<std::pair<const geom::Shape&, const equip::Light&>>&    lights_,
                                                                                                   const std::vector<std::pair<const geom::Shape&, const equip::Entity&>>&   entities_,
                                                                                                   const std::vector<std::pair<const geom::Shape&, const equip::Detector&>>& detectors_, const size_t cur_depth_, const size_t max_depth_,
                                                                                                   const size_t target_shapes_) const noexcept
            {
                std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> childs;

                const vec3 size                = half_width();
                const bool depth_limit_reached = cur_depth_ >= max_depth_;

                for (size_t i = 0; i <= 1; ++i)
                {
                    for (size_t j = 0; j <= 1; ++j)
                    {
                        for (size_t k = 0; k <= 1; ++k)
                        {
                            const vec3 min(_min.x + (i * size.x), _min.y + (j * size.y), _min.z + (k * size.z));
                            const vec3 max = min + size;

                            const geom::shape::Aabb box(min, max);

                            const std::vector<std::pair<const geom::Shape&, const equip::Light&>>    lights    = init_lights_intersect(box, lights_);
                            const std::vector<std::pair<const geom::Shape&, const equip::Entity&>>   entities  = init_entities_intersect(box, entities_);
                            const std::vector<std::pair<const geom::Shape&, const equip::Detector&>> detectors = init_detectors_intersect(box, detectors_);

                            const size_t total_primitives = lights.size() + entities.size() + detectors.size();

                            if (depth_limit_reached || (total_primitives <= target_shapes_))
                            {
                                childs[i][j][k] = std::make_unique<Leaf>(min, max, lights, entities, detectors, cur_depth_);
                            }
                            else
                            {
                                childs[i][j][k] = std::make_unique<Branch>(min, max, lights, entities, detectors, cur_depth_ + 1, max_depth_, target_shapes_);
                            }
                        }
                    }
                }

                return (childs);
            }

            /**
             *  Initialise the vector of shape-light pairs which intersect with the node.
             *
             *  @param  box_    Bounding box of the node.
             *  @param  lights_ Vector of lights that may be found within the mesh's bounds.
             *
             *  @return Initialise vector of shape-light pairs which intersect with the node.
             */
            std::vector<std::pair<const geom::Shape&, const equip::Light&>> Branch::init_lights_intersect(const geom::shape::Aabb& box_, const std::vector<std::pair<const geom::Shape&, const equip::Light&>>& lights_) const noexcept
            {
                std::vector<std::pair<const geom::Shape&, const equip::Light&>> lights;

                for (size_t i = 0; i < lights_.size(); ++i)
                {
                    if (lights_[i].first.intersect_vol(box_))
                    {
                        lights.emplace_back(lights_[i]);
                    }
                }

                return (lights);
            }

            /**
             *  Initialise the vector of shape-entity pairs which intersect with the node.
             *
             *  @param  box_        Bounding box of the node.
             *  @param  entities_   Vector of entities that may be found within the mesh's bounds.
             *
             *  @return Initialise vector of shape-entity pairs which intersect with the node.
             */
            std::vector<std::pair<const geom::Shape&, const equip::Entity&>> Branch::init_entities_intersect(const geom::shape::Aabb& box_, const std::vector<std::pair<const geom::Shape&, const equip::Entity&>>& entities_) const noexcept
            {
                std::vector<std::pair<const geom::Shape&, const equip::Entity&>> entities;

                for (size_t i = 0; i < entities_.size(); ++i)
                {
                    if (entities_[i].first.intersect_vol(box_))
                    {
                        entities.emplace_back(entities_[i]);
                    }
                }

                return (entities);
            }

            /**
             *  Initialise the vector of shape-detector pairs which intersect with the node.
             *
             *  @param  box_        Bounding box of the node.
             *  @param  detectors_  Vector of detectors that may be found within the mesh's bounds.
             *
             *  @return Initialise vector of shape-detector pairs which intersect with the node.
             */
            std::vector<std::pair<const geom::Shape&, const equip::Detector&>> Branch::init_detectors_intersect(const geom::shape::Aabb& box_, const std::vector<std::pair<const geom::Shape&, const equip::Detector&>>& detectors_) const noexcept
            {
                std::vector<std::pair<const geom::Shape&, const equip::Detector&>> detectors;

                for (size_t i = 0; i < detectors_.size(); ++i)
                {
                    if (detectors_[i].first.intersect_vol(box_))
                    {
                        detectors.emplace_back(detectors_[i]);
                    }
                }

                return (detectors);
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the maximum depth of this node and any of its descendents.
             *
             *  @return Maximum depth of this node and any of its descendents.
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
             *  Get the maximum number of shapes contained within this node and any of its descendents.
             *
             *  @return Maximum number of shapes contained within this node and any of its descendents.
             */
            inline size_t Branch::max_shapes() const noexcept
            {
                size_t max_shapes = 0;

                for (size_t i = 0; i <= 1; ++i)
                {
                    for (size_t j = 0; j <= 1; ++j)
                    {
                        for (size_t k = 0; k <= 1; ++k)
                        {
                            if (_childs[i][j][k]->max_shapes() > max_shapes)
                            {
                                max_shapes = _childs[i][j][k]->max_shapes();
                            }
                        }
                    }
                }

                return (max_shapes);
            }

            /**
             *  Get the total number of nodes related to this node.
             *  Includes this node in the count.
             *
             *  @return Total number of nodes related to this node.
             */
            inline size_t Branch::num_nodes() const noexcept
            {
                size_t num_contained = 0;

                for (size_t i = 0; i <= 1; ++i)
                {
                    for (size_t j = 0; j <= 1; ++j)
                    {
                        for (size_t k = 0; k <= 1; ++k)
                        {
                            num_contained += _childs[i][j][k]->num_nodes();
                        }
                    }
                }

                return (1 + num_contained);
            }

            /**
             *  Get a vector of all the axis-aligned bounding boxes of the leaf nodes descended from this node.
             *
             *  @return Vector of all the axis-aligned bounding boxes of the leaf nodes descended from this node.
             */
            inline std::vector<geom::shape::Aabb> Branch::boxes() const noexcept
            {
                std::vector<geom::shape::Aabb> boxes;

                for (size_t i = 0; i <= 1; ++i)
                {
                    for (size_t j = 0; j <= 1; ++j)
                    {
                        for (size_t k = 0; k <= 1; ++k)
                        {
                            std::vector<geom::shape::Aabb> child_boxes = _childs[i][j][k]->boxes();

                            utl::manip::move_append(boxes, child_boxes);
                        }
                    }
                }

                return (boxes);
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
            inline Leaf const* Branch::leaf(const vec3& pos_) const noexcept
            {
                PRE(contains(pos_));

                return (_childs[(pos_.x < _centre.x) ? 0 : 1][(pos_.y < _centre.y) ? 0 : 1][(pos_.z < _centre.z) ? 0 : 1]->leaf(pos_));
            }



        } // namespace node
    }     // namespace mesh
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MESH_NODE_BRANCH_HPP
