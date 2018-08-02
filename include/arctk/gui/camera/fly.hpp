/**
 *  @file   arctk/gui/camera/fly.hpp
 *  @date   02/08/2018
 *  @author Freddy Wordingham
 *
 *  Scene camera class with fly controls.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_CAMERA_FLY_HPP
#define ARCTK_GUI_CAMERA_FLY_HPP



//  == IMPORTS ==
//  -- Graphical --
#include <glm/glm.hpp>

//  -- Arctk --
#include <arctk/camera/fly.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {
        namespace camera //! camera namespace
        {



            //  == CONSTANTS ==
            //  -- Culling --
            constexpr const float FLY_NEAR_CULL_DIST = 1e-3f; //!< Far culling distance for the fly camera.
            constexpr const float FLY_FAR_CULL_DIST  = 1e+3f; //!< Near culling distance for the fly camera.



            //  == CLASS ==
            /**
             *  Scene camera class with fly controls.
             */
            class Fly : public Camera
            {
                //  == FIELDS ==
              private:
                //  -- Positioning --
                glm::vec3 _dir; //!< Direction of the camera.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Fly(const glm::vec3& pos_, const glm::vec3& dir_ = glm::vec3(0.0f, 1.0f, 0.0f), const glm::vec3& up_ = glm::vec3(0.0f, 0.0f, 1.0f) noexcept;


                //  == METHODS ==
              public:
                //  -- Control --
                inline void move(const glm::vec3& vec_) noexcept;
                inline void rotate(const glm::vec3& vec_) noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Fly::Fly(const glm::vec3& pos_, const glm::vec3& dir_, const glm::vec3& up_) noexcept
              : Camera(pos_, pos_ + dir_, up_)
              , _dir(dir_)
            {
            }



            //  == METHODS ==
            //  -- Control --
            /**
             *  Move the camera forward, right and up.
             *
             *  @param  vec_    Vector specifying the amount to move in the forward, right and up directions.
             */
            inline void Fly::move(const glm::vec3& vec_) noexcept
            {
                _pos += dir_ * vec_.x;
                _pos += glm::normalise(glm::cross(dir_, vec_)) * vec_.y;
                _pos += up_ * vec_.z;
            }

            inline void Fly::rotate(const glm::vec3& vec_) noexcept
            {
            }



        } // namespace camera
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_FLY_HPP
