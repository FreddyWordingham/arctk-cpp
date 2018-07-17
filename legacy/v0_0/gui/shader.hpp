/**
 *  @file   arctk/gui/shader.hpp
 *  @date   17/07/2018
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
#include <arctk/debug.hpp>
#include <arctk/gui/uniform.hpp>



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
            const GLint                    _mvp;       //!< Model-view-projection uniform handle.
            const GLint                    _model;     //!< Model uniform handle.
            std::map<std::string, Uniform> _uniform{}; //!< Uniform mappings.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Shader(const std::string& vert_code_, const std::string& frag_code_) noexcept;
            inline Shader(const std::string& vert_code_, const std::string& geom_code_, const std::string& frag_code_) noexcept;

          private:
            //  -- Initialisation --
            inline GLuint init_handle(const std::string& vert_code_, const std::string& frag_code_) const noexcept;
            inline GLuint init_handle(const std::string& vert_code_, const std::string& geom_code_, const std::string& frag_code_) const noexcept;
            inline GLuint init_sub_shader(const std::string& code_, GLenum type_) const noexcept;
            inline GLint  init_mvp() const noexcept;
            inline GLint  init_model() const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline GLuint                                handle() const noexcept;
            inline GLint                                 mvp() const noexcept;
            inline GLint                                 model() const noexcept;
            inline const std::map<std::string, Uniform>& uniform() const noexcept;

            //  -- Setters --
            inline void add_uniform(const std::string& name_, Uniform::stored type_, Uniform::controller control_) noexcept;
            inline void set_uniform(const std::string& name_, int int_) noexcept;
            inline void set_uniform(const std::string& name_, float float_) noexcept;
            inline void set_uniform(const std::string& name_, const glm::vec2& vec2_) noexcept;
            inline void set_uniform(const std::string& name_, const glm::vec3& vec3_) noexcept;
            inline void set_uniform(const std::string& name_, const glm::vec4& vec4_) noexcept;
            inline void set_uniform(const std::string& name_, const glm::mat2& mat2_) noexcept;
            inline void set_uniform(const std::string& name_, const glm::mat3& mat3_) noexcept;
            inline void set_uniform(const std::string& name_, const glm::mat4& mat4_) noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a shader program from vertex and fragment sub-shader programs.
         *
         *  @param  vert_code_  Vertex sub-shader code.
         *  @param  frag_code_  Fragment sub-shader code.
         *
         *  @pre    vert_code_ must not be empty.
         *  @pre    frag_code_ must not be empty.
         */
        inline Shader::Shader(const std::string& vert_code_, const std::string& frag_code_) noexcept
          : _handle(init_handle(vert_code_, frag_code_))
          , _mvp(init_mvp())
          , _model(init_model())
        {
            assert(!vert_code_.empty());
            assert(!frag_code_.empty());
        }

        /**
         *  Construct a shader program from vertex, geometry and fragment sub-shader programs.
         *
         *  @param  vert_code_  Vertex sub-shader code.
         *  @param  geom_code_  Geometry sub-shader code.
         *  @param  frag_code_  Fragment sub-shader code.
         *
         *  @pre    vert_code_ must not be empty.
         *  @pre    geom_code_ must not be empty.
         *  @pre    frag_code_ must not be empty.
         */
        inline Shader::Shader(const std::string& vert_code_, const std::string& geom_code_, const std::string& frag_code_) noexcept
          : _handle(init_handle(vert_code_, geom_code_, frag_code_))
          , _mvp(init_mvp())
          , _model(init_model())
        {
            assert(!vert_code_.empty());
            assert(!geom_code_.empty());
            assert(!frag_code_.empty());
        }


        //  -- Initialisation --
        /**
         *  Initialise a complete shader program.
         *
         *  @param  vert_code_  Vertex sub-shader code.
         *  @param  frag_code_  Fragment sub-shader code.
         *
         *  @pre    vert_code_ must not be empty.
         *  @pre    frag_code_ must not be empty.
         *
         *  @return Handle to a complete shader program.
         */
        inline GLuint Shader::init_handle(const std::string& vert_code_, const std::string& frag_code_) const noexcept
        {
            assert(!vert_code_.empty());
            assert(!frag_code_.empty());

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

        /**
         *  Initialise a complete shader program.
         *
         *  @param  vert_code_  Vertex sub-shader code.
         *  @param  geom_code_  Geometry sub-shader code.
         *  @param  frag_code_  Fragment sub-shader code.
         *
         *  @pre    vert_code_ must not be empty.
         *  @pre    geom_code_ must not be empty.
         *  @pre    frag_code_ must not be empty.
         *
         *  @return Handle to a complete shader program.
         */
        inline GLuint Shader::init_handle(const std::string& vert_code_, const std::string& geom_code_, const std::string& frag_code_) const noexcept
        {
            assert(!vert_code_.empty());
            assert(!geom_code_.empty());
            assert(!frag_code_.empty());

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

                ERROR(42) << "Unable to construct gui Shader.\n"
                          << "Shader linking failed with error: '" << error_text << "'.";
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
         *  @return Handle to the initialised sub-shader program.
         */
        inline GLuint Shader::init_sub_shader(const std::string& code_, const GLenum type_) const noexcept
        {
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

                ERROR(42) << "Unable to construct gui Shader.\n"
                          << "Shader compilation failed with error: '" << error_text << "'.";
            }

            assert(sub_shader != 0);

            return (sub_shader);
        }

        /**
         *  Initialise handle the the shader's mvp handle.
         *
         *  @return Initialised mvp uniform handle.
         */
        inline GLint Shader::init_mvp() const noexcept
        {
            GLint mvp = glGetUniformLocation(_handle, "mvp");

            if (mvp < 0)
            {
                ERROR(42) << "Unable to construct gui Shader.\n"
                          << "Failed to determine the uniform location of: mvp within the shader.";
            }

            return (mvp);
        }

        /**
         *  Initialise handle the the shader's model matrix handle.
         *
         *  @return Initialised model matrix uniform handle.
         */
        inline GLint Shader::init_model() const noexcept
        {
            GLint model = glGetUniformLocation(_handle, "model");

            if (model < 0)
            {
                ERROR(42) << "Unable to construct gui Shader.\n"
                          << "Failed to determine the uniform location of: model within the shader.";
            }

            return (model);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the shader program handle.
         *
         *  @return Shader program handle.
         */
        inline GLuint Shader::handle() const noexcept
        {
            return (_handle);
        }

        /**
         *  Get the Model-view-projection matrix uniform handle.
         *
         *  @return Model-view-projection matrix uniform handle.
         */
        inline GLint Shader::mvp() const noexcept
        {
            return (_mvp);
        }

        /**
         *  Get the Model matrix uniform handle.
         *
         *  @return Model matrix uniform handle.
         */
        inline GLint Shader::model() const noexcept
        {
            return (_model);
        }

        /**
         *  Get the uniform map.
         *
         *  @return Uniform map.
         */
        inline const std::map<std::string, Uniform>& Shader::uniform() const noexcept
        {
            return (_uniform);
        }


        //  -- Setters --
        /**
         *  Add a uniform to the shader.
         *
         *  @param  name_       Name of the uniform.
         *  @param  type_       Type stored by the uniform.
         *  @param  control_    Controller of the uniform.
         *
         *  @pre    name_ must not be empty.
         */
        inline void Shader::add_uniform(const std::string& name_, const Uniform::stored type_, const Uniform::controller control_) noexcept
        {
            assert(!name_.empty());

            GLint id = glGetUniformLocation(_handle, name_.c_str());

            if (id < 0)
            {
                ERROR(42) << "Unable to add uniform to gui Shader.\n"
                          << "Failed to determine the uniform location of: '" << name_ << "' within the shader.";
            }

            _uniform.emplace(std::make_pair(name_, Uniform(id, type_, control_)));
        }

        /**
         *  Set the value of an integer uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  int_    Value of uniform.
         *
         *  @pre    name_ must exist within the integer uniform map.
         */
        inline void Shader::set_uniform(const std::string& name_, const int int_) noexcept
        {
            assert(_uniform.find(name_) != _uniform.end());

            glUseProgram(_handle);

            glUniform1i(_uniform.find(name_)->second.handle(), int_);
        }

        /**
         *  Set the value of a float uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  float_  Value of uniform.
         *
         *  @pre    name_ must exist within the float uniform map.
         */
        inline void Shader::set_uniform(const std::string& name_, const float float_) noexcept
        {
            assert(_uniform.find(name_) != _uniform.end());

            glUseProgram(_handle);

            glUniform1f(_uniform.find(name_)->second.handle(), float_);
        }

        /**
         *  Set the value of a vec2 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  vec2_   Value of uniform.
         *
         *  @pre    name_ must exist within the vec2 uniform map.
         */
        inline void Shader::set_uniform(const std::string& name_, const glm::vec2& vec2_) noexcept
        {
            assert(_uniform.find(name_) != _uniform.end());

            glUseProgram(_handle);

            glUniform2fv(_uniform.find(name_)->second.handle(), 1, &vec2_[0]);
        }

        /**
         *  Set the value of a vec3 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  vec3_   Value of uniform.
         *
         *  @pre    name_ must exist within the vec3 uniform map.
         */
        inline void Shader::set_uniform(const std::string& name_, const glm::vec3& vec3_) noexcept
        {
            assert(_uniform.find(name_) != _uniform.end());

            glUseProgram(_handle);

            glUniform3fv(_uniform.find(name_)->second.handle(), 1, &vec3_[0]);
        }

        /**
         *  Set the value of a vec4 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  vec4_   Value of uniform.
         *
         *  @pre    name_ must exist within the vec4 uniform map.
         */
        inline void Shader::set_uniform(const std::string& name_, const glm::vec4& vec4_) noexcept
        {
            assert(_uniform.find(name_) != _uniform.end());

            glUseProgram(_handle);

            glUniform4fv(_uniform.find(name_)->second.handle(), 1, &vec4_[0]);
        }

        /**
         *  Set the value of a mat2 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  mat2_   Value of uniform.
         *
         *  @pre    name_ must exist within the mat2 uniform map.
         */
        inline void Shader::set_uniform(const std::string& name_, const glm::mat2& mat2_) noexcept
        {
            assert(_uniform.find(name_) != _uniform.end());

            glUseProgram(_handle);

            glUniformMatrix2fv(_uniform.find(name_)->second.handle(), 1, GL_FALSE, &mat2_[0][0]);
        }

        /**
         *  Set the value of a mat3 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  mat3_   Value of uniform.
         *
         *  @pre    name_ must exist within the mat3 uniform map.
         */
        inline void Shader::set_uniform(const std::string& name_, const glm::mat3& mat3_) noexcept
        {
            assert(_uniform.find(name_) != _uniform.end());

            glUseProgram(_handle);

            glUniformMatrix3fv(_uniform.find(name_)->second.handle(), 1, GL_FALSE, &mat3_[0][0]);
        }

        /**
         *  Set the value of a mat4 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  mat4_   Value of uniform.
         *
         *  @pre    name_ must exist within the mat4 uniform map.
         */
        inline void Shader::set_uniform(const std::string& name_, const glm::mat4& mat4_) noexcept
        {
            assert(_uniform.find(name_) != _uniform.end());

            glUseProgram(_handle);

            glUniformMatrix4fv(_uniform.find(name_)->second.handle(), 1, GL_FALSE, &mat4_[0][0]);
        }



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_HPP
