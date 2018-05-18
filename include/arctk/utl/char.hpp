/**
 *  @file   arctk/utl/char.hpp
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
        constexpr const char* const WHITESPACE_CHARS{" \f\n\r\t\v"}; //!< Characters which are considered whitespace.
        constexpr const char* const GLYPH_CHARS{
          "-_0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"}; //!< Characters which are considered glyphs.



        //  == FUNCTION PROTOTYPES ==
        //  -- Properties --
        inline bool numerical(char ch_) noexcept;
        inline bool whitespace(char ch_) noexcept;
        inline bool glyph(char ch_) noexcept;



        //  == FUNCTIONS ==
        //  -- Properties --
        /**
         *  Determine if the given character is numerical.
         *
         *  @param  ch_ Character to be tested.
         *
         *  @return True if the given character is numerical.
         */
        inline bool numerical(const char ch_) noexcept
        {
            return ((ch_ >= '0') && (ch_ <= '9'));
        }

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
                if ((ch_ == *it) && !numerical(ch_))
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
