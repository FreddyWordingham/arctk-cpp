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



//  == BASE ==
#include <arctk/gui/shader.hpp>



//  == IMPORTS ==
//  -- Graphical --
#include <GL/glew.h>
#include <glm/glm.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {
        class Lens;
        class Camera;
        class Actor;
    } // namespace gui
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {
        namespace shader //! shader namespace
        {



            //  == CLASS ==
            /**
             *  Shader drawing normals.
             */
            class Normal : public Shader
            {
                //  == FIELDS ==
              private:
                //  -- Uniforms --
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
                inline void set_length(float length_) noexcept;

                //  -- Rendering --
                inline void activate(const Lens& lens_, const Camera& cam_) noexcept;
                inline void render(const Actor& act_) noexcept;
            };



        } // namespace shader
    }     // namespace gui
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/gui/shader/normal.inl>



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_NORMAL_HPP
