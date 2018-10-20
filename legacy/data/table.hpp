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



//  == IMPORTS ==
//  -- Std --
#include <cstdlib>
#include <string>
#include <tuple>
#include <vector>



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
        class Table
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            std::vector<std::tuple<A...>> _rows; //!< Table row data.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Table(const std::vector<std::tuple<A...>>& rows_) noexcept;
            inline explicit Table(const std::vector<A>&... cols_) noexcept;
            inline explicit Table(const std::string& serial_, char delim_ = consts::format::DELIM) noexcept;

          private:
            //  -- Initialisation --
            template <typename T, typename... B>
            inline std::vector<std::tuple<A...>> init_rows(const std::vector<T>& first_col_, const std::vector<B>&... cols_) noexcept;
            inline std::vector<std::tuple<A...>> init_rows(const std::string& serial_, char delim_) noexcept;
            template <size_t... I>
            inline std::tuple<A...> init_row(size_t index_, const std::index_sequence<I...>& /*unused*/, const std::vector<A>&... cols_) noexcept;


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
        };



    } // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/table.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
