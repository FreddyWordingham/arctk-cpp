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
//  -- Graphical --
#include <glm/glm.hpp>



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
            glm::mat4 _view{}; //!< View matrix.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Camera(const glm::vec3& pos_, const glm::vec3& focus_, const glm::vec3& up_) noexcept;
            inline Camera(const Camera&) = default; //!< Defaulted copy constructor.
            inline Camera(Camera&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Camera() noexcept = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Camera& operator=(const Camera&) = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Camera& operator=(Camera&&) = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const glm::mat4& view() const noexcept;

            //  -- Control --
            virtual inline void move(const glm::vec3& vec_) noexcept   = 0; //!< Move the camera about the scene.    @param  vec_    Movement vector.
            virtual inline void rotate(const glm::vec3& vec_) noexcept = 0; //!< Rotate the camera around the scene.    @param  vec_    Rotation vector.

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


        //  -- Destructors --
        /**
         *  Defaulted destructor method.
         */
        inline Camera::~Camera() noexcept = default;



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
