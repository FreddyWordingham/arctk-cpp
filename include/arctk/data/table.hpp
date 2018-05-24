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
            inline explicit Table(const std::tuple<std::vector<T>...> _cols) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            template <size_t I, class S = typename std::tuple_element<I, std::tuple<T...>>::type>
            std::vector<S>& col()
            {
                return (std::get<I>(_cols[i]));
            }

            template <size_t I, class S = typename std::tuple_element<I, std::tuple<T...>>::type>
            const std::vector<S>& col()
            {
                return (std::get<I>(_cols[i]));
            }
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <class... T>
        inline Table<T...>::Table(const std::tuple<std::vector<T>...> _cols) noexcept
          : _cols(cols_)
        {
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
