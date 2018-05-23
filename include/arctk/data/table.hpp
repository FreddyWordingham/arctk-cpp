/**
 *  @file   arctk/data/table.hpp
 *  @date   23/05/2018
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
         *  Data table class.
         *  Stores vectors of different types.
         */
        template <class... T>
        class Table
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            std::tuple<std::vector<T>...> _cols; //!< Data columns.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Table(const std::tuple<std::vector<T>...> cols_) noexcept;


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <class... T>
        inline Table<T...>::Table(const std::tuple<std::vector<T>...> cols_) noexcept
          : _cols(cols_)
        {
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
