/**
 *  @file   arctk/gui/shader/ray.hpp
 *  @date   07/08/2018
 *  @author Freddy Wordingham
 *
 *  Ray drawing shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_RAY_HPP
#define ARCTK_GUI_SHADER_RAY_HPP



//  == IMPORTS ==
//  -- Graphical --
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//  -- Arctk --
#include <arctk/gui/actor.hpp>
#include <arctk/gui/camera.hpp>
#include <arctk/gui/lens.hpp>
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
            constexpr const char* RAY_SOURCE_VERT = R""(
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
                out vec4 vert_col;
                out vec4 vert_time;



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
            constexpr const char* RAY_SOURCE_FRAG = R""(
                //  == VERSION ==
                #version 330 core



                //  == LINKING ==
                //  -- Uniforms --
                uniform float render_time       = 0.0;
                uniform float render_time_delta = 1000.0;



                //  == IN/OUTPUT ==
                //  -- Input --
                in vec4 vert_col;
                in vec4 vert_time;

                //  -- Output --
                out vec4 frag_col;



                //  == MAIN ==
                void main()
                {
                    if (abs(vert_time - render_time) > render_time_delta)
                    {
                        discard;
                    }

                    frag_col = vert_col;
                }
            )""; //!< Ray fragment subshader source code.



            //  == CLASS ==
            /**
             *  Shader rendering rays.
             */
            class Ray : public Shader
            {
                //  == FIELDS ==
              private:
                //  -- Uniforms --
                const GLint _model;             //!< Model matrix uniform handle.
                const GLint _view;              //!< View matrix uniform handle.
                const GLint _proj;              //!< Projection matrix uniform handle.
                const GLint _render_time;       //!< Render time uniform handle.
                const GLint _render_time_delta; //!< Render time delta uniform handle.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Ray() noexcept;


                //  == METHODS ==
              public:
                //  -- Setters --
                inline void set_render_time(const float render_time_) noexcept;
                inline void set_render_time_delta(const float render_time_delta_) noexcept;

                //  -- Rendering --
                inline void activate(const Lens& lens_, const Camera& cam_) noexcept;
                inline void render(const Actor& act_) noexcept;
            };



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
              , _render_time(init_uniform("render_time"))
              , _render_time_delta(init_uniform("render_time_delta"))
            {
            }



            //  == METHODS ==
            //  -- Setters --
            inline void set_render_time(const float render_time_) noexcept
            {
                glUniform1f(_render_time, render_time_);
            }

            inline void set_render_time_delta(const float render_time_delta_) noexcept
            {
                glUniform1f(_render_time_delta, render_time_delta_);
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
#endif // ARCTK_GUI_SHADER_RAY_HPP
