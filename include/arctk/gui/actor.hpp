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
#include <cassert>
#include <vector>

//  -- Graphical --
#include <GL/glew.h>
#include <glm/glm.hpp>

//  -- Arctk --
#include <arctk/gui/point.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {
        class Region;
    }              // namespace dom
    namespace geom //! geometric namespace
    {
        namespace shape //! shape namespace
        {
            class Box;
            class Triangle;
            class Mesh;
        }          // namespace shape
    }              // namespace geom
    namespace tree //! tree namespace
    {
        class Root;
    } // namespace tree
} // namespace arc



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



        namespace actor //! actor namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Designs --
            inline Actor grid(const glm::vec2& min_, const glm::vec2& max_, const glm::vec2& cell_size_) noexcept;
            inline Actor axis_helper_x(float length_ = 1.0f, float width_ = 0.01f) noexcept;
            inline Actor axis_helper_y(float length_ = 1.0f, float width_ = 0.01f) noexcept;
            inline Actor axis_helper_z(float length_ = 1.0f, float width_ = 0.01f) noexcept;
            inline Actor path(const std::vector<Point>& points_) noexcept;
            inline Actor shape(const geom::shape::Box& box_) noexcept;
            inline Actor shape(const geom::shape::Triangle& tri_) noexcept;
            inline Actor shape(const geom::shape::Mesh& mesh_) noexcept;
            inline Actor domain(const dom::Region& dom_) noexcept;
            inline Actor tree(const tree::Root& root_) noexcept;



        } // namespace actor
    }     // namespace gui
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/gui/actor.inl>



//  == GUARD END ==
#endif // ARCTK_GUI_ACTOR_HPP
