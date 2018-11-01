/**
 *  @file   arctk/gui/keymap.hpp
 *  @date   02/08/2018
 *  @author Freddy Wordingham
 *
 *  Graphical keymapping class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_KEYMAP_HPP
#define ARCTK_GUI_KEYMAP_HPP



//  == IMPORTS ==
//  -- Std --
#include <functional>
#include <map>

//  -- Graphical --
#include <GLFW/glfw3.h>

//  -- Arctk --
#include <arctk/gui/keybind.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {
        class Camera;
        class Window;
    } // namespace gui
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {



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
            inline void bind(int key_, const std::function<void()>& func_, bool sticky_ = false, int state_ = GLFW_RELEASE) noexcept; // NOLINT
            inline void unbind(int key_) noexcept;
            inline void use_fly_controls(Camera* cam_, const float speed_) noexcept;   // NOLINT
            inline void use_orbit_controls(Camera* cam_, const float speed_) noexcept; // NOLINT

            //  -- Operation --
            inline bool poll(const Window& win_) noexcept; // NOLINT
        };



    } // namespace gui
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/gui/keymap.inl>



//  == GUARD END ==
#endif // ARCTK_GUI_KEYMAP_HPP
