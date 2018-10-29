/**
 *  @file   arctk/gui/shader/ray.hpp
 *  @date   07/08/2018
 *  @author Freddy Wordingham
 *
 *  Ray drawing shader class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_SHADER_RAY_HPP
#define ARCTK_GUI_SHADER_RAY_HPP



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
             *  Shader rendering rays.
             */
            class Ray : public Shader
            {
                //  == FIELDS ==
              private:
                //  -- Uniforms --
                const GLint _model;      //!< Model matrix uniform handle.
                const GLint _view;       //!< View matrix uniform handle.
                const GLint _proj;       //!< Projection matrix uniform handle.
                const GLint _time_start; //!< Render time start uniform handle.
                const GLint _time_end;   //!< Render time end uniform handle.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Ray() noexcept;


                //  == METHODS ==
              public:
                //  -- Setters --
                inline void set_time_start(float time_start_) noexcept;
                inline void set_time_end(float time_end_) noexcept;

                //  -- Rendering --
                inline void activate(const Lens& lens_, const Camera& cam_) noexcept;
                inline void render(const Actor& act_) noexcept;
            };



        } // namespace shader
    }     // namespace gui
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/gui/shader/ray.inl>



//  == GUARD END ==
#endif // ARCTK_GUI_SHADER_RAY_HPP
