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
            static const char* NORMAL_SOURCE_VERT =
#include <arctk/gui/shader/normal.vert>
              ; //!< Normal vertex subshader source code.
            static const char* NORMAL_SOURCE_GEOM =
#include <arctk/gui/shader/normal.geom>
              ; //!< Normal geometry subshader source code.
            static const char* NORMAL_SOURCE_FRAG =
#include <arctk/gui/shader/normal.frag>
              ; //!< Normal fragment subshader source code.



            //  == CLASS ==
            /**
             *  Shader drawing normals.
             */
            class Normal : public Shader
            {
                //  == FIELDS ==
              private:
                //  -- Uniforms Handles --
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
                inline void set_length(const float length_) noexcept;

                //  -- Rendering --
                inline void activate(const Lens& lens_, const Camera& cam_) noexcept override;
                inline void render(const Actor& act_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
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
            inline void Normal::set_vert_col(const glm::vec4& vert_col_) noexcept
            {
                glUniform4fv(_vert_col, 1, &vert_col_[0]);
            }

            inline void Normal::set_face_col(const glm::vec4& face_col_) noexcept
            {
                glUniform4fv(_face_col, 1, &face_col_[0]);
            }

            inline void Normal::set_length(const float length_) noexcept
            {
                glUniform1f(_length, length_);
            }


            //  -- Rendering --
            inline void Normal::activate(const Lens& lens_, const Camera& cam_) noexcept
            {
                glUseProgram(_handle);

                glUniformMatrix4fv(_proj, 1, GL_FALSE, &lens_.proj()[0][0]);

                glUniformMatrix4fv(_view, 1, GL_FALSE, &cam_.view()[0][0]);
            }

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
