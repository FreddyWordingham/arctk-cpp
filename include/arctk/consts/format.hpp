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
                ARRAY,
                VECTOR,
                STRING,
                PAIR,
                TUPLE,
                MAP,
                VEC,
                MAT,
                TOTAL
            };



            //  == CONSTANTS ==
            //  -- Bookends --
            constexpr std::array<char, container::TOTAL> OPENERS({{'[', '(', '"', '<', '<', ':', '{', '{'}});
            constexpr std::array<char, container::TOTAL> CLOSERS({{']', ')', '"', '>', '>', ':', '}', '}'}});

            //  -- Special Characters --
            constexpr char                COMMENT = '#';
            constexpr char                DELIM   = ',';
            constexpr std::array<char, 4> WHITESPACE({{' ', '\t', '\r', '\n'}});



        } // namespace format
    }     // namespace consts
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_CONSTS_FORMAT_HPP
