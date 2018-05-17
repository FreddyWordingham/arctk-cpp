/**
 *  @file   char.hpp
 *  @date   17/05/2018
 *  @author Freddy Wordingham
 *
 *  Character utility functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_CHAR_HPP
#define ARCTK_UTL_CHAR_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace utl //! utility namespace
    {



        //  == SETTINGS ==
        //  -- Whitespace --
        constexpr const char* const WHITESPACE_CHARS(" \f\n\r\t\v"); //!< String of characters which are considered whitespace.



        //  == FUNCTION PROTOTYPES ==
        //  -- Properties --
        inline bool whitespace(char ch_) noexcept;



        //  == FUNCTIONS ==
        //  -- Properties --
        /**
         *  Determine if the given character is whitespace.
         *
         *  @param  ch_ Character to be tested.
         *
         *  @return True if the given character is considered whitespace.
         */
        inline bool whitespace(const char ch_) noexcept
        {
            for (auto it = WHITESPACE_CHARS; *it; ++it)
            {
                if (ch_ == *it)
                {
                    return (true);
                }
            }

            return (false);
        }



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_CHAR_HPP
