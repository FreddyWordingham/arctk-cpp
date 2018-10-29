/**
 *  @file   arctk/gui/shader/ray.inl
 *  @date   07/08/2018
 *  @author Freddy Wordingham
 *
 *  Ray drawing shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_RAY_INL
#define ARCTK_GUI_SHADER_RAY_INL



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
            constexpr const char* const RAY_SOURCE_VERT = R""(
                //  == VERSION ==
                #version 330 core



                //  == LINKING ==
                //  -- Layout --
                layout(location = 0) in vec3  pos;
                layout(location = 1) in float time;
                layout(location = 2) in float wavelength;

                //  -- Uniforms --
                uniform mat4  model;
                uniform mat4  view;
                uniform mat4  proj;



                //  == IN/OUTPUT ==
                //  -- Output --
                out vec4  vert_col;
                out float vert_time;



                //  == FUNCTION PROTOTYPES ==
                vec4 colourmap(const float t_x);
                float colourmap_red(const float t_x);
                float colourmap_green(const float t_x);
                float colourmap_blue(const float t_x);



                //  == MAIN ==
                void main()
                {
                    gl_Position = proj * view * model * vec4(pos, 1.0);

                    vert_col  = colourmap((wavelength - 400E-9) / 300E-9);
                    vert_time = time;
                }



                //  == FUNCTIONS ==
                vec4 colourmap(const float t_x)
                {
                    // Check if t_x is outside limits.
                    if ((t_x < 0.0) || (t_x > 1.0))
                    {
                        return (vec4(1.0, 0.0, 1.0, 1.0));
                    }

                    // Determine red, green blue values.
                    float red = clamp(colourmap_red(t_x), 0.0, 1.0);
                    float green = clamp(colourmap_green(t_x), 0.0, 1.0);
                    float blue = clamp(colourmap_blue(t_x), 0.0, 1.0);

                    return vec4(red, green, blue, 1.0);
                }

                float colourmap_red(const float t_x)
                {
                    if (t_x < 0.7)
                    {
                        return ((4.0 * t_x) - 1.5);
                    }

                    return ((-4.0 * t_x) + 4.5);
                }

                float colourmap_green(const float t_x)
                {
                    if (t_x < 0.5)
                    {
                        return ((4.0 * t_x) - 0.5);
                    }

                    return ((-4.0 * t_x) + 3.5);
                }

                float colourmap_blue(const float t_x)
                {
                    if (t_x < 0.3)
                    {
                    return ((4.0 * t_x) + 0.5);
                    }

                    return ((-4.0 * t_x) + 2.5);
                }
            )""; //!< Ray vertex subshader source code.
            constexpr const char* const RAY_SOURCE_FRAG = R""(
                //  == VERSION ==
                #version 330 core



                //  == LINKING ==
                //  -- Uniforms --
                uniform float time_start = 0.0;
                uniform float time_end   = 1000.0;



                //  == IN/OUTPUT ==
                //  -- Input --
                in vec4  vert_col;
                in float vert_time;

                //  -- Output --
                out vec4 frag_col;



                //  == MAIN ==
                void main()
                {
                    if ((vert_time < time_start) || (vert_time > time_end))
                    {
                        discard;
                    }

                    frag_col = vert_col;
                }
            )""; //!< Ray fragment subshader source code.



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a ray drawing shader.
             */
            inline Ray::Ray() noexcept
              : Shader(RAY_SOURCE_VERT, RAY_SOURCE_FRAG)
              , _model(init_uniform("model"))
              , _view(init_uniform("view"))
              , _proj(init_uniform("proj"))
              , _time_start(init_uniform("time_start"))
              , _time_end(init_uniform("time_end"))
            {
            }



            //  == METHODS ==
            //  -- Setters --
            /**
             *  Set the start rendering time uniform value.
             *
             *  @param  time_start_ Value to set the time uniform value to.
             */
            inline void Ray::set_time_start(const float time_start_) noexcept
            {
                glUniform1f(_time_start, time_start_);
            }

            /**
             *  Set the end rendering time uniform value.
             *
             *  @param  time_end_   Value to set the time uniform value to.
             */
            inline void Ray::set_time_end(const float time_end_) noexcept
            {
                glUniform1f(_time_end, time_end_);
            }


            //  -- Rendering --
            /**
             *  Setup the shader to perform as the current active shader.
             *
             *  @param  lens_   Lens used to perform rendering.
             *  @param  cam_    Camera used to perform rendering.
             */
            inline void Ray::activate(const Lens& lens_, const Camera& cam_) noexcept
            {
                glUseProgram(_handle);

                glUniformMatrix4fv(_proj, 1, GL_FALSE, &lens_.proj()[0][0]);

                glUniformMatrix4fv(_view, 1, GL_FALSE, &cam_.view()[0][0]);
            }

            /**
             *  Render an actor using the ray shader.
             *
             *  @param  act_    Actor to render.
             */
            inline void Ray::render(const Actor& act_) noexcept
            {
                glPolygonMode(GL_FRONT_AND_BACK, act_.fill_mode());

                glUniformMatrix4fv(_model, 1, GL_FALSE, &act_.model()[0][0]);

                glEnableVertexAttribArray(0);
                glBindVertexArray(act_.vao());
                glDrawArrays(act_.primitive_type(), 0, act_.num_vert());
            }



        } // namespace shader
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_RAY_INL
