/**
 *  @file   arctk/io/output.hpp
 *  @date   25/09/2018
 *  @author Freddy Wordingham
 *
 *  Output functions.
 */



//  == GUARD ==
#ifndef ARCTK_IO_OUTPUT_HPP
#define ARCTK_IO_OUTPUT_HPP



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <iomanip>
#include <sstream>
#include <string>

//  -- Arctk --
#include <arctk/consts.hpp>
#include <arctk/type/temp.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace io //! input/output namespace
    {
        namespace output //! output namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Formatting --
            template <typename T, typename... A>
            inline std::string csv(const std::vector<T>& vec_, const A&... vecs_) noexcept;



            //  == FUNCTIONS ==
            //  -- Formatting --
            /**
             *  Format a group of vectors into a csv-style string.
             *
             *  @tparam T   Type stored by the first vector.
             *  @tparam A   Types stored by the remaining vectors.
             *
             *  @param  vec_    Vector forming the first column of the csv.
             *  @param  vecs_   Vectors forming the remaining columns of the csv.
             *
             *  @pre    vecs_ must all be vectors.
             *  @pre    vecs_ sizes must match the size of vec_.
             *
             *  @return String of the csv.
             */
            template <typename T, typename... A>
            inline std::string csv(const std::vector<T>& vec_, const A&... vecs_) noexcept
            {
                (assert(type::temp::is_vector<A>::value), ...);
                (assert(vecs_.size() == vec_.size()), ...);

                std::stringstream stream;

                for (size_t i = 0; i < vec_.size(); ++i)
                {
                    stream << std::setw(16) << vec_[i];
                    ((stream << consts::format::DELIM << std::setw(16) << vecs_[i]), ...);
                    stream << '\n';
                }

                return (stream.str());
            }



        } // namespace output
    }     // namespace io
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IO_OUTPUT_HPP
