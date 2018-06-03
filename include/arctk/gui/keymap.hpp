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
//  -- Std --
#include <map>

//  -- Graphical --
#include <GL/glew.h>
#include <GLFW/glfw3.h>

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
            //  -- Mapping --
            std::map<int, Keybind> _map; //!< Map of keybindings.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Keymap() noexcept = default;


            //  == METHODS ==
          public:
            //  -- Setters --
            inline void bind(int key_, const std::function<void()>& func_, bool sticky_ = false, int state_ = GLFW_RELEASE) noexcept;
            inline void unbind(int key_) noexcept;

            //  -- Operation --
            inline bool poll(const Window& win_) noexcept;
        };



        //  == METHODS ==
        //  -- Setters --
        /**
         *  Bind a new keybinding to the keymap.
         *
         *  @param  key_    Key to bind to.
         *  @param  func_   Function to bind.
         *  @param  sticky_ Sticky status of the keybinding.
         *  @param  state_  Initial state of the keybinding.
         */
        inline void Keymap::bind(int key_, const std::function<void()>& func_, const bool sticky_, const int state_) noexcept
        {
            assert(key_ != QUIT_KEY);

            _map.emplace(std::make_pair(key_, Keybind(func_, sticky_, state_)));
        }

        inline void Keymap::unbind(const int key_) noexcept
        {
            assert(key_ != QUIT_KEY);
            assert(_map.find(key_) != _map.end());

            _map.erase(key_);
        }


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

            for (auto& [key, keybind] : _map)
            {
                const int state = glfwGetKey(win_.handle(), key);

                if (state == GLFW_PRESS)
                {
                    if (keybind.sticky() || (keybind.state() == GLFW_RELEASE))
                    {
                        keybind();
                    }
                }

                keybind.set_state(state);
            }

            return (true);
        }



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_KEYMAP_HPP
