/**
 *  @file   arctk/gui/camera.hpp
 *  @date   17/07/2018
 *  @author Freddy Wordingham
 *
 *  Rendering camera class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_CAMERA_HPP
#define ARCTK_GUI_CAMERA_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_GUI



//  == IMPORTS ==
//  -- Std --
#include <map>

//  -- Graphical --
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/transform.hpp>

//  -- Arctk --
#include <arctk/debug.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical user interface namespace
    {



        //  == CLASS ==
        /**
         *  Graphical rendering camera class.
         */
        class Camera
        {
            //  == FIELDS ==
          protected:
            //  -- Positioning --
            glm::vec3 _pos; //!< Position of the camera.
            glm::vec3 _dir; //!< Direction the camera is facing.
            glm::vec3 _up;  //!< Up direction of the camera.

            //  -- Uniform --
            glm::mat4 _view_proj{}; //!< View-projection matrix.

          private:
            //  -- Uniform --
            std::map<std::string, int>       _int_uniform{};   //!< Integer uniform map.
            std::map<std::string, float>     _float_uniform{}; //!< Float uniform map.
            std::map<std::string, glm::vec2> _vec2_uniform{};  //!< Vec2 uniform map.
            std::map<std::string, glm::vec3> _vec3_uniform{};  //!< Vec3 uniform map.
            std::map<std::string, glm::vec4> _vec4_uniform{};  //!< Vec4 uniform map.
            std::map<std::string, glm::mat2> _mat2_uniform{};  //!< Mat2 uniform map.
            std::map<std::string, glm::mat3> _mat3_uniform{};  //!< Mat3 uniform map.
            std::map<std::string, glm::mat4> _mat4_uniform{};  //!< Mat4 uniform map.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Camera(const glm::vec3& pos_, const glm::vec3& dir_, const glm::vec3& up_) noexcept;
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
            inline const glm::vec3& dir() const noexcept;
            inline const glm::vec3& up() const noexcept;
            inline const glm::mat4& mvp() const noexcept;
            inline int              int_uniform(const std::string& name_) const noexcept;
            inline float            float_uniform(const std::string& name_) const noexcept;
            inline const glm::vec2& vec2_uniform(const std::string& name_) const noexcept;
            inline const glm::vec3& vec3_uniform(const std::string& name_) const noexcept;
            inline const glm::vec4& vec4_uniform(const std::string& name_) const noexcept;
            inline const glm::mat2& mat2_uniform(const std::string& name_) const noexcept;
            inline const glm::mat3& mat3_uniform(const std::string& name_) const noexcept;
            inline const glm::mat4& mat4_uniform(const std::string& name_) const noexcept;

            //  -- Setters --
            inline void set_pos(const glm::vec3& pos_) noexcept;
            inline void set_dir(const glm::vec3& dir_) noexcept;
            inline void set_up(const glm::vec3& up_) noexcept;
            inline void set_int_uniform(const std::string& name_, int int_) noexcept;
            inline void set_float_uniform(const std::string& name_, float float_) noexcept;
            inline void set_vec2_uniform(const std::string& name_, const glm::vec2& vec2_) noexcept;
            inline void set_vec3_uniform(const std::string& name_, const glm::vec3& vec3_) noexcept;
            inline void set_vec4_uniform(const std::string& name_, const glm::vec4& vec4_) noexcept;
            inline void set_mat2_uniform(const std::string& name_, const glm::mat2& mat2_) noexcept;
            inline void set_mat3_uniform(const std::string& name_, const glm::mat3& mat3_) noexcept;
            inline void set_mat4_uniform(const std::string& name_, const glm::mat4& mat4_) noexcept;

            //  -- Control --
            inline void move(const glm::vec3& vec_) noexcept;
            inline void rotate(const glm::vec2& vec_) noexcept;

          private:
            //  -- Updating --
            virtual void update_mvp() noexcept = 0; //!< Update the model-view-projection matrix.
        };



        //  == INSTANTIATION --
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
         *  Get the facing direction of the camera.
         *
         *  @return Facing direction of the camera.
         */
        inline const glm::vec3& Camera::dir() const noexcept
        {
            return (_dir);
        }

        /**
         *  Get the up direction of the camera.
         *
         *  @return Up direction of the camera.
         */
        inline const glm::vec3& Camera::up() const noexcept
        {
            return (_up);
        }

        /**
         *  Get the model-view-projection matrix.
         *
         *  @return Model-view-projection matrix.
         */
        inline const glm::mat4& Camera::mvp() const noexcept
        {
            return (_mvp);
        }

        /**
         *  Get the value of an integer uniform variable.
         *
         *  @param  name_   Of the uniform.
         *
         *  @pre    name_ must exist within the integer uniform map.
         *
         *  @return Value of the uniform.
         */
        inline int Camera::int_uniform(const std::string& name_) const noexcept
        {
            PRE(_int_uniform.find(name_) != _int_uniform.end());

            return (_int_uniform.find(name_)->second);
        }
        /**
         *  Get the value of an float uniform variable.
         *
         *  @param  name_   Of the uniform.
         *
         *  @pre    name_ must exist within the float uniform map.
         *
         *  @return Value of the uniform.
         */
        inline float Camera::float_uniform(const std::string& name_) const noexcept
        {
            PRE(_float_uniform.find(name_) != _float_uniform.end());

            return (_float_uniform.find(name_)->second);
        }
        /**
         *  Get the value of an vec2 uniform variable.
         *
         *  @param  name_   Of the uniform.
         *
         *  @pre    name_ must exist within the vec2 uniform map.
         *
         *  @return Value of the uniform.
         */
        inline const glm::vec2& Camera::vec2_uniform(const std::string& name_) const noexcept
        {
            PRE(_vec2_uniform.find(name_) != _vec2_uniform.end());

            return (_vec2_uniform.find(name_)->second);
        }
        /**
         *  Get the value of an vec3 uniform variable.
         *
         *  @param  name_   Of the uniform.
         *
         *  @pre    name_ must exist within the vec3 uniform map.
         *
         *  @return Value of the uniform.
         */
        inline const glm::vec3& Camera::vec3_uniform(const std::string& name_) const noexcept
        {
            PRE(_vec3_uniform.find(name_) != _vec3_uniform.end());

            return (_vec3_uniform.find(name_)->second);
        }
        /**
         *  Get the value of an vec4 uniform variable.
         *
         *  @param  name_   Of the uniform.
         *
         *  @pre    name_ must exist within the vec4 uniform map.
         *
         *  @return Value of the uniform.
         */
        inline const glm::vec4& Camera::vec4_uniform(const std::string& name_) const noexcept
        {
            PRE(_vec4_uniform.find(name_) != _vec4_uniform.end());

            return (_vec4_uniform.find(name_)->second);
        }
        /**
         *  Get the value of an mat2 uniform variable.
         *
         *  @param  name_   Of the uniform.
         *
         *  @pre    name_ must exist within the mat2 uniform map.
         *
         *  @return Value of the uniform.
         */
        inline const glm::mat2& Camera::mat2_uniform(const std::string& name_) const noexcept
        {
            PRE(_mat2_uniform.find(name_) != _mat2_uniform.end());

            return (_mat2_uniform.find(name_)->second);
        }
        /**
         *  Get the value of an mat3 uniform variable.
         *
         *  @param  name_   Of the uniform.
         *
         *  @pre    name_ must exist within the mat3 uniform map.
         *
         *  @return Value of the uniform.
         */
        inline const glm::mat3& Camera::mat3_uniform(const std::string& name_) const noexcept
        {
            PRE(_mat3_uniform.find(name_) != _mat3_uniform.end());

            return (_mat3_uniform.find(name_)->second);
        }
        /**
         *  Get the value of an mat4 uniform variable.
         *
         *  @param  name_   Of the uniform.
         *
         *  @pre    name_ must exist within the mat4 uniform map.
         *
         *  @return Value of the uniform.
         */
        inline const glm::mat4& Camera::mat4_uniform(const std::string& name_) const noexcept
        {
            PRE(_mat4_uniform.find(name_) != _mat4_uniform.end());

            return (_mat4_uniform.find(name_)->second);
        }


        //  -- Setters --
        /**
         *  Set the camera position.
         *  Update the model-view-projection matrix.
         *
         *  @param  pos_    Position to move the camera to.
         */
        inline void Camera::set_pos(const glm::vec3& pos_) noexcept
        {
            _pos = pos_;

            update_mvp();
        }

        /**
         *  Set the camera facing direction.
         *  Update the up direction of the camera.
         *  Update the model-view-projection matrix.
         *
         *  @param  dir_    Direction to face the camera.
         */
        inline void Camera::set_dir(const glm::vec3& dir_) noexcept
        {
            _dir = dir_;

            _up = glm::normalize(glm::cross(glm::normalize(glm::cross(_dir, _up)), _dir));

            update_mvp();
        }

        /**
         *  Set the up direction of the camera.
         *
         *  @param  up_ Up direction of the camera.
         */
        inline void Camera::set_up(const glm::vec3& up_) noexcept
        {
            _up = up_;

            update_mvp();
        }

        /**
         *  Set the value of an integer uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  int_    Value of uniform.
         *
         *  @pre    name_ must exist within the integer uniform map.
         */
        inline void Camera::set_int_uniform(const std::string& name_, const int int_) noexcept
        {
            PRE(_int_uniform.find(name_) != _int_uniform.end());

            _int_uniform.emplace(std::make_pair(name_, int_));
        }

        /**
         *  Set the value of a float uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  float_  Value of uniform.
         *
         *  @pre    name_ must exist within the float uniform map.
         */
        inline void Camera::set_float_uniform(const std::string& name_, const float float_) noexcept
        {
            PRE(_float_uniform.find(name_) != _float_uniform.end());

            _float_uniform.emplace(std::make_pair(name_, float_));
        }

        /**
         *  Set the value of a vec2 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  vec2_   Value of uniform.
         *
         *  @pre    name_ must exist within the vec2 uniform map.
         */
        inline void Camera::set_vec2_uniform(const std::string& name_, const glm::vec2& vec2_) noexcept
        {
            PRE(_vec2_uniform.find(name_) != _vec2_uniform.end());

            _vec2_uniform.emplace(std::make_pair(name_, vec2_));
        }

        /**
         *  Set the value of a vec3 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  vec3_   Value of uniform.
         *
         *  @pre    name_ must exist within the vec3 uniform map.
         */
        inline void Camera::set_vec3_uniform(const std::string& name_, const glm::vec3& vec3_) noexcept
        {
            PRE(_vec3_uniform.find(name_) != _vec3_uniform.end());

            _vec3_uniform.emplace(std::make_pair(name_, vec3_));
        }

        /**
         *  Set the value of a vec4 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  vec4_   Value of uniform.
         *
         *  @pre    name_ must exist within the vec4 uniform map.
         */
        inline void Camera::set_vec4_uniform(const std::string& name_, const glm::vec4& vec4_) noexcept
        {
            PRE(_vec4_uniform.find(name_) != _vec4_uniform.end());

            _vec4_uniform.emplace(std::make_pair(name_, vec4_));
        }

        /**
         *  Set the value of a mat2 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  mat2_   Value of uniform.
         *
         *  @pre    name_ must exist within the mat2 uniform map.
         */
        inline void Camera::set_mat2_uniform(const std::string& name_, const glm::mat2& mat2_) noexcept
        {
            PRE(_mat2_uniform.find(name_) != _mat2_uniform.end());

            _mat2_uniform.emplace(std::make_pair(name_, mat2_));
        }

        /**
         *  Set the value of a mat3 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  mat3_   Value of uniform.
         *
         *  @pre    name_ must exist within the mat3 uniform map.
         */
        inline void Camera::set_mat3_uniform(const std::string& name_, const glm::mat3& mat3_) noexcept
        {
            PRE(_mat3_uniform.find(name_) != _mat3_uniform.end());

            _mat3_uniform.emplace(std::make_pair(name_, mat3_));
        }

        /**
         *  Set the value of a mat4 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  mat4_   Value of uniform.
         *
         *  @pre    name_ must exist within the mat4 uniform map.
         */
        inline void Camera::set_mat4_uniform(const std::string& name_, const glm::mat4& mat4_) noexcept
        {
            PRE(_mat4_uniform.find(name_) != _mat4_uniform.end());

            _mat4_uniform.emplace(std::make_pair(name_, mat4_));
        }


        //  -- Control --
        /**
         *  Mode the camera along a given vector.
         *
         *  @param  vec_    Vector to move the camera along.
         */
        inline void Camera::move(const glm::vec3& vec_) noexcept
        {
            _pos += vec_;

            update_mvp();
        }

        /**
         *  Rotate the camera using a given vector.
         *
         *  @param  vec_    Vector to rotate the camera with.
         */
        inline void Camera::rotate(const glm::vec2& vec_) noexcept
        {
            _dir = glm::rotate(_dir, vec_.x, _up);

            const glm::vec3 right = glm::normalize(glm::cross(_dir, _up));
            _dir                  = glm::rotate(_dir, vec_.y, right);

            _up = glm::normalize(glm::cross(right, _dir));

            update_mvp();
        }



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_HPP
