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
                inline void move_forward(float dist_) noexcept override;
                inline void move_right(float dist_) noexcept override;
                inline void move_up(float dist_) noexcept override;
                inline void rotate_roll(float ang_) noexcept override;
                inline void rotate_pitch(float ang_) noexcept override;
                inline void rotate_yaw(float ang_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Orbit::Orbit(const glm::vec3& pos_, const glm::vec3& focus_, const glm::vec3& up_) noexcept
              : Camera(pos_, focus_, up_)
            {
            }



            //  == METHODS ==
            //  -- Control --
            inline void Orbit::move_forward(const float dist_) noexcept
            {

                update_view();
            }

            inline void Orbit::move_right(const float dist_) noexcept
            {

                update_view();
            }

            inline void Orbit::move_up(const float dist_) noexcept
            {

                update_view();
            }

            inline void Orbit::rotate_roll(const float ang_) noexcept
            {

                update_view();
            }

            inline void Orbit::rotate_pitch(const float ang_) noexcept
            {

                update_view();
            }

            inline void Orbit::rotate_yaw(const float ang_) noexcept
            {

                update_view();
            }



        } // namespace camera
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_ORBIT_HPP
