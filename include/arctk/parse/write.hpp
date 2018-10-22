/**
 *  @file   arctk/parse/write.hpp
 *  @date   21/10/2018
 *  @author Freddy Wordingham
 *
 *  Write parsing functions.
 */



//  == GUARD ==
#ifndef ARCTK_PARSE_WRITE_HPP
#define ARCTK_PARSE_WRITE_HPP



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cstddef>
#include <iomanip>
#include <string>
#include <vector>

//  -- Arctk --
#include <arctk/consts/format.hpp>
#include <arctk/type/temp.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace parse //! parsing namespace
    {
        namespace write //! writing namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Format --
            inline std::string timestamp(long int sec_) noexcept;
            inline std::string bar(unsigned int length_, double frac_, char fill_ = '|') noexcept;

            //  -- Table --
            template <typename T, typename... A>
            inline std::string csv(const std::vector<T>& vec_, const A&... vecs_, unsigned int width_ = 16) noexcept;



            //  == FUNCTIONS ==
            /**
             *  Format a given number of seconds into a hr:min:sec string.
             *
             *  @param  sec_    Total number of seconds.
             *
             *  @return Formatted time string.
             */
            inline std::string timestamp(long int sec_) noexcept
            {
                const bool negative = sec_ < 0;
                if (negative)
                {
                    sec_ = -sec_;
                }

                const long int hr = sec_ / 3600;
                sec_ %= 3600;

                const long int min = sec_ / 60;
                sec_ %= 60;

                return ((negative ? std::string("-") : std::string("")) + ((hr < 10) ? "0" : "") + std::to_string(hr) + ((min < 10) ? ":0" : ":") + std::to_string(min) + ((sec_ < 10) ? ":0" : ":") + std::to_string(sec_));
            }

            /**
             *  Format the given fraction into a progress bar of a given length using the fill character.
             *
             *  @param  length_ Length of the progress bar.
             *  @param  frac_   Fraction of the bar to fill.
             *  @param  fill_   Character used to fill the bar.
             *
             *  @pre    frac_ must be non-negative.
             *  @pre    frac_ must be less than, or equal to, unity.
             *
             *  @return Formatted bar string.
             */
            inline std::string bar(const unsigned int length_, const double frac_, const char fill_) noexcept
            {
                assert(frac_ >= 0.0);
                assert(frac_ <= 1.0);

                std::string bar(length_, ' ');

                const auto ticks = static_cast<size_t>(length_ * frac_);
                for (size_t i = 0; i < ticks; ++i)
                {
                    bar[i] = fill_;
                }

                return (bar);
            }


            //  -- Table --
            /**
             *  Format a group of vectors into a csv-style string.
             *
             *  @tparam T   Type stored by the first vector.
             *  @tparam A   Types stored by the remaining vectors.
             *
             *  @param  vec_    Vector forming the first column of the csv.
             *  @param  vecs_   Vectors forming the remaining columns of the csv.
             *  @param  width_  Width of the columns.
             *
             *  @pre    vecs_ must all be vectors.
             *  @pre    vecs_ sizes must match the size of vec_.
             *  @pre    width_ must be greater than, or equal to, eight.
             *
             *  @return String of the csv.
             */
            template <typename T, typename... A>
            inline std::string csv(const std::vector<T>& vec_, const A&... vecs_, const unsigned int width_) noexcept
            {
                (assert(type::temp::is_vector<A>::value), ...);
                (assert(vecs_.size() == vec_.size()), ...);
                assert(width_ >= 8);

                std::stringstream stream;

                for (size_t i = 0; i < vec_.size(); ++i)
                {
                    stream << std::setw(width_) << vec_[i];
                    ((stream << consts::format::DELIM << std::setw(width_) << vecs_[i]), ...);
                    stream << '\n';
                }

                return (stream.str());
            }



        } // namespace write
    }     // namespace parse
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PARSE_WRITE_HPP
