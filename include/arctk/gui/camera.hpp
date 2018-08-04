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
            inline const glm::mat4& view() const noexcept;

            //  -- Control --
            virtual inline void move_forward(const float dist_) noexcept = 0; //!< Move the camera forward. @param  dist_   Distance to move the camera forward.
            virtual inline void move_right(const float dist_) noexcept   = 0; //!< Move the camera right.   @param  dist_   Distance to move the camera right.
            virtual inline void move_up(const float dist_) noexcept      = 0; //!< Move the camera upwards. @param  dist_   Distance to move the camera up.
            virtual inline void rotate_roll(const float ang_) noexcept   = 0; //!< Rotate through a roll.   @param  ang_    Angle to rotate.
            virtual inline void rotate_pitch(const float ang_) noexcept  = 0; //!< Rotate through a pitch.  @param  ang_    Angle to rotate.
            virtual inline void rotate_yaw(const float ang_) noexcept    = 0; //!< Rotate through a yaw.    @param  ang_    Angle to rotate.

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
