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
#include <tuple>
#include <vector>

//  -- Arctk --
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
        class Table
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            std::vector<std::tuple<A...>> _rows; //!< Table row data.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            template <typename T, typename... B>
            inline explicit Table(const std::vector<T>& first_col_, const B&... cols_) noexcept;

            //  -- Initialisation --
            template <typename T, typename... B>
            inline std::vector<std::tuple<A...>> init_rows(const std::vector<T>& first_col_, const B&... cols_) noexcept;
            template <size_t... I, typename... B>
            inline std::tuple<A...> init_row(size_t index_, std::index_sequence<I...> /*unused*/, const B&... cols_) noexcept;


            //  == OPERATORS ==
          public:
            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename... A>
        template <typename T, typename... B>
        inline Table<A...>::Table(const std::vector<T>& first_col_, const B&... cols_) noexcept
          : _rows(init_rows(first_col_, cols_...))
        {
            static_assert(sizeof...(A) == (sizeof...(B) + 1));
            static_assert(utl::properties::all_true<(utl::type::is_vector<B>::value)...>::value);
            (PRE(first_col_.size() == cols_.size()), ...);
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
        template <size_t... I, typename... B>
        inline std::tuple<A...> Table<A...>::init_row(const size_t index_, std::index_sequence<I...> /*unused*/, const B&... cols_) noexcept
        {
            std::tuple<A...> tup;

            ((std::get<I>(tup) = cols_[index_]), ...);

            return (tup);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
