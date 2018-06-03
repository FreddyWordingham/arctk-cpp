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



        //  == CLASS ==
        /**
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



    } // namespace gui
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_GUI



//  == GUARD END ==
#endif // ARCTK_GUI_KEYMAP_HPP
