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
        };



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
