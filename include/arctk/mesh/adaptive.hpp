/**
 *  @file   arctk/mesh/adaptive.hpp
 *  @date   19/09/2018
 *  @author Freddy Wordingham
 *
 *  Adaptive mesh class.
 */



//  == GUARD ==
#ifndef ARCTK_MESH_ADAPTIVE_HPP
#define ARCTK_MESH_ADAPTIVE_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <memory>

//  -- Arctk --
#include <arctk/math.hpp>
#include <arctk/mesh/node/branch.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace mesh //! mesh namespace
    {



        //  == CLASS ==
        /**
         *  Mesh node base class.
         */
        class Adaptive : public node::Branch
        {
            //  -- Properties --
            const size_t _max_shapes;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Adaptive(const vec3& min_, const vec3& max_, std::vector<equip::Light> lights_, std::vector<equip::Entity> entities_, std::vector<equip::Detector> detectors_, const size_t max_depth_, const size_t target_shapes_) noexcept;

            //  -- Initialisation --
          private:
            std::vector<std::pair<const geom::Shape&, const equip::Light&>>    init_light_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Light>& lights_) const noexcept;
            std::vector<std::pair<const geom::Shape&, const equip::Entity&>>   init_entity_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Entity>& entities_) const noexcept;
            std::vector<std::pair<const geom::Shape&, const equip::Detector&>> init_detector_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Detector>& detectors_) const noexcept;


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Adaptive::Adaptive(const vec3& min_, const vec3& max_, std::vector<equip::Light> lights_, std::vector<equip::Entity> entities_, std::vector<equip::Detector> detectors_, const size_t max_depth_, const size_t target_shapes_) noexcept
          : Branch(min_, max_, init_light_shape_list(geom::shape::Aabb(min_, max_), lights_), init_entity_shape_list(geom::shape::Aabb(min_, max_), entities_), init_detector_shape_list(geom::shape::Aabb(min_, max_), detectors_), 0, max_depth_,
                   target_shapes_)
          , _max_shapes(max_shapes())
          , _depth(max_depth())
        {
            PRE(min_.x < max_.x);
            PRE(min_.y < max_.y);
            PRE(min_.z < max_.z);
            PRE(max_depth_ > 0);
        }


        //  -- Initialisation --
        std::vector<std::pair<const geom::Shape&, const equip::Light&>> Adaptive::init_light_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Light>& lights_) const noexcept
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

            return (list);
        }

        std::vector<std::pair<const geom::Shape&, const equip::Entity&>> Adaptive::init_entity_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Entity>& entities_) const noexcept
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

            return (list);
        }

        std::vector<std::pair<const geom::Shape&, const equip::Detector&>> Adaptive::init_detector_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Detector>& detectors_) const noexcept
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

            return (list);
        }



    } // namespace mesh
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MESH_ADAPTIVE_HPP
