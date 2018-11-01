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
             *  Camera class with orbital controls.
             */
            class Orbit : public Camera
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Orbit(const glm::vec3& pos_, const glm::vec3& focus_ = glm::vec3(0.0f, 0.0f, 0.0f), const glm::vec3& up_ = glm::vec3(0.0f, 0.0f, 1.0f), float speed_ = 1.0f) noexcept;


                //  == METHODS ==
              public:
                //  -- Control --
                inline void move(float forward_, float right_, float up_) noexcept override;
                inline void rotate(float /*unused*/, float /*unused*/, float /*unused*/) noexcept override;
            };



        } // namespace camera
    }     // namespace gui
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/gui/camera/orbit.inl>



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_ORBIT_HPP
