/**
 *  @file   arctk/gui/shader.hpp
 *  @date   01/08/2018
 *  @author Freddy Wordingham
 *
 *  Shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_HPP
#define ARCTK_GUI_SHADER_HPP



//  == IMPORTS ==
//  -- Std --
#include <string>

//  -- Graphical --
#include <GL/glew.h>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {



        //  == CLASS ==
        /**
         *  Shader class.
         */
        class Shader
        {
            //  == FIELDS ==
          protected:
            //  -- Handle --
            const GLuint _handle; //!< Handle of the shader.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Shader(const std::string& vert_code_, const std::string& frag_code_) noexcept;
            inline Shader(const std::string& vert_code_, const std::string& geom_code_, const std::string& frag_code_) noexcept;
            inline Shader(const Shader&) = default; //!< Defaulted copy constructor.
            inline Shader(Shader&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Shader() noexcept = 0;


            //  == INSTANTIATION ==
          protected:
            //  -- Initialisation --
            inline GLuint init_handle(const std::string& vert_code_, const std::string& frag_code_) const noexcept;
            inline GLuint init_handle(const std::string& vert_code_, const std::string& geom_code_, const std::string& frag_code_) const noexcept;
            inline GLuint init_sub_shader(const std::string& code_, GLenum type_) const noexcept;
            inline GLint  init_uniform(const std::string& name_) const noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Shader& operator=(const Shader&) = delete; //!< Deleted copy operator. @return Reference to copied object.
            inline Shader& operator=(Shader&&) = delete;      //!< Deleted move operator. @return Reference to moved object.
        };



    } // namespace gui
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/gui/shader.inl>



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_HPP
