/**
 *  @file   arctk/write/format.hpp
 *  @date   21/09/2018
 *  @author Freddy Wordingham
 *
 *  Writing formatting constants.
 */



//  == GUARD ==
#ifndef ARCTK_WRITE_FORMAT_HPP
#define ARCTK_WRITE_FORMAT_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace write //! writing namespace
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
    }     // namespace write
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_WRITE_FORMAT_HPP
