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
            static const char* SPECULAR_SOURCE_VERT =
#include <arctk/gui/shader/specular.vert>
              ; //!< Specular vertex subshader source code.
            static const char* SPECULAR_SOURCE_FRAG =
#include <arctk/gui/shader/specular.frag>
              ; //!< Specular fragment subshader source code.



            //  == CLASS ==
            /**
             *  Shader using a specular lighting source.
             */
            class Specular : public Shader
            {
                //  == FIELDS ==
              private:
                //  -- Uniforms Handles --
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
                inline void activate(const Lens& lens_, const Camera& cam_) noexcept override;
                inline void render(const Actor& act_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
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
            inline void Specular::set_sun_col(const glm::vec3& sun_col_) noexcept
            {
                glUniform3fv(_sun_col, 1, &sun_col_[0]);
            }

            inline void Specular::set_sun_pos(const glm::vec3& sun_pos_) noexcept
            {
                glUniform3fv(_sun_pos, 1, &sun_pos_[0]);
            }


            //  -- Rendering --
            inline void Specular::activate(const Lens& lens_, const Camera& cam_) noexcept
            {
                glUseProgram(_handle);

                glUniformMatrix4fv(_proj, 1, GL_FALSE, &lens_.proj()[0][0]);

                glUniformMatrix4fv(_view, 1, GL_FALSE, &cam_.view()[0][0]);
                glUniform3fv(_cam_pos, 1, &cam_.pos()[0]);
            }

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
