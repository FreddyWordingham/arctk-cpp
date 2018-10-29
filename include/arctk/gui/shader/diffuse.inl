/**
 *  @file   arctk/gui/shader/diffuse.inl
 *  @date   07/08/2018
 *  @author Freddy Wordingham
 *
 *  Diffuse lighting shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_DIFFUSE_INL
#define ARCTK_GUI_SHADER_DIFFUSE_INL



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
            constexpr const char* const DIFFUSE_SOURCE_VERT = R""(
                //  == VERSION ==
                #version 330 core



                //  == LINKING ==
                //  -- Layout --
                layout(location = 0) in vec3 pos;
                layout(location = 1) in vec3 norm;

                //  -- Uniforms --
                uniform mat4 model;
                uniform mat4 view;
                uniform mat4 proj;



                //  == IN/OUTPUT ==
                //  -- Output --
                out vec3 vert_pos;
                out vec3 vert_norm;



                //  == MAIN ==
                void main()
                {
                    vert_pos  = vec3(model * vec4(pos, 1.0));
                    vert_norm = mat3(transpose(inverse(model))) * norm;

                    gl_Position = proj * view * vec4(vert_pos, 1.0);
                }
            )""; //!< Diffuse vertex subshader source code.
            constexpr const char* const DIFFUSE_SOURCE_FRAG = R""(
                //  == VERSION ==
                #version 330 core



                //  == CONSTANTS ==
                //  -- Lighting --
                const float amb_pow  = 0.1;



                //  == LINKING ==
                //  -- Uniforms --
                uniform vec4 col;
                uniform vec3 cam_pos;
                uniform vec3 sun_col = vec3(1.0, 1.0, 1.0);
                uniform vec3 sun_pos = vec3(3.0, 4.0, 5.0);



                //  == IN/OUTPUT ==
                //  -- Input --
                in vec3 vert_norm;
                in vec3 vert_pos;

                //  -- Output --
                out vec4 frag_col;



                //  == MAIN ==
                void main()
                {
                    vec4 ambient = amb_pow * vec4(sun_col, 1.0);

                    vec3  vert_norm = normalize(vert_norm);
                    vec3  light_dir = normalize(sun_pos - vert_pos);
                    float diff      = max(dot(vert_norm, light_dir), 0.0);
                    vec4  diffuse   = diff * vec4(sun_col, 1.0);

                    frag_col = (ambient + diffuse) * col;
                }
            )""; //!< Diffuse fragment subshader source code.



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a diffuse lighting shader.
             */
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
            /**
             *  Setup the shader to perform as the current active shader.
             *
             *  @param  lens_   Lens used to perform rendering.
             *  @param  cam_    Camera used to perform rendering.
             */
            inline void Diffuse::activate(const Lens& lens_, const Camera& cam_) noexcept
            {
                glUseProgram(_handle);

                glUniformMatrix4fv(_proj, 1, GL_FALSE, &lens_.proj()[0][0]);

                glUniformMatrix4fv(_view, 1, GL_FALSE, &cam_.view()[0][0]);
            }

            /**
             *  Render an actor using the diffuse shader.
             *
             *  @param  act_    Actor to render.
             */
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
#endif // ARCTK_GUI_SHADER_DIFFUSE_INL
