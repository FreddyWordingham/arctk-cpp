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
        };



        //  == INSTANTIATION --



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



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_CAMERA_HPP
