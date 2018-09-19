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
            const size_t _depth;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Adaptive(const vec3& min_, const vec3& max_, std::vector<equip::Light> lights_, std::vector<equip::Entity> entities_, std::vector<equip::Detector> detectors_, const size_t max_depth_, const size_t target_shapes_) noexcept;


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Adaptive::Adaptive(const vec3& min_, const vec3& max_, std::vector<equip::Light> lights_, std::vector<equip::Entity> entities_, std::vector<equip::Detector> detectors_, const size_t max_depth_, const size_t target_shapes_) noexcept
          : Branch(min_, max_, init_light_shape_list(geom::shape::Aabb(min_, max_), lights_), init_entity_shape_list(geom::shape::Aabb(min_, max_), entities_), init_detector_shape_list(geom::shape::Aabb(min_, max_), detectors_), 0, max_depth_,
                   target_shapes_)
        {
            PRE(min_.x < max_.x);
            PRE(min_.y < max_.y);
            PRE(min_.z < max_.z);
            PRE(max_depth_ > 0);
        }



    } // namespace mesh
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MESH_ADAPTIVE_HPP
