/**
 *  @file   arctk/gui/keybind.hpp
 *  @date   03/06/2018
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


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        inline explicit Keybind::Keybind(const std::function<void()>& func_, bool sticky_, int state_) noexcept
          : _func(func_)
          , _sticky(sticky_)
          , _state(state_)
        {
        }



        //  == METHODS ==



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_KEYBIND_HPP
