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
//  -- Std --
#include <cassert>

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
            constexpr const char* const NORMAL_SOURCE_VERT = R""(
                //  == VERSION ==
                #version 330 core



                //  == LINKING ==
                //  -- Layout --
                layout(location = 0) in vec3 pos;
                layout(location = 1) in vec3 norm;



                //  == IN/OUTPUT ==
                //  -- Output --
                out vec3 vert_pos;
                out vec3 vert_norm;



                //  == MAIN ==
                void main()
                {
                    vert_pos  = pos;
                    vert_norm = norm;
                }
            )""; //!< Normal vertex subshader source code.
            constexpr const char* const NORMAL_SOURCE_GEOM = R""(
                //  == VERSION ==
                #version 330 core



                //  == LINKING ==
                //  -- Layout --
                layout(triangles) in;
                layout(line_strip, max_vertices = 8) out;

                //  -- Uniforms --
                uniform mat4  model;
                uniform mat4  view;
                uniform mat4  proj;
                uniform vec4  vert_col = vec4(1.0, 0.0, 0.0, 0.0);
                uniform vec4  face_col = vec4(1.0, 1.0, 0.0, 0.0);
                uniform float length  = 0.4;



                //  == IN/OUTPUT ==
                //  -- Input --
                in vec3 vert_pos[];
                in vec3 vert_norm[];

                //  -- Output --
                out vec4 geom_col;



                //  == FUNCTION PROTOTYPES ==
                //  -- Normals --
                void create_normal(const mat4 mvp_, const vec3 pos_, const vec3 norm_);



                //  == MAIN ==
                void main()
                {
                    mat4 mvp = proj * view * model;

                    create_normal(mvp, vert_pos[0], vert_norm[0]);
                    create_normal(mvp, vert_pos[1], vert_norm[1]);
                    create_normal(mvp, vert_pos[2], vert_norm[2]);

                    vec3 center = (vert_pos[0] + vert_pos[1] + vert_pos[2]) / 3.0;

                    vec3 plane_norm = normalize(cross(vert_pos[1] - vert_pos[0], vert_pos[2] - vert_pos[0]));

                    vec4 start  = vec4(center, 1.0);
                    gl_Position = mvp * start;
                    geom_col    = face_col;
                    EmitVertex();

                    vec4 end    = start + vec4(plane_norm * length, 0.0);
                    gl_Position = mvp * end;
                    geom_col    = face_col;
                    EmitVertex();

                    EndPrimitive();
                }



                //  == FUNCTIONS ==
                //  -- Normals --
                void create_normal(const mat4 mvp_, const vec3 pos_, const vec3 norm_)
                {
                    vec4 start  = vec4(pos_, 1.0);
                    gl_Position = mvp_ * start;
                    geom_col    = vert_col;
                    EmitVertex();

                    vec4 end    = start + vec4(norm_ * length, 0.0);
                    gl_Position = mvp_ * end;
                    geom_col    = vert_col;
                    EmitVertex();

                    EndPrimitive();
                }
            )""; //!< Normal geometry subshader source code.
            constexpr const char* const NORMAL_SOURCE_FRAG = R""(
                //  == VERSION ==
                #version 330 core



                //  == IN/OUTPUT ==
                //  -- Input --
                in vec4 geom_col;

                //  -- Output --
                out vec4 frag_col;



                //  == MAIN ==
                void main()
                {
                    frag_col = geom_col;
                }
            )""; //!< Normal fragment subshader source code.



            //  == CLASS ==
            /**
             *  Shader drawing normals.
             */
            class Normal : public Shader
            {
                //  == FIELDS ==
              private:
                //  -- Uniforms --
                const GLint _model;    //!< Model matrix uniform handle.
                const GLint _view;     //!< View matrix uniform handle.
                const GLint _proj;     //!< Projection matrix uniform handle.
                const GLint _vert_col; //!< Vertex colour uniform handle.
                const GLint _face_col; //!< Face colour uniform handle.
                const GLint _length;   //!< Normal length uniform handle.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Normal() noexcept;


                //  == METHODS ==
              public:
                //  -- Setters --
                inline void set_vert_col(const glm::vec4& vert_col_) noexcept;
                inline void set_face_col(const glm::vec4& face_col_) noexcept;
                inline void set_length(float length_) noexcept;

                //  -- Rendering --
                inline void activate(const Lens& lens_, const Camera& cam_) noexcept;
                inline void render(const Actor& act_) noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a normal drawing shader.
             */
            inline Normal::Normal() noexcept
              : Shader(NORMAL_SOURCE_VERT, NORMAL_SOURCE_GEOM, NORMAL_SOURCE_FRAG)
              , _model(init_uniform("model"))
              , _view(init_uniform("view"))
              , _proj(init_uniform("proj"))
              , _vert_col(init_uniform("vert_col"))
              , _face_col(init_uniform("face_col"))
              , _length(init_uniform("length"))
            {
            }



            //  == METHODS ==
            //  -- Setters --
            /**
             *  Set the vertex normal colour uniform of the shader.
             *
             *  @param  vert_col_   Colour to draw the vertex normals.
             *
             *  @pre    col_.r must be non-negative.
             *  @pre    col_.r must be less than, or equal to, unity.
             *  @pre    col_.g must be non-negative.
             *  @pre    col_.g must be less than, or equal to, unity.
             *  @pre    col_.b must be non-negative.
             *  @pre    col_.b must be less than, or equal to, unity.
             *  @pre    col_.a must be non-negative.
             *  @pre    col_.a must be less than, or equal to, unity.y.
             */
            inline void Normal::set_vert_col(const glm::vec4& vert_col_) noexcept
            {
                assert(vert_col_.r >= 0.0f);
                assert(vert_col_.r <= 1.0f);
                assert(vert_col_.g >= 0.0f);
                assert(vert_col_.g <= 1.0f);
                assert(vert_col_.b >= 0.0f);
                assert(vert_col_.b <= 1.0f);
                assert(vert_col_.a >= 0.0f);
                assert(vert_col_.a <= 1.0f);

                glUniform4fv(_vert_col, 1, &vert_col_[0]);
            }

            /**
             *  Set the face normal colour uniform of the shader.
             *
             *  @param  face_col_   Colour to draw the face normals.
             *
             *  @pre    col_.r must be non-negative.
             *  @pre    col_.r must be less than, or equal to, unity.
             *  @pre    col_.g must be non-negative.
             *  @pre    col_.g must be less than, or equal to, unity.
             *  @pre    col_.b must be non-negative.
             *  @pre    col_.b must be less than, or equal to, unity.
             *  @pre    col_.a must be non-negative.
             *  @pre    col_.a must be less than, or equal to, unity.
             */
            inline void Normal::set_face_col(const glm::vec4& face_col_) noexcept
            {
                assert(face_col_.r >= 0.0f);
                assert(face_col_.r <= 1.0f);
                assert(face_col_.g >= 0.0f);
                assert(face_col_.g <= 1.0f);
                assert(face_col_.b >= 0.0f);
                assert(face_col_.b <= 1.0f);
                assert(face_col_.a >= 0.0f);
                assert(face_col_.a <= 1.0f);

                glUniform4fv(_face_col, 1, &face_col_[0]);
            }

            /**
             *  Set the normal length uniform of the shader.
             *
             *  @param  length_ Length to draw the normals.
             *
             *  @pre    length_ must be positive.
             */
            inline void Normal::set_length(const float length_) noexcept
            {
                assert(length_ > 0.0f);

                glUniform1f(_length, length_);
            }


            //  -- Rendering --
            /**
             *  Setup the shader to perform as the current active shader.
             *
             *  @param  lens_   Lens used to perform rendering.
             *  @param  cam_    Camera used to perform rendering.
             */
            inline void Normal::activate(const Lens& lens_, const Camera& cam_) noexcept
            {
                glUseProgram(_handle);

                glUniformMatrix4fv(_proj, 1, GL_FALSE, &lens_.proj()[0][0]);

                glUniformMatrix4fv(_view, 1, GL_FALSE, &cam_.view()[0][0]);
            }

            /**
             *  Render an actor using the normal shader.
             *
             *  @param  act_    Actor to render.
             */
            inline void Normal::render(const Actor& act_) noexcept
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
#endif // ARCTK_GUI_SHADER_NORMAL_HPP
