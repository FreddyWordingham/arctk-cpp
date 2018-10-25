/**
 *  @file   arctk/parse/process.hpp
 *  @date   22/10/2018
 *  @author Freddy Wordingham
 *
 *  Pre-processing parsing functions.
 */



//  == GUARD ==
#ifndef ARCTK_PARSE_PROCESS_HPP
#define ARCTK_PARSE_PROCESS_HPP



//  == IMPORTS ==
//  -- Std --
#include <string>
#include <vector>

//  -- Arctk --
#include <arctk/consts/format.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace parse //! parsing namespace
    {
        namespace process //! processing namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Filtering --
            inline void filter_comments(std::string* str_) noexcept;
            inline void filter_whitespace(std::string* str_) noexcept;

            //  -- Extraction --
            inline void extract_contents(std::string* str_, consts::format::container type_) noexcept;

            //  -- Tokenization --
            inline std::vector<std::string> tokenise(const std::string& str_) noexcept;



        } // namespace process
    }     // namespace parse
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/parse/process.inl>



//  == GUARD END ==
#endif // ARCTK_PARSE_PROCESS_HPP
