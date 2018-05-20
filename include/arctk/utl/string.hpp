/**
 *  @file   arctk/utl/string.hpp
 *  @date   17/05/2018
 *  @author Freddy Wordingham
 *
 *  String utility functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_STRING_HPP
#define ARCTK_UTL_STRING_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <algorithm>
#include <cassert>
#include <sstream>
#include <string>

//  -- Arctk --
#include <arctk/utl/char.hpp>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace utl //! utility namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Properties --
        template <class T>
        inline bool parsable(const std::string& str_) noexcept;
        inline bool numerical(const std::string& str_) noexcept;
        inline bool whitespace(const std::string& str_) noexcept;
        inline bool glyph(const std::string& str_) noexcept;

        //  -- Filtering --
        inline std::string filter(const std::string& str_, char ch_) noexcept;
        inline std::string filter(const std::string& str_, const std::string& sub_) noexcept;
        inline std::string filter(const std::string& str_, const std::string& start_, const std::string& end_ = "\n") noexcept;
        inline std::string filter_blank_lines(const std::string& str_) noexcept;
        inline std::string filter_whitespace(const std::string& str_) noexcept;

        //  -- Replacement --
        inline std::string replace(const std::string& str_, char find_, char replace_) noexcept;
        inline std::string replace(const std::string& str_, const std::string& find_, const std::string& replace_) noexcept;

        //  -- Glyphs --
        inline std::string make_glyph(const std::string& str_, char ch_ = '_') noexcept;

        //  -- File Paths --
        inline std::string filename(const std::string& path_) noexcept;
        inline std::string extension(const std::string& path_) noexcept;

        //  -- Parsing --
        template <class T>
        inline T parse(const std::string& str_) noexcept;

        //  -- Time --
        inline std::string time(double total_sec_) noexcept;



        //  == FUNCTIONS ==
        //  -- Properties --
        /**
         *  Determine if a given string can be converted to a given type.
         *  Trailing whitespace is not tolerated.
         *
         *  @tparam T   Type to convert the string to.
         *
         *  @param  str_    String to be tested.
         *
         *  @return True if the string can be converted to the given type.
         */
        template <class T>
        inline bool parsable(const std::string& str_) noexcept
        {
            T                 result;
            std::stringstream stream{str_};

            stream >> result;

            return (!stream.fail() && (stream.rdbuf()->in_avail() == 0));
        }

        /**
         *  Determine if a given string can be converted to an arithmetic type.
         *  If the string can be converted to a double, then it can be converted to any arithmetic type.
         *
         *  @param  str_    String to be tested.
         *
         *  @return True if the string can be converted to an arithmetic type.
         */
        inline bool numerical(const std::string& str_) noexcept
        {
            return (parsable<double>(str_));
        }

        /**
         *  Determine if a given string contains only whitespace characters.
         *  Empty strings are considered whitespace.
         *
         *  @param  str_    String to be tested.
         *
         *  @return True if the string contains only whitespace characters.
         */
        inline bool whitespace(const std::string& str_) noexcept
        {
            return (str_.find_first_not_of(WHITESPACE_CHARS) == std::string::npos);
        }

        /**
         *  Determine if a given string contains only glyph characters and is not numerical.
         *  Empty strings are not considered glyphs.
         *
         *  @param  str_    String to be tested.
         *
         *  @return True if the string contains only glyph characters and is not numerical.
         */
        inline bool glyph(const std::string& str_) noexcept
        {
            return (str_.empty() || ((str_.find_first_not_of(GLYPH_CHARS) == std::string::npos) && !numerical(str_)));
        }


        //  -- Filtering --
        /**
         *  Filter all instances of a character from a string.
         *
         *  @param  str_    String to be filtered.
         *  @param  ch_     Character to be removed from the string.
         *
         *  @return A copy of str_ filtered of ch_ characters.
         */
        inline std::string filter(const std::string& str_, const char ch_) noexcept
        {
            std::string str{str_};

            str.erase(std::remove(str.begin(), str.end(), ch_), str.end());

            return (str);
        }

        /**
         *  Filter all instances of a sub-string from a string.
         *
         *  @param  str_    String to be filtered.
         *  @param  sub_    Sub-string to be removed from the string.
         *
         *  @pre    sub_ must not be empty.
         *
         *  @return A copy of str_ filtered of sub_ sub-strings.
         */
        inline std::string filter(const std::string& str_, const std::string& sub_) noexcept
        {
            assert(!sub_.empty());

            return (replace(str_, sub_, ""));
        }

        /**
         *  Filter out parts of string between given start and end strings.
         *
         *  @param  str_    String to be filtered.
         *  @param  start_  Start of the filter range.
         *  @param  end_    End of the filter range.
         *
         *  @pre    start_ must not be empty.
         *  @pre    end_ must not be empty.
         *
         *  @return A filtered copy of str_.
         */
        inline std::string filter(const std::string& str_, const std::string& start_, const std::string& end_) noexcept
        {
            assert(!start_.empty());
            assert(!end_.empty());

            std::string str{str_};

            size_t start;
            while ((start = str.find(start_)) != std::string::npos)
            {
                size_t end;
                if ((end = str.find(end_, start)) != std::string::npos)
                {
                    str.erase(start, end - start + end_.size());
                }
                else
                {
                    return (str);
                }
            }

            return (str);
        }

        /**
         *  Filter all blank lines from a string.
         *
         *  @param  str_    String to be filtered.
         *
         *  @return A copy of str_ filtered of blank lines.
         */
        inline std::string filter_blank_lines(const std::string& str_) noexcept
        {
            std::string str{str_};

            str.erase(std::unique(str.begin(), str.end(), [](const char first_, const char second_) { return ((first_ == '\n') && (second_ == '\n')); }), str.end());

            return (str);
        }

        /**
         *  Filter leading and trailing whitespace from a string.
         *
         *  @param  str_    String to be filtered.
         *
         *  @return A copy of str_ filtered of leading and trailing whitespace.
         */
        inline std::string filter_whitespace(const std::string& str_) noexcept
        {
            std::string str{str_};

            str.erase(0, str.find_first_not_of(" \f\n\r\t\v"));
            str.erase(str.find_last_not_of(" \f\n\r\t\v") + 1);

            return (str);
        }


        //  -- Replacement --
        /**
         *  Find and replace all instances of a character within a string with a given replacement character.
         *
         *  @param  str_        String to be modified.
         *  @param  find_       Character to be replaced.
         *  @param  replace_    Character to replace find_ character with.
         *
         *  @return A copy of str_ with all instances of the find_ character replaced with the replace_ character.
         */
        inline std::string replace(const std::string& str_, const char find_, const char replace_) noexcept
        {
            std::string str{str_};

            std::replace(str.begin(), str.end(), find_, replace_);

            return (str);
        }

        /**
         *  Find and replace all instances of a sub-string within a string with a given replacement string.
         *
         *  @pre    find_ must not be empty.
         *  @pre    replace_ must not be empty.
         *
         *  @param  str_        String to be modified.
         *  @param  find_       Sub-string to be replaced.
         *  @param  replace_    Sub-string to replace find_ sub-string with.
         *
         *  @return A copy of str_ with all instances of the find_ sub-string replaced with the replace_ sub-string.
         */
        inline std::string replace(const std::string& str_, const std::string& find_, const std::string& replace_) noexcept
        {
            assert(!find_.empty());
            assert(!replace_.empty());

            std::string str{str_};

            for (size_t pos{0}; (pos = str.find(find_, pos)) != std::string::npos; pos += replace_.size())
            {
                str.replace(pos, find_.size(), replace_);
            }

            return (str);
        }


        //  -- Glyphs --
        /**
         *  Form the given string into a glyph string by replacing all non-glyph characters using a replacement character.
         *
         *  @pre    ch_ must be a glyph.
         *
         *  @post   str must be a glyph.
         *
         *  @param  str_    String to be formed into a glyph.
         *  @param  ch_     Character used to replace non-glyph characters.
         *
         *  @return A copy of str_ with non-glyph characters replaced with the ch_ character.
         */
        inline std::string make_glyph(const std::string& str_, const char ch_) noexcept
        {
            assert(glyph(ch_));

            std::string str = filter_whitespace(str_);

            for (size_t i = 0; i < str.size(); ++i)
            {
                if (!glyph(str[i]))
                {
                    str[i] = ch_;
                }
            }

            assert(glyph(str));

            return (str);
        }


        //  -- File Paths --
        /**
         *  Determine the filename from a the file path.
         *
         *  @pre    path_ may not be empty.
         *
         *  @param  path_   Full file path.
         *
         *  @return Name of the file.
         */
        inline std::string filename(const std::string& path_) noexcept
        {
            assert(!path_.empty());

            const size_t slash_pos{path_.find_last_of('/')};

            return (slash_pos == std::string::npos ? path_ : path_.substr(slash_pos + 1));
        }

        /**
         *  Determine the extension from a the file path.
         *  If no dot is found within the file path, an empty string is returned.
         *
         *  @pre    path_ may not be empty.
         *
         *  @param  path_   Full file path.
         *
         *  @return Extension of the file.
         */
        inline std::string extension(const std::string& path_) noexcept
        {
            assert(!path_.empty());

            const size_t dot_pos{path_.find_last_of('.')};

            return (dot_pos == std::string::npos ? "" : path_.substr(dot_pos + 1));
        }


        //  -- Parsing --
        /**
         *  Parse a value from a string.
         *
         *  @pre    Str_ must be parsable.
         *
         *  @tparam T   Type to be parsed.
         *
         *  @param  str_    String to be parsed.
         *
         *  @return Value of the parsed string.
         */
        template <class T>
        inline T parse(const std::string& str_) noexcept
        {
            assert(parsable<T>(str_));

            T                 result;
            std::stringstream stream{str_};

            stream >> result;

            return (result);
        }


        //  -- Time --
        /**
         *  Convert the number of seconds into a time string.
         *
         *  @pre    total_sec_ must be positive.
         *
         *  @param  total_sec_  Number of seconds.
         *
         *  @return String of the time.
         */
        inline std::string time(const double total_sec_) noexcept
        {
            assert(total_sec_ >= 0.0);

            auto       sec      = static_cast<uint64_t>(total_sec_);
            const auto millisec = static_cast<uint64_t>((total_sec_ - sec) * 1000);

            const uint64_t hrs{sec / 3600};
            sec %= 3600;

            const uint64_t min{sec / 60};
            sec %= 60;

            return (std::to_string(hrs) + "hrs " + std::to_string(min) + "min " + std::to_string(sec) + "sec " + std::to_string(millisec) + "ms");
        }



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_STRING_HPP
