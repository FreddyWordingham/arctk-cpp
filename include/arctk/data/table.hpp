/**
 *  @file   arctk/data/table.hpp
 *  @date   24/06/2018
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



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Data table class.
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
            template <typename T, typename... A>
            Table(const std::vector<T>& first_, const S&... vecs_)
            {
                ((assert(first_.size() = vecs_.size())), ...);
            }


            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION ==
        //  -- Constructors --



        //  == METHODS ==
        //  -- Getters --



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
