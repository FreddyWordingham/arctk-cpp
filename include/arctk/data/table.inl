/**
 *  @file   arctk/data/table.inl
 *  @date   11/07/2018
 *  @author Freddy Wordingham
 *
 *  Data table class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_TABLE_INL
#define ARCTK_DATA_TABLE_INL



//  == IMPORTS ==
//  -- Std --
#include <iostream>

//  -- Arctk --
#include <arctk/exit.hpp>
#include <arctk/io.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



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
         *  @param  cols_   Vector columns used to construct table.
         */
        template <typename... A>
        inline Table<A...>::Table(const std::vector<A>&... cols_) noexcept
          : _rows(init_rows(cols_...))
        {
        }

        /**
         *  Construct a table from a serialisation.
         *
         *  @param  serial_ Serialised table data.
         *  @param  delim_  Delimiter character.
         */
        template <typename... A>
        inline Table<A...>::Table(const std::string& serial_, const char delim_) noexcept
          : _rows(init_rows(serial_, delim_))
        {
        }


        //  -- Initialisation --
        /**
         *  Initialise the vector of data rows.
         *
         *  @tparam T   Type stored by first vector.
         *  @tparam B   Types stored by remaining vectors.
         *
         *  @param  first_col_  First vector used to form the first column.
         *  @param  cols_       Remaining vectors used to form remaining columns.
         *
         *  @return Initialised vector of table rows.
         */
        template <typename... A>
        template <typename T, typename... B>
        inline std::vector<std::tuple<A...>> Table<A...>::init_rows(const std::vector<T>& first_col_, const std::vector<B>&... cols_) noexcept
        {
            std::vector<size_t> col_length;
            (col_length.emplace_back(cols_.size()), ...);

            for (size_t i = 0; i < col_length.size(); ++i)
            {
                if (col_length[i] != first_col_.size())
                {
                    std::cerr << "Unable to initialise rows of data table.\n"
                              << "Column: `" << i << "` contains: `" << col_length[i] << "` elements, but the first column contains: `" << first_col_.size() << "` elements.\n";

                    std::exit(exit::error::FAILED_INITIALISATION);
                }
            }

            std::vector<std::tuple<A...>> rows;
            rows.reserve(first_col_.size());

            for (size_t i = 0; i < first_col_.size(); ++i)
            {
                rows.emplace_back(init_row(i, std::make_index_sequence<sizeof...(B) + 1>{}, first_col_, cols_...));
            }

            return (rows);
        }

        /**
         *  Initialise the vector of data rows from a serialisation.
         *
         *  @param  serial_ Serialised table data.
         *  @param  delim_  Delimiter character.
         *
         *  @return Initialised vector of table rows.
         */
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
                              << "Line: `" << line << "`, does not contain " << sizeof...(A) << " elements as required.\n";

                    std::exit(exit::error::FAILED_INITIALISATION);
                }

                std::string str;
                for (size_t i = 0; i < strs.size(); ++i)
                {
                    str += strs[i];
                }

                rows.emplace_back(io::parse<std::tuple<A...>>(str));
            }

            return (rows);
        }

        /**
         *  Initialise a row of the table.
         *
         *  @tparam I   Index sequence of A.
         *
         *  @param  index_  Index of the vectors to read form.
         *  @param  cols_   Vectors used to construct table columns.
         *
         *  @return Initialised data row.
         */
        template <typename... A>
        template <size_t... I>
        inline std::tuple<A...> Table<A...>::init_row(const size_t index_, const std::index_sequence<I...>& /*unused*/, const std::vector<A>&... cols_) noexcept
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



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_INL
