/**
 *  @file   arctk/gui/camera/fly.inl
 *  @date   08/08/2018
 *  @author Freddy Wordingham
 *
 *  Fly camera class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_CAMERA_FLY_INL
#define ARCTK_GUI_CAMERA_FLY_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Graphical --
#include <glm/gtx/rotate_vector.hpp>



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
             *  Construct an fly camera at a given position with a given view direction and up direction.
             *
             *  @param  pos_    Position of the camera.
             *  @param  dir_    Direction to point the camera.
             *  @param  up_     Up direction of the camera.
             *  @param  speed_  Initial speed of the camera.
             *
             *  @pre    speed_ must be positive.
             */
            inline Fly::Fly(const glm::vec3& pos_, const glm::vec3& dir_, const glm::vec3& up_, const float speed_) noexcept
              : Camera(pos_, pos_ + dir_, up_, speed_)
              , _dir(glm::normalize(dir_))
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
            inline void Fly::move(const float forward_, const float right_, const float up_) noexcept
            {
                const glm::vec3 right = glm::normalize(glm::cross(_dir, _up));
                const glm::vec3 top   = glm::normalize(glm::cross(right, _dir));

                _pos += _dir * (forward_ * _speed);
                _pos += right * (right_ * _speed);
                _pos += top * (up_ * _speed);

                _focus = _pos + _dir;

                update_view();
            }

            /**
             *  Rotate the camera's orientation.
             *
             *  @param  roll_   Angle to roll the camera.
             *  @param  pitch_  Angle to pitch the camera.
             *  @param  yaw_    Angle to yaw the camera.
             */
            inline void Fly::rotate(const float roll_, const float pitch_, const float yaw_) noexcept
            {
                const glm::vec3 right = glm::normalize(glm::cross(_dir, _up));
                const glm::vec3 top   = glm::normalize(glm::cross(right, _dir));

                _up  = glm::rotate(_up, roll_, _dir);
                _dir = glm::rotate(_dir, pitch_, right);
                _dir = glm::rotate(_dir, yaw_, top);

                _focus = _pos + _dir;

                update_view();
            }



        } // namespace camera
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_FLY_INL
