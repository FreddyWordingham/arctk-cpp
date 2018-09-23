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



            //  == ENUMERATIONS ==
            //  -- Container Types --
            enum container
            {
                ARRAY,
                VECTOR,
                STRING,
                VEC,
                MAT,
                TOTAL
            };



            //  == CONSTANTS ==
            //  -- Bookends --
            constexpr std::array<char, container::TOTAL> OPENERS({{'[', '(', '"', '{', '{'}});
            constexpr std::array<char, container::TOTAL> CLOSERS({{']', ')', '"', '}', '}'}});


            //  -- Delimiters --
            constexpr char DELIM = ',';



        } // namespace format
    }     // namespace io
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IO_FORMAT_HPP
