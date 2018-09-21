/**
 *  @file   arctk/write/format.hpp
 *  @date   21/09/2018
 *  @author Freddy Wordingham
 *
 *  Writing formatting constants.
 */



//  == GUARD ==
#ifndef ARCTK_WRITING_FORMAT_HPP
#define ARCTK_WRITING_FORMAT_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace write //! writing namespace
    {
        namespace format //! formatting namespace
        {



            //  == CONSTANTS ==
            //  -- Bookends --
            constexpr const char const* VEC_START = "{";
            constexpr const char const* VEC_END   = "}";

            //  -- Delimiters --
            constexpr const char const* DELIM = ", ";

            //  -- Widths --
            constexpr const size_t FIELD_WIDTH = 16;



        } // namespace format
    }     // namespace write
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_WRITING_FORMAT_HPP
