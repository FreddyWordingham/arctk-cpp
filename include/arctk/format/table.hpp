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
        template <typename... A>
        inline std::string rows(int width_, const std::string& delim_, A... args);
        template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
        inline std::string rows(int width_, const std::string& delim_, const C& cont_) noexcept;

        template <typename... A>
        inline std::string cols(int width, const std::string& delim_, A... args);



        //  == FUNCTIONS ==
        //  -- Table --
        /**
         *  Form a pack of container objects into a table.
         *  Containers are formatted as rows.
         *
         *  @tparam A   Container type pack.
         *
         *  @param  width_  Width allocated to each container element print.
         *  @param  delim_  Delimiter used to separate container elements.
         *  @param  args    Container pack to form table rows.
         *
         *  @return String of table of rows.
         */
        template <typename... A>
        inline std::string rows(int width_, const std::string& delim_, A... args)
        {
            std::vector<std::stringstream> row_stream(sizeof...(A));
            size_t                         row = 0;
            ((row_stream[row] << str::to_string(args, width_, "", delim_, ""), ++row), ...);

            std::vector<size_t> rows;
            (rows.emplace_back(args.size()), ...);

            for (size_t i = 0; i < rows.size(); ++i)
            {
                for (size_t j = rows[i]; j < search::max(rows); ++j)
                {
                    row_stream[i] << delim_ << std::setw(width_) << ' ';
                }
            }

            std::stringstream stream;

            for (size_t i = 0; i < row_stream.size(); ++i)
            {
                if (i != 0)
                {
                    stream << '\n';
                }

                stream << row_stream[i].str();
            }

            return (stream.str());
        }

        /**
         *  Form a container into a human reader table.
         *  Each element of the container is treated as a row.
         *
         *  @tparam C   Type of container.
         *  @tparam T   Type stored by C.
         *  @tparam I   Type of const iterator of C.
         *
         *  @param  width_  Width allocated to each container element print.
         *  @param  delim_  Delimiter used to separate container elements.
         *  @param  cont_   Container to form into a table.
         *
         *  @return String of table of rows.
         */
        template <typename C, typename T, typename I>
        inline std::string rows(int width_, const std::string& delim_, const C& cont_) noexcept
        {
            std::stringstream stream;

            for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
            {
                if (it != std::begin(cont_))
                {
                    stream << '\n';
                }

                if constexpr (std::is_same<T, std::string>::value)
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

        /**
         *  Form a pack of container objects into a table.
         *  Containers are formatted as columns.
         *
         *  @tparam Container type pack.
         *
         *  @param  width_  Width allocated to each container element print.
         *  @param  delim_  Delimiter used to separate container elements.
         *  @param  args    Container pack to form table columns.
         *
         *  @return String of table of columns.
         */
        template <typename... A>
        inline std::string cols(int width_, const std::string& delim_, A... args)
        {
            std::vector<size_t> rows;
            (rows.emplace_back(args.size()), ...);

            std::vector<std::stringstream> row_stream(search::max(rows));

            auto to_string = [](auto x) {
                std::stringstream val_stream;
                val_stream << x;
                return (val_stream.str());
            };

            for (size_t i = 0; i < search::max(rows); ++i)
            {
                size_t col = 0;

                ((row_stream[i] << ((col != 0) ? delim_ : "") << std::setw(width_) << ((i < rows[col]) ? to_string(args[i]) : ""), ++col), ...);
            }

            std::stringstream stream;

            for (size_t i = 0; i < row_stream.size(); ++i)
            {
                if (i != 0)
                {
                    stream << '\n';
                }

                stream << row_stream[i].str();
            }

            return (stream.str());
        }



    } // namespace format
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_FORMAT_TABLE_HPP
