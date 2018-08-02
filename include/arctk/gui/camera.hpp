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
          protected:
            //  -- Positioning --
            glm::vec3 _pos;   //!< Position of the camera.
            glm::vec3 _focus; //!< Foxus position of the camera.
            glm::vec3 _up;    //!< Up direction of the camera.

          private:
            //  -- Uniform --
            glm::mat4 _view{}; //!< View transformation matrix.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Camera(const glm::vec3& pos_, const glm::vec3& focus_, const glm::vec3& up_) noexcept;
            inline Camera(const Camera&) = default; //!< Defaulted copy constructor.
            inline Camera(Camera&&)      = default; //!< Defaulted move constructor.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const glm::mat4& view() const noexcept;

            //  -- Control --
            virtual inline void move(const glm::vec3& vec_) noexcept   = 0;
            virtual inline void rotate(const glm::vec3& vec_) noexcept = 0;

          protected:
            //  -- Updating --
            inline void update_view() noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a camera at a position, facing a direction.
         *
         *  @param  pos_    Initial position of the camera.
         *  @param  focus_  Focus position of the camera.
         *  @param  up_     Up direction of the camera.
         */
        inline Camera::Camera(const glm::vec3& pos_, const glm::vec3& focus_, const glm::vec3& up_) noexcept
          : _pos(pos_)
          , _focus(focus_)
          , _up(up_)
        {
            update_view();
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the view matrix of the camera.
         *
         *  @return View matrix of the camera.
         */
        inline const glm::mat4& Camera::view() const noexcept
        {
            return (_view);
        }


        //  -- Updating --
        /**
         *  Update the view matrix.
         */
        inline void Camera::update_view() noexcept
        {
            _view = glm::lookAt(_pos, _focus, _up);
        }



    } // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_HPP
