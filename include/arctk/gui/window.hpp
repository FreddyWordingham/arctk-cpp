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
//  -- Graphical --



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


            //  == METHODS ==
          public:
            //  -- Getters --
            inline GLFWwindow* handle() const noexcept;
        };



        //  == INSTANTIATION ==



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



    } // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_WINDOW_HPP
