/**
 *  @file   arctk/data/table.hpp
 *  @date   24/05/2018
 *  @author Freddy Wordingham
 *
 *  Data table class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_TABLE_HPP
#define ARCTK_DATA_TABLE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <tuple>
#include <vector>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         */
        template <class... T>
        class Table
        {
            //  == FIELDS ==
          private:
            //  - Data --
            std::tuple<std::vector<T>...> _cols; //!< Data columns.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Table(const std::tuple<std::vector<T>...> cols_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            template <std::size_t I, class S = typename std::tuple_element<I, std::tuple<T...>>::type>
            std::vector<S>& col();
            template <std::size_t I, class S = typename std::tuple_element<I, std::tuple<T...>>::type>
            const std::vector<S>& col() const;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <class... T>
        inline Table<T...>::Table(const std::tuple<std::vector<T>...> cols_) noexcept
          : _cols(cols_)
        {
        }



        //  == METHODS ==
        //  -- Getters --
        template <std::size_t I, class S = typename std::tuple_element<I, std::tuple<T...>>::type>
        std::vector<S>& Table::col()
        {
            return (std::get<I>(_cols));
        }

        template <std::size_t I, class S = typename std::tuple_element<I, std::tuple<T...>>::type>
        const std::vector<S>& Table::col() const
        {
            return (std::get<I>(_cols));
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
