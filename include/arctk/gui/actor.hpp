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
#include <arctk/geom.hpp>
#include <arctk/gui/point.hpp>
#include <arctk/math.hpp>
#include <arctk/phys.hpp>



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
            inline explicit Actor(const std::vector<glm::vec3>& verts_, const std::vector<size_t>& layout_ = {3}, GLenum primitive_type_ = GL_TRIANGLES, GLenum fill_mode_ = GL_FILL) noexcept;

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
            inline void set_col(const glm::vec3& col_) noexcept;
            inline void set_col(const glm::vec4& col_) noexcept;
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
         *  @param  layout_         Dimension layout patturn.
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

        /**
         *  Construct an actor using a vector of three-dimensional positions in a given layout in terms of triplets.
         *  Actor is rendered as the given primitive type with the given fill mode.
         *
         *  @param  verts_          Vector of vertex positions.
         *  @param  layout_         Vertex layout patturn.
         *  @param  primitive_type_ Primitive used to render the actor.
         *  @param  fill_mode_      Fill mode used to render the actor.
         *
         *  @pre    verts_.size() * 3 must be exactly divisible by the sum of the layout patturn.
         */
        inline Actor::Actor(const std::vector<glm::vec3>& verts_, const std::vector<size_t>& layout_, GLenum primitive_type_, GLenum fill_mode_) noexcept
          : _num_vert(static_cast<GLsizei>((verts_.size() * 3) / math::container::sum(layout_)))
          , _vao(init_vao())
          , _vbo(init_vbo())
          , _primitive_type(primitive_type_)
          , _fill_mode(fill_mode_)
          , _trans(glm::vec3(0.0f, 0.0f, 0.0f))
          , _rot(glm::vec3(0.0f, 0.0f, 0.0f))
          , _scale(glm::vec3(1.0f, 1.0f, 1.0f))
          , _col(glm::vec4(1.0f, 0.0f, 1.0f, 1.0f))
        {
            PRE(((verts_.size() * 3) % math::container::sum(layout_)) == 0);

            glBindVertexArray(_vao);
            glBindBuffer(GL_ARRAY_BUFFER, _vbo);
            glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(verts_.size() * 3 * sizeof(GLfloat)), &verts_.front(), GL_STATIC_DRAW);

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

        /**
         *  Get the colour used to render the actor.
         *
         *  @return Colour used to render the actor.
         */
        inline const glm::vec4& Actor::col() const noexcept
        {
            return (_col);
        }

        /**
         *  Get the model matrix used to render the actor.
         *
         *  @return Model matrix used to render the actor.
         */
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
         *  Alpha value will be set to unity.
         *
         *  @param  col_    Colour used to render the actor.
         *
         *  @pre    col_.r must be between zero and unity.
         *  @pre    col_.g must be between zero and unity.
         *  @pre    col_.b must be between zero and unity.
         */
        inline void Actor::set_col(const glm::vec3& col_) noexcept
        {
            PRE((col_.r >= 0.0f) && (col_.r <= 1.0f));
            PRE((col_.g >= 0.0f) && (col_.g <= 1.0f));
            PRE((col_.b >= 0.0f) && (col_.b <= 1.0f));

            _col = glm::vec4(col_, 1.0f);
        }

        /**
         *  Set the rendering colour of the actor.
         *
         *  @param  col_    Colour used to render the actor.
         *
         *  @pre    col_.r must be between zero and unity.
         *  @pre    col_.g must be between zero and unity.
         *  @pre    col_.b must be between zero and unity.
         *  @pre    col_.a must be between zero and unity.
         */
        inline void Actor::set_col(const glm::vec4& col_) noexcept
        {
            PRE((col_.r >= 0.0f) && (col_.r <= 1.0f));
            PRE((col_.g >= 0.0f) && (col_.g <= 1.0f));
            PRE((col_.b >= 0.0f) && (col_.b <= 1.0f));
            PRE((col_.a >= 0.0f) && (col_.a <= 1.0f));

            _col = col_;
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
            glm::mat4 model(1.0f);

            model = glm::translate(model, _trans);
            model = glm::rotate(model, _rot.x, glm::vec3(1.0f, 0.0f, 0.0f));
            model = glm::rotate(model, _rot.y, glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::rotate(model, _rot.z, glm::vec3(0.0f, 0.0f, 1.0f));
            model = glm::scale(model, _scale);

            _model = model;
        }



        namespace actor //! actor namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Designs --
            inline Actor grid(const glm::vec2& min_, const glm::vec2& max_, const glm::vec2& cell_size_) noexcept;
            inline Actor axis_helper_x(float length_ = 1.0f, float width_ = 0.01f) noexcept;
            inline Actor axis_helper_y(float length_ = 1.0f, float width_ = 0.01f) noexcept;
            inline Actor axis_helper_z(float length_ = 1.0f, float width_ = 0.01f) noexcept;
            inline Actor box(const glm::vec3& min_ = glm::vec3(-1.0f, -1.0f, -1.0f), const glm::vec3& max_ = glm::vec3(1.0f, 1.0f, 1.0f)) noexcept;
            inline Actor box(const geom::Shape& shape_) noexcept;
            inline Actor cuboid(const glm::vec3& min_ = glm::vec3(-1.0f, -1.0f, -1.0f), const glm::vec3& max_ = glm::vec3(1.0f, 1.0f, 1.0f)) noexcept;
            inline Actor path(const std::vector<Point>& points_) noexcept;
            inline Actor act(const geom::shape::Aabb& tri_) noexcept;
            inline Actor act(const geom::shape::Circle& circ_) noexcept;
            inline Actor act(const geom::shape::Mesh& mesh_) noexcept;
            inline Actor act(const geom::shape::Plane& plane_) noexcept;
            inline Actor act(const geom::shape::Triangle& tri_) noexcept;



            //  == FUNCTIONS ==
            //  -- Designs --
            /**
             *  Create a grid actor over a given area with a given cell size.
             *
             *  @param  min_        Minimum bound of the grid.
             *  @param  max_        Maximum bound of the grid.
             *  @param  cell_size_  Size of the grid's cells.
             *
             *  @pre    min_.x must be less than max_.x.
             *  @pre    min_.y must be less than max_.y.
             *  @pre    cell_size_.x must be positive.
             *  @pre    cell_size_.y must be positive.
             *
             *  @return Grid actor.
             */
            inline Actor grid(const glm::vec2& min_, const glm::vec2& max_, const glm::vec2& cell_size_) noexcept
            {
                PRE(min_.x < max_.x);
                PRE(min_.y < max_.y);
                PRE(cell_size_.x > 0.0f);
                PRE(cell_size_.y > 0.0f);

                const auto x_start = static_cast<int>(std::trunc(min_.x / cell_size_.x));
                const auto x_end   = static_cast<int>(std::trunc(max_.x / cell_size_.x));
                const auto y_start = static_cast<int>(std::trunc(min_.y / cell_size_.y));
                const auto y_end   = static_cast<int>(std::trunc(max_.y / cell_size_.y));

                std::vector<glm::vec3> verts;
                verts.reserve(2 * static_cast<size_t>((x_end - x_start + 1) + (y_end - y_start + 1)));

                for (int i = x_start; i <= x_end; ++i)
                {
                    verts.emplace_back(glm::vec3(static_cast<float>(i) * cell_size_.x, min_.y, 0.0f));
                    verts.emplace_back(glm::vec3(static_cast<float>(i) * cell_size_.x, max_.y, 0.0f));
                }

                for (int i = y_start; i <= y_end; ++i)
                {
                    verts.emplace_back(glm::vec3(min_.x, static_cast<float>(i) * cell_size_.y, 0.0f));
                    verts.emplace_back(glm::vec3(max_.x, static_cast<float>(i) * cell_size_.y, 0.0f));
                }

                Actor grid(verts, {3}, GL_LINES);
                grid.set_col(glm::vec3(0.25f, 0.25f, 0.25f));

                return (grid);
            }

            /**
             *  Create a x-axis helper actor.
             *
             *  @param  length_ Length of the actor.
             *  @param  width_  Width of the actor.
             *
             *  @pre    length_ must be positive.
             *  @pre    width_ must be positive.
             *
             *  @return X-axis helper actor.
             */
            inline Actor axis_helper_x(const float length_, const float width_) noexcept
            {
                PRE(length_ > 0.0f);
                PRE(width_ > 0.0f);

                std::vector<glm::vec3> verts;
                verts.reserve(3 * 8);

                verts.emplace_back(glm::vec3(0.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(+width_, +width_, +width_));
                verts.emplace_back(glm::vec3(+width_, -width_, +width_));

                verts.emplace_back(glm::vec3(0.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(+width_, -width_, +width_));
                verts.emplace_back(glm::vec3(+width_, -width_, -width_));

                verts.emplace_back(glm::vec3(0.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(+width_, -width_, -width_));
                verts.emplace_back(glm::vec3(+width_, +width_, -width_));

                verts.emplace_back(glm::vec3(0.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(+width_, +width_, -width_));
                verts.emplace_back(glm::vec3(+width_, +width_, +width_));

                verts.emplace_back(glm::vec3(+width_, +width_, +width_));
                verts.emplace_back(glm::vec3(+width_, -width_, +width_));
                verts.emplace_back(glm::vec3(length_, 0.0f, 0.0f));

                verts.emplace_back(glm::vec3(+width_, -width_, +width_));
                verts.emplace_back(glm::vec3(+width_, -width_, -width_));
                verts.emplace_back(glm::vec3(length_, 0.0f, 0.0f));

                verts.emplace_back(glm::vec3(+width_, -width_, -width_));
                verts.emplace_back(glm::vec3(+width_, +width_, -width_));
                verts.emplace_back(glm::vec3(length_, 0.0f, 0.0f));

                verts.emplace_back(glm::vec3(+width_, +width_, -width_));
                verts.emplace_back(glm::vec3(+width_, +width_, +width_));
                verts.emplace_back(glm::vec3(length_, 0.0f, 0.0f));

                Actor helper(verts);
                helper.set_col(glm::vec3(1.0f, 0.0f, 0.0f));

                return (helper);
            }

            /**
             *  Create a y-axis helper actor.
             *
             *  @param  length_ Length of the actor.
             *  @param  width_  Width of the actor.
             *
             *  @pre    length_ must be positive.
             *  @pre    width_ must be positive.
             *
             *  @return Y-axis helper actor.
             */
            inline Actor axis_helper_y(const float length_, const float width_) noexcept
            {
                PRE(length_ > 0.0f);
                PRE(width_ > 0.0f);

                std::vector<glm::vec3> verts;
                verts.reserve(3 * 8);

                verts.emplace_back(glm::vec3(0.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(+width_, +width_, +width_));
                verts.emplace_back(glm::vec3(-width_, +width_, +width_));

                verts.emplace_back(glm::vec3(0.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(-width_, +width_, +width_));
                verts.emplace_back(glm::vec3(-width_, +width_, -width_));

                verts.emplace_back(glm::vec3(0.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(-width_, +width_, -width_));
                verts.emplace_back(glm::vec3(+width_, +width_, -width_));

                verts.emplace_back(glm::vec3(0.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(+width_, +width_, -width_));
                verts.emplace_back(glm::vec3(+width_, +width_, +width_));

                verts.emplace_back(glm::vec3(+width_, +width_, +width_));
                verts.emplace_back(glm::vec3(-width_, +width_, +width_));
                verts.emplace_back(glm::vec3(0.0f, length_, 0.0f));

                verts.emplace_back(glm::vec3(-width_, +width_, +width_));
                verts.emplace_back(glm::vec3(-width_, +width_, -width_));
                verts.emplace_back(glm::vec3(0.0f, length_, 0.0f));

                verts.emplace_back(glm::vec3(-width_, +width_, -width_));
                verts.emplace_back(glm::vec3(+width_, +width_, -width_));
                verts.emplace_back(glm::vec3(0.0f, length_, 0.0f));

                verts.emplace_back(glm::vec3(+width_, +width_, -width_));
                verts.emplace_back(glm::vec3(+width_, +width_, +width_));
                verts.emplace_back(glm::vec3(0.0f, length_, 0.0f));

                Actor helper(verts);
                helper.set_col(glm::vec3(0.0f, 1.0f, 0.0f));

                return (helper);
            }

            /**
             *  Create a z-axis helper actor.
             *
             *  @param  length_ Length of the actor.
             *  @param  width_  Width of the actor.
             *
             *  @pre    length_ must be positive.
             *  @pre    width_ must be positive.
             *
             *  @return Z-axis helper actor.
             */
            inline Actor axis_helper_z(const float length_, const float width_) noexcept
            {
                PRE(length_ > 0.0f);
                PRE(width_ > 0.0f);

                std::vector<glm::vec3> verts;
                verts.reserve(3 * 8);

                verts.emplace_back(glm::vec3(0.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(+width_, +width_, +width_));
                verts.emplace_back(glm::vec3(-width_, +width_, +width_));

                verts.emplace_back(glm::vec3(0.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(-width_, +width_, +width_));
                verts.emplace_back(glm::vec3(-width_, -width_, +width_));

                verts.emplace_back(glm::vec3(0.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(-width_, -width_, +width_));
                verts.emplace_back(glm::vec3(+width_, -width_, +width_));

                verts.emplace_back(glm::vec3(0.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(+width_, -width_, +width_));
                verts.emplace_back(glm::vec3(+width_, +width_, +width_));

                verts.emplace_back(glm::vec3(+width_, +width_, +width_));
                verts.emplace_back(glm::vec3(-width_, +width_, +width_));
                verts.emplace_back(glm::vec3(0.0f, 0.0f, length_));

                verts.emplace_back(glm::vec3(-width_, +width_, +width_));
                verts.emplace_back(glm::vec3(-width_, -width_, +width_));
                verts.emplace_back(glm::vec3(0.0f, 0.0f, length_));

                verts.emplace_back(glm::vec3(-width_, -width_, +width_));
                verts.emplace_back(glm::vec3(+width_, -width_, +width_));
                verts.emplace_back(glm::vec3(0.0f, 0.0f, length_));

                verts.emplace_back(glm::vec3(+width_, -width_, +width_));
                verts.emplace_back(glm::vec3(+width_, +width_, +width_));
                verts.emplace_back(glm::vec3(0.0f, 0.0f, length_));

                Actor helper(verts);
                helper.set_col(glm::vec3(0.0f, 0.0f, 1.0f));

                return (helper);
            }

            /**
             *  Create a axis-aligned bounding box actor.
             *  This is only the frame of the box.
             *
             *  @param  min_    Minimum vertex of the box.
             *  @param  max_    Maximum vertex of the box.
             *
             *  @pre    min_.x must be less than max_.x.
             *  @pre    min_.y must be less than max_.y.
             *  @pre    min_.z must be less than max_.z.
             *
             *  @return Axis aligned bounding box actor.
             */
            inline Actor box(const glm::vec3& min_, const glm::vec3& max_) noexcept
            {
                PRE(min_.x < max_.x);
                PRE(min_.y < max_.y);
                PRE(min_.z < max_.z);

                std::vector<glm::vec3> verts;
                verts.reserve(2 * 4 * 3);

                verts.emplace_back(glm::vec3(min_.x, min_.y, min_.z));
                verts.emplace_back(glm::vec3(max_.x, min_.y, min_.z));
                verts.emplace_back(glm::vec3(min_.x, max_.y, min_.z));
                verts.emplace_back(glm::vec3(max_.x, max_.y, min_.z));
                verts.emplace_back(glm::vec3(min_.x, min_.y, max_.z));
                verts.emplace_back(glm::vec3(max_.x, min_.y, max_.z));
                verts.emplace_back(glm::vec3(min_.x, max_.y, max_.z));
                verts.emplace_back(glm::vec3(max_.x, max_.y, max_.z));

                verts.emplace_back(glm::vec3(min_.x, min_.y, min_.z));
                verts.emplace_back(glm::vec3(min_.x, max_.y, min_.z));
                verts.emplace_back(glm::vec3(min_.x, min_.y, max_.z));
                verts.emplace_back(glm::vec3(min_.x, max_.y, max_.z));
                verts.emplace_back(glm::vec3(max_.x, min_.y, min_.z));
                verts.emplace_back(glm::vec3(max_.x, max_.y, min_.z));
                verts.emplace_back(glm::vec3(max_.x, min_.y, max_.z));
                verts.emplace_back(glm::vec3(max_.x, max_.y, max_.z));

                verts.emplace_back(glm::vec3(min_.x, min_.y, min_.z));
                verts.emplace_back(glm::vec3(min_.x, min_.y, max_.z));
                verts.emplace_back(glm::vec3(max_.x, min_.y, min_.z));
                verts.emplace_back(glm::vec3(max_.x, min_.y, max_.z));
                verts.emplace_back(glm::vec3(min_.x, max_.y, min_.z));
                verts.emplace_back(glm::vec3(min_.x, max_.y, max_.z));
                verts.emplace_back(glm::vec3(max_.x, max_.y, min_.z));
                verts.emplace_back(glm::vec3(max_.x, max_.y, max_.z));

                return (Actor(verts, {3}, GL_LINES));
            }

            /**
             *  Create an axis-aligned bounding box actor from a geometric shape.
             *
             *  @param  shape_  Shape to create an axis-aligned bounding box actor of.
             *
             *  @return Axis aligned bounding box actor.
             */
            inline Actor box(const geom::Shape& shape_) noexcept
            {
                return (box(glm::vec3(shape_.min().x, shape_.min().y, shape_.min().z), glm::vec3(shape_.max().x, shape_.max().y, shape_.max().z)));
            }

            /**
             *  Create a cuboid actor.
             *  This is a solid cuboid with faces.
             *
             *  @param  min_    Minimum vertex of the cuboid.
             *  @param  max_    Maximum vertex of the cuboid.
             *
             *  @pre    min_.x must be less than max_.x.
             *  @pre    min_.y must be less than max_.y.
             *  @pre    min_.z must be less than max_.z.
             *
             *  @return Cuboid actor.
             */
            inline Actor cuboid(const glm::vec3& min_, const glm::vec3& max_) noexcept // NOLINT
            {
                PRE(min_.x < max_.x);
                PRE(min_.y < max_.y);
                PRE(min_.z < max_.z);

                std::vector<glm::vec3> verts;
                verts.reserve(3 * 2 * 6);

                verts.emplace_back(glm::vec3(min_.x, min_.y, min_.z));
                verts.emplace_back(glm::vec3(0.0f, 0.0f, -1.0f));
                verts.emplace_back(glm::vec3(max_.x, max_.y, min_.z));
                verts.emplace_back(glm::vec3(0.0f, 0.0f, -1.0f));
                verts.emplace_back(glm::vec3(min_.x, max_.y, min_.z));
                verts.emplace_back(glm::vec3(0.0f, 0.0f, -1.0f));
                verts.emplace_back(glm::vec3(max_.x, max_.y, min_.z));
                verts.emplace_back(glm::vec3(0.0f, 0.0f, -1.0f));
                verts.emplace_back(glm::vec3(min_.x, min_.y, min_.z));
                verts.emplace_back(glm::vec3(0.0f, 0.0f, -1.0f));
                verts.emplace_back(glm::vec3(max_.x, min_.y, min_.z));
                verts.emplace_back(glm::vec3(0.0f, 0.0f, -1.0f));

                verts.emplace_back(glm::vec3(min_.x, min_.y, max_.z));
                verts.emplace_back(glm::vec3(0.0f, 0.0f, +1.0f));
                verts.emplace_back(glm::vec3(max_.x, max_.y, max_.z));
                verts.emplace_back(glm::vec3(0.0f, 0.0f, +1.0f));
                verts.emplace_back(glm::vec3(min_.x, max_.y, max_.z));
                verts.emplace_back(glm::vec3(0.0f, 0.0f, +1.0f));
                verts.emplace_back(glm::vec3(max_.x, max_.y, max_.z));
                verts.emplace_back(glm::vec3(0.0f, 0.0f, +1.0f));
                verts.emplace_back(glm::vec3(min_.x, min_.y, max_.z));
                verts.emplace_back(glm::vec3(0.0f, 0.0f, +1.0f));
                verts.emplace_back(glm::vec3(max_.x, min_.y, max_.z));
                verts.emplace_back(glm::vec3(0.0f, 0.0f, +1.0f));

                verts.emplace_back(glm::vec3(min_.x, min_.y, min_.z));
                verts.emplace_back(glm::vec3(-1.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(min_.x, max_.y, max_.z));
                verts.emplace_back(glm::vec3(-1.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(min_.x, min_.y, max_.z));
                verts.emplace_back(glm::vec3(-1.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(min_.x, max_.y, max_.z));
                verts.emplace_back(glm::vec3(-1.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(min_.x, min_.y, min_.z));
                verts.emplace_back(glm::vec3(-1.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(min_.x, max_.y, min_.z));
                verts.emplace_back(glm::vec3(-1.0f, 0.0f, 0.0f));

                verts.emplace_back(glm::vec3(max_.x, min_.y, min_.z));
                verts.emplace_back(glm::vec3(+1.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(max_.x, max_.y, max_.z));
                verts.emplace_back(glm::vec3(+1.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(max_.x, min_.y, max_.z));
                verts.emplace_back(glm::vec3(+1.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(max_.x, max_.y, max_.z));
                verts.emplace_back(glm::vec3(+1.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(max_.x, min_.y, min_.z));
                verts.emplace_back(glm::vec3(+1.0f, 0.0f, 0.0f));
                verts.emplace_back(glm::vec3(max_.x, max_.y, min_.z));
                verts.emplace_back(glm::vec3(+1.0f, 0.0f, 0.0f));

                verts.emplace_back(glm::vec3(min_.x, min_.y, min_.z));
                verts.emplace_back(glm::vec3(0.0f, -1.0f, 0.0f));
                verts.emplace_back(glm::vec3(max_.x, min_.y, max_.z));
                verts.emplace_back(glm::vec3(0.0f, -1.0f, 0.0f));
                verts.emplace_back(glm::vec3(max_.x, min_.y, min_.z));
                verts.emplace_back(glm::vec3(0.0f, -1.0f, 0.0f));
                verts.emplace_back(glm::vec3(max_.x, min_.y, max_.z));
                verts.emplace_back(glm::vec3(0.0f, -1.0f, 0.0f));
                verts.emplace_back(glm::vec3(min_.x, min_.y, min_.z));
                verts.emplace_back(glm::vec3(0.0f, -1.0f, 0.0f));
                verts.emplace_back(glm::vec3(min_.x, min_.y, max_.z));
                verts.emplace_back(glm::vec3(0.0f, -1.0f, 0.0f));

                verts.emplace_back(glm::vec3(min_.x, max_.y, min_.z));
                verts.emplace_back(glm::vec3(0.0f, +1.0f, 0.0f));
                verts.emplace_back(glm::vec3(max_.x, max_.y, max_.z));
                verts.emplace_back(glm::vec3(0.0f, +1.0f, 0.0f));
                verts.emplace_back(glm::vec3(max_.x, max_.y, min_.z));
                verts.emplace_back(glm::vec3(0.0f, +1.0f, 0.0f));
                verts.emplace_back(glm::vec3(max_.x, max_.y, max_.z));
                verts.emplace_back(glm::vec3(0.0f, +1.0f, 0.0f));
                verts.emplace_back(glm::vec3(min_.x, max_.y, min_.z));
                verts.emplace_back(glm::vec3(0.0f, +1.0f, 0.0f));
                verts.emplace_back(glm::vec3(min_.x, max_.y, max_.z));
                verts.emplace_back(glm::vec3(0.0f, +1.0f, 0.0f));

                return (Actor(verts, {3, 3}));
            }

            /**
             *  Create path actor from a vector of points.
             *
             *  @param  points_ Vector of point data to create a path actor of.
             *
             *  @return Path actor.
             */
            inline Actor path(const std::vector<Point>& points_) noexcept
            {
                std::vector<float> verts;
                verts.reserve(points_.size() * (sizeof(Point) / sizeof(float)));

                for (size_t i = 0; i < points_.size(); ++i)
                {
                    verts.emplace_back(points_[i].pos.x);
                    verts.emplace_back(points_[i].pos.y);
                    verts.emplace_back(points_[i].pos.z);
                    verts.emplace_back(points_[i].time);
                    verts.emplace_back(points_[i].wavelength);
                }

                return (Actor(verts, {3, 1, 1}, GL_LINE_STRIP));
            }

            /**
             *  Create an actor from a axis-aligned bounding box shape.
             *
             *  @param  aabb_   Axis-aligned bounding box to create an actor of.
             *
             *  @return Axis-aligned bounding box actor.
             */
            inline Actor act(const geom::shape::Aabb& aabb_) noexcept
            {
                return (cuboid(glm::vec3(aabb_.min().x, aabb_.min().y, aabb_.min().z), glm::vec3(aabb_.max().x, aabb_.max().y, aabb_.max().z)));
            }

            inline Actor act(const geom::shape::Circle& circ_) noexcept
            {
                const size_t res = 16;

                std::vector<glm::vec3> verts;
                verts.reserve(res * 3 * 2);

                const mat4 transform = math::mat::translate(circ_.pos()) * math::mat::rotate_z(std::copysign(std::acos(vec3(circ_.norm().x, circ_.norm().y, 0.0).normal().y), -circ_.norm().x)) * math::mat::rotate_x(-std::acos(circ_.norm().z));

                const vec3 norm(std::sin(circ_.aperture()), 0.0, std::cos(circ_.aperture()));

                const double delta = consts::math::TWO_PI / res;
                for (size_t i = 0; i < res; ++i)
                {
                    const double phi_0 = delta * static_cast<double>(i);
                    const double phi_1 = delta * static_cast<double>(i + 1);

                    const vec4 p_0 = transform * vec4(0.0, 0.0, 0.0, 1.0);
                    const vec4 p_1 = transform * vec4(std::cos(phi_0) * circ_.rad(), std::sin(phi_0) * circ_.rad(), 0.0, 1.0);
                    const vec4 p_2 = transform * vec4(std::cos(phi_1) * circ_.rad(), std::sin(phi_1) * circ_.rad(), 0.0, 1.0);

                    const vec4 n_0 = transform * vec4(0.0, 0.0, 1.0, 0.0);
                    const vec4 n_1 = transform * vec4(std::cos(phi_0) * std::sin(circ_.aperture()), std::sin(phi_0) * std::sin(circ_.aperture()), std::cos(circ_.aperture()), 0.0);
                    const vec4 n_2 = transform * vec4(std::cos(phi_1) * std::sin(circ_.aperture()), std::sin(phi_1) * std::sin(circ_.aperture()), std::cos(circ_.aperture()), 0.0);

                    verts.emplace_back(glm::vec3(static_cast<float>(p_0.x), static_cast<float>(p_0.y), static_cast<float>(p_0.z)));
                    verts.emplace_back(glm::vec3(static_cast<float>(n_0.x), static_cast<float>(n_0.y), static_cast<float>(n_0.z)));
                    verts.emplace_back(glm::vec3(static_cast<float>(p_1.x), static_cast<float>(p_1.y), static_cast<float>(p_1.z)));
                    verts.emplace_back(glm::vec3(static_cast<float>(n_1.x), static_cast<float>(n_1.y), static_cast<float>(n_1.z)));
                    verts.emplace_back(glm::vec3(static_cast<float>(p_2.x), static_cast<float>(p_2.y), static_cast<float>(p_2.z)));
                    verts.emplace_back(glm::vec3(static_cast<float>(n_2.x), static_cast<float>(n_2.y), static_cast<float>(n_2.z)));
                }

                return (Actor(verts, {3, 3}));
            }

            /**
             *  Create an actor from a mesh shape.
             *
             *  @param  mesh_   Mesh to create an actor of.
             *
             *  @return Mesh actor.
             */
            inline Actor act(const geom::shape::Mesh& mesh_) noexcept
            {
                std::vector<glm::vec3> verts;
                verts.reserve(mesh_.num_tri() * 3 * 2);

                for (size_t i = 0; i < mesh_.num_tri(); ++i)
                {
                    const geom::shape::Triangle& tri = mesh_.tri(i);

                    for (size_t j = 0; j < 3; ++j)
                    {
                        verts.emplace_back(glm::vec3(static_cast<float>(tri.poss()[j].x), static_cast<float>(tri.poss()[j].y), static_cast<float>(tri.poss()[j].z)));
                        verts.emplace_back(glm::vec3(static_cast<float>(tri.norms()[j].x), static_cast<float>(tri.norms()[j].y), static_cast<float>(tri.norms()[j].z)));
                    }
                }

                return (Actor(verts, {3, 3}));
            }

            inline Actor act(const geom::shape::Plane& plane_) noexcept
            {
                const size_t res = 4;
                const double rad = 1e6;

                std::vector<glm::vec3> verts;
                verts.reserve(res * 3 * 2);

                const mat4 transform = math::mat::translate(plane_.pos()) * math::mat::rotate_z(std::copysign(std::acos(vec3(plane_.norm().x, plane_.norm().y, 0.0).normal().y), -plane_.norm().x)) * math::mat::rotate_x(-std::acos(plane_.norm().z));

                const double delta = consts::math::TWO_PI / res;
                for (size_t i = 0; i < res; ++i)
                {
                    const double phi_0 = delta * static_cast<double>(i);
                    const double phi_1 = delta * static_cast<double>(i + 1);

                    const vec4 p_0 = transform * vec4(0.0, 0.0, 0.0, 1.0);
                    const vec4 p_1 = transform * vec4(std::cos(phi_0) * rad, std::sin(phi_0) * rad, 0.0, 1.0);
                    const vec4 p_2 = transform * vec4(std::cos(phi_1) * rad, std::sin(phi_1) * rad, 0.0, 1.0);

                    const vec4 norm = transform * vec4(0.0, 0.0, 1.0, 0.0);

                    verts.emplace_back(glm::vec3(static_cast<float>(p_0.x), static_cast<float>(p_0.y), static_cast<float>(p_0.z)));
                    verts.emplace_back(glm::vec3(static_cast<float>(norm.x), static_cast<float>(norm.y), static_cast<float>(norm.z)));
                    verts.emplace_back(glm::vec3(static_cast<float>(p_1.x), static_cast<float>(p_1.y), static_cast<float>(p_1.z)));
                    verts.emplace_back(glm::vec3(static_cast<float>(norm.x), static_cast<float>(norm.y), static_cast<float>(norm.z)));
                    verts.emplace_back(glm::vec3(static_cast<float>(p_2.x), static_cast<float>(p_2.y), static_cast<float>(p_2.z)));
                    verts.emplace_back(glm::vec3(static_cast<float>(norm.x), static_cast<float>(norm.y), static_cast<float>(norm.z)));
                }

                return (Actor(verts, {3, 3}));
            }

            /**
             *  Create an actor from a triangle shape.
             *
             *  @param  tri_    Triangle to create an actor of.
             *
             *  @return Triangle actor.
             */
            inline Actor act(const geom::shape::Triangle& tri_) noexcept
            {
                std::vector<glm::vec3> verts;
                verts.reserve(3 * 2);

                for (size_t i = 0; i < 3; ++i)
                {
                    verts.emplace_back(glm::vec3(static_cast<float>(tri_.poss()[i].x), static_cast<float>(tri_.poss()[i].y), static_cast<float>(tri_.poss()[i].z)));
                    verts.emplace_back(glm::vec3(static_cast<float>(tri_.norms()[i].x), static_cast<float>(tri_.norms()[i].y), static_cast<float>(tri_.norms()[i].z)));
                }

                return (Actor(verts, {3, 3}));
            }



        } // namespace actor
    }     // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_ACTOR_HPP
