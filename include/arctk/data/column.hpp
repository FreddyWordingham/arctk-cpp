/**
 *  @file   arctk/data/column.hpp
 *  @date   24/05/2018
 *  @author Freddy Wordingham
 *
 *  Data column class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_COLUMN_HPP
#define ARCTK_DATA_COLUMN_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
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
        class Column
        {
            //  == FIELDS ==
          private:
            //  - Data --
            std::vector<T> _data;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
            //  -- Getters --
        };



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_COLUMN_HPP
