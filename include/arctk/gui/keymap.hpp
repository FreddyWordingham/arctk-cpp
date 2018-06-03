/**
 *  @file   arctk/gui/keymap.hpp
 *  @date   03/06/2018
 *  @author Freddy Wordingham
 *
 *  Graphical key mapping class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_KEYMAP_HPP
#define ARCTK_GUI_KEYMAP_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_GUI



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/gui/window.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical user interface namespace
    {



        //  == CONSTANTS ==
        //  -- Keys --
        constexpr const int QUIT_KEY = GLFW_KEY_ESCAPE; //!< Key used to close open window.



        //  == CLASS ==
        /**
         *  Keymap class providing function bindings to keypresses.
         */
        class Keymap
        {
            //  == FIELDS ==
          private:
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
            //  -- Operation --
            inline bool poll(const Window& win_) noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --



        //  == METHODS ==
        //  -- Getters --

        //  -- Operation --
        /**
         *  Poll through key press events from the given window and call corresponding functions.
         *  Determine if the given window should remain open.
         *
         *  @param  win_    Window to poll events from.
         *
         *  @return True if the window should remain open.
         */
        inline bool Keymap::poll(const Window& win_) noexcept
        {
            glfwPollEvents();

            if ((glfwGetKey(win_.handle(), QUIT_KEY) == GL_TRUE) || (glfwWindowShouldClose(win_.handle()) == GL_TRUE))
            {
                return (false);
            }
            /*
                        for (auto& [key, keybind] : _map)
                        {
                            const int state = glfwGetKey(win_.handle(), key);

                            if (state == GLFW_PRESS)
                            {
                                if (keybind._sticky || (keybind._state == GLFW_RELEASE))
                                {
                                    keybind._func();
                                }
                            }

                            keybind._state = state;
                        }
            */
            return (true);
        }



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_KEYMAP_HPP
