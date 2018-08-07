/**
 *  @file   arctk/gui/shader/skybox.hpp
 *  @date   07/08/2018
 *  @author Freddy Wordingham
 *
 *  Skybox shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_SKYBOX_HPP
#define ARCTK_GUI_SHADER_SKYBOX_HPP



//  == IMPORTS ==
//  -- Graphical --
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//  -- Arctk --
#include <arctk/gui/shader.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {
        namespace shader //! shader namespace
        {



            //  == CONSTANTS ==
            //  -- Shader Source Code --
            constexpr const char* SKYBOX_SOURCE_VERT =
#include <arctk/gui/shader/skybox.vert>
              ; //!< Skybox vertex subshader source code.
            constexpr const char* SKYBOX_SOURCE_FRAG =
#include <arctk/gui/shader/skybox.frag>
              ; //!< Skybox fragment subshader source code.



            //  == CLASS ==
            /**
             *  Shader drawing a skybox.
             */
            class Skybox : public Shader
            {
                //  == FIELDS ==
              private:
                //  -- Textures --
                const GLuint _cubemap;

                //  -- Uniforms --


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Skybox(const std::array<std::string, 6>& images_) noexcept;


                //  == METHODS ==
              public:
                //  -- Rendering --
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Skybox::Skybox(const std::array<std::string, 6>& images_) noexcept
              : Shader(SKYBOX_SOURCE_VERT, SKYBOX_SOURCE_FRAG)
              , _cubemap(init_cubemap(images_))
            {
            }


            //  -- Initialisation --



            //  == METHODS ==
            //  -- Rendering --



        } // namespace shader
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_SKYBOX_HPP
