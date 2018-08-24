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
            inline std::string time(unsigned long int sec_) noexcept;



            //  == FUNCTIONS ==
            //  -- Time --
            /**
             *  Format a given number of seconds into a hr:min:sec string.
             *
             *  @param  sec_    Total number of seconds.
             *
             *  @return Formatted time string.
             */
            inline std::string time(unsigned long int sec_) noexcept
            {
                const unsigned long int hr = sec_ / 3600;
                sec_ %= 3600;

                const unsigned long int min = sec_ / 60;
                sec_ %= 60;

                return (((hr < 10) ? "0" : "") + std::to_string(hr) + ((min < 10) ? ":0" : ":") + std::to_string(min) + ((sec_ < 10) ? ":0" : ":") + std::to_string(sec_));
            }



        } // namespace format
    }     // namespace str
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_STR_FORMAT_HPP
