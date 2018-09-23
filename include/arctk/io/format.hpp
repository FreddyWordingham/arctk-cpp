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
            constexpr char const* const ARRAY_START  = "[";
            constexpr char const* const ARRAY_END    = "]";
            constexpr char const* const VECTOR_START = "{";
            constexpr char const* const VECTOR_END   = "}";
            constexpr char const* const STRING_START = "\"";
            constexpr char const* const STRING_END   = "\"";

            //  -- Delimiters --
            constexpr char const* const DELIM = ",";



        } // namespace format
    }     // namespace io
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IO_FORMAT_HPP
