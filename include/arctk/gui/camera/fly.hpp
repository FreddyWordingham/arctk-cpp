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



//  == BASE ==
#include <arctk/gui/camera.hpp>



//  == IMPORTS ==
//  -- Graphical --
#include <glm/glm.hpp>



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
                inline explicit Fly(const glm::vec3& pos_, const glm::vec3& dir_ = glm::vec3(0.0f, 1.0f, 0.0f), const glm::vec3& up_ = glm::vec3(0.0f, 0.0f, 1.0f), float speed_) noexcept;


                //  == METHODS ==
              public:
                //  -- Control --
                inline void move(float forward_, float right_, float up_) noexcept override;
                inline void rotate(float roll_, float pitch_, float yaw_) noexcept override;
            };



        } // namespace camera
    }     // namespace gui
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/gui/camera/fly.inl>



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_FLY_HPP
