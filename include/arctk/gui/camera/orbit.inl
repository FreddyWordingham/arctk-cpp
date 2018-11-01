/**
 *  @file   arctk/gui/camera/orbit.inl
 *  @date   04/08/2018
 *  @author Freddy Wordingham
 *
 *  Orbital camera class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_CAMERA_ORBIT_INL
#define ARCTK_GUI_CAMERA_ORBIT_INL



//  == IMPORTS ==
//  -- Std --
#include <algorithm>
#include <cassert>

//  -- Graphical --
#include <glm/gtx/polar_coordinates.hpp>

//  -- Arctk --
#include <arctk/math/convert.hpp>
#include <arctk/math/vec3.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {
        namespace camera //! camera namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct an orbital camera at a given position with a given focus point and up direction.
             *
             *  @param  pos_    Position of the camera.
             *  @param  focus_  Point to focus the camera on.
             *  @param  up_     Up direction of the camera.
             *  @param  speed_  Initial speed of the camera.
             *
             *  @pre    speed_ must be positive.
             */
            inline Orbit::Orbit(const glm::vec3& pos_, const glm::vec3& focus_, const glm::vec3& up_, const float speed_) noexcept
              : Camera(pos_, focus_, up_, speed_)
            {
                assert(speed_ > 0.0f);
            }



            //  == METHODS ==
            //  -- Control --
            /**
             *  Move the camera position.
             *
             *  @param  forward_    Distance to move the camera forward.
             *  @param  right_      Distance to move the camera to the right.
             *  @param  up_         Distance to move the camera upward.
             */
            inline void Orbit::move(const float forward_, const float right_, const float up_) noexcept
            {
                vec3f pos = math::convert::cart_to_polar(vec3f(_pos.x, _pos.y, _pos.z));

                pos = math::convert::polar_to_cart(vec3f(std::max(pos.rho + (forward_ * _speed), 0.001f), std::clamp(pos.theta - (up_ * _speed), 0.001f, 3.140f), pos.phi + (right_ * _speed)));

                _pos.x = pos.x;
                _pos.y = pos.y;
                _pos.z = pos.z;

                update_view();
            }

            /**
             *  Rotate the camera's orientation.
             */
            inline void Orbit::rotate(const float /*unused*/, const float /*unused*/, const float /*unused*/) noexcept
            {
            }



        } // namespace camera
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_ORBIT_INL
