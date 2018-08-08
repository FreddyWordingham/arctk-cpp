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
                inline explicit Fly(const glm::vec3& pos_, const glm::vec3& dir_ = glm::vec3(0.0f, 0.0f, 0.0f), const glm::vec3& up_ = glm::vec3(0.0f, 0.0f, 1.0f)) noexcept;


                //  == METHODS ==
              public:
                //  -- Control --
                inline void move(float forward_, float right_, float up_) noexcept override;
                inline void rotate(float /*unused*/, float /*unused*/, float /*unused*/) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct an fly camera at a given position with a given focus point and up direction.
             *
             *  @param  pos_    Position of the camera.
             *  @param  focus_  Point to focus the camera on.
             *  @param  up_     Up direction of the camera.
             */
            inline Fly::Fly(const glm::vec3& pos_, const glm::vec3& focus_, const glm::vec3& up_) noexcept
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
            inline void Fly::move(const float forward_, const float right_, const float up_) noexcept
            {
            }

            /**
             *  Rotate the camera's orientation.
             */
            inline void Fly::rotate(const float /*unused*/, const float /*unused*/, const float /*unused*/) noexcept
            {
            }



        } // namespace camera
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_FLY_HPP
