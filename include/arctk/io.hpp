/**
 *  @file   arctk/io.hpp
 *  @date   21/09/2018
 *  @author Freddy Wordingham
 *
 *  Collection of input/output operators and functions.
 */



//  == GUARD ==
#ifndef ARCTK_IO_HPP
#define ARCTK_IO_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cassert>
#include <fstream>
#include <ostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/consts.hpp>
#include <arctk/io/file.hpp>
#include <arctk/io/input.hpp>
#include <arctk/io/output.hpp>
#include <arctk/type/tag.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace io //! input/output namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Parsing --
        template <typename T>
        inline T parse(std::string* str_) noexcept;



        //  == FUNCTIONS ==
        //  -- Parsing --
        /**
         *  Parse a given string of characters into a given type.
         *
         *  @tparam T   Type to be parsed into.
         *
         *  @param  str_    String to be parsed.
         *
         *  @pre    str_ may not be nullptr.
         *
         *  @return Parsed type.
         */
        template <typename T>
        inline T parse(std::string* const str_) noexcept
        {
            assert(str_ != nullptr);

            input::filter_comments(str_);
            input::filter_whitespace(str_);

            return (input::parse(type::Tag<T>(), str_));
        }



    } // namespace io
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IO_HPP
