/**
 *  @file   arctk/gui/window.hpp
 *  @date   03/08/2018
 *  @author Freddy Wordingham
 *
 *  Graphical window class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_WINDOW_HPP
#define ARCTK_GUI_WINDOW_HPP



//  == IMPORTS ==
//  -- Std --
#include <string>

//  -- Graphical --
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {



        //  == CLASS ==
        /**
         *  Graphical window rendering class.
         */
        class Window
        {
            //  == FIELDS ==
          private:
            //  -- Handle --
            GLFWwindow* _handle; //!< Handle to the graphical window.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Window(const std::string& title_, int width_, int height_, int aa_samples_ = 4) noexcept;
            inline Window(const Window&) noexcept = default; //!< Defaulted copy constructor.
            inline Window(Window&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            inline ~Window() noexcept;

          private:
            //  -- Initialisation --
            inline GLFWwindow* init_handle(const std::string& title_, int width_, int height_, int aa_samples_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Window& operator=(const Window&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Window& operator=(Window&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline GLFWwindow* handle() const noexcept;

            //  -- Setters --
            inline void set_clear_col(const glm::vec3& col_) noexcept;
            inline void set_clear_col(const glm::vec4& col_) noexcept;

            //  -- Rendering --
            inline void clear_buffer() const noexcept;
            inline void swap_buffer() const noexcept;
        };



    } // namespace gui
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/gui/window.inl>



//  == GUARD END ==
#endif // ARCTK_GUI_WINDOW_HPP
