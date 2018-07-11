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
            template <typename... B>
            inline explicit Table(const B&... cols_) noexcept;

            //  -- Initialisation --
            template <typename... B>
            inline std::vector<std::tuple<A...>> init_rows(const B&... cols_) noexcept;


            //  == OPERATORS ==
          public:
            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename... A>
        template <typename... B>
        inline Table<A...>::Table(const B&... cols_) noexcept
          : _rows(init_rows(cols_...))
        {
            static_assert(sizeof...(A) == sizeof...(B));
        }

        //  -- Initialisation --
        template <typename... B>
        inline std::vector<std::tuple<A...>> Table<A...>::init_rows(const B&... cols_) noexcept
        {
            std::vector<std::tuple<A...>> rows;

            return (rows);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
