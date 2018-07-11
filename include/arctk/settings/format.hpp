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
            constexpr const int PRINT_WIDTH = 10; //!< Width allocated to data prints.

            //  -- Limiters --
            constexpr const char DELIMITER       = ','; //!< Character used to delimit consecutive data.
            constexpr const char CONTAINER_START = '['; //!< Character used to indicate container end point.
            constexpr const char CONTAINER_END   = ']'; //!< Character used to indicate container start point.
            constexpr const char TUPLE_START     = '('; //!< Character used to indicate tuple end point.
            constexpr const char TUPLE_END       = ')'; //!< Character used to indicate tuple start point.



        } // namespace format
    }     // namespace settings
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SETTINGS_FORMAT_HPP
