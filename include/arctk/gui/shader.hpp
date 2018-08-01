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
            const GLint                        _model;   //!< Model matrix uniform handle.
            const GLint                        _view;    //!< View matrix uniform handle.
            const GLint                        _proj;    //!< Projection matrix uniform handle.
            const std::map<std::string, GLint> _uniform; //!< Additional uniform mappings.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Shader(const std::string& vert_code_, const std::string& frag_code_, const std::vector<std::string>& uniform_names_) noexcept;
            inline Shader(const std::string& vert_code_, const std::string& geom_code_, const std::string& frag_code_, const std::vector<std::string>& uniform_names_) noexcept;

            //  -- Initialisation --
            inline GLint init_model() const noexcept;
            inline GLint init_view() const noexcept;
            inline GLint init_proj() const noexcept;


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION ==
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
        inline Shader::Shader(const std::string& vert_code_, const std::string& frag_code_, const std::vector<std::string>& uniform_names_) noexcept
          : _handle(init_handle(vert_code_, frag_code_))
          , _model(init_model())
          , _proj(init_proj())
          , _uniform(init_uniform())
        {
            PRE(!vert_code_.empty());
            PRE(!frag_code_.empty());
        }


        //  -- Initialisation --
        inline GLint Shader::init_model() const noexcept
        {
            GLint model = glGetUniformLocation(_handle, "model");

            if (model < 0)
            {
                std::cerr << "Unable to construct gui shader.\n"
                          << "Failed to determine the model uniform location within the shader.\n";

                std::exit(exit::error::SHADER_UNIFORM_NOT_FOUND);
            }

            return (model);
        }

        inline GLint Shader::init_view() const noexcept
        {
            GLint view = glGetUniformLocation(_handle, "view");

            if (view < 0)
            {
                std::cerr << "Unable to construct gui shader.\n"
                          << "Failed to determine the view uniform location within the shader.\n";

                std::exit(exit::error::SHADER_UNIFORM_NOT_FOUND);
            }

            return (view);
        }

        inline GLint Shader::init_proj() const noexcept
        {
        }



    } // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_HPP
