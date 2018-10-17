/**
 *  @file   arctk/consts/format.hpp
 *  @date   25/09/2018
 *  @author Freddy Wordingham
 *
 *  Formatting constants.
 */



//  == GUARD ==
#ifndef ARCTK_CONSTS_FORMAT_HPP
#define ARCTK_CONSTS_FORMAT_HPP



//  == PRAGMAS ==
#if defined(__clang__)

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"

#endif



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cstddef>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace consts //! constants namespace
    {
        namespace format //! formatting namespace
        {



            //  == ENUMERATIONS ==
            //  -- Container Types --
            /**
             *  Enumeration of container types with specified opener and closer characters.
             */
            enum container
            {
                ARRAY,  //!< Array.
                VECTOR, //!< Vector.
                STRING, //!< String.
                PAIR,   //!< Pair.
                TUPLE,  //!< Tuple.
                MAP,    //!< Map.
                VEC,    //!< Vec.
                MAT,    //!< Mat.
                TOTAL   //!< Total number of container types.
            };



            //  == CONSTANTS ==
            //  -- Bookends --
            constexpr const std::array<char, container::TOTAL> OPENERS({{'[', '(', '"', '<', '<', ':', '{', '{'}}); //!< Container opening characters. @return Container opening characters.
            constexpr const std::array<char, container::TOTAL> CLOSERS({{']', ')', '"', '>', '>', ':', '}', '}'}}); //!< Container closing characters. @return Container closing characters.

            //  -- Special Characters --
            constexpr const char                COMMENT = '#';                         //!< Default comment starting character.
            constexpr const char                DELIM   = ',';                         //!< Default delimiter character.
            constexpr const std::array<char, 4> WHITESPACE({{' ', '\t', '\r', '\n'}}); //!< Characters considered whitespace. @return Whitespace character array.



        } // namespace format
    }     // namespace consts
} // namespace arc



//  == PRAGMAS ==
#if defined(__clang__)

#pragma GCC diagnostic pop

#endif



//  == GUARD END ==
#endif // ARCTK_CONSTS_FORMAT_HPP
