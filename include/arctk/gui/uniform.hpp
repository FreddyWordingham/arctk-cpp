/**
 *  @file   arctk/gui/uniform.hpp
 *  @date   04/06/2018
 *  @author Freddy Wordingham
 *
 *  Shader uniform class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_UNIFORM_HPP
#define ARCTK_GUI_UNIFORM_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_GUI



//  == IMPORTS ==
//  -- Graphical --
#include <GL/glew.h>
#include <GLFW/glfw3.h>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical user interface namespace
    {



        //  == CLASS ==
        /**
         *  Shader uniform object.
         */
        class Uniform
        {
            //  == ENUMERATION ==
          public:
            //  -- Type --
            /**
             *  Enumeration of possible types to be handled by the uniform.
             */
            enum class type
            {
                INT,
                FLOAT,
                VEC2,
                VEC3,
                VEC4,
                MAT2,
                MAT3,
                MAT4
            };

            //  -- Controller --
            /**
             *  Enumeration of possible handlers of the uniform.
             */
            enum class control
            {
                CAMERA,
                ACTOR,
                USER
            };


            //  == FIELDS ==
          private:
            //  -- Handle --
            const GLint _handle; //!< Uniform handle.

            //  -- Information --
            type    _type;    //!< Type handled by the uniform.
            control _control; //!< Object controlling the uniform.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Uniform(GLint handle_, type type_, control control_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline GLint   handle() const noexcept;
            inline control control() const noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct an object to handle a shader uniform of a type to be controlled by agiven type.
         *
         *  @param  handle_     Uniform handle.
         *  @param  type_       Type to be controlled by uniform.
         *  @param  control_    Handler of uniform.
         *
         *  @pre    handle_ must be positive.
         */
        inline Uniform::Uniform(const GLint handle_, const type type_, const control control_) noexcept
          : _handle(handle_)
          , _type(type_)
          , _control(control_)
        {
            assert(handle_ > 0);
        }



        //  == METHODS ==
        //  -- Getters --
        inline GLint Uniform::handle() const noexcept
        {
            return (_handle);
        }

        inline control Uniform::control() const noexcept
        {
            return (_control);
        }



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_UNIFORM_HPP
