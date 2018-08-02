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
#include <map>

//  -- Graphical --
#include <GL/glew.h>
#include <GLFW/glfw3.h>



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

            //  == INSTANTIATION ==
          public:
            //  -- Constructors --



            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION ==
        /**
         *  Construct a keybind object using a function and a key status.
         *
         *  @param  func_   Function to bind.
         *  @param  sticky_ Sticky status of the binding.
         *  @param  state_  Current keybind state.
         */
        inline Keybind::Keybind(const std::function<void()>& func_, const bool sticky_, const int state_) noexcept
          : _func(func_)
          , _sticky(sticky_)
          , _state(state_)
        {
        }



        //  == OPERATORS ==
        //  -- Call --
        /**
         *  Call the bound function.
         */
        inline void Keybind::operator()() const noexcept
        {
            _func();
        }



        //  == METHODS ==



    } // namespace gui
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GUI_KEYMAP_HPP
