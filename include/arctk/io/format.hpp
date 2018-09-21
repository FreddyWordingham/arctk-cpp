/**
 *  @file   arctk/io/format.hpp
 *  @date   21/09/2018
 *  @author Freddy Wordingham
 *
 *  Input/output formatting constants.
 */



//  == GUARD ==
#ifndef ARCTK_IO_FORMAT_HPP
#define ARCTK_IO_FORMAT_HPP



//  == IMPORTS ==
//  -- Std --
#include <cstddef>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace io //! input/output namespace
    {
        namespace format //! formatting namespace
        {



            //  == CONSTANTS ==
            //  -- Bookends --
            constexpr char const* const VEC_START     = "{";
            constexpr char const* const VEC_END       = "}";
            constexpr char const* const MAT_ROW_START = "{";
            constexpr char const* const MAT_ROW_END   = "}";

            //  -- Delimiters --
            constexpr char const* const DELIM = ", ";

            //  -- Widths --
            constexpr const size_t FIELD_WIDTH = 16;



        } // namespace format
    }     // namespace io
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IO_FORMAT_HPP
