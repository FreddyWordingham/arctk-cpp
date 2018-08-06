/**
 *  @file   arctk/gui/camera/orbit.hpp
 *  @date   06/08/2018
 *  @author Freddy Wordingham
 *
 *  Specular shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_SPECULAR_HPP
#define ARCTK_GUI_SHADER_SPECULAR_HPP



//  == IMPORTS ==
//  -- Std --



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {
        namespace shader //! shader namespace
        {



            //  == CONSTANTS ==
            //  -- Shader Source Code --
            const char* SPECULAR_SOURCE_VERT =
#include <arctk/gui/shader/specular.vert>
              ; //!< Specular vertex subshader source code.
            const char* SPECULAR_SOURCE_FRAG =
#include <arctk/gui/shader/specular.frag>
              ; //!< Specular fragment subshader source code.



            //  == CLASS ==
            /**
             *  Shader using a specular lighting source.
             */
            class Specular : public Shader
            {
                //  == FIELDS ==
              private:
                //  -- Uniforms Handles --
                const GLint _model;   //!< Model matrix uniform handle.
                const GLint _view;    //!< View matrix uniform handle.
                const GLint _proj;    //!< Projection matrix uniform handle.
                const GLint _col;     //!< Colour uniform handle.
                const GLint _cam_pos; //!< Camera position uniform handle.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Specular() noexcept;


                //  == METHODS ==
              public:
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Specular::Specular() noexcept
              : Shader(SPECULAR_SOURCE_VERT, SPECULAR_SOURCE_FRAG)
            {
            }



            //  == METHODS ==



        } // namespace shader
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_SPECULAR_HPP
