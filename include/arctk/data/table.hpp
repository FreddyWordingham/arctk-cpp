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
            static_assert(sizeof...(A) > 0);
            static_assert(sizeof...(A) == sizeof...(B));
            static_assert(utl::properties::all_true<(utl::type::is_vector<B>::value)...>::value);
        }


        //  -- Initialisation --
        template <typename... A>
        template <typename T, typename... B>
        inline std::vector<std::tuple<A...>> Table<A...>::init_rows(const std::vector<T>& first_col_, const B&... cols_) noexcept
        {
            static_assert(sizeof...(A) > 0);
            static_assert(sizeof...(A) == sizeof...(B));
            static_assert(utl::properties::all_true<(utl::type::is_vector<B>::value)...>::value);
            (PRE(first_col_.size() == cols_.size()), ...);

            std::vector<std::tuple<A...>> rows;

            return (rows);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
