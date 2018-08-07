/**
 *  @file   arctk/gui/shader/ambient.hpp
 *  @date   07/08/2018
 *  @author Freddy Wordingham
 *
 *  Ambient lighting shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_AMBIENT_HPP
#define ARCTK_GUI_SHADER_AMBIENT_HPP



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
            constexpr const char* AMBIENT_SOURCE_VERT = R""(
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
            constexpr const char* AMBIENT_SOURCE_FRAG = R""(
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



            //  == CLASS ==
            /**
             *  Shader using a ambient lighting source.
             */
            class Ambient : public Shader
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
                inline Ambient() noexcept;


                //  == METHODS ==
              public:
                //  -- Rendering --
                inline void activate(const Lens& lens_, const Camera& cam_) noexcept override;
                inline void render(const Actor& act_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
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
            inline void Ambient::activate(const Lens& lens_, const Camera& cam_) noexcept
            {
                glUseProgram(_handle);

                glUniformMatrix4fv(_proj, 1, GL_FALSE, &lens_.proj()[0][0]);

                glUniformMatrix4fv(_view, 1, GL_FALSE, &cam_.view()[0][0]);
            }

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
#endif // ARCTK_GUI_SHADER_AMBIENT_HPP
