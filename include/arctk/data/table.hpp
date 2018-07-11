/**
 *  @file   arctk/data/table.hpp
 *  @date   11/07/2018
 *  @author Freddy Wordingham
 *
 *  Data table class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_TABLE_HPP
#define ARCTK_DATA_TABLE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

//  -- Arctk --
#include <arctk/exit.hpp>
#include <arctk/settings.hpp>
#include <arctk/str.hpp>
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Data table class.
         *
         *  @tparam A   Types stored in data columns.
         */
        template <typename... A>
        class Table : str::Printable
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            std::vector<std::tuple<A...>> _rows; //!< Table row data.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Table(const std::vector<std::tuple<A...>>& rows_) noexcept;
            template <typename... B>
            inline Table(const B&... cols_) noexcept;
            inline explicit Table(const std::string& serial_, char delim_ = settings::format::DELIMITER) noexcept;

            //  -- Initialisation --
            template <typename T, typename... B>
            inline std::vector<std::tuple<A...>> init_rows(const std::vector<T>& first_col_, const B&... cols_) noexcept;
            inline std::vector<std::tuple<A...>> init_rows(const std::string& serial_, char delim_) noexcept;
            template <size_t... I, typename... B>
            inline std::tuple<A...> init_row(size_t index_, std::index_sequence<I...> /*unused*/, const B&... cols_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Access --
            std::tuple<A...>&       operator[](size_t index_) noexcept;
            const std::tuple<A...>& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::vector<std::tuple<A...>>& rows() const noexcept;
            template <size_t I>
            inline std::vector<typename std::tuple_element<I, std::tuple<A...>>::type> col() const noexcept;

            //  -- Printing --
            inline std::string str() noexcept override;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a vector of tuples.
         *
         *  @param  rows_   Vector of tuples to form rows.
         */
        template <typename... A>
        inline Table<A...>::Table(const std::vector<std::tuple<A...>>& rows_) noexcept
          : _rows(rows_)
        {
        }

        /**
         *  Construct a table from data vector columns.
         *
         *  @tparam B   Types stored in data vector columns.
         *
         *  @param  cols_   Vector columns used to construct table.
         */
        template <typename... A>
        template <typename... B>
        inline Table<A...>::Table(const B&... cols_) noexcept
          : _rows(init_rows(cols_...))
        {
            static_assert(sizeof...(A) == sizeof...(B));
            static_assert(utl::properties::all_true<(utl::type::is_vector<B>::value)...>::value);
        }

        template <typename... A>
        inline Table<A...>::Table(const std::string& serial_, const char delim_) noexcept
          : _rows(init_rows(serial_, delim_))
        {
        }


        //  -- Initialisation --
        template <typename... A>
        template <typename T, typename... B>
        inline std::vector<std::tuple<A...>> Table<A...>::init_rows(const std::vector<T>& first_col_, const B&... cols_) noexcept
        {
            static_assert(sizeof...(A) == (sizeof...(B) + 1));
            static_assert(utl::properties::all_true<(utl::type::is_vector<B>::value)...>::value);
            (PRE(first_col_.size() == cols_.size()), ...);

            std::vector<std::tuple<A...>> rows;
            rows.reserve(first_col_.size());

            for (size_t i = 0; i < first_col_.size(); ++i)
            {
                rows.emplace_back(init_row(i, std::make_index_sequence<sizeof...(B) + 1>{}, first_col_, cols_...));
            }

            return (rows);
        }

        template <typename... A>
        inline std::vector<std::tuple<A...>> Table<A...>::init_rows(const std::string& serial_, const char delim_) noexcept
        {
            std::vector<std::tuple<A...>> rows;

            std::stringstream serial_stream(serial_);
            std::string       line;
            while (std::getline(serial_stream, line))
            {
                std::vector<std::string> strs;
                strs.reserve(sizeof...(A));

                std::stringstream line_stream(line);
                std::string       word;
                while (std::getline(line_stream, word, delim_))
                {
                    strs.push_back(word);
                }

                if (strs.size() != sizeof...(A))
                {
                    std::cerr << "Unable to construct data table.\n"
                              << "Line: `" << line << "`, does not contain " << sizeof...(A) << " elements as required.";

                    std::exit(exit::error::FAILED_PARSE);
                }

                rows.emplace_back(str::parse::to<A...>(strs));
            }

            return (rows);
        }

        template <typename... A>
        template <size_t... I, typename... B>
        inline std::tuple<A...> Table<A...>::init_row(const size_t index_, std::index_sequence<I...> /*unused*/, const B&... cols_) noexcept
        {
            std::tuple<A...> tup;

            ((std::get<I>(tup) = cols_[index_]), ...);

            return (tup);
        }



        //  == OPERATORS ==
        //  -- Access --
        /**
         *  Access a const row of the table.
         *
         *  @tparam A   Types stored in data columns.
         *
         *  @param  index_  Index of the row to access.
         *
         *  @return Const reference to the requested row.
         */
        template <typename... A>
        std::tuple<A...>& Table<A...>::operator[](const size_t index_) noexcept
        {
            return (_rows[index_]);
        }

        /**
         *  Access a row of the table.
         *
         *  @tparam A   Types stored in data columns.
         *
         *  @param  index_  Index of the row to access.
         *
         *  @return Reference to the requested row.
         */
        template <typename... A>
        const std::tuple<A...>& Table<A...>::operator[](const size_t index_) const noexcept
        {
            return (_rows[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the row data of the table.
         *
         *  @return Row data of the table.
         */
        template <typename... A>
        inline const std::vector<std::tuple<A...>>& Table<A...>::rows() const noexcept
        {
            return (_rows);
        }

        /**
         *  Get a copy of a data column.
         *
         *  @tparam I   Index of the column to copy.
         *
         *  @return Copy of a data column.
         */
        template <typename... A>
        template <size_t I>
        inline std::vector<typename std::tuple_element<I, std::tuple<A...>>::type> Table<A...>::col() const noexcept
        {
            std::vector<typename std::tuple_element<I, std::tuple<A...>>::type> col;

            col.reserve(_rows.size());
            for (size_t i = 0; i < _rows.size(); ++i)
            {
                col.push_back(std::get<I>(_rows[i]));
            }

            return (col);
        }


        //  -- Printing --
        template <typename... A>
        inline std::string Table<A...>::str() noexcept
        {
            std::stringstream stream;

            for (size_t i = 0; i < _rows.size(); ++i)
            {
                if (i != 0)
                {
                    stream << '\n';
                }

                stream << str::parse::from(_rows[i], false);
            }

            return (stream.str());
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
