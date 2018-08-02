/**
 *  @file   arctk/gui/actor.hpp
 *  @date   02/08/2018
 *  @author Freddy Wordingham
 *
 *  Graphical actor class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_ACTOR_HPP
#define ARCTK_GUI_ACTOR_HPP



//  == IMPORTS ==



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {



        //  == CLASS ==
        /**
         *  Renderable actor class.
         */
        class Actor
        {
            //  == FIELDS ==
          private:
            //  -- Properties --
            const GLsizei _num_vert; //!< Number of actor vertices.

            //  -- Vertices --
            const GLuint _vao; //!< Vertex array object handle.
            const GLuint _vbo; //!< Vertex buffer object handle.

            //  -- Rendering --
            GLenum _primitive_type; //!< Primitive type used to render the actor.
            GLenum _fill_mode;      //!< Fill mode used to render the actor.

            //  -- Transform --
            glm::vec3 _trans;  //!< Model translation vector.
            glm::vec3 _rotate; //!< Model rotation vector.
            glm::vec3 _scale;  //!< Model scale vector.

            //  -- Uniforms --
            glm::mat4 _model; //!< Model transformation matrix.



            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Actor(const std::vector<GLfloat>& verts_, const std::vector<size_t>& layout_ = {3}, GLenum primitive_type_ = GL_TRIANGLES, GLenum fill_mode_ = GL_FILL) noexcept;


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Actor(const std::vector<GLfloat>& verts_, const std::vector<size_t>& layout_, GLenum primitive_type_, GLenum fill_mode_) noexcept
          : _num_vert(static_cast<GLsizei>(verts_.size() / math::sum(layout)))
          , _vao(init_vao())
          , _vbo(init_vbo())
          , _primitive_type(primitive_type_)
          , _fill_mode(fill_mode_)
          , _trans(glm::vec3(0.0f, 0.0f, 0.0f))
          , _rotate(glm::vec3(0.0f, 0.0f, 0.0f))
          , _scale(glm::vec3(1.0f, 1.0f, 1.0f))
        {
            PRE((verts_.size() % math::sum(layout_)) == 0);

            glBindVertexArray(_vao);
            glBindBuffer(GL_ARRAY_BUFFER, _vbo);
            glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(verts_.size() * sizeof(GLfloat)), &verts_.front(), GL_STATIC_DRAW);

            const size_t chunk_size = math::sum(layout_) * sizeof(GLfloat);
            size_t       start      = 0;
            for (size_t i = 0; i < layout_.size(); ++i)
            {
                glVertexAttribPointer(static_cast<GLuint>(i), static_cast<GLint>(layout_[i]), GL_FLOAT, GL_FALSE, static_cast<GLsizei>(chunk_size), reinterpret_cast<GLvoid*>(start * sizeof(GLfloat)));
                glEnableVertexAttribArray(static_cast<GLuint>(i));

                start += layout_[i];
            }

            glBindBuffer(GL_ARRAY_BUFFER, 0);

            glBindVertexArray(0);

            update_model();
        }



    } // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_ACTOR_HPP
