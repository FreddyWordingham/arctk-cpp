/**
 *  @file   arctk/parse/write.hpp
 *  @date   21/10/2018
 *  @author Freddy Wordingham
 *
 *  Write parsing functions.
 */



//  == GUARD ==
#ifndef ARCTK_PARSE_WRITE_HPP
#define ARCTK_PARSE_WRITE_HPP



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cstddef>
#include <string>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace parse //! parsing namespace
    {
        namespace write //! writing namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Format --
            inline std::string timestamp(long int sec_) noexcept;
            inline std::string bar(unsigned int length_, double frac_, char fill_ = '|') noexcept;



            //  == FUNCTIONS ==
            /**
             *  Format a given number of seconds into a hr:min:sec string.
             *
             *  @param  sec_    Total number of seconds.
             *
             *  @return Formatted time string.
             */
            inline std::string timestamp(long int sec_) noexcept
            {
                const bool negative = sec_ < 0;
                if (negative)
                {
                    sec_ = -sec_;
                }

                const long int hr = sec_ / 3600;
                sec_ %= 3600;

                const long int min = sec_ / 60;
                sec_ %= 60;

                return ((negative ? std::string("-") : std::string("")) + ((hr < 10) ? "0" : "") + std::to_string(hr) + ((min < 10) ? ":0" : ":") + std::to_string(min) + ((sec_ < 10) ? ":0" : ":") + std::to_string(sec_));
            }

            /**
             *  Format the given fraction into a progress bar of a given length using the fill character.
             *
             *  @param  length_ Length of the progress bar.
             *  @param  frac_   Fraction of the bar to fill.
             *  @param  fill_   Character used to fill the bar.
             *
             *  @pre    frac_ must be non-negative.
             *  @pre    frac_ must be less than, or equal to, unity.
             *
             *  @return Formatted bar string.
             */
            inline std::string bar(const unsigned int length_, const double frac_, const char fill_) noexcept
            {
                assert(frac_ >= 0.0);
                assert(frac_ <= 1.0);

                std::string bar(length_, ' ');

                const auto ticks = static_cast<size_t>(length_ * frac_);
                for (size_t i = 0; i < ticks; ++i)
                {
                    bar[i] = fill_;
                }

                return (bar);
            }



        } // namespace write
    }     // namespace parse
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PARSE_WRITE_HPP
