/**
 *  @file   arctk/gui/shader.hpp
 *  @date   04/06/2018
 *  @author Freddy Wordingham
 *
 *  Graphical shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_HPP
#define ARCTK_GUI_SHADER_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_GUI



//  == IMPORTS ==
//  -- Std --
#include <map>

//  -- Graphical --
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//  -- Arctk --
#include <arctk/gui/uniform.hpp>
#include <arctk/log.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical user interface namespace
    {



        //  == CLASS ==
        /**
         *  Graphical shader class used for rendering actors.
         */
        class Shader
        {
            //  == FIELDS ==
          private:
            //  -- Handle --
            const GLuint _handle; //!< Handle of the shader.

            //  -- Uniforms --
            const GLint                    _mvp;     //!< Model-view-projection uniform handle.
            const GLint                    _model;   //!< Model uniform handle.
            std::map<std::string, Uniform> _uniform; //!< Uniform mappings.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Shader(const std::string& vert_code_, const std::string& frag_code_) noexcept;
            inline Shader(const std::string& vert_code_, const std::string& geom_code_, const std::string& frag_code_) noexcept;

          private:
            //  -- Initialisation --
            inline GLuint init_handle(const std::string& vert_code_, const std::string& frag_code_) const noexcept;



            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        inline Shader::Shader(const std::string& vert_code_, const std::string& frag_code_) noexcept
          : _handle(init_handle(vert_code_, frag_code_))
          , _mvp(init_mvp())
          , _model(init_model())
        {
        }

        inline Shader::Shader(const std::string& vert_code_, const std::string& geom_code_, const std::string& frag_code_) noexcept
          : _handle(init_handle(vert_code_, geom_code_, frag_code_))
          , _mvp(init_mvp())
          , _model(init_model())
        {
        }


        //  -- Initialisation --
        inline GLuint Shader::init_handle(const std::string& vert_code_, const std::string& frag_code_) const noexcept
        {
            const GLuint vert_shader = init_sub_shader(vert_code_, GL_VERTEX_SHADER);
            const GLuint frag_shader = init_sub_shader(frag_code_, GL_FRAGMENT_SHADER);

            const GLuint handle = glCreateProgram();
            glAttachShader(handle, vert_shader);
            glAttachShader(handle, frag_shader);
            glLinkProgram(handle);

            GLint success;
            glGetProgramiv(handle, GL_LINK_STATUS, &success);
            if (success == GL_FALSE)
            {
                GLint log_length;
                glGetProgramiv(handle, GL_INFO_LOG_LENGTH, &log_length);
                std::vector<char> error_log(static_cast<size_t>(log_length));

                glGetProgramInfoLog(handle, log_length, nullptr, error_log.data());
                std::string error_text(begin(error_log), end(error_log));

                ERROR(42) << "Unable to construct gui Shader.\n"
                          << "Shader linking failed with error: '" << error_text << "'.";
            }

            glDeleteShader(vert_shader);
            glDeleteShader(frag_shader);

            return (handle);
        }



        //  == METHODS ==
        //  -- Getters --



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_HPP
