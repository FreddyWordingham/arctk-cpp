/**
 *  @file   arctk/gui/shader/ambient.hpp
 *  @date   07/08/2018
 *  @author Freddy Wordingham
 *
 *  Ambient lighting shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_AMBIENT_HPP
#define ARCTK_GUI_SHADER_AMBIENT_HPP



//  == BASE ==
#include <arctk/gui/shader.hpp>



//  == IMPORTS ==
//  -- Graphical --
#include <GL/glew.h>



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
             *  Shader using a ambient lighting source.
             */
            class Ambient : public Shader
            {
                //  == FIELDS ==
              private:
                //  -- Uniforms --
                const GLint _model; //!< Model matrix uniform handle.
                const GLint _view;  //!< View matrix uniform handle.
                const GLint _proj;  //!< Projection matrix uniform handle.
                const GLint _col;   //!< Colour uniform handle.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Ambient() noexcept;


                //  == METHODS ==
              public:
                //  -- Rendering --
                inline void activate(const Lens& lens_, const Camera& cam_) noexcept;
                inline void render(const Actor& act_) noexcept;
            };



        } // namespace shader
    }     // namespace gui
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/gui/shader/ambient.inl>



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_AMBIENT_HPP
