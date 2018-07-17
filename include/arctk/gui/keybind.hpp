/**
 *  @file   arctk/gui/keybind.hpp
 *  @date   17/07/2018
 *  @author Freddy Wordingham
 *
 *  Graphical keybinding class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_KEYBIND_HPP
#define ARCTK_GUI_KEYBIND_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_GUI



//  == IMPORTS ==
//  -- Std --
#include <functional>

//  -- Graphical --
#include <GL/glew.h>
#include <GLFW/glfw3.h>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical user interface namespace
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
            inline void operator()() const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline bool sticky() const noexcept;
            inline int  state() const noexcept;

            //  -- Setters --
            inline void set_state(int state_) noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a keybind object using a function and a key status.
         *
         *  @param  func_   Function to bind.
         *  @param  sticky_ Sticky status of the binding.
         *  @param  state_  Current keybind state.
         */
        inline Keybind::Keybind(const std::function<void()>& func_, bool sticky_, int state_) noexcept
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
        //  -- Getters --
        /**
         *  Get the sticky status of the keybinding.
         *
         *  @return Keybinding sticky status.
         */
        inline bool Keybind::sticky() const noexcept
        {
            return (_sticky);
        }

        /**
         *  Get the current key press status state of the keybinding.
         *
         *  @return Current press status of the keybinding.
         */
        inline int Keybind::state() const noexcept
        {
            return (_state);
        }


        //  -- Setters --
        /**
         *  Set the key press state of the keybinding.
         *
         *  @param  state_  State to set the keybinding to.
         */
        inline void Keybind::set_state(const int state_) noexcept
        {
            _state = state_;
        }



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_KEYBIND_HPP
