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
            )""; //!< Ray vertex subshader source code.
            constexpr const char* RAY_SOURCE_FRAG = R""(
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
                const GLint _model; //!< Model matrix uniform handle.
                const GLint _view;  //!< View matrix uniform handle.
                const GLint _proj;  //!< Projection matrix uniform handle.
                const GLint _col;   //!< Colour uniform handle.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Ray() noexcept;


                //  == METHODS ==
              public:
                //  -- Rendering --
                inline void activate(const Lens& lens_, const Camera& cam_) noexcept;
                inline void render(const Actor& act_) noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
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



            //  == METHODS ==



        } // namespace shader
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_RAY_HPP
