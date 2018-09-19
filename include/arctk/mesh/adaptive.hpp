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
#include <arctk/mesh/node.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace mesh //! mesh namespace
    {



        //  == CLASS ==
        /**
         *  Mesh node base class.
         */
        class Adaptive : public geom::shape::Aabb
        {
            //  -- Positioning --
            const vec3 _centre; //!< Centre coordinate of the node.

            //  -- Children --
            const std::array<std::array<std::array<std::unique_ptr<Node>, 2>, 2>, 2> _childs;

            //  -- Properties --
            const size_t _max_shapes;
            const size_t _depth;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Branch(const vec3& min_, const vec3& max_, std::vector<equip::Light> lights_, std::vector<equip::Entity> entities_, std::vector<equip::Detector> detectors_, const size_t max_depth_, const size_t target_shapes_) noexcept;


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



    } // namespace mesh
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MESH_ADAPTIVE_HPP
