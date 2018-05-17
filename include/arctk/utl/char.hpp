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



//  == INCLUDES ==
//  -- Std --
#include <cctype>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace utl //! utility namespace
    {



        //  == SETTINGS ==
        //  -- Whitespace --
        constexpr const char* const WHITESPACE_CHARS(" \f\n\r\t\v"); //!< Characters which are considered whitespace.
        constexpr const char* const GLYPH_CHARS("-_");               //!< Additional characters which are considered glyphs.



        //  == FUNCTION PROTOTYPES ==
        //  -- Properties --
        inline bool whitespace(char ch_) noexcept;
        inline bool glyph(char ch_) noexcept;



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
            for (auto it = WHITESPACE_CHARS; *it != 0; ++it)
            {
                if (ch_ == *it)
                {
                    return (true);
                }
            }

            return (false);
        }

        /**
         *  Determine if the given character is a glyph.
         *
         *  @param  ch_ Character to be tested.
         *
         *  @return True if the given character is considered a glyph.
         */
        inline bool glyph(const char ch_) noexcept
        {
            for (auto it = GLYPH_CHARS; *it != 0; ++it)
            {
                if (ch_ == *it)
                {
                    return (true);
                }
            }

            return (std::isalnum(ch_) != 0);
        }



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_CHAR_HPP
