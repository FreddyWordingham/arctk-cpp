/**
 *  @file   arctk/gui/shader/specular.hpp
 *  @date   06/08/2018
 *  @author Freddy Wordingham
 *
 *  Specular shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_SPECULAR_HPP
#define ARCTK_GUI_SHADER_SPECULAR_HPP



//  == IMPORTS ==
//  -- Graphical --
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

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
            constexpr const char* const SPECULAR_SOURCE_VERT = R""(
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
            )""; //!< Specular vertex subshader source code.
            constexpr const char* const SPECULAR_SOURCE_FRAG = R""(
                //  == VERSION ==
                #version 330 core



                //  == CONSTANTS ==
                //  -- Lighting --
                const float amb_pow  = 0.1;
                const float spec_pow = 0.5;



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

                    vec3  view_dir    = normalize(cam_pos - vert_pos);
                    vec3  reflect_dir = reflect(-light_dir, vert_norm);
                    float spec        = pow(max(dot(view_dir, reflect_dir), 0.0), 16);
                    vec4  specular    = spec_pow * spec * vec4(sun_col, 1.0);

                    frag_col = (ambient + diffuse + specular) * col;
                }
            )""; //!< Specular fragment subshader source code.



            //  == CLASS ==
            /**
             *  Shader using a specular lighting source.
             */
            class Specular : public Shader
            {
                //  == FIELDS ==
              private:
                //  -- Uniforms --
                const GLint _model;   //!< Model matrix uniform handle.
                const GLint _view;    //!< View matrix uniform handle.
                const GLint _proj;    //!< Projection matrix uniform handle.
                const GLint _col;     //!< Colour uniform handle.
                const GLint _cam_pos; //!< Camera position uniform handle.
                const GLint _sun_col; //!< Colour of the sun illuminator.
                const GLint _sun_pos; //!< Position of the sun illuminator.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Specular() noexcept;


                //  == METHODS ==
              public:
                //  -- Setters --
                inline void set_sun_col(const glm::vec3& sun_col_) noexcept;
                inline void set_sun_pos(const glm::vec3& sun_pos_) noexcept;

                //  -- Rendering --
                inline void activate(const Lens& lens_, const Camera& cam_) noexcept;
                inline void render(const Actor& act_) noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a specular lighting shader.
             */
            inline Specular::Specular() noexcept
              : Shader(SPECULAR_SOURCE_VERT, SPECULAR_SOURCE_FRAG)
              , _model(init_uniform("model"))
              , _view(init_uniform("view"))
              , _proj(init_uniform("proj"))
              , _col(init_uniform("col"))
              , _cam_pos(init_uniform("cam_pos"))
              , _sun_col(init_uniform("sun_col"))
              , _sun_pos(init_uniform("sun_pos"))
            {
            }



            //  == METHODS ==
            //  -- Setters --
            /**
             *  Set the colour of the sun illuminator object.
             *
             *  @param  sun_col_    Colour to use for the sun illuminator.
             *
             *  @pre    sun_col_.r must be non-negative.
             *  @pre    sun_col_.r must be less than, or equal to, unity.
             *  @pre    sun_col_.g must be non-negative.
             *  @pre    sun_col_.g must be less than, or equal to, unity.
             *  @pre    sun_col_.b must be non-negative.
             *  @pre    sun_col_.b must be less than, or equal to, unity.
             */
            inline void Specular::set_sun_col(const glm::vec3& sun_col_) noexcept
            {
                assert(sun_col_.r >= 0.0f);
                assert(sun_col_.r <= 1.0f);
                assert(sun_col_.g >= 0.0f);
                assert(sun_col_.g <= 1.0f);
                assert(sun_col_.b >= 0.0f);
                assert(sun_col_.b <= 1.0f);

                glUniform3fv(_sun_col, 1, &sun_col_[0]);
            }

            /**
             *  Set the position of the sun illuminator object.
             *
             *  @param  sun_pos_    Postion of the sun illuminator.
             */
            inline void Specular::set_sun_pos(const glm::vec3& sun_pos_) noexcept
            {
                glUniform3fv(_sun_pos, 1, &sun_pos_[0]);
            }


            //  -- Rendering --
            /**
             *  Setup the shader to perform as the current active shader.
             *
             *  @param  lens_   Lens used to perform rendering.
             *  @param  cam_    Camera used to perform rendering.
             */
            inline void Specular::activate(const Lens& lens_, const Camera& cam_) noexcept
            {
                glUseProgram(_handle);

                glUniformMatrix4fv(_proj, 1, GL_FALSE, &lens_.proj()[0][0]);

                glUniformMatrix4fv(_view, 1, GL_FALSE, &cam_.view()[0][0]);
                glUniform3fv(_cam_pos, 1, &cam_.pos()[0]);
            }

            /**
             *  Render an actor using the specular shader.
             *
             *  @param  act_    Actor to render.
             */
            inline void Specular::render(const Actor& act_) noexcept
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
#endif // ARCTK_GUI_SHADER_SPECULAR_HPP
