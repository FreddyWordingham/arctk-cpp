/**
 *  @file   arctk/gui/camera/orbit.hpp
 *  @date   04/08/2018
 *  @author Freddy Wordingham
 *
 *  Orbital camera class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_CAMERA_ORBIT_HPP
#define ARCTK_GUI_CAMERA_ORBIT_HPP



//  == IMPORTS ==
//  -- Std --
#include <algorithm>

//  -- Graphical --
#include <glm/gtx/polar_coordinates.hpp>

//  -- Arctk --
#include <arctk/gui/camera.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {
        namespace camera //! camera namespace
        {



            //  == CLASS ==
            /**
             *  Camera class with orbital controls.
             */
            class Orbit : public Camera
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Orbit(const glm::vec3& pos_, const glm::vec3& focus_ = glm::vec3(0.0f, 0.0f, 0.0f), const glm::vec3& up_ = glm::vec3(0.0f, 0.0f, 1.0f)) noexcept;


                //  == METHODS ==
              public:
                //  -- Control --
                inline void move(const float forward_, const float right_, const float up_) noexcept override;
                inline void rotate(const float roll_, const float pitch_, const float yaw_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct an orbital camera at a given position with a given focus point and up direction.
             *
             *  @param  pos_    Position of the camera.
             *  @param  focus_  Point to focus the camera on.
             *  @param  up_     Up direction of the camera.
             */
            inline Orbit::Orbit(const glm::vec3& pos_, const glm::vec3& focus_, const glm::vec3& up_) noexcept
              : Camera(pos_, focus_, up_)
            {
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

                pos = math::convert::polar_to_cart(vec3f(std::max(pos.rho + (forward_ * _speed), 0.001f), std::clamp(pos.theta + (right_ * _speed), 0.001f, 3.140f), pos.phi + (up_ * _speed)));

                _pos.x = pos.x;
                _pos.y = pos.y;
                _pos.z = pos.z;

                update_view();
            }

            /**
             *  Rotate the camera's orientation.
             *
             *  @param  roll_   Angle to roll the camera.
             *  @param  pitch_  Angle to pitch the camera.
             *  @param  yaw_    Angle to yaw the camera.
             */
            inline void Orbit::rotate(const float roll_, const float pitch_, const float yaw_) noexcept
            {
            }



        } // namespace camera
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_ORBIT_HPP
