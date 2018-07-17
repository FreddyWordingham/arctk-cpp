/**
 *  @file   arctk/gui/uniform.hpp
 *  @date   17/07/2018
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
//  -- Std --
#include <cassert>

//  -- Graphical --
#include <GL/glew.h>
#include <GLFW/glfw3.h>

//  -- Arctk --
#include <arctk/debug.hpp>



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
            enum class stored
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
            enum class controller
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
            stored     _type;    //!< Type handled by the uniform.
            controller _control; //!< Object controlling the uniform.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Uniform(GLint handle_, stored type_, controller control_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline GLint      handle() const noexcept;
            inline stored     type() const noexcept;
            inline controller control() const noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct an object to handle a shader uniform of a type to be controlled by a given type.
         *
         *  @param  handle_     Uniform handle.
         *  @param  type_       Type to be controlled by uniform.
         *  @param  control_    Handler of uniform.
         *
         *  @pre    handle_ must be non-negative.
         */
        inline Uniform::Uniform(const GLint handle_, const stored type_, const controller control_) noexcept
          : _handle(handle_)
          , _type(type_)
          , _control(control_)
        {
            PRE(handle_ >= 0);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the uniform handle.
         *
         *  @return Uniform handle.
         */
        inline GLint Uniform::handle() const noexcept
        {
            return (_handle);
        }

        /**
         *  Get the uniform stored type.
         *
         *  @return Uniform stored type.
         */
        inline Uniform::stored Uniform::type() const noexcept
        {
            return (_type);
        }

        /**
         *  Get the uniform control type.
         *
         *  @return Uniform control type.
         */
        inline Uniform::controller Uniform::control() const noexcept
        {
            return (_control);
        }



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_UNIFORM_HPP
