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
#include <string>

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

            //  -- Initialisation --
            inline GLuint init_cubemap(const std::array<std::string, 6>& images_) const noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Shader& operator=(const Shader&) = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Shader& operator=(Shader&&) = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Rendering --
            virtual inline void activate(const Lens& lens_, const Camera& cam_) noexcept = 0;
            virtual inline void render(const Actor& act_) noexcept                       = 0;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a shader program from vertex and fragment sub-shader programs.
         *
         *  @param  vert_code_      Vertex sub-shader code.
         *  @param  frag_code_      Fragment sub-shader code.
         *
         *  @pre    vert_code_ must not be empty.
         *  @pre    frag_code_ must not be empty.
         */
        inline Shader::Shader(const std::string& vert_code_, const std::string& frag_code_) noexcept
          : _handle(init_handle(vert_code_, frag_code_))
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
         *
         *  @pre    vert_code_ must not be empty.
         *  @pre    geom_code_ must not be empty.
         *  @pre    frag_code_ must not be empty.
         */
        inline Shader::Shader(const std::string& vert_code_, const std::string& geom_code_, const std::string& frag_code_) noexcept
          : _handle(init_handle(vert_code_, geom_code_, frag_code_))
        {
            PRE(!vert_code_.empty());
            PRE(!geom_code_.empty());
            PRE(!frag_code_.empty());
        }


        //  -- Destructors --
        /**
         *  Defaulted destructor method.
         */
        inline Shader::~Shader() noexcept = default;



        //  == INSTANTIATION ==
        //  -- Initialisation --
        /**
         *  Initialise a shader program consisting of a vertex and a fragment subshaders.
         *
         *  @param  vert_code_  Vertex sub-shader code.
         *  @param  frag_code_  Fragment sub-shader code.
         *
         *  @pre    vert_code_ must not be empty.
         *  @pre    frag_code_ must not be empty.
         *
         *  @return Handle to a shader program.
         */
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

        /**
         *  Initialise a shader program consisting of a vertex, geometry and a fragment subshaders.
         *
         *  @param  vert_code_  Vertex sub-shader code.
         *  @param  geom_code_  Geometry sub-shader code.
         *  @param  frag_code_  Fragment sub-shader code.
         *
         *  @pre    vert_code_ must not be empty.
         *  @pre    geom_code_ must not be empty.
         *  @pre    frag_code_ must not be empty.
         *
         *  @return Handle to a shader program.
         */
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

        /**
         *  Initialise a handle to a uniform of the shader.
         *
         *  @param  name_   Name of the uniform.
         *
         *  @pre    name_ may not be empty.
         *
         *  @return Handle to the initialised uniform within the shader.
         */
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



    } // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_HPP
