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
            inline Orbit::Orbit(const glm::vec3& pos_, const glm::vec3& focus_, const glm::vec3& up_) noexcept
              : Camera(pos_, focus_, up_)
            {
            }



            //  == METHODS ==
            //  -- Control --
            inline void Orbit::move(const float forward_, const float right_, const float up_) noexcept
            {
                vec3 pos = math::convert::cart_to_polar(vec3f(_pos.x, _pos.y, _pos.z));

                pos.rho += forward_;
                pos.theta += right_;
                pos.phi += up_;

                pos = math::convert::polar_to_cart(pos);

                _pos.x = pos.x;
                _pos.y = pos.y;
                _pos.z = pos.z;

                update_view();
            }

            inline void Orbit::rotate(const float roll_, const float pitch_, const float yaw_) noexcept
            {
            }



        } // namespace camera
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_ORBIT_HPP
