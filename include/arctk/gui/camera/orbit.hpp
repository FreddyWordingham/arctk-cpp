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
                //  == FIELDS ==


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


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



            //  == METHODS ==



        } // namespace camera
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_ORBIT_HPP
