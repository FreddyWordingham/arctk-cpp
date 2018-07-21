/**
 *  @file   arctk/gui/uniform.hpp
 *  @date   20/07/2018
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
#include <typeid>
#include <typeinfo>

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
            //  == FIELDS ==
          private:
            //  -- Handle --
            const GLint _handle; //!< Uniform handle.

            //  -- Info --
            const size_t _type_hash; //!< Handled type hash.


            //  == INSTANTIATION ==
          public:
            //  -- Factories --
            template <typename T>
            static inline create(const GLint handle_) noexcept;

          private:
            //  -- Constructors --
            inline Uniform(const GLint handle_, const size_t type_hash_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const GLint  handle() noexcept;
            inline const size_t type_hash() noexcept;
        };



        //  == INSTANTIATION --
        //  -- Factories --
        /**
         *  Create a shader uniform object using an existing handle.
         *  Type hash number is created.
         *
         *  @tparam T   Type handled by the shader uniform.
         *
         *  @param  handle_ Pre-initialised shader uniform handle.
         *
         *  @return Uniform to handle given shader uniform handle.
         */
        template <typename T>
        static inline create(const GLint handle_) noexcept
        {
            PRE(handle_ >= 0);

            return (handle_, typeid(T).hash_code());
        }


        //  -- Constructors --
        /**
         *  Construct a shader uniform using an existing handle and type hash number.
         *
         *  @param  handle_     Pre-initialised shader uniform handle.
         *  @param  type_hash_  Type hash number.
         *
         *  @pre    handle_ must be non-negative.
         */
        inline Uniform::Uniform(const GLint handle_, const size_t type_hash_) noexcept
          : _handle(handle_)
          , _type_hash(type_hash_)
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
        inline const GLint Uniform::handle() noexcept
        {
            return (_handle);
        }

        /**
         *  Get the uniform type hash.
         *
         *  @return Uniform type hash.
         */
        inline const size_t Uniform::type_hash() noexcept
        {
            return (_type_hash);
        }



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_UNIFORM_HPP
