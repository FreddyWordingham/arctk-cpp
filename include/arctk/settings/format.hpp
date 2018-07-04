/**
 *  @file   arctk/settings/format.hpp
 *  @date   04/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection of formatting settings.
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
        namespace format //! format namespace
        {



            //  == CONSTANTS ==
            //  -- Files --
            constexpr const char DELIMITER   = ','; //!< Character used to delimit consecutive data.
            constexpr const int  PRINT_WIDTH = 16;  //!< Width allocated to data prints.



        } // namespace format
    }     // namespace settings
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SETTINGS_FORMAT_HPP
