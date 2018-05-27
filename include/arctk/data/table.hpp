/**
 *  @file   arctk/data/table.hpp
 *  @date   27/05/2018
 *  @author Freddy Wordingham
 *
 *  Table data class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_TABLE_HPP
#define ARCTK_DATA_TABLE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Data table class storing rows of heterogeneous types.
         *
         *  @tparam A   Types stored by each row.
         */
        template <class... A>
        class Table
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            std::vector<std::tuple<A...>> _rows{};


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == OPERATORS ==
          public:
            //  -- Getters --
            const std::tuple<A...>& operator[](const size_t index_);

            //  -- Access --



            //  == METHODS ==
          public:
        };



        //  == OPERATORS ==
        //  -- Getters --
        const std::tuple<A...>& Table<A...>::operator[](const size_t index_)
        {
            return (_rows[index_]);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
