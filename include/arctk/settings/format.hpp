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
            constexpr const char DELIMITER    = ','; //!< Character used to delimit consecutive data.
            constexpr const char ARRAY_START  = '['; //!< Character used to indicate array end point.
            constexpr const char ARRAY_END    = ']'; //!< Character used to indicate array start point.
            constexpr const char MAP_START    = '<'; //!< Character used to indicate map end point.
            constexpr const char MAP_END      = '>'; //!< Character used to indicate map start point.
            constexpr const char PAIR_START   = '(';
            constexpr const char PAIR_END     = ')';
            constexpr const char TUPLE_START  = '(';
            constexpr const char TUPLE_END    = ')';
            constexpr const char VECTOR_START = '{';
            constexpr const char VECTOR_END   = '}';



        } // namespace format
    }     // namespace settings
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SETTINGS_FORMAT_HPP
