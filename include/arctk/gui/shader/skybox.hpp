/**
 *  @file   arctk/gui/shader/skybox.hpp
 *  @date   07/08/2018
 *  @author Freddy Wordingham
 *
 *  Skybox shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_SKYBOX_HPP
#define ARCTK_GUI_SHADER_SKYBOX_HPP



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Graphical --
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//  -- Arctk --
#include <arctk/consts.hpp>
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
            constexpr const char* const SKYBOX_SOURCE_VERT = R""(
                //  == VERSION ==
                #version 330 core



                //  == LINKING ==
                //  -- Layout --
                layout(location = 0) in vec3 pos;
                layout(location = 1) in vec3 norm;

                //  -- Uniforms --
                uniform mat4 model;
                uniform mat4 proj;
                uniform mat4 view;



                //  == IN/OUTPUT ==
                //  -- Output --
                out vec3 texture_coor;



                //  == MAIN ==
                void main()
                {
                    gl_Position = (proj * view * model * vec4(pos, 1.0)).xyww;

                    texture_coor = pos;
                }
            )""; //!< Skybox vertex subshader source code.
            constexpr const char* const SKYBOX_SOURCE_FRAG = R""(
                //  == VERSION ==
                #version 330 core



                //  == LINKING ==
                //  -- Uniforms --
                uniform samplerCube skybox;



                //  == IN/OUTPUT ==
                //  -- Input --
                in vec3 texture_coor;

                //  -- Output --
                out vec4 frag_colour;



                //  == MAIN ==
                void main()
                {
                    frag_colour = texture(skybox, texture_coor);
                }
            )""; //!< Skybox fragment subshader source code.



            //  == CLASS ==
            /**
             *  Shader drawing a skybox.
             */
            class Skybox : public Shader
            {
                //  == FIELDS ==
              private:
                //  -- Actor --
                Actor _cube; //!< Cube actor.

                //  -- Textures --
                const GLuint _cubemap; //!< Cubemap forming the background of the skybox.

                //  -- Uniforms --
                const GLint _model;  //!< Model matrix uniform handle.
                const GLint _view;   //!< View matrix uniform handle.
                const GLint _proj;   //!< Projection matrix uniform handle.
                const GLint _skybox; //!< Skybox cubemap uniform handle.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Skybox(const std::array<std::string, 6>& images_) noexcept;


                //  == METHODS ==
              public:
                //  -- Rendering --
                inline void activate(const Lens& lens_, const Camera& cam_) noexcept;
                inline void render() noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a skybox shader using a given set of images for the background.
             *
             *  @param  images_ Array of images used to build the cubemap.
             *
             *  @pre    images_ values may not be empty.
             */
            inline Skybox::Skybox(const std::array<std::string, 6>& images_) noexcept
              : Shader(SKYBOX_SOURCE_VERT, SKYBOX_SOURCE_FRAG)
              , _cube(actor::shape(geom::shape::Box(vec3(-1.0, -1.0, -1.0), vec3(1.0, 1.0, 1.0))))
              , _cubemap(init_cubemap(images_))
              , _model(init_uniform("model"))
              , _view(init_uniform("view"))
              , _proj(init_uniform("proj"))
              , _skybox(init_uniform("skybox"))
            {
                for (size_t i = 0; i < images_.size(); ++i)
                {
                    assert(!images_[i].empty());
                }

                _cube.rotate(glm::vec3(static_cast<float>(consts::math::HALF_PI), 0.0f, 0.0f));
            }



            //  == METHODS ==
            //  -- Rendering --
            /**
             *  Setup the shader to perform as the current active shader.
             *
             *  @param  lens_   Lens used to perform rendering.
             *  @param  cam_    Camera used to perform rendering.
             */
            inline void Skybox::activate(const Lens& lens_, const Camera& cam_) noexcept
            {
                glUseProgram(_handle);

                glUniformMatrix4fv(_proj, 1, GL_FALSE, &lens_.proj()[0][0]);

                glm::mat4 view = glm::mat4(glm::mat3(cam_.view()));
                glUniformMatrix4fv(_view, 1, GL_FALSE, &view[0][0]);
            }

            /**
             *  Render the skybox.
             */
            inline void Skybox::render() noexcept
            {
                glPolygonMode(GL_FRONT_AND_BACK, _cube.fill_mode());

                glUniformMatrix4fv(_model, 1, GL_FALSE, &_cube.model()[0][0]);

                glEnableVertexAttribArray(0);
                glBindVertexArray(_cube.vao());
                glBindTexture(GL_TEXTURE_CUBE_MAP, _cubemap);
                glDrawArrays(_cube.primitive_type(), 0, _cube.num_vert());
            }



        } // namespace shader
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_SKYBOX_HPP
