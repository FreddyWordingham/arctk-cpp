/**
 *  @file   arctk/io/str.hpp
 *  @date   21/09/2018
 *  @author Freddy Wordingham
 *
 *  String input/output functions.
 */



//  == GUARD ==
#ifndef ARCTK_IO_READ_HPP
#define ARCTK_IO_READ_HPP



//  == IMPORTS ==
//  -- Std --
#include <string>
#include <vector>

//  -- Arctk --
#include <arctk/exit.hpp>
#include <arctk/io/format.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace io //! input/output namespace
    {
        namespace str //! string namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Pre-processing --
            inline void                     filter_comments(std::string* const str_) noexcept;
            inline void                     filter_whitespace(std::string* const str_) noexcept;
            inline void                     extract_contents(std::string* const str_, const format::container type_) noexcept;
            inline std::vector<std::string> tokenise(const std::string& str_) noexcept;

            //  -- Parsing --



            //  == FUNCTIONS ==
            //  -- Pre-processing --
            inline void filter_comments(std::string* const str_) noexcept
            {
                std::string& str_ref = *str_;

                for (size_t i = 0; i < str_ref.size(); ++i)
                {
                    if (str_ref[i] == format::OPENERS[format::container::STRING])
                    {
                        const size_t string_container_end_pos = str_ref.find_first_of(format::CLOSERS[format::container::STRING], i + 1);

                        if (string_container_end_pos == std::string::npos)
                        {
                            std::cerr << "Unable to parse string.\n"
                                      << "String contains string opener but does not contain a corresponding closer.\n";

                            std::exit(exit::error::FAILED_PARSE);
                        }

                        i = string_container_end_pos;
                    }
                    else if (str_ref[i] == format::COMMENT)
                    {
                        size_t j;
                        for (j = i; j < str_ref.size(); ++j)
                        {
                            if (str_ref[j] == format::OPENERS[format::container::STRING])
                            {
                                const size_t string_container_end_pos = str_ref.find_first_of(format::CLOSERS[format::container::STRING], j + 1);

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

            inline void filter_whitespace(std::string* const str_) noexcept
            {
                std::string& str_ref = *str_;

                for (size_t i = 0; i < str_ref.size(); ++i)
                {
                    if (str_ref[i] == format::OPENERS[format::container::STRING])
                    {
                        const size_t string_container_end_pos = str_ref.find_first_of(format::CLOSERS[format::container::STRING], i + 1);

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
                        for (size_t j = 0; j < format::WHITESPACE.size(); ++j)
                        {
                            if (str_ref[i] == format::WHITESPACE[j])
                            {
                                str_ref.erase(i, 1);
                                --i;

                                break;
                            }
                        }
                    }
                }
            }

            inline void extract_contents(std::string* const str_, const format::container type_) noexcept
            {
                std::string& str_ref = *str_;

                const size_t open = str_ref.find_first_of(format::OPENERS[type_]);
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

                const size_t close = str_ref.find_last_of(format::CLOSERS[type_]);
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

            inline std::vector<std::string> tokenise(const std::string& str_) noexcept
            {
                std::vector<std::string> tokens;

                size_t prev_delim = 0;
                for (size_t i = 0; i < str_.size(); ++i)
                {
                    if (str_[i] == format::DELIM)
                    {
                        tokens.emplace_back(str_.substr(prev_delim, i - prev_delim));
                        prev_delim = i + 1;
                    }
                    else
                    {
                        for (size_t j = 0; j < format::OPENERS.size(); ++j)
                        {
                            if (str_[i] == format::OPENERS[j])
                            {
                                i = str_.find_first_of(format::CLOSERS[j], i + 1);

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
                tokens.emplace_back(str_.substr(prev_delim, str_.size() - 1));

                return (tokens);
            }


            //  -- Parsing --



        } // namespace str
    }     // namespace io
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IO_READ_HPP
