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
#include <sstream>
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
        template <class T>
        class Column : public std::vector<T>
        {
          private:
            using std::vector<T>::push_back;
            using std::vector<T>::emplace_back;
            using std::vector<T>::pop_back;

          public:
            inline Column() noexcept
              : std::vector<T>()
            {
            }
            inline Column(const size_t size_) noexcept
              : std::vector<T>(size_)
            {
            }
            inline Column(const std::initializer_list<T>& init_list_) noexcept
              : std::vector<T>(init_list_)
            {
            }
        };


        template <class... T>
        class Table
        {
            //  == FIELDS ==
          private:
            //  - Data --
            std::tuple<Column<T>...> _cols; //!< Data columns.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Table(const std::tuple<Column<T>...> cols_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            template <size_t I, class S = typename std::tuple_element<I, std::tuple<T...>>::type>
            Column<S>& col();
            template <size_t I, class S = typename std::tuple_element<I, std::tuple<T...>>::type>
            const Column<S>& col() const;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <class... T>
        inline Table<T...>::Table(const std::tuple<Column<T>...> cols_) noexcept
          : _cols(cols_)
        {
        }



        //  == METHODS ==
        //  -- Getters --
        template <class... T>
        template <size_t I, class S>
        Column<S>& Table<T...>::col()
        {
            return (std::get<I>(_cols));
        }

        template <class... T>
        template <size_t I, class S>
        const Column<S>& Table<T...>::col() const
        {
            return (std::get<I>(_cols));
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
