/**
 *  @file   arctk/gui/actor.hpp
 *  @date   17/07/2018
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
//  -- Std --
#include <map>
#include <vector>

//  -- Graphical --
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math.hpp>



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
            const GLsizei _num_vert; //!< Number of actor vertices.

            //  -- Vertices --
            const GLuint _vao; //!< Vertex array object handle.
            const GLuint _vbo; //!< Vertex buffer object handle.

            //  -- Rendering --
            GLenum _primitive_type; //!< Primitive type used to render actor.
            GLenum _fill_mode;      //!< Fill mode used to render actor.

            //  -- Transform --
            glm::vec3 _trans;  //!< Model translation vector.
            glm::vec3 _rotate; //!< Model rotation vector.
            glm::vec3 _scale;  //!< Model scaling vector.

            //  -- Uniforms --
            glm::mat4                        _model{};         //!< Model transformation matrix.
            std::map<std::string, int>       _int_uniform{};   //!< Integer uniform map.
            std::map<std::string, float>     _float_uniform{}; //!< Float uniform map.
            std::map<std::string, glm::vec2> _vec2_uniform{};  //!< Vec2 uniform map.
            std::map<std::string, glm::vec3> _vec3_uniform{};  //!< Vec3 uniform map.
            std::map<std::string, glm::vec4> _vec4_uniform{};  //!< Vec4 uniform map.
            std::map<std::string, glm::mat2> _mat2_uniform{};  //!< Mat2 uniform map.
            std::map<std::string, glm::mat3> _mat3_uniform{};  //!< Mat3 uniform map.
            std::map<std::string, glm::mat4> _mat4_uniform{};  //!< Mat4 uniform map.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Actor(const std::vector<GLfloat>& verts_, const std::vector<size_t>& layout_, GLenum primitive_type_ = GL_TRIANGLES, GLenum fill_mode_ = GL_FILL) noexcept;

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
            inline const glm::vec3& trans() const noexcept;
            inline const glm::vec3& rotate() const noexcept;
            inline const glm::vec3& scale() const noexcept;
            inline const glm::mat4& model() const noexcept;
            inline int              int_uniform(const std::string& name_) const noexcept;
            inline float            float_uniform(const std::string& name_) const noexcept;
            inline const glm::vec2& vec2_uniform(const std::string& name_) const noexcept;
            inline const glm::vec3& vec3_uniform(const std::string& name_) const noexcept;
            inline const glm::vec4& vec4_uniform(const std::string& name_) const noexcept;
            inline const glm::mat2& mat2_uniform(const std::string& name_) const noexcept;
            inline const glm::mat3& mat3_uniform(const std::string& name_) const noexcept;
            inline const glm::mat4& mat4_uniform(const std::string& name_) const noexcept;

            //  -- Setters --
            inline void set_primitive_type(GLenum primitive_type_) noexcept;
            inline void set_fill_mode(GLenum fill_mode_) noexcept;
            inline void set_trans(const glm::vec3& trans_) noexcept;
            inline void set_rotate(const glm::vec3& rotate_) noexcept;
            inline void set_scale(const glm::vec3& scale_) noexcept;
            inline void set_int_uniform(const std::string& name_, int int_) noexcept;
            inline void set_float_uniform(const std::string& name_, float float_) noexcept;
            inline void set_vec2_uniform(const std::string& name_, const glm::vec2& vec2_) noexcept;
            inline void set_vec3_uniform(const std::string& name_, const glm::vec3& vec3_) noexcept;
            inline void set_vec4_uniform(const std::string& name_, const glm::vec4& vec4_) noexcept;
            inline void set_mat2_uniform(const std::string& name_, const glm::mat2& mat2_) noexcept;
            inline void set_mat3_uniform(const std::string& name_, const glm::mat3& mat3_) noexcept;
            inline void set_mat4_uniform(const std::string& name_, const glm::mat4& mat4_) noexcept;

          private:
            //  -- Updating --
            inline void update_model() noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct an actor using a vector of floats in a given layout.
         *  Actor is rendered as the given primitive type.
         *
         *  @param  verts_          Vector of vertex data.
         *  @param  layout_         Layout patturn of vertex data.
         *  @param  primitive_type_ Type of primitive used to render the actor.
         *  @param  fill_mode_      Type of mode used to render the actor.
         */
        inline Actor::Actor(const std::vector<GLfloat>& verts_, const std::vector<size_t>& layout_, const GLenum primitive_type_, const GLenum fill_mode_) noexcept
          : _num_vert(static_cast<GLsizei>(verts_.size() / math::container::sum(layout_)))
          , _vao(init_vao())
          , _vbo(init_vbo())
          , _primitive_type(primitive_type_)
          , _fill_mode(fill_mode_)
          , _trans(glm::vec3(0.0f, 0.0f, 0.0f))
          , _rotate(glm::vec3(0.0f, 0.0f, 0.0f))
          , _scale(glm::vec3(1.0f, 1.0f, 1.0f))
        {
            PRE((verts_.size() % math::container::sum(layout_)) == 0);

            glBindVertexArray(_vao);
            glBindBuffer(GL_ARRAY_BUFFER, _vbo);
            glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(verts_.size() * sizeof(GLfloat)), &verts_.front(), GL_STATIC_DRAW);

            const size_t chunk_size = math::sum(layout_) * sizeof(GLfloat);
            size_t       start      = 0;
            for (size_t i = 0; i < layout_.size(); ++i)
            {
                glVertexAttribPointer(static_cast<GLuint>(i), static_cast<GLint>(layout_[i]), GL_FLOAT, GL_FALSE, static_cast<GLsizei>(chunk_size),
                                      reinterpret_cast<GLvoid*>(start * sizeof(GLfloat))); // NOLINT
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
         *  Get the model translation vector.
         *
         *  @return Model translation vector.
         */
        inline const glm::vec3& Actor::trans() const noexcept
        {
            return (_trans);
        }

        /**
         *  Get the model rotate vector.
         *
         *  @return Model rotate vector.
         */
        inline const glm::vec3& Actor::rotate() const noexcept
        {
            return (_rotate);
        }

        /**
         *  Get the model scale vector.
         *
         *  @return Model scale vector.
         */
        inline const glm::vec3& Actor::scale() const noexcept
        {
            return (_scale);
        }

        /**
         *  Get the model transformation matrix.
         *
         *  @return Model transformation matrix.
         */
        inline const glm::mat4& Actor::model() const noexcept
        {
            return (_model);
        }

        /**
         *  Get the value of an integer uniform variable.
         *
         *  @param  name_   Of the uniform.
         *
         *  @pre    name_ must exist within the integer uniform map.
         *
         *  @return Value of the uniform.
         */
        inline int Actor::int_uniform(const std::string& name_) const noexcept
        {
            PRE(_int_uniform.find(name_) != _int_uniform.end());

            return (_int_uniform.find(name_)->second);
        }

        /**
         *  Get the value of an float uniform variable.
         *
         *  @param  name_   Of the uniform.
         *
         *  @pre    name_ must exist within the float uniform map.
         *
         *  @return Value of the uniform.
         */
        inline float Actor::float_uniform(const std::string& name_) const noexcept
        {
            PRE(_float_uniform.find(name_) != _float_uniform.end());

            return (_float_uniform.find(name_)->second);
        }

        /**
         *  Get the value of an vec2 uniform variable.
         *
         *  @param  name_   Of the uniform.
         *
         *  @pre    name_ must exist within the vec2 uniform map.
         *
         *  @return Value of the uniform.
         */
        inline const glm::vec2& Actor::vec2_uniform(const std::string& name_) const noexcept
        {
            PRE(_vec2_uniform.find(name_) != _vec2_uniform.end());

            return (_vec2_uniform.find(name_)->second);
        }

        /**
         *  Get the value of an vec3 uniform variable.
         *
         *  @param  name_   Of the uniform.
         *
         *  @pre    name_ must exist within the vec3 uniform map.
         *
         *  @return Value of the uniform.
         */
        inline const glm::vec3& Actor::vec3_uniform(const std::string& name_) const noexcept
        {
            PRE(_vec3_uniform.find(name_) != _vec3_uniform.end());

            return (_vec3_uniform.find(name_)->second);
        }

        /**
         *  Get the value of an vec4 uniform variable.
         *
         *  @param  name_   Of the uniform.
         *
         *  @pre    name_ must exist within the vec4 uniform map.
         *
         *  @return Value of the uniform.
         */
        inline const glm::vec4& Actor::vec4_uniform(const std::string& name_) const noexcept
        {
            PRE(_vec4_uniform.find(name_) != _vec4_uniform.end());

            return (_vec4_uniform.find(name_)->second);
        }

        /**
         *  Get the value of an mat2 uniform variable.
         *
         *  @param  name_   Of the uniform.
         *
         *  @pre    name_ must exist within the mat2 uniform map.
         *
         *  @return Value of the uniform.
         */
        inline const glm::mat2& Actor::mat2_uniform(const std::string& name_) const noexcept
        {
            PRE(_mat2_uniform.find(name_) != _mat2_uniform.end());

            return (_mat2_uniform.find(name_)->second);
        }

        /**
         *  Get the value of an mat3 uniform variable.
         *
         *  @param  name_   Of the uniform.
         *
         *  @pre    name_ must exist within the mat3 uniform map.
         *
         *  @return Value of the uniform.
         */
        inline const glm::mat3& Actor::mat3_uniform(const std::string& name_) const noexcept
        {
            PRE(_mat3_uniform.find(name_) != _mat3_uniform.end());

            return (_mat3_uniform.find(name_)->second);
        }

        /**
         *  Get the value of an mat4 uniform variable.
         *
         *  @param  name_   Of the uniform.
         *
         *  @pre    name_ must exist within the mat4 uniform map.
         *
         *  @return Value of the uniform.
         */
        inline const glm::mat4& Actor::mat4_uniform(const std::string& name_) const noexcept
        {
            PRE(_mat4_uniform.find(name_) != _mat4_uniform.end());

            return (_mat4_uniform.find(name_)->second);
        }


        //  -- Setters --
        /**
         *  Set the primitive type used to render the actor.
         *
         *  @param  primitive_type_ Primitive type to render actor with.
         */
        inline void Actor::set_primitive_type(const GLenum primitive_type_) noexcept
        {
            _primitive_type = primitive_type_;
        }

        /**
         *  Set the fill mode used to render the actor.
         *
         *  @param  fill_mode_  Fill mode to render actor with.
         */
        inline void Actor::set_fill_mode(const GLenum fill_mode_) noexcept
        {
            _fill_mode = fill_mode_;
        }

        /**
         *  Set the model translation vector used to render the actor.
         *
         *  @param  trans_  Translation of model matrix.
         */
        inline void Actor::set_trans(const glm::vec3& trans_) noexcept
        {
            _trans = trans_;

            update_model();
        }

        /**
         *  Set the model rotation vector used to render the actor.
         *
         *  @param  rotate_ Rotation of model matrix.
         */
        inline void Actor::set_rotate(const glm::vec3& rotate_) noexcept
        {
            _rotate = rotate_;

            update_model();
        }

        /**
         *  Set the model scale vector used to render the actor.
         *
         *  @param  scale_  Scale of model matrix.
         */
        inline void Actor::set_scale(const glm::vec3& scale_) noexcept
        {
            _scale = scale_;

            update_model();
        }

        /**
         *  Set the value of an integer uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  int_    Value of uniform.
         *
         *  @pre    name_ must exist within the integer uniform map.
         */
        inline void Actor::set_int_uniform(const std::string& name_, const int int_) noexcept
        {
            PRE(_int_uniform.find(name_) != _int_uniform.end());

            _int_uniform.emplace(std::make_pair(name_, int_));
        }

        /**
         *  Set the value of a float uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  float_  Value of uniform.
         *
         *  @pre    name_ must exist within the float uniform map.
         */
        inline void Actor::set_float_uniform(const std::string& name_, const float float_) noexcept
        {
            PRE(_float_uniform.find(name_) != _float_uniform.end());

            _float_uniform.emplace(std::make_pair(name_, float_));
        }

        /**
         *  Set the value of a vec2 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  vec2_   Value of uniform.
         *
         *  @pre    name_ must exist within the vec2 uniform map.
         */
        inline void Actor::set_vec2_uniform(const std::string& name_, const glm::vec2& vec2_) noexcept
        {
            PRE(_vec2_uniform.find(name_) != _vec2_uniform.end());

            _vec2_uniform.emplace(std::make_pair(name_, vec2_));
        }

        /**
         *  Set the value of a vec3 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  vec3_   Value of uniform.
         *
         *  @pre    name_ must exist within the vec3 uniform map.
         */
        inline void Actor::set_vec3_uniform(const std::string& name_, const glm::vec3& vec3_) noexcept
        {
            PRE(_vec3_uniform.find(name_) != _vec3_uniform.end());

            _vec3_uniform.emplace(std::make_pair(name_, vec3_));
        }

        /**
         *  Set the value of a vec4 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  vec4_   Value of uniform.
         *
         *  @pre    name_ must exist within the vec4 uniform map.
         */
        inline void Actor::set_vec4_uniform(const std::string& name_, const glm::vec4& vec4_) noexcept
        {
            PRE(_vec4_uniform.find(name_) != _vec4_uniform.end());

            _vec4_uniform.emplace(std::make_pair(name_, vec4_));
        }

        /**
         *  Set the value of a mat2 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  mat2_   Value of uniform.
         *
         *  @pre    name_ must exist within the mat2 uniform map.
         */
        inline void Actor::set_mat2_uniform(const std::string& name_, const glm::mat2& mat2_) noexcept
        {
            PRE(_mat2_uniform.find(name_) != _mat2_uniform.end());

            _mat2_uniform.emplace(std::make_pair(name_, mat2_));
        }

        /**
         *  Set the value of a mat3 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  mat3_   Value of uniform.
         *
         *  @pre    name_ must exist within the mat3 uniform map.
         */
        inline void Actor::set_mat3_uniform(const std::string& name_, const glm::mat3& mat3_) noexcept
        {
            PRE(_mat3_uniform.find(name_) != _mat3_uniform.end());

            _mat3_uniform.emplace(std::make_pair(name_, mat3_));
        }

        /**
         *  Set the value of a mat4 uniform.
         *
         *  @param  name_   Name of uniform.
         *  @param  mat4_   Value of uniform.
         *
         *  @pre    name_ must exist within the mat4 uniform map.
         */
        inline void Actor::set_mat4_uniform(const std::string& name_, const glm::mat4& mat4_) noexcept
        {
            PRE(_mat4_uniform.find(name_) != _mat4_uniform.end());

            _mat4_uniform.emplace(std::make_pair(name_, mat4_));
        }


        //  -- Updating --
        /**
         *  Update the model matrix.
         */
        inline void Actor::update_model() noexcept
        {
            glm::mat4 model;

            model = glm::translate(model, _trans);
            model = glm::rotate(model, math::rad_to_deg(_rotate.x), glm::vec3(1.0f, 0.0f, 0.0f));
            model = glm::rotate(model, math::rad_to_deg(_rotate.y), glm::vec3(0.0f, 1.0f, 0.0f));
            model = glm::rotate(model, math::rad_to_deg(_rotate.z), glm::vec3(0.0f, 0.0f, 1.0f));
            model = glm::scale(model, _scale);

            _model = model;
        }



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_ACTOR_HPP
