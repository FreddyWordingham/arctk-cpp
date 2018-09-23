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
            inline void filter_comments(std::string* const str_) noexcept;

            //  -- Parsing --



            //  == FUNCTIONS ==
            //  -- Pre-processing --
            inline void filter_comments(std::string* const str_) noexcept
            {
                for (size_t i = 0; i < str_->size(); ++i)
                {
                    if (str_[i] == format::OPENERS[format::container::STRING])
                    {
                        const size_t string_container_end_pos = str_->find_first_of(format::CLOSERS[format::container::STRING], i + 1);

                        if (string_container_end_pos == std::string::npos)
                        {
                            std::cerr << "Unable to parse string.\n"
                                      << "String contains string opener but does not contain a corresponding closer.\n";

                            std::exit(exit::error::FAILED_PARSE);
                        }

                        i = string_container_end_pos;
                    }
                }
            }


            //  -- Parsing --



        } // namespace str
    }     // namespace io
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IO_READ_HPP
