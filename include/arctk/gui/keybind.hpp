/**
 *  @file   arctk/gui/keybind.hpp
 *  @date   02/08/2018
 *  @author Freddy Wordingham
 *
 *  Graphical keybinding class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_KEYBIND_HPP
#define ARCTK_GUI_KEYBIND_HPP



//  == IMPORTS ==
//  -- Std --
#include <functional>

//  -- Graphical --
#include <GLFW/glfw3.h>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {



        //  == CLASS ==
        /**
         *  Keybinding class mapping a key to a function call.
         */
        class Keybind
        {
            //  == FIELDS ==
          private:
            //  -- Operation --
            const std::function<void()> _func; //!< Function to call upon keypress.

            //  -- Press --
            const bool _sticky; //!< True if held key causes repeat function calling.
            int        _state;  //!< Current press state of key.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Keybind(const std::function<void()>& func_, bool sticky_ = false, int state_ = GLFW_RELEASE) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Call --
            inline void operator()() const noexcept; // NOLINT


            //  == METHODS ==
          public:
            //  -- Getters --
            inline bool sticky() const noexcept;
            inline int  state() const noexcept;

            //  -- Setters --
            inline void set_state(int state_) noexcept;
        };



    } // namespace gui
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/gui/keybind.inl>



//  == GUARD END ==
#endif // ARCTK_GUI_KEYBIND_HPP
