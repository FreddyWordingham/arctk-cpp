/**
 *  @file   arctk/read/string.hpp
 *  @date   21/09/2018
 *  @author Freddy Wordingham
 *
 *  String reading functions.
 */



//  == GUARD ==
#ifndef ARCTK_READ_STRING_HPP
#define ARCTK_READ_STRING_HPP



//  == IMPORTS ==
//  -- Std --
#include <sstream>
#include <string>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/exit.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace read //! reading namespace
    {
        namespace string //! string namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Primitive --
            template <typename T>
            inline bool primitive(const std::string& str_) noexcept;



            //  == FUNCTIONS ==
            //  -- Primitive --
            template <typename T>
            inline bool primitive(const std::string& str_) noexcept
            {
                std::stringstream stream;
                stream << str_;

                T val{};
                stream >> val;

                if (stream.fail())
                {
                    std::cerr << "Unable to parse string: '" << str_ << "' to type.\n"
                              << "String: '" << str_ << "' can not be parsed to type: '" << typeid(T).name() << "'.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                if (stream.rdbuf()->in_avail() != 0)
                {
                    std::cerr << "Unable to parse string to type.\n"
                              << "String: '" << str_ << "' contains leftover characters after parsing to type: '" << typeid(T).name() << "'.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                return (val);
            }



        } // namespace string
    }     // namespace read
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_READ_STRING_HPP
