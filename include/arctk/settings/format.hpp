/**
 *  @file   arctk/settings/format.hpp
 *  @date   27/06/2018
 *  @author Freddy Wordingham
 *
 *  Formatting settings.
 */



//  == GUARD ==
#ifndef ARCTK_SETTINGS_FORMAT_HPP
#define ARCTK_SETTINGS_FORMAT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace settings //! settings namespace
    {



        //  == CONSTANTS ==
        //  -- Formatting --
        constexpr const char DEFAULT_DELIM       = ','; //!< Default character used to delimit printed values.
        constexpr const char DEFAULT_PRINT_WIDTH = 16;  //!< Default width allocated to each value print.



    } // namespace settings
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SETTINGS_FORMAT_HPP
