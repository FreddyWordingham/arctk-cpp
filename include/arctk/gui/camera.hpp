/**
 *  @file   arctk/gui/camera.hpp
 *  @date   04/06/2018
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
//  -- Graphical --
#include <glm/glm.hpp>



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
          private:
            //  -- Positioning --
            glm::vec3 _pos;
            glm::vec3 _dir;
            glm::vec3 _up;

            //  -- Uniform --
            glm::mat4                        _mvp;
            std::map<std::string, int>       _int_uniform;
            std::map<std::string, float>     _float_uniform;
            std::map<std::string, glm::vec2> _vec2_uniform;
            std::map<std::string, glm::vec3> _vec3_uniform;
            std::map<std::string, glm::vec4> _vec4_uniform;
            std::map<std::string, glm::mat2> _mat2_uniform;
            std::map<std::string, glm::mat3> _mat3_uniform;
            std::map<std::string, glm::mat4> _mat4_uniform;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Camera(const glm::vec3& pos_, const glm::vec3& dir_, const glm::vec3& up_) noexcept;

            //  -- Destructors --
            virtual inline ~Camera() noexcept = 0;


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
            virtual inline void update_mvp() noexcept = 0;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        inline Camera::Camera(const glm::vec3& pos_, const glm::vec3& dir_, const glm::vec3& up_) noexcept
          : _pos(pos_)
          , _dir(dir_)
          , _up(up_)
        {
            update_mvp();
        }


        //  -- Destructors --
        inline Camera::~Camera() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        inline const glm::vec3& Camera::pos() const noexcept
        {
            return (_pos);
        }

        inline const glm::vec3& Camera::dir() const noexcept
        {
            return (_dir);
        }

        inline const glm::vec3& Camera::up() const noexcept
        {
            return (_up);
        }

        inline const glm::mat4& Camera::mvp() const noexcept
        {
            return (_mvp);
        }

        inline int Camera::int_uniform(const std::string& name_) const noexcept
        {
            assert(_int_uniform.find(name_) != _int_uniform.end());

            return (_int_uniform.find(name_)->second);
        }

        inline float Camera::float_uniform(const std::string& name_) const noexcept
        {
            assert(_float_uniform.find(name_) != _float_uniform.end());

            return (_float_uniform.find(name_)->second);
        }

        inline const glm::vec2& Camera::vec2_uniform(const std::string& name_) const noexcept
        {
            assert(_vec2_uniform.find(name_) != _vec2_uniform.end());

            return (_vec2_uniform.find(name_)->second);
        }

        inline const glm::vec3& Camera::vec3_uniform(const std::string& name_) const noexcept
        {
            assert(_vec3_uniform.find(name_) != _vec3_uniform.end());

            return (_vec3_uniform.find(name_)->second);
        }

        inline const glm::vec4& Camera::vec4_uniform(const std::string& name_) const noexcept
        {
            assert(_vec4_uniform.find(name_) != _vec4_uniform.end());

            return (_vec4_uniform.find(name_)->second);
        }

        inline const glm::mat2& Camera::mat2_uniform(const std::string& name_) const noexcept
        {
            assert(_mat2_uniform.find(name_) != _mat2_uniform.end());

            return (_mat2_uniform.find(name_)->second);
        }

        inline const glm::mat3& Camera::mat3_uniform(const std::string& name_) const noexcept
        {
            assert(_mat3_uniform.find(name_) != _mat3_uniform.end());

            return (_mat3_uniform.find(name_)->second);
        }

        inline const glm::mat4& Camera::mat4_uniform(const std::string& name_) const noexcept
        {
            assert(_mat4_uniform.find(name_) != _mat4_uniform.end());

            return (_mat4_uniform.find(name_)->second);
        }


        //  -- Setters --
        inline void Camera::set_fov(const float fov_) noexcept
        {
            _fov = fov_;
        }

        inline void Camera::set_aspect_ratio(const float aspect_ratio_) noexcept
        {
            _aspect_ratio = aspect_ratio_;
        }

        inline void Camera::set_pos(const glm::vec3& pos_) noexcept
        {
            _pos = pos_;

            update_mvp();
        }

        inline void Camera::set_dir(const glm::vec3& dir_) noexcept
        {
            _dir = dir_;

            _up = glm::normalize(glm::cross(glm::normalize(glm::cross(_dir, _up)), _dir));

            update_mvp();
        }

        inline void Camera::set_up(const glm::vec3& up_) noexcept
        {
            _up = up_;

            update_mvp();
        }

        inline void Camera::set_int_uniform(const std::string& name_, const int int_) noexcept
        {
            assert(_int_uniform.find(name_) != _int_uniform.end());

            _int_uniform.emplace(std::make_pair(name_, int_));
        }

        inline void Camera::set_float_uniform(const std::string& name_, const float float_) noexcept
        {
            assert(_float_uniform.find(name_) != _float_uniform.end());

            _float_uniform.emplace(std::make_pair(name_, float_));
        }

        inline void Camera::set_vec2_uniform(const std::string& name_, const glm::vec2& vec2_) noexcept
        {
            assert(_vec2_uniform.find(name_) != _vec2_uniform.end());

            _vec2_uniform.emplace(std::make_pair(name_, vec2_));
        }

        inline void Camera::set_vec3_uniform(const std::string& name_, const glm::vec3& vec3_) noexcept
        {
            assert(_vec3_uniform.find(name_) != _vec3_uniform.end());

            _vec3_uniform.emplace(std::make_pair(name_, vec3_));
        }

        inline void Camera::set_vec4_uniform(const std::string& name_, const glm::vec4& vec4_) noexcept
        {
            assert(_vec4_uniform.find(name_) != _vec4_uniform.end());

            _vec4_uniform.emplace(std::make_pair(name_, vec4_));
        }

        inline void Camera::set_mat2_uniform(const std::string& name_, const glm::mat2& mat2_) noexcept
        {
            assert(_mat2_uniform.find(name_) != _mat2_uniform.end());

            _mat2_uniform.emplace(std::make_pair(name_, mat2_));
        }

        inline void Camera::set_mat3_uniform(const std::string& name_, const glm::mat3& mat3_) noexcept
        {
            assert(_mat3_uniform.find(name_) != _mat3_uniform.end());

            _mat3_uniform.emplace(std::make_pair(name_, mat3_));
        }

        inline void Camera::set_mat4_uniform(const std::string& name_, const glm::mat4& mat4_) noexcept
        {
            assert(_mat4_uniform.find(name_) != _mat4_uniform.end());

            _mat4_uniform.emplace(std::make_pair(name_, mat4_));
        }


        //  -- Control --
        inline void Camera::move(const glm::vec3& vec_) noexcept
        {
            _pos += vec_;

            update_mvp();
        }

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
