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
//  -- Arctk --
#include <arctk/print.hpp>
#include <arctk/search.hpp>
#include <arctk/str.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace format //! format namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Table --
        template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
        inline std::string row_table(const C& cont_, size_t width_ = 0, const std::string& delim_ = ", ") noexcept;
        template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator, typename J = typename T::const_iterator>
        inline std::string col_table(const C& cont_, size_t width_ = 0, const std::string& delim_ = ", ") noexcept;



        //  == FUNCTIONS ==
        //  -- Table --
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
        inline std::string row_table(const C& cont_, const size_t width_, const std::string& delim_) noexcept
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

        template <typename C, typename T, typename I, typename J>
        inline std::string col_table(const C& cont_, const size_t width_, const std::string& delim_) noexcept
        {
            std::stringstream stream;

            std::vector<size_t> rows;

            for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
            {
                rows.emplace_back(std::distance(std::begin(*it), std::end(*it)));
            }

            const size_t max_rows = search::max(rows);

            for (size_t i = 0; i < max_rows; ++i)
            {
                if (i != 0)
                {
                    stream << '\n';
                }

                for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                {
                    const size_t col = std::distance(std::begin(cont_), it);

                    if (it != std::begin(cont_))
                    {
                        if (i < rows[col - 1])
                        {
                            stream << delim_;
                        }
                        else
                        {
                            stream << std::string(delim_.size(), ' ');
                        }
                    }

                    if (i < rows[col])
                    {
                        stream << std::setw(width_) << *std::next(std::begin(*it), i);
                    }
                    else
                    {
                        stream << std::setw(width_) << ' ';
                    }
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
