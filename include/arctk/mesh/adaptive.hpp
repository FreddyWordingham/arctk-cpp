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
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Adaptive(const vec3& min_, const vec3& max_, const std::vector<equip::Light>& lights_, const std::vector<equip::Entity>& entities_, const std::vector<equip::Detector>& detectors_, size_t max_depth_, size_t target_shapes_) noexcept;

          private:
            //  -- Initialisation --
            std::vector<std::pair<const geom::Shape&, const equip::Light&>>    init_light_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Light>& lights_) const noexcept;
            std::vector<std::pair<const geom::Shape&, const equip::Entity&>>   init_entity_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Entity>& entities_) const noexcept;
            std::vector<std::pair<const geom::Shape&, const equip::Detector&>> init_detector_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Detector>& detectors_) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct an adaptive mesh.
         *
         *  @param  min_            Minimum bound of the mesh.
         *  @param  max_            Maximum bound of the mesh.
         *  @param  lights_         Vector of lights that may be found within the mesh's bounds.
         *  @param  entities_       Vector of entities that may be found within the mesh's bounds.
         *  @param  detectors_      Vector of detectors that may be found within the mesh's bounds.
         *  @param  max_depth_      Maximum depth the mesh may reach.
         *  @param  target_shapes_  Target maximum number of shapes to find within each leaf cell of the mesh.
         *
         *  @pre    min_.x must be less than max_.x.
         *  @pre    min_.y must be less than max_.y.
         *  @pre    min_.z must be less than max_.z.
         *  @pre    max_depth_ must be positive.
         */
        inline Adaptive::Adaptive(const vec3& min_, const vec3& max_, const std::vector<equip::Light>& lights_, const std::vector<equip::Entity>& entities_, const std::vector<equip::Detector>& detectors_, const size_t max_depth_,
                                  const size_t target_shapes_) noexcept
          : Branch(min_, max_, init_light_shape_list(geom::shape::Aabb(min_, max_), lights_), init_entity_shape_list(geom::shape::Aabb(min_, max_), entities_), init_detector_shape_list(geom::shape::Aabb(min_, max_), detectors_), 0, max_depth_,
                   target_shapes_)
        {
            PRE(min_.x < max_.x);
            PRE(min_.y < max_.y);
            PRE(min_.z < max_.z);
            PRE(max_depth_ > 0);
        }


        //  -- Initialisation --
        /**
         *  Initialise the vector of shape-light pairs that are located within the bounds of the mesh.
         *
         *  @param  box_    Bounding box of the mesh.
         *  @param  lights_ Vector of lights that may be found within the mesh's bounds.
         *
         *  @return Initialised vector of shape-light pairs that are located within the bounds of the mesh.
         */
        inline std::vector<std::pair<const geom::Shape&, const equip::Light&>> Adaptive::init_light_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Light>& lights_) const noexcept
        {
            std::vector<std::pair<const geom::Shape&, const equip::Light&>> list;

            for (size_t i = 0; i < lights_.size(); ++i)
            {
                const std::vector<const Shape*> shapes = lights_[i].surf()->shape_list();

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

        /**
         *  Initialise the vector of shape-entity pairs that are located within the bounds of the mesh.
         *
         *  @param  box_        Bounding box of the mesh.
         *  @param  entities_   Vector of entities that may be found within the mesh's bounds.
         *
         *  @return Initialised vector of shape-entity pairs that are located within the bounds of the mesh.
         */
        inline std::vector<std::pair<const geom::Shape&, const equip::Entity&>> Adaptive::init_entity_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Entity>& entities_) const noexcept
        {
            std::vector<std::pair<const geom::Shape&, const equip::Entity&>> list;

            for (size_t i = 0; i < entities_.size(); ++i)
            {
                const std::vector<const Shape*> shapes = entities_[i].surf()->shape_list();

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

        /**
         *  Initialise the vector of shape-detector pairs that are located within the bounds of the mesh.
         *
         *  @param  box_        Bounding box of the mesh.
         *  @param  detectors_  Vector of detectors that may be found within the mesh's bounds.
         *
         *  @return Initialised vector of shape-detector pairs that are located within the bounds of the mesh.
         */
        inline std::vector<std::pair<const geom::Shape&, const equip::Detector&>> Adaptive::init_detector_shape_list(const geom::shape::Aabb& box_, const std::vector<equip::Detector>& detectors_) const noexcept
        {
            std::vector<std::pair<const geom::Shape&, const equip::Detector&>> list;

            for (size_t i = 0; i < detectors_.size(); ++i)
            {
                const std::vector<const Shape*> shapes = detectors_[i].surf()->shape_list();

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
