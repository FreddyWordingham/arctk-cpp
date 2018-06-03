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
            type _type;    //!< Type handled by the uniform.
            type _control; //!< Object controlling the uniform.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Uniform(GLint handle_, type type_, control control_) noexcept;


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        inline Uniform::Uniform(const GLint handle_, const type type_, const control control_) noexcept
          : _handle(handle_)
          , _type(type_)
          , _control(control_)
        {
        }



        //  == METHODS ==
        //  -- Getters --



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_UNIFORM_HPP
