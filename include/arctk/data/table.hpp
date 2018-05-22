/**
 *  @file   arctk/data/table.hpp
 *  @date   22/05/2018
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
         *  Store a data table of variable types.
         */
        class Table
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            std::vector<std::string>              _title; //!< Vector of column title strings.
            std::vector<std::vector<std::string>> _data;  //!< Table of stringified data.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
        };



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
