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
            //  -- Movement --
            float _speed; //!< Movement speed.

            //  -- Positioning --
            glm::vec3 _pos;   //!< Position of the camera.
            glm::vec3 _focus; //!< Focus position of the camera.
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
            inline const glm::vec3& pos() const noexcept;
            inline const glm::mat4& view() const noexcept;

            //  -- Control --
            inline void  accelerate(float delta_) noexcept;
            virtual void move(
              float forward_, float right_,
              float up_) noexcept = 0; //!< Move the camera position.   @param  forward_    Distance to move the camera forward.    @param  right_      Distance to move the camera to the right.   @param  up_         Distance to move the camera upward.
            virtual void rotate(float roll_, float pitch_,
                                float yaw_) noexcept = 0; //!< Rotate the camera's orientation.    @param  roll_   Angle to roll the camera.   @param  pitch_  Angle to pitch the camera.  @param  yaw_    Angle to yaw the camera.

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
          : _speed(1.0f)
          , _pos(pos_)
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
         *  Get the position of the camera.
         *
         *  @return Position of the camera.
         */
        inline const glm::vec3& Camera::pos() const noexcept
        {
            return (_pos);
        }

        /**
         *  Get the view matrix of the camera.
         *
         *  @return View matrix of the camera.
         */
        inline const glm::mat4& Camera::view() const noexcept
        {
            return (_view);
        }


        //  -- Control --
        /**
         *  Accelerate the camera's speed.
         *
         *  @param  delta_  Speed to accelerate the camera.
         */
        inline void Camera::accelerate(const float delta_) noexcept
        {
            _speed += delta_;

            if (_speed < 0.0f)
            {
                _speed = 0.0f;
            }
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
