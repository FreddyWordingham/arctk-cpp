/**
 *  @file   arctk/gui/camera/fly.hpp
 *  @date   08/08/2018
 *  @author Freddy Wordingham
 *
 *  Fly camera class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_CAMERA_FLY_HPP
#define ARCTK_GUI_CAMERA_FLY_HPP



//  == IMPORTS ==
//  -- Std --
#include <algorithm>

//  -- Graphical -
#include <glm/gtx/rotate_vector.hpp>

//  -- Arctk --
#include <arctk/gui/camera.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {
        namespace camera //! camera namespace
        {



            //  == CLASS ==
            /**
             *  Camera class with fly controls.
             */
            class Fly : public Camera
            {
                //  == FIELDS ==
              protected:
                //  -- Direction --
                glm::vec3 _dir; //!< Direction of the camera.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Fly(const glm::vec3& pos_, const glm::vec3& dir_ = glm::vec3(0.0f, 1.0f, 0.0f), const glm::vec3& up_ = glm::vec3(0.0f, 0.0f, 1.0f)) noexcept;


                //  == METHODS ==
              public:
                //  -- Control --
                inline void move(float forward_, float right_, float up_) noexcept override;
                inline void rotate(float roll_, float pitch_, float yaw_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct an fly camera at a given position with a given view direction and up direction.
             *
             *  @param  pos_    Position of the camera.
             *  @param  dir_    Direction to point the camera.
             *  @param  up_     Up direction of the camera.
             */
            inline Fly::Fly(const glm::vec3& pos_, const glm::vec3& dir_, const glm::vec3& up_) noexcept
              : Camera(pos_, pos_ + dir_, up_)
              , _dir(glm::normalize(dir_))
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
#endif // ARCTK_GUI_CAMERA_FLY_HPP
