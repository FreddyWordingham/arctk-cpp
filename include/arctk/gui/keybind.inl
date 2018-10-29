/**
 *  @file   arctk/gui/keybind.inl
 *  @date   02/08/2018
 *  @author Freddy Wordingham
 *
 *  Graphical keybinding class.
 */



//  == GUARD ==
#ifndef ARCTK_GUI_KEYBIND_INL
#define ARCTK_GUI_KEYBIND_INL



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace gui //! graphical-user-interface namespace
    {



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
        inline void Keybind::operator()() const noexcept // NOLINT
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



//  == GUARD END ==
#endif // ARCTK_GUI_KEYBIND_INL
