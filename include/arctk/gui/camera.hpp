/**
 *  @file   arctk/gui/camera.hpp
 *  @date   02/08/2018
 *  @author Freddy Wordingham
 *
 *  Scene camera class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_CAMERA_HPP
#define ARCTK_GUI_CAMERA_HPP



//  == IMPORTS ==



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {



        //  == CLASS ==
        /**
         *  Scene camera class.
         */
        class Camera
        {
            //  == FIELDS ==
          private:
            //  -- Positioning --
            glm::vec3 _pos; //!< Position of the camera.
            glm::vec3 _dir; //!< Direction the camera is facing.
            glm::vec3 _up;  //!< Up direction of the camera.

            //  -- Uniform --
            glm::mat4 _view{}; //!< View transformation matrix.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Camera(const glm::vec3& pos_, const glm::vec3& dir_, const glm::vec3& up_) noexcept;


            //  == METHODS ==
          public:
          private:
            //  -- Updating --
            inline update_view() noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a camera at a position, facing a direction.
         *
         *  @param  pos_    Initial position of the camera.
         *  @param  dir_    Direction for the camera to face.
         *  @param  up_     Up direction of the camera.
         */
        inline Camera::Camera(const glm::vec3& pos_, const glm::vec3& dir_, const glm::vec3& up_) noexcept
          : _pos(pos_)
          , _dir(dir_)
          , _up(up_)
        {
        }



        //  == METHODS ==
        //  -- Updating --
        inline Camera::update_view() noexcept
        {
            _view = glm::lookAt(_pos, _pos + _dir, _up);
        }



    } // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_HPP
