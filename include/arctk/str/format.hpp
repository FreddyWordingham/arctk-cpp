/**
 *  @file   arctk/str/format.hpp
 *  @date   24/08/2018
 *  @author Freddy Wordingham
 *
 *  Collection of string formatting functions.
 */



//  == GUARD ==
#ifndef ARCTK_STR_FORMAT_HPP
#define ARCTK_STR_FORMAT_HPP



//  == IMPORTS ==
//  -- Std --
#include <string>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace str //! string namespace
    {
        namespace format //! formatting namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Time --
            inline std::string time(long int sec_) noexcept;
            inline std::string bar(unsigned int length_, double frac_) noexcept;



            //  == FUNCTIONS ==
            //  -- Time --
            /**
             *  Format a given number of seconds into a hr:min:sec string.
             *
             *  @param  sec_    Total number of seconds.
             *
             *  @return Formatted time string.
             */
            inline std::string time(long int sec_) noexcept
            {
                const bool negative = sec_ < 0;
                if (negative)
                {
                    sec_ *= -1;
                }

                const long int hr = sec_ / 3600;
                sec_ %= 3600;

                const long int min = sec_ / 60;
                sec_ %= 60;

                return ((negative ? std::string("-") : std::string(" ")) + ((hr < 10) ? "0" : "") + std::to_string(hr) + ((min < 10) ? ":0" : ":") + std::to_string(min) + ((sec_ < 10) ? ":0" : ":") + std::to_string(sec_));
            }

            inline std::string bar(const unsigned int length_, const double frac_) noexcept
            {
                PRE(length_ >= 12);
                std::string bar(length_, ' ');
                bar.front() = '[';
                bar.back()  = ']';

                return (bar);
            }



        } // namespace format
    }     // namespace str
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_STR_FORMAT_HPP
