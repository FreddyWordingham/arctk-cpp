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



        //  == METHODS ==
        //  -- Getters --



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_HPP
