/**
 *  @file   arctk/gui/shader/diffuse.hpp
 *  @date   07/08/2018
 *  @author Freddy Wordingham
 *
 *  Diffuse lighting shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_DIFFUSE_HPP
#define ARCTK_GUI_SHADER_DIFFUSE_HPP



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
            constexpr const char* DIFFUSE_SOURCE_VERT =
#include <arctk/gui/shader/diffuse.vert>
              ; //!< Diffuse vertex subshader source code.
            constexpr const char* DIFFUSE_SOURCE_FRAG =
#include <arctk/gui/shader/diffuse.frag>
              ; //!< Diffuse fragment subshader source code.



            //  == CLASS ==
            /**
             *  Shader using a diffuse lighting source.
             */
            class Diffuse : public Shader
            {
                //  == FIELDS ==
              private:
                //  -- Uniforms --
                const GLint _model; //!< Model matrix uniform handle.
                const GLint _view;  //!< View matrix uniform handle.
                const GLint _proj;  //!< Projection matrix uniform handle.
                const GLint _col;   //!< Colour uniform handle.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Diffuse() noexcept;


                //  == METHODS ==
              public:
                //  -- Rendering --
                inline void activate(const Lens& lens_, const Camera& cam_) noexcept override;
                inline void render(const Actor& act_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Diffuse::Diffuse() noexcept
              : Shader(DIFFUSE_SOURCE_VERT, DIFFUSE_SOURCE_FRAG)
              , _model(init_uniform("model"))
              , _view(init_uniform("view"))
              , _proj(init_uniform("proj"))
              , _col(init_uniform("col"))
            {
            }



            //  == METHODS ==
            //  -- Rendering --
            inline void Diffuse::activate(const Lens& lens_, const Camera& cam_) noexcept
            {
                glUseProgram(_handle);

                glUniformMatrix4fv(_proj, 1, GL_FALSE, &lens_.proj()[0][0]);

                glUniformMatrix4fv(_view, 1, GL_FALSE, &cam_.view()[0][0]);
            }

            inline void Diffuse::render(const Actor& act_) noexcept
            {
                glPolygonMode(GL_FRONT_AND_BACK, act_.fill_mode());

                glUniformMatrix4fv(_model, 1, GL_FALSE, &act_.model()[0][0]);
                glUniform4fv(_col, 1, &act_.col()[0]);

                glEnableVertexAttribArray(0);
                glBindVertexArray(act_.vao());
                glDrawArrays(act_.primitive_type(), 0, act_.num_vert());
            }



        } // namespace shader
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_DIFFUSE_HPP
