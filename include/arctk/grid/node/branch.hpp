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
#include <arctk/equip.hpp>
#include <arctk/geom.hpp>
#include <arctk/grid/node/leaf.hpp>
#include <arctk/math.hpp>
#include <arctk/utl.hpp>



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
                inline Branch(const vec3& min_, const vec3& max_, std::vector<equip::Light> lights_, std::vector<equip::Entity> entities_, std::vector<equip::Detector> detectors_, const size_t max_depth_, const size_t target_shapes_) noexcept;
                inline Branch(const vec3& min_, const vec3& max_, const std::vector<std::pair<const geom::Shape&, const equip::Light&>>& lights_, const std::vector<std::pair<const geom::Shape&, const equip::Entity&>>& entities_,
                              const std::vector<std::pair<const geom::Shape&, const equip::Detector&>>& detectors_, const size_t cur_depth_, const size_t max_depth_, const size_t target_shapes_) noexcept;

                //  -- Initialisation --
              private:
                std::vector<std::pair<const geom::Shape&, const equip::Light&>>    init_light_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Light>& lights_) const noexcept;
                std::vector<std::pair<const geom::Shape&, const equip::Entity&>>   init_entity_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Entity>& entities_) const noexcept;
                std::vector<std::pair<const geom::Shape&, const equip::Detector&>> init_detector_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Detector>& detectors_) const noexcept;
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
                inline size_t                         num_nodes() const noexcept override;
                inline std::vector<geom::shape::Aabb> boxes() const noexcept override;

                //  -- Retrieval --
                inline Leaf const* leaf(const vec3& pos_) const noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Branch::Branch(const vec3& min_, const vec3& max_, std::vector<equip::Light> lights_, std::vector<equip::Entity> entities_, std::vector<equip::Detector> detectors_, const size_t max_depth_, const size_t target_shapes_) noexcept
              : Branch(min_, max_, init_light_shape_list(geom::shape::Aabb(min_, max_), lights_), init_entity_shape_list(geom::shape::Aabb(min_, max_), entities_), init_detector_shape_list(geom::shape::Aabb(min_, max_), detectors_), 0, max_depth_,
                       target_shapes_)
            {
                PRE(min_.x < max_.x);
                PRE(min_.y < max_.y);
                PRE(min_.z < max_.z);
                PRE(max_depth_ > 0);
            }

            inline Branch::Branch(const vec3& min_, const vec3& max_, const std::vector<std::pair<const geom::Shape&, const equip::Light&>>& lights_, const std::vector<std::pair<const geom::Shape&, const equip::Entity&>>& entities_,
                                  const std::vector<std::pair<const geom::Shape&, const equip::Detector&>>& detectors_, const size_t cur_depth_, const size_t max_depth_, const size_t target_shapes_) noexcept
              : Node(min_, max_)
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
            std::vector<std::pair<const geom::Shape&, const equip::Light&>> Branch::init_light_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Light>& lights_) const noexcept
            {
                std::vector<std::pair<const geom::Shape&, const equip::Light&>> list;

                for (size_t i = 0; i < lights_.size(); ++i)
                {
                    const std::vector<const Shape*> shapes = lights_[i].surf().shape_list();

                    for (size_t j = 0; j < shapes.size(); ++j)
                    {
                        if (shapes[j]->intersect_vol(box_))
                        {
                            list.emplace_back(std::pair<const geom::Shape&, const equip::Light&>(*shapes[j], lights_[i]));
                        }
                    }
                }
                std::cout << "lgt" << '\t' << list.size() << '\n';
                return (list);
            }

            std::vector<std::pair<const geom::Shape&, const equip::Entity&>> Branch::init_entity_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Entity>& entities_) const noexcept
            {
                std::vector<std::pair<const geom::Shape&, const equip::Entity&>> list;

                for (size_t i = 0; i < entities_.size(); ++i)
                {
                    const std::vector<const Shape*> shapes = entities_[i].surf().shape_list();

                    for (size_t j = 0; j < shapes.size(); ++j)
                    {
                        if (shapes[j]->intersect_vol(box_))
                        {
                            list.emplace_back(std::pair<const geom::Shape&, const equip::Entity&>(*shapes[j], entities_[i]));
                        }
                    }
                }
                std::cout << "ent" << '\t' << list.size() << '\n';
                return (list);
            }

            std::vector<std::pair<const geom::Shape&, const equip::Detector&>> Branch::init_detector_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Detector>& detectors_) const noexcept
            {
                std::vector<std::pair<const geom::Shape&, const equip::Detector&>> list;

                for (size_t i = 0; i < detectors_.size(); ++i)
                {
                    const std::vector<const Shape*> shapes = detectors_[i].surf().shape_list();

                    for (size_t j = 0; j < shapes.size(); ++j)
                    {
                        if (shapes[j]->intersect_vol(box_))
                        {
                            list.emplace_back(std::pair<const geom::Shape&, const equip::Detector&>(*shapes[j], detectors_[i]));
                        }
                    }
                }
                std::cout << "det" << '\t' << list.size() << '\n';
                return (list);
            }

            std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> Branch::init_childs(const std::vector<std::pair<const geom::Shape&, const equip::Light&>>&    lights_,
                                                                                                   const std::vector<std::pair<const geom::Shape&, const equip::Entity&>>&   entities_,
                                                                                                   const std::vector<std::pair<const geom::Shape&, const equip::Detector&>>& detectors_, const size_t cur_depth_, const size_t max_depth_,
                                                                                                   const size_t target_shapes_) const noexcept
            {
                std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> childs;

                const vec3 size                = half_width();
                const bool depth_limit_reached = (cur_depth_ + 1) >= max_depth_;

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
                                childs[i][j][k] = std::make_unique<Leaf>(min, max, lights, entities, detectors);
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

                            utl::manip::move_append(&boxes, &child_boxes);
                        }
                    }
                }

                return (boxes);
            }


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
