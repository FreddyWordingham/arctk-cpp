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
#include <iostream>
#include <map>
#include <string>
#include <vector>

//  -- Graphical --
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/exit.hpp>



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
          private:
            //  -- Handle --
            const GLuint _handle; //!< Handle of the shader.

            //  -- Uniforms Handles --
            const GLint                        _model;    //!< Model matrix uniform handle.
            const GLint                        _view;     //!< View matrix uniform handle.
            const GLint                        _proj;     //!< Projection matrix uniform handle.
            const std::map<std::string, GLint> _uniforms; //!< Additional uniform mappings.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Shader(const std::string& vert_code_, const std::string& frag_code_, const std::vector<std::string>& uniform_names_) noexcept;
            inline Shader(const std::string& vert_code_, const std::string& geom_code_, const std::string& frag_code_, const std::vector<std::string>& uniform_names_) noexcept;

            //  -- Initialisation --
            inline GLuint                       init_handle(const std::string& vert_code_, const std::string& frag_code_) const noexcept;
            inline GLuint                       init_handle(const std::string& vert_code_, const std::string& geom_code_, const std::string& frag_code_) const noexcept;
            inline GLuint                       init_sub_shader(const std::string& code_, GLenum type_) const noexcept;
            inline GLint                        init_uniform(const std::string& name_) const noexcept;
            inline std::map<std::string, GLint> init_uniforms(const std::vector<std::string>& uniform_names_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline bool has_uniform(const std::string& name_) const noexcept;

            //  -- Setters --
            inline void set_model(const glm::mat4& model_mat_) noexcept;
            inline void set_view(const glm::mat4& view_mat_) noexcept;
            inline void set_proj(const glm::mat4& proj_mat_) noexcept;
            inline void set_uniform(const std::string& name_, const int val_) noexcept;
            inline void set_uniform(const std::string& name_, const float val_) noexcept;
            inline void set_uniform(const std::string& name_, const glm::vec2& val_) noexcept;
            inline void set_uniform(const std::string& name_, const glm::vec3& val_) noexcept;
            inline void set_uniform(const std::string& name_, const glm::vec4& val_) noexcept;
            inline void set_uniform(const std::string& name_, const glm::mat2& val_) noexcept;
            inline void set_uniform(const std::string& name_, const glm::mat3& val_) noexcept;
            inline void set_uniform(const std::string& name_, const glm::mat4& val_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a shader program from vertex and fragment sub-shader programs.
         *
         *  @param  vert_code_      Vertex sub-shader code.
         *  @param  frag_code_      Fragment sub-shader code.
         *  @param  uniform_names_  Vector of additional uniform names.
         *
         *  @pre    vert_code_ must not be empty.
         *  @pre    frag_code_ must not be empty.
         */
        inline Shader::Shader(const std::string& vert_code_, const std::string& frag_code_, const std::vector<std::string>& uniform_names_) noexcept
          : _handle(init_handle(vert_code_, frag_code_))
          , _model(init_uniform("model"))
          , _view(init_uniform("view"))
          , _proj(init_uniform("proj"))
          , _uniforms(init_uniforms(uniform_names_))
        {
            PRE(!vert_code_.empty());
            PRE(!frag_code_.empty());
        }

        /**
         *  Construct a shader program from vertex, geometry and fragment sub-shader programs.
         *
         *  @param  vert_code_      Vertex sub-shader code.
         *  @param  geom_code_      Geometry sub-shader code.
         *  @param  frag_code_      Fragment sub-shader code.
         *  @param  uniform_names_  Vector of additional uniform names.
         *
         *  @pre    vert_code_ must not be empty.
         *  @pre    geom_code_ must not be empty.
         *  @pre    frag_code_ must not be empty.
         */
        inline Shader::Shader(const std::string& vert_code_, const std::string& geom_code_, const std::string& frag_code_, const std::vector<std::string>& uniform_names_) noexcept
          : _handle(init_handle(vert_code_, geom_code_, frag_code_))
          , _model(init_uniform("model"))
          , _view(init_uniform("view"))
          , _proj(init_uniform("proj"))
          , _uniforms(init_uniforms(uniform_names_))
        {
            PRE(!vert_code_.empty());
            PRE(!geom_code_.empty());
            PRE(!frag_code_.empty());
        }


        //  -- Initialisation --
        inline GLuint Shader::init_handle(const std::string& vert_code_, const std::string& frag_code_) const noexcept
        {
            PRE(!vert_code_.empty());
            PRE(!frag_code_.empty());

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

                std::cerr << "Unable to construct gui Shader.\n"
                          << "Shader linking failed with error: `" << error_text << "`.";

                std::exit(exit::error::SHADER_LINKING_FAILED);
            }

            glDeleteShader(vert_shader);
            glDeleteShader(frag_shader);

            return (handle);
        }

        inline GLuint Shader::init_handle(const std::string& vert_code_, const std::string& geom_code_, const std::string& frag_code_) const noexcept
        {
            PRE(!vert_code_.empty());
            PRE(!geom_code_.empty());
            PRE(!frag_code_.empty());

            const GLuint vert_shader = init_sub_shader(vert_code_, GL_VERTEX_SHADER);
            const GLuint geom_shader = init_sub_shader(geom_code_, GL_GEOMETRY_SHADER);
            const GLuint frag_shader = init_sub_shader(frag_code_, GL_FRAGMENT_SHADER);

            const GLuint handle = glCreateProgram();
            glAttachShader(handle, vert_shader);
            glAttachShader(handle, geom_shader);
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

                std::cerr << "Unable to construct gui Shader.\n"
                          << "Shader linking failed with error: `" << error_text << "`.";

                std::exit(exit::error::SHADER_LINKING_FAILED);
            }

            glDeleteShader(vert_shader);
            glDeleteShader(geom_shader);
            glDeleteShader(frag_shader);

            return (handle);
        }

        /**
         *  Initialise a sub-shader program.
         *
         *  @param  code_   Sub-shader program code.
         *  @param  type_   Type of sub-shader to initialise.
         *
         *  @pre    code_ must not be empty.
         *
         *  @return Handle to the initialised sub-shader program.
         */
        inline GLuint Shader::init_sub_shader(const std::string& code_, const GLenum type_) const noexcept
        {
            PRE(!code_.empty());

            const char* code = code_.c_str();

            const GLuint sub_shader = glCreateShader(type_);
            glShaderSource(sub_shader, 1, &code, nullptr);
            glCompileShader(sub_shader);

            GLint success;
            glGetShaderiv(sub_shader, GL_COMPILE_STATUS, &success);
            if (success == GL_FALSE)
            {
                GLint log_length;
                glGetShaderiv(sub_shader, GL_INFO_LOG_LENGTH, &log_length);
                std::vector<char> error_log(static_cast<size_t>(log_length));

                glGetShaderInfoLog(sub_shader, log_length, nullptr, error_log.data());
                const std::string error_text(begin(error_log), end(error_log));

                std::cerr << "Unable to construct gui Shader.\n"
                          << "Shader compilation failed with error: `" << error_text << "`.";

                std::exit(exit::error::SHADER_COMPILATION_FAILED);
            }

            POST(sub_shader != 0);

            return (sub_shader);
        }

        inline GLint Shader::init_uniform(const std::string& name_) const noexcept
        {
            PRE(!name_.empty());

            GLint handle = glGetUniformLocation(_handle, name_.c_str());

            if (handle < 0)
            {
                std::cerr << "Unable to construct gui shader.\n"
                          << "Failed to determine the location of the: `" << name_ << "` uniform within the shader.\n";

                std::exit(exit::error::SHADER_UNIFORM_NOT_FOUND);
            }

            return (handle);
        }

        inline std::map<std::string, GLint> Shader::init_uniforms(const std::vector<std::string>& uniform_names_) const noexcept
        {
            std::map<std::string, GLint> uniforms;

            for (size_t i = 0; i < uniform_names_.size(); ++i)
            {
                PRE(uniform_names_[i] != "model");
                PRE(uniform_names_[i] != "view");
                PRE(uniform_names_[i] != "proj");

                if (uniforms.find(uniform_name_[i]) != uniforms.end())
                {
                    std::cerr << "Unable to construct gui shader.\n"
                              << "Uniform name: `" << uniform_name_[i] << "` may only have a single handle.\n";

                    std::exit(exit::error::SHADER_UNIFORM_DUPLICATE);
                }

                uniforms.emplace(std::make_pair(uniform_name_[i], init_uniform(uniform_names_[i]))));
            }

            return (uniforms);
        }



        //  == METHODS ==
        //  -- Getters --
        inline bool Shader::has_uniform(const std::string& name_) const noexcept
        {
            return (_uniforms.find(name_) != _uniforms.end());
        }


        //  -- Setters --
        inline void Shader::set_model(const glm::mat4& model_mat_) noexcept
        {
            glUseProgram(_handle);
            glUniformMatrix4fv(_model, 1, GL_FALSE, &model_mat_[0][0]);
        }

        inline void Shader::set_view(const glm::mat4& view_mat_) noexcept
        {
            glUseProgram(_handle);
            glUniformMatrix4fv(_model, 1, GL_FALSE, &view_mat_[0][0]);
        }

        inline void Shader::set_proj(const glm::mat4& proj_mat_) noexcept
        {
            glUseProgram(_handle);
            glUniformMatrix4fv(_model, 1, GL_FALSE, &proj_mat_[0][0]);
        }

        inline void Shader::set_uniform(const std::string& name_, const int val_) noexcept
        {
            PRE(_uniforms.find(name_) != _uniforms.end());

            glUseProgram(_handle);
            glUniform1i(_uniforms[name_], val_);
        }

        inline void Shader::set_uniform(const std::string& name_, const float val_) noexcept
        {
            PRE(_uniforms.find(name_) != _uniforms.end());

            glUseProgram(_handle);
            glUniform1f(_uniforms[name_], val_);
        }

        inline void Shader::set_uniform(const std::string& name_, const glm::vec2& val_) noexcept
        {
            PRE(_uniforms.find(name_) != _uniforms.end());

            glUseProgram(_handle);
            glUniform2fv(_uniforms[name_], 1, &val_[0]);
        }

        inline void Shader::set_uniform(const std::string& name_, const glm::vec3& val_) noexcept
        {
            PRE(_uniforms.find(name_) != _uniforms.end());

            glUseProgram(_handle);
            glUniform3fv(_uniforms[name_], 1, &val_[0]);
        }

        inline void Shader::set_uniform(const std::string& name_, const glm::vec4& val_) noexcept
        {
            PRE(_uniforms.find(name_) != _uniforms.end());

            glUseProgram(_handle);
            glUniform4fv(_uniforms[name_], 1, &val_[0]);
        }

        inline void Shader::set_uniform(const std::string& name_, const glm::mat2& val_) noexcept
        {
            PRE(_uniforms.find(name_) != _uniforms.end());

            glUseProgram(_handle);
            glUniformMatrix2fv(_uniforms[name_], 1, GL_FALSE, &val_[0][0]);
        }

        inline void Shader::set_uniform(const std::string& name_, const glm::mat3& val_) noexcept
        {
            PRE(_uniforms.find(name_) != _uniforms.end());

            glUseProgram(_handle);
            glUniformMatrix3fv(_uniforms[name_], 1, GL_FALSE, &val_[0][0]);
        }

        inline void Shader::set_uniform(const std::string& name_, const glm::mat4& val_) noexcept
        {
            PRE(_uniforms.find(name_) != _uniforms.end());

            glUseProgram(_handle);
            glUniformMatrix4fv(_uniforms[name_], 1, GL_FALSE, &val_[0][0]);
        }



    } // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_HPP
