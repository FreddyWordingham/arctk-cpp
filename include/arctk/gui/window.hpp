/**
 *  @file   arctk/gui/window.hpp
 *  @date   03/06/2018
 *  @author Freddy Wordingham
 *
 *  Graphical window class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_WINDOW_HPP
#define ARCTK_GUI_WINDOW_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_GUI



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Graphical --
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

//  -- Arctk --
#include <arctk/log.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical user interface namespace
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
            inline Window(const std::string& title_, int width_, int height_, int aa_samples_) noexcept;
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
            inline void set_clear_col(const math::Vec4<float>& col_) noexcept;

            //  -- Rendering --
            inline void clear_buffer() const noexcept;
            inline void swap_buffer() const noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a graphical window object.
         *
         *  @param  title_      Title of window.
         *  @param  width_      Width of window in pixels.
         *  @param  height_     Height of window in pixels.
         *  @param  aa_samples_ Number of anti-aliasing samples.
         *
         *  @pre    title_ must not be empty.
         *  @pre    width_ must be positive.
         *  @pre    height_ must be positive.
         *  @pre    aa_samples_ must be positive.
         */
        inline Window::Window(const std::string& title_, const int width_, const int height_, const int aa_samples_) noexcept
          : _handle(init_handle(title_, width_, height_, aa_samples_))
        {
            assert(!title_.empty());
            assert(width_ > 0);
            assert(height_ > 0);
            assert(aa_samples_ > 0);
        }


        //  -- Destructors --
        /**
         *  Destruct the window object.
         *  Terminate all glfw operations.
         */
        inline Window::~Window() noexcept
        {
            glfwTerminate();
        }


        //  -- Initialisation --
        /**
         *  Initialise a window handle.
         *
         *  @param  title_      Title of window.
         *  @param  width_      Width of window in pixels.
         *  @param  height_     Height of window in pixels.
         *  @param  aa_samples_ Number of anti-aliasing samples.
         *
         *  @pre    title_ must not be empty.
         *  @pre    width_ must be positive.
         *  @pre    height_ must be positive.
         *  @pre    aa_samples_ must be positive.
         *
         *  @return Initialised window handle.
         */
        inline GLFWwindow* Window::init_handle(const std::string& title_, const int width_, const int height_, const int aa_samples_) noexcept
        {
            assert(!title_.empty());
            assert(width_ > 0);
            assert(height_ > 0);
            assert(aa_samples_ > 0);

            if (glfwInit() == 0)
            {
                ERROR(42) << "Unable to construct graphical Window.\n"
                          << "Glfw could not be initialised.";
            }

            glfwWindowHint(GLFW_SAMPLES, aa_samples_);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            GLFWwindow* handle = glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr);

            if (handle == nullptr)
            {
                ERROR(42) << "Unable to construct graphical Window.\n"
                          << "Window pointer could not be created.";
            }

            glfwMakeContextCurrent(handle);
            glewExperimental = GL_TRUE;

            if (glewInit() != GLEW_OK)
            {
                ERROR(42) << "Unable to construct graphical Window.\n"
                          << "Glew could not be initialised.";
            }

            glfwSetInputMode(handle, GLFW_STICKY_KEYS, GL_FALSE);

            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

            glEnable(GL_DEPTH_TEST);
            glDepthFunc(GL_LEQUAL);

            return (handle);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the handle of the window.
         *
         *  @return Window handle.
         */
        inline GLFWwindow* Window::handle() const noexcept
        {
            return (_handle);
        }


        //  -- Setters --
        /**
         *  Set the clear colour of the window.
         *
         *  @param  col_    Colour used to clear the window.
         */
        inline void Window::set_clear_col(const math::Vec4<float>& col_) noexcept
        {
            glClearColor(col_.r, col_.g, col_.b, col_.a);
        }


        //  -- Rendering --
        /**
         *  Clear the window buffer.
         */
        inline void Window::clear_buffer() const noexcept
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // NOLINT
        }

        /**
         *  Swap the window buffer.
         */
        inline void Window::swap_buffer() const noexcept
        {
            glfwSwapBuffers(_handle);
        }



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_WINDOW_HPP
