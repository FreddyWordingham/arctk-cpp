/**
 *  @file   arctk/io/read.hpp
 *  @date   21/09/2018
 *  @author Freddy Wordingham
 *
 *  Input reading functions.
 */



//  == GUARD ==
#ifndef ARCTK_IO_READ_HPP
#define ARCTK_IO_READ_HPP



//  == IMPORTS ==
//  -- Std --
#include <sstream>
#include <string>
#include <type_traits>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/exit.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace io //! input/output namespace
    {
        namespace read //! reading namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Primitive --
            template <typename T>
            inline T str(const std::string& str_) noexcept;
            template <typename T, typename S>
            inline std::pair<T, S> str(const std::string& str_0_, const std::string& str_1_) noexcept;



            //  == FUNCTIONS ==
            //  -- Primitive --
            template <typename T>
            inline T str(const std::string& str_) noexcept
            {
                static_assert(std::is_fundamental<T>::value);

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

            template <>
            inline bool str(const std::string& str_) noexcept
            {
                if (str_ == "0")
                {
                    return (false);
                }
                if (str_ == "1")
                {
                    return (true);
                }

                std::string str = str_;
                std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c_) { return std::tolower(c_); });

                if (str == "false")
                {
                    return (false);
                }
                if (str == "true")
                {
                    return (true);
                }

                std::cerr << "Unable to parse string: '" << str_ << "' to type.\n"
                          << "String: '" << str_ << "' can not be parsed to type: '" << typeid(bool).name() << "'.\n";

                std::exit(exit::error::FAILED_PARSE);
            }

            template <typename T, typename S>
            inline std::pair<T, S> str(const std::string& str_0_, const std::string& str_1_) noexcept
            {
                return (std::make_pair(str<T>(str_0_), str<S>(str_1_)));
            }



        } // namespace read
    }     // namespace io
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IO_READ_HPP
