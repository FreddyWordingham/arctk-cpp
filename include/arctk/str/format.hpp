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
            inline std::string time(unsigned long int sec_) noexcept
            {
                const unsigned long int hr = sec_ / 3600;
                sec_ %= 3600;

                const unsigned long int min = sec_ / 60;
                sec_ %= 60;

                return (std::to_string(hr) + "hr " + std::to_string(min) + "min " + std::to_string(sec_) + "s");
            }



        } // namespace format
    }     // namespace str
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_STR_FORMAT_HPP
