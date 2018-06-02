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
        template <typename A0, typename A1>
        inline std::string row_table(const std::pair<A0, A1>& pair_, int width_ = 0, const std::string& delim_ = ", ") noexcept;


        template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
        inline std::string row_table(const C& cont_, int width_ = 0, const std::string& delim_ = ", ") noexcept;


        template <typename A0, typename A1>
        inline std::string col_table(const std::pair<A0, A1>& pair_, int width_ = 0, const std::string& delim_ = ", ") noexcept;

        template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
        inline std::string col_table(const C& cont_, int width_ = 0, const std::string& delim_ = ", ") noexcept;



        //  == FUNCTIONS ==
        //  -- Table --
        template <typename A0, typename A1>
        inline std::string row_table(const std::pair<A0, A1>& pair_, int width_, const std::string& delim_) noexcept
        {
            std::stringstream stream;

            if constexpr (std::is_fundamental<A0>::value)
            {
                stream << std::setw(width_) << std::get<0>(pair_);
            }
            else
            {
                stream << str::to_string(std::get<0>(pair_), width_, "", delim_, "");
            }

            stream << '\n';

            if constexpr (std::is_fundamental<A1>::value)
            {
                stream << std::setw(width_) << std::get<1>(pair_);
            }
            else
            {
                stream << str::to_string(std::get<1>(pair_), width_, "", delim_, "");
            }

            return (stream.str());
        }

        /**
         *  Format a given container into a row focused table.
         *
         *  @tparam C   Type of container.
         *  @tparam T   Type stored by C.
         *  @tparam I   Type of const iterator of C.
         *
         *  @param  cont_   Container to form into table.
         *  @param  width_  Print width allocated to each element.
         *  @param  delim_  Table delimiter string.
         *
         *  @return Formatted data table string.
         */
        template <typename C, typename T, typename I>
        inline std::string row_table(const C& cont_, const int width_, const std::string& delim_) noexcept
        {
            std::stringstream stream;

            for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
            {
                if (it != std::begin(cont_))
                {
                    stream << '\n';
                }

                if constexpr (std::is_fundamental<T>::value || std::is_same<T, std::string>::value)
                {
                    stream << std::setw(width_) << *it;
                }
                else
                {
                    stream << str::to_string(*it, width_, "", delim_, "");
                }
            }

            return (stream.str());
        }


        template <typename A0, typename A1>
        inline std::string col_table(const std::pair<A0, A1>& pair_, int width_, const std::string& delim_) noexcept
        {
            std::stringstream stream;

            std::vector<size_t> rows({std::get<0>(pair_).size(), std::get<1>(pair_).size()});
            const size_t        max_rows = search::max(rows);

            for (size_t i = 0; i < max_rows; ++i)
            {
                stream << std::setw(width_);

                if (std::get<0>(pair_).size() < i)
                {
                    stream << *std::next(std::begin(std::get<0>(pair_)), i);
                }
                else
                {
                    stream << ' ';
                }

                stream << std::setw(width_) << delim_;
                if (std::get<1>(pair_).size() < i)
                {
                    stream << *std::next(std::begin(std::get<1>(pair_)), i);
                }
                else
                {
                    stream << ' ';
                }
            }

            return (stream.str());
        }


        /**
         *  Format a given container into a column focused table.
         *
         *  @tparam C   Type of container.
         *  @tparam T   Type stored by C.
         *  @tparam I   Type of const iterator of C.
         *
         *  @param  cont_   Container to form into table.
         *  @param  width_  Print width allocated to each element.
         *  @param  delim_  Table delimiter string.
         *
         *  @return Formatted data table string.
         */
        template <typename C, typename T, typename I>
        inline std::string col_table(const C& cont_, const int width_, const std::string& delim_) noexcept
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
