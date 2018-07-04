/**
 *  @file   arctk/str/parse.hpp
 *  @date   04/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection of string parsing functions.
 */



//  == GUARD ==
#ifndef ARCTK_STR_PARSE_HPP
#define ARCTK_STR_PARSE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace str //! string namespace
    {
        namespace parse //! parsing namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Parsing --
            template <typename T>
            inline bool parsable(const std::string& str_) noexcept;



            //  == FUNCTIONS ==
            //  -- Parsing --
            template <typename T>
            inline bool parsable(const std::string& str_) noexcept
            {
                std::stringstream stream;
                stream << str_;

                T val{};
                stream >> val;

                if (stream.fail())
                {
                    return (false);
                }

                if (stream.rdbuf()->in_avail() != 0)
                {
                    return (false);
                }

                return (true);
            }

            template <>
            inline bool parsable<bool>(const std::string& str_) noexcept
            {
                std::string str = str_;
                std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c_) { return std::tolower(c_); });

                if ((str == "false") || (str == "true"))
                {
                    return (true);
                }

                return (false);
            }



        } // namespace parse
    }     // namespace str
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_STR_PARSE_HPP
