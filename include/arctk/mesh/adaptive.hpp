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
            std::vector<std::pair<const equip::Light&, const geom::shape::Triangle&>>    init_light_tri_list(const geom::shape::Aabb& box_, const std::vector<equip::Light>& lights_) const noexcept;
            std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>>   init_entity_tri_list(const geom::shape::Aabb& box_, const std::vector<equip::Entity>& entities_) const noexcept;
            std::vector<std::pair<const equip::Detector&, const geom::shape::Triangle&>> init_detector_tri_list(const geom::shape::Aabb& box_, const std::vector<equip::Detector>& detectors_) const noexcept;
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
          : Branch(min_, max_, init_light_tri_list(geom::shape::Aabb(min_, max_), lights_), init_entity_tri_list(geom::shape::Aabb(min_, max_), entities_), init_detector_tri_list(geom::shape::Aabb(min_, max_), detectors_), 1, max_depth_, target_shapes_)
        {
            PRE(min_.x < max_.x);
            PRE(min_.y < max_.y);
            PRE(min_.z < max_.z);
            PRE(max_depth_ > 0);
        }


        //  -- Initialisation --
        /**
         *  Initialise the vector of light-triangle pairs that are located within the bounds of the mesh.
         *
         *  @param  box_    Bounding box of the mesh.
         *  @param  lights_ Vector of lights that may be found within the mesh's bounds.
         *
         *  @return Initialised vector of light-triangle pairs that are located within the bounds of the mesh.
         */
        inline std::vector<std::pair<const equip::Light&, const geom::shape::Triangle&>> Adaptive::init_light_tri_list(const geom::shape::Aabb& box_, const std::vector<equip::Light>& lights_) const noexcept
        {
            std::vector<std::pair<const equip::Light&, const geom::shape::Triangle&>> list;

            for (size_t i = 0; i < lights_.size(); ++i)
            {
                for (size_t j = 0; j < lights_[i].surf().num_faces(); ++j)
                {
                    if (lights_[i].surf().tri(j).intersect_vol(box_))
                    {
                        list.emplace_back(std::pair<const equip::Light&, const geom::shape::Triangle&>(lights_[i], lights_[i].surf().tri(j)));
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
        inline std::vector<std::pair<const geom::Shape&, const equip::Entity&>> Adaptive::init_entity_tri_list(const geom::shape::Aabb& box_, const std::vector<equip::Entity>& entities_) const noexcept
        {
            std::vector<std::pair<const equip::Entity&, const geom::shape::Triangle&>> list;

            for (size_t i = 0; i < entities_.size(); ++i)
            {
                for (size_t j = 0; j < entities_[i].surf().num_faces(); ++j)
                {
                    if (entities_[i].surf().tri(j).intersect_vol(box_))
                    {
                        list.emplace_back(std::pair<const equip::Entity&, const geom::shape::Triangle&>(entities_[i], entities_[i].surf().tri(j)));
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
        inline std::vector<std::pair<const geom::Shape&, const equip::Detector&>> Adaptive::init_detector_tri_list(const geom::shape::Aabb& box_, const std::vector<equip::Detector>& detectors_) const noexcept
        {
            std::vector<std::pair<const equip::Detector&, const geom::shape::Triangle&>> list;

            for (size_t i = 0; i < detectors_.size(); ++i)
            {
                for (size_t j = 0; j < detectors_[i].surf().num_faces(); ++j)
                {
                    if (detectors_[i].surf().tri(j).intersect_vol(box_))
                    {
                        list.emplace_back(std::pair<const equip::Detector&, const geom::shape::Triangle&>(detectors_[i], detectors_[i].surf().tri(j)));
                    }
                }
            }

            return (list);
        }



    } // namespace mesh
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MESH_ADAPTIVE_HPP
