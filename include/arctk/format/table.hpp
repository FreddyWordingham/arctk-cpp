/**
 *  @file   arctk/format/table.hpp
 *  @date   28/05/2018
 *  @author Freddy Wordingham
 *
 *  Table formating functions.
 */



//  == GUARD ==
#ifndef ARCTK_FORMAT_TABLE_HPP
#define ARCTK_FORMAT_TABLE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <arctk/print.hpp>
#include <arctk/str.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace format //! format namespace
    {



        //  == FUNCTION PROTOTYPES ==
        template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
        inline std::string table(const C& cont_, const size_t width_ = 0, const std::string& delim_ = ", ") noexcept;



        //  == FUNCTIONS ==
        /**
         *  Format a given container into a table.
         *
         *  @param  cont_   Container to form into table.
         *  @param  width_  Print width allocated to each element.
         *  @param  delim_  Table delimiter string.
         *
         *  @return Formatted data table string.
         */
        template <typename C, typename T, typename I>
        inline std::string table(const C& cont_, const size_t width_, const std::string& delim_) noexcept
        {
            std::stringstream stream;

            for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
            {
                if constexpr (std::is_fundamental<T>::value || std::is_same<T, std::string>::value)
                {
                    stream << std::setw(width_) << *it << '\n';
                }
                else
                {
                    stream << str::to_string(*it, width_, "", delim_, "") << '\n';
                }
            }

            return (stream.str());
        }



    } // namespace format
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_FORMAT_TABLE_HPP
