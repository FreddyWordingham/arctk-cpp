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
        class Keymap
        {
            //  == FIELDS ==
          private:
            //  -- Operation --
            const std::function<void()> _func; //!< Function to call upon keypress.

            //  -- Press --
            const bool _sticky; //!< True if held key causes repeat function calling.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION --
        //  -- Constructors --



        //  == METHODS ==



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_KEYBIND_HPP
