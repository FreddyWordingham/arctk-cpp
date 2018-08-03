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
//  -- Std --
#include <vector>

//  -- Graphical --
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/transform.hpp>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>



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
            glm::vec3 _trans; //!< Model translation vector.
            glm::vec3 _rot;   //!< Model rotation vector.
            glm::vec3 _scale; //!< Model scale vector.

            //  -- Uniforms --
            glm::vec4 _col;     //!< Colour vector.
            glm::mat4 _model{}; //!< Model transformation matrix.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Actor(const std::vector<GLfloat>& verts_, const std::vector<size_t>& layout_ = {3}, GLenum primitive_type_ = GL_TRIANGLES, GLenum fill_mode_ = GL_FILL) noexcept;

          private:
            //  -- Initialisation --
            inline GLuint init_vao() const noexcept;
            inline GLuint init_vbo() const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline GLsizei          num_vert() const noexcept;
            inline GLuint           vao() const noexcept;
            inline GLuint           vbo() const noexcept;
            inline GLenum           primitive_type() const noexcept;
            inline GLenum           fill_mode() const noexcept;
            inline const glm::vec4& col() const noexcept;
            inline const glm::mat4& model() const noexcept;

            //  -- Setters --
            inline void set_primitive_type(GLenum primitive_type_) noexcept;
            inline void set_fill_mode(GLenum fill_mode_) noexcept;
            inline void set_col(float red_, float green_, float blue_, float alpha_) noexcept;
            inline void translate(const glm::vec3& trans_) noexcept;
            inline void rotate(const glm::vec3& rot_) noexcept;
            inline void scale(const glm::vec3& scale_) noexcept;

          private:
            //  -- Updating --
            inline void update_model() noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct an actor using a vector of floats in a given layout.
         *  Actor is rendered as the given primitive type with the given fill mode.
         *
         *  @param  verts_          Vector of vertex dimensions.
         *  @param  layout_         Vertex layout patturn.
         *  @param  primitive_type_ Primitive used to render the actor.
         *  @param  fill_mode_      Fill mode used to render the actor.
         *
         *  @pre    verts_.size() must be exactly divisible by the sum of the layout patturn.
         */
        inline Actor::Actor(const std::vector<GLfloat>& verts_, const std::vector<size_t>& layout_, GLenum primitive_type_, GLenum fill_mode_) noexcept
          : _num_vert(static_cast<GLsizei>(verts_.size() / math::container::sum(layout_)))
          , _vao(init_vao())
          , _vbo(init_vbo())
          , _primitive_type(primitive_type_)
          , _fill_mode(fill_mode_)
          , _trans(glm::vec3(0.0f, 0.0f, 0.0f))
          , _rot(glm::vec3(0.0f, 0.0f, 0.0f))
          , _scale(glm::vec3(1.0f, 1.0f, 1.0f))
          , _col(glm::vec4(1.0f, 0.0f, 1.0f, 1.0f))
        {
            PRE((verts_.size() % math::container::sum(layout_)) == 0);

            glBindVertexArray(_vao);
            glBindBuffer(GL_ARRAY_BUFFER, _vbo);
            glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(verts_.size() * sizeof(GLfloat)), &verts_.front(), GL_STATIC_DRAW);

            const size_t chunk_size = math::container::sum(layout_) * sizeof(GLfloat);
            size_t       start      = 0;
            for (size_t i = 0; i < layout_.size(); ++i)
            {
                glVertexAttribPointer(static_cast<GLuint>(i), static_cast<GLint>(layout_[i]), GL_FLOAT, GL_FALSE, static_cast<GLsizei>(chunk_size), reinterpret_cast<GLvoid*>(start * sizeof(GLfloat))); // NOLINT
                glEnableVertexAttribArray(static_cast<GLuint>(i));

                start += layout_[i];
            }

            glBindBuffer(GL_ARRAY_BUFFER, 0);

            glBindVertexArray(0);

            update_model();
        }


        //  -- Initialisation --
        /**
         *  Initialise the vertex array object.
         *
         *  @return Handle to the initialised vertex array object.
         */
        inline GLuint Actor::init_vao() const noexcept
        {
            GLuint vao;

            glGenVertexArrays(1, &vao);

            return (vao);
        }

        /**
         *  Initialise the vertex buffer object.
         *
         *  @return Handle to the initialised vertex buffer object.
         */
        inline GLuint Actor::init_vbo() const noexcept
        {
            GLuint vbo;

            glGenBuffers(1, &vbo);

            return (vbo);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the number of vertices used by the actor.
         *
         *  @return Number of vertices.
         */
        inline GLsizei Actor::num_vert() const noexcept
        {
            return (_num_vert);
        }

        /**
         *  Get the vertex array object handle.
         *
         *  @return Vertex array object handle.
         */
        inline GLuint Actor::vao() const noexcept
        {
            return (_vao);
        }

        /**
         *  Get the vertex buffer object handle.
         *
         *  @return Vertex buffer object handle.
         */
        inline GLuint Actor::vbo() const noexcept
        {
            return (_vbo);
        }

        /**
         *  Get the primitive type used to render the actor.
         *
         *  @return Primitive type used to render the actor.
         */
        inline GLenum Actor::primitive_type() const noexcept
        {
            return (_primitive_type);
        }

        /**
         *  Get the fill mode used to render the actor.
         *
         *  @return Fill mode used to render the actor.
         */
        inline GLenum Actor::fill_mode() const noexcept
        {
            return (_fill_mode);
        }

        inline const glm::vec4& Actor::col() const noexcept
        {
            return (_col);
        }

        inline const glm::mat4& Actor::model() const noexcept
        {
            return (_model);
        }


        //  -- Setters --
        /**
         *  Set the primitive rendering type of the actor.
         *
         *  @param  primitive_type_ Primitive type used to render the actor.
         */
        inline void Actor::set_primitive_type(const GLenum primitive_type_) noexcept
        {
            _primitive_type = primitive_type_;
        }

        /**
         *  Set the fill mode rendering type of the actor.
         *
         *  @param  fill_mode_  Primitive type used to render the actor.
         */
        inline void Actor::set_fill_mode(const GLenum fill_mode_) noexcept
        {
            _fill_mode = fill_mode_;
        }

        /**
         *  Set the rendering colour of the actor.
         *
         *  @param  red_    Redness of colour used to render the actor.
         *  @param  green_  Greenness of colour used to render the actor.
         *  @param  blue_   Blueness of colour used to render the actor.
         *  @param  alpha_  Alpha of colour used to render the actor.
         *
         *  @pre    red_ must be between zero and unity.
         *  @pre    green_ must be between zero and unity.
         *  @pre    blue_ must be between zero and unity.
         *  @pre    alpha_ must be between zero and unity.
         */
        inline void Actor::set_col(const float red_, const float green_, const float blue_, const float alpha_) noexcept
        {
            PRE((red_ >= 0.0f) && (red_ <= 1.0f));
            PRE((green_ >= 0.0f) && (green_ <= 1.0f));
            PRE((blue_ >= 0.0f) && (blue_ <= 1.0f));
            PRE((alpha_ >= 0.0f) && (alpha_ <= 1.0f));

            _col = glm::vec4(red_, green_, blue_, alpha_);
        }

        /**
         *  Translate the actor by the given vector.
         *
         *  @param  trans_  Vector by which to translate the actor along each dimension.
         */
        inline void Actor::translate(const glm::vec3& trans_) noexcept
        {
            _trans += trans_;

            update_model();
        }

        /**
         *  Rotate the actor using the given vector.
         *  Rotations are performed in the order x, y, z.
         *
         *  @param  rot_    Vector by which to rotate the actor around each axis.
         */
        inline void Actor::rotate(const glm::vec3& rot_) noexcept
        {
            _rot += rot_;

            update_model();
        }

        /**
         *  Scale the actor using the given vector.
         *
         *  @param  scale_  Vector by which to scale the actor in each dimension.
         */
        inline void Actor::scale(const glm::vec3& scale_) noexcept
        {
            _scale.x *= scale_.x;
            _scale.y *= scale_.y;
            _scale.z *= scale_.z;

            update_model();
        }


        //  -- Updating --
        /**
         *  Update the model matrix.
         */
        inline void Actor::update_model() noexcept
        {
            glm::mat4 model;

            model = glm::translate(model, _trans);
            model = glm::rotateX(model, _rotate.x);
            model = glm::rotateY(model, _rotate.y);
            model = glm::rotateZ(model, _rotate.z);
            model = glm::scale(model, _scale);

            _model = model;
        }



    } // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_ACTOR_HPP
