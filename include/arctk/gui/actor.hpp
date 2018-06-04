/**
 *  @file   arctk/gui/actor.hpp
 *  @date   04/06/2018
 *  @author Freddy Wordingham
 *
 *  Renderable actor class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_ACTOR_HPP
#define ARCTK_GUI_ACTOR_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_GUI



//  == IMPORTS ==
//  -- Graphical --
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical user interface namespace
    {



        //  == CLASS ==
        /**
         *  Renderable object class.
         */
        class Actor
        {
            //  == FIELDS ==
          private:
            //  -- Properties --
            const GLsizei _num_vert;

            //  -- Vertices --
            const GLuint _vao;
            const GLuint _vbo;

            //  -- Rendering --
            GLenum _primitive_type;
            GLenum _fill_mode;

            //  -- Transform --
            glm::vec3 _trans;
            glm::vec3 _rotate;
            glm::vec3 _scale;

            //  -- Uniforms --
            glm::mat4                        _model;
            std::map<std::string, int>       _int_uniform;
            std::map<std::string, float>     _float_uniform;
            std::map<std::string, glm::vec2> _vec2_uniform;
            std::map<std::string, glm::vec3> _vec3_uniform;
            std::map<std::string, glm::vec4> _vec4_uniform;
            std::map<std::string, glm::mat2> _mat2_uniform;
            std::map<std::string, glm::mat3> _mat3_uniform;
            std::map<std::string, glm::mat4> _mat4_uniform;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Actor(const std::vector<GLfloat>& verts_, const std::vector<size_t>& layout_, GLenum primitive_type_ = GL_TRIANGLES, GLenum fill_mode_ = GL_FILL) noexcept;

          private:
            //  -- Initialisation --
            inline GLuint init_vao() const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        inline Actor::Actor(const std::vector<GLfloat>& verts_, const std::vector<size_t>& layout_, const GLenum primitive_type_, const GLenum fill_mode_) noexcept
          : _num_vert(static_cast<GLsizei>(verts_.size() / utl::sum(layout_)))
          , _vao(init_vao())
          , _vbo(init_vbo())
          , _primitive_type(primitive_type_)
          , _fill_mode(fill_mode_)
          , _trans(glm::vec3(0.0f, 0.0f, 0.0f))
          , _rotate(glm::vec3(0.0f, 0.0f, 0.0f))
          , _scale(glm::vec3(1.0f, 1.0f, 1.0f))
        {
            assert((verts_.size() % utl::sum(layout_)) == 0);

            glBindVertexArray(_vao);
            glBindBuffer(GL_ARRAY_BUFFER, _vbo);
            glBufferData(GL_ARRAY_BUFFER, verts_.size() * sizeof(GLfloat), &verts_.front(), GL_STATIC_DRAW);

            const size_t chunk_size = utl::sum(layout_) * sizeof(GLfloat);
            size_t       start      = 0;
            for (size_t i = 0; i < layout_.size(); ++i)
            {
                glVertexAttribPointer(i, layout_[i], GL_FLOAT, GL_FALSE, chunk_size,
                                      reinterpret_cast<GLvoid*>(start * sizeof(GLfloat))); // NOLINT
                glEnableVertexAttribArray(i);

                start += layout_[i];
            }

            glBindBuffer(GL_ARRAY_BUFFER, 0);

            glBindVertexArray(0);

            update_model();
        }


        //  -- Initialisation --
        inline GLuint Actor::init_vao() const noexcept
        {
            GLuint vao;

            glGenVertexArrays(1, &vao);

            return (vao);
        }



        //  == METHODS ==



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_ACTOR_HPP
