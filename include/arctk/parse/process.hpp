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
#include <iostream>
#include <string>
#include <vector>

//  -- Arctk --
#include <arctk/consts/format.hpp>
#include <arctk/exit/error.hpp>



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



            //  == FUNCTIONS ==
            //  -- Filtering --
            /**
             *  Filter the comments from a given string.
             *
             *  @param  str_    String to be filtered.
             *
             *  @pre    str_ may not be nullptr.
             */
            inline void filter_comments(std::string* const str_) noexcept // NOLINT
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                for (size_t i = 0; i < str_ref.size(); ++i)
                {
                    if (str_ref[i] == consts::format::OPENERS[consts::format::container::STRING])
                    {
                        const size_t string_container_end_pos = str_ref.find_first_of(consts::format::CLOSERS[consts::format::container::STRING], i + 1);

                        if (string_container_end_pos == std::string::npos)
                        {
                            std::cerr << "Unable to parse string.\n"
                                      << "String contains string opener but does not contain a corresponding closer.\n";

                            std::exit(exit::error::FAILED_PARSE);
                        }

                        i = string_container_end_pos;
                    }
                    else if (str_ref[i] == consts::format::COMMENT)
                    {
                        size_t j;
                        for (j = i; j < str_ref.size(); ++j)
                        {
                            if (str_ref[j] == consts::format::OPENERS[consts::format::container::STRING])
                            {
                                const size_t string_container_end_pos = str_ref.find_first_of(consts::format::CLOSERS[consts::format::container::STRING], j + 1);

                                if (string_container_end_pos == std::string::npos)
                                {
                                    std::cerr << "Unable to parse string.\n"
                                              << "String contains string opener but does not contain a corresponding closer.\n";

                                    std::exit(exit::error::FAILED_PARSE);
                                }

                                j = string_container_end_pos;
                            }
                            else if (str_ref[j] == '\n')
                            {
                                break;
                            }
                        }

                        str_ref.erase(i, j - i);
                    }
                }
            }

            /**
             *  Filter the whitespace from a given string.
             *
             *  @param  str_    String to be filtered.
             *
             *  @pre    str_ may not be nullptr.
             */
            inline void filter_whitespace(std::string* const str_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                for (size_t i = 0; i < str_ref.size(); ++i)
                {
                    if (str_ref[i] == consts::format::OPENERS[consts::format::container::STRING])
                    {
                        const size_t string_container_end_pos = str_ref.find_first_of(consts::format::CLOSERS[consts::format::container::STRING], i + 1);

                        if (string_container_end_pos == std::string::npos)
                        {
                            std::cerr << "Unable to parse string.\n"
                                      << "String contains string opener but does not contain a corresponding closer.\n";

                            std::exit(exit::error::FAILED_PARSE);
                        }

                        i = string_container_end_pos;
                    }
                    else
                    {
                        for (size_t j = 0; j < consts::format::WHITESPACE.size(); ++j)
                        {
                            if (str_ref[i] == consts::format::WHITESPACE[j])
                            {
                                str_ref.erase(i, 1);
                                --i;

                                break;
                            }
                        }
                    }
                }
            }


            //  -- Extraction --
            /**
             *  Extracted the contents of a string container.
             *
             *  @param  str_    String to be filtered.
             *  @param  type_   Container type contained within the string.
             *
             *  @pre    str_ may not be nullptr.
             */
            inline void extract_contents(std::string* const str_, const consts::format::container type_) noexcept
            {
                assert(str_ != nullptr);

                std::string& str_ref = *str_;

                const size_t open = str_ref.find_first_of(consts::format::OPENERS[type_]);
                if (open == std::string::npos)
                {
                    std::cerr << "Error extracting contents of container.\n"
                              << "Containter opener was not found.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }
                else if (open != 0)
                {
                    std::cerr << "Error extracting contents of container.\n"
                              << "Additional characters found before container opener.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }
                str_ref.erase(open, 1);

                const size_t close = str_ref.find_last_of(consts::format::CLOSERS[type_]);
                if (close == std::string::npos)
                {
                    std::cerr << "Error extracting contents of container.\n"
                              << "Containter closer was not found.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }
                else if (close != (str_ref.size() - 1))
                {
                    std::cerr << "Error extracting contents of container.\n"
                              << "Additional characters found after container closer.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }
                str_ref.erase(close, 1);
            }


            //  -- Tokenization --
            /**
             *  Split a given string into a vector of token strings which are delimited using the set character.
             *
             *  @param  str_    String to be tokenised.
             *
             *  @return Vector of string tokens.
             */
            inline std::vector<std::string> tokenise(const std::string& str_) noexcept
            {
                std::vector<std::string> tokens;

                size_t prev_delim = 0;
                for (size_t i = 0; i < str_.size(); ++i)
                {
                    if (str_[i] == consts::format::DELIM)
                    {
                        tokens.emplace_back(str_.substr(prev_delim, i - prev_delim));
                        prev_delim = i + 1;
                    }
                    else
                    {
                        for (size_t j = 0; j < consts::format::OPENERS.size(); ++j)
                        {
                            if (str_[i] == consts::format::OPENERS[j])
                            {
                                i = str_.find_first_of(consts::format::CLOSERS[j], i + 1);

                                if (i == std::string::npos)
                                {
                                    std::cerr << "Error parsing container.\n"
                                              << "Corresponding container closer was not found.\n";

                                    std::exit(exit::error::FAILED_PARSE);
                                }

                                break;
                            }
                        }
                    }
                }
                tokens.emplace_back(str_.substr(prev_delim, str_.size()));

                return (tokens);
            }



        } // namespace process
    }     // namespace parse
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PARSE_PROCESS_HPP
