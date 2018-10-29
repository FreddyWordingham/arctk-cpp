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
             *  Shader using a specular lighting source.
             */
            class Specular : public Shader
            {
                //  == FIELDS ==
              private:
                //  -- Uniforms --
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
                inline void activate(const Lens& lens_, const Camera& cam_) noexcept;
                inline void render(const Actor& act_) noexcept;
            };



        } // namespace shader
    }     // namespace gui
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/gui/shader/specular.inl>



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_SPECULAR_HPP
