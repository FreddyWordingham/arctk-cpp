/**
 *  @file   arctk/gui/window.inl
 *  @date   03/08/2018
 *  @author Freddy Wordingham
 *
 *  Graphical window class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_WINDOW_INL
#define ARCTK_GUI_WINDOW_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cstdlib>
#include <iostream>

//  -- Arctk --
#include <arctk/exit/error.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a graphical window object.
         *
         *  @param  title_      Title of window.
         *  @param  width_      Width of window in pixels.
         *  @param  height_     Height of window in pixels.
         *  @param  aa_samples_ Number of anti-aliasing samples.
         *
         *  @pre    title_ may not be empty.
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
                std::cerr << "Unable to construct graphical Window.\n"
                          << "Glfw could not be initialised.\n";

                std::exit(exit::error::GLFW_INIT_FAILED);
            }

            glfwWindowHint(GLFW_SAMPLES, aa_samples_);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            GLFWwindow* handle = glfwCreateWindow(width_, height_, title_.c_str(), nullptr, nullptr);

            if (handle == nullptr)
            {
                std::cerr << "Unable to construct graphical Window.\n"
                          << "Window pointer could not be created.\n";

                std::exit(exit::error::WINDOW_POINTER_INIT_FAILED);
            }

            glfwMakeContextCurrent(handle);
            glewExperimental = GL_TRUE;

            if (glewInit() != GLEW_OK)
            {
                std::cerr << "Unable to construct graphical Window.\n"
                          << "Glew could not be initialised.\n";

                std::exit(exit::error::GLEW_INIT_FAILED);
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
         *  Alpha value will be set to unity.
         *
         *  @param  col_    Colour used to clear the window.
         *
         *  @pre    col_.r must be non-negative.
         *  @pre    col_.r must be less than, or equal to, unity.
         *  @pre    col_.g must be non-negative.
         *  @pre    col_.g must be less than, or equal to, unity.
         *  @pre    col_.b must be non-negative.
         *  @pre    col_.b must be less than, or equal to, unity.
         */
        inline void Window::set_clear_col(const glm::vec3& col_) noexcept
        {
            assert(col_.r >= 0.0f);
            assert(col_.r <= 1.0f);
            assert(col_.g >= 0.0f);
            assert(col_.g <= 1.0f);
            assert(col_.b >= 0.0f);
            assert(col_.b <= 1.0f);

            glClearColor(col_.r, col_.g, col_.b, 1.0f);
        }

        /**
         *  Set the clear colour of the window.
         *
         *  @param  col_    Colour used to clear the window.
         *
         *  @pre    col_.r must be non-negative.
         *  @pre    col_.r must be less than, or equal to, unity.
         *  @pre    col_.g must be non-negative.
         *  @pre    col_.g must be less than, or equal to, unity.
         *  @pre    col_.b must be non-negative.
         *  @pre    col_.b must be less than, or equal to, unity.
         *  @pre    col_.a must be non-negative.
         *  @pre    col_.a must be less than, or equal to, unity.
         */
        inline void Window::set_clear_col(const glm::vec4& col_) noexcept
        {
            assert(col_.r >= 0.0f);
            assert(col_.r <= 1.0f);
            assert(col_.g >= 0.0f);
            assert(col_.g <= 1.0f);
            assert(col_.b >= 0.0f);
            assert(col_.b <= 1.0f);
            assert(col_.a >= 0.0f);
            assert(col_.a <= 1.0f);


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



//  == GUARD END ==
#endif // ARCTK_GUI_WINDOW_INL
