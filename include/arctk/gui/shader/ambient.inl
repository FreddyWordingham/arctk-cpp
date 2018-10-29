/**
 *  @file   arctk/gui/shader/ambient.inl
 *  @date   07/08/2018
 *  @author Freddy Wordingham
 *
 *  Ambient lighting shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_AMBIENT_INL
#define ARCTK_GUI_SHADER_AMBIENT_INL



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/gui/actor.hpp>
#include <arctk/gui/camera.hpp>
#include <arctk/gui/lens.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {
        namespace shader //! shader namespace
        {



            //  == CONSTANTS ==
            //  -- Shader Source Code --
            constexpr const char* const AMBIENT_SOURCE_VERT = R""(
                //  == VERSION ==
                #version 330 core



                //  == LINKING ==
                //  -- Layout --
                layout(location = 0) in vec3 pos;

                //  -- Uniforms --
                uniform mat4 model;
                uniform mat4 view;
                uniform mat4 proj;
                uniform vec4 col;



                //  == IN/OUTPUT ==
                //  -- Output --
                out vec4 vert_col;



                //  == MAIN ==
                void main()
                {
                    gl_Position = proj * view * model * vec4(pos, 1.0);

                    vert_col = col;
                }
            )""; //!< Ambient vertex subshader source code.
            constexpr const char* const AMBIENT_SOURCE_FRAG = R""(
                //  == VERSION ==
                #version 330 core



                //  == IN/OUTPUT ==
                //  -- Input --
                in vec4 vert_col;

                //  -- Output --
                out vec4 frag_col;



                //  == MAIN ==
                void main()
                {
                    frag_col = vert_col;
                }
            )""; //!< Ambient fragment subshader source code.



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a ambient lighting shader.
             */
            inline Ambient::Ambient() noexcept
              : Shader(AMBIENT_SOURCE_VERT, AMBIENT_SOURCE_FRAG)
              , _model(init_uniform("model"))
              , _view(init_uniform("view"))
              , _proj(init_uniform("proj"))
              , _col(init_uniform("col"))
            {
            }



            //  == METHODS ==
            //  -- Rendering --
            /**
             *  Setup the shader to perform as the current active shader.
             *
             *  @param  lens_   Lens used to perform rendering.
             *  @param  cam_    Camera used to perform rendering.
             */
            inline void Ambient::activate(const Lens& lens_, const Camera& cam_) noexcept
            {
                glUseProgram(_handle);

                glUniformMatrix4fv(_proj, 1, GL_FALSE, &lens_.proj()[0][0]);

                glUniformMatrix4fv(_view, 1, GL_FALSE, &cam_.view()[0][0]);
            }

            /**
             *  Render an actor using the ambient shader.
             *
             *  @param  act_    Actor to render.
             */
            inline void Ambient::render(const Actor& act_) noexcept
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
#endif // ARCTK_GUI_SHADER_AMBIENT_INL
