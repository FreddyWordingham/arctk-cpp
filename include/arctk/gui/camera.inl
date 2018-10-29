/**
 *  @file   arctk/gui/camera.inl
 *  @date   02/08/2018
 *  @author Freddy Wordingham
 *
 *  Scene camera class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_CAMERA_INL
#define ARCTK_GUI_CAMERA_INL



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {



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
#endif // ARCTK_GUI_CAMERA_INL
