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
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical user interface namespace
    {



        //  == CLASS ==
        /**
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

            //  -- Destructors --
            inline ~Window() noexcept;

          private:
            //  -- Initialisation --
            inline GLFWwindow* init_handle(const std::string& title_, int width_, int height_, int aa_samples_) noexcept;


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        inline Window::Window(const std::string& title_, const int width_, const int height_, const int aa_samples_) noexcept
          : _handle(init_handle(title_, width_, height_, aa_samples_))
        {
        }


        //  -- Destructors --
        inline Window::~Window() noexcept
        {
            glfwTerminate();
        }


        //  -- Initialisation --
        inline GLFWwindow* Window::init_handle(const std::string& title_, const int width_, const int height_, const int aa_samples_) noexcept
        {
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



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_GUI_WINDOW_HPP
