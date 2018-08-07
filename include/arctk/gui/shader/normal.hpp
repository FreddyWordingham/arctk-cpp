/**
 *  @file   arctk/gui/shader/normal.hpp
 *  @date   07/08/2018
 *  @author Freddy Wordingham
 *
 *  Normal drawing shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_NORMAL_HPP
#define ARCTK_GUI_SHADER_NORMAL_HPP



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
            static const char* NORMAL_SOURCE_VERT =
#include <arctk/gui/shader/normal.vert>
              ; //!< Normal vertex subshader source code.
            static const char* NORMAL_SOURCE_GEOM =
#include <arctk/gui/shader/normal.geom>
              ; //!< Normal geometry subshader source code.
            static const char* NORMAL_SOURCE_FRAG =
#include <arctk/gui/shader/normal.frag>
              ; //!< Normal fragment subshader source code.



            //  == CLASS ==
            /**
             *  Shader drawing normals.
             */
            class Normal : public Shader
            {
                //  == FIELDS ==
              private:
                //  -- Uniforms Handles --
                const GLint _model; //!< Model matrix uniform handle.
                const GLint _view;  //!< View matrix uniform handle.
                const GLint _proj;  //!< Projection matrix uniform handle.
                const GLint _col;   //!< Colour uniform handle.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Normal() noexcept;


                //  == METHODS ==
              public:
                //  -- Rendering --
                inline void activate(const Lens& lens_, const Camera& cam_) noexcept override;
                inline void render(const Actor& act_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Normal::Normal() noexcept
              : Shader(AMBIENT_SOURCE_VERT, AMBIENT_SOURCE_GEOM, AMBIENT_SOURCE_FRAG)
              , _model(init_uniform("model"))
              , _view(init_uniform("view"))
              , _proj(init_uniform("proj"))
              , _col(init_uniform("col"))
            {
            }



            //  == METHODS ==
            //  -- Rendering --



        } // namespace shader
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_NORMAL_HPP
