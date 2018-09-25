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
#include <iomanip>
#include <sstream>
#include <string>

//  -- Arctk --
#include <arctk/consts.hpp>
#include <arctk/debug.hpp>



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
            template <typename T, typename... A>
            inline std::string csv(const std::vector<T>& vec_, const A&... vecs_) noexcept
            {
                const size_t rows = vec_.size();
                (PRE(vecs_.size() == rows), ...);

                std::stringstream stream;

                for (size_t i = 0; i < rows; ++i)
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
