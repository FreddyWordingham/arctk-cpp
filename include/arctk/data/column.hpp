/**
 *  @file   arctk/data/column.hpp
 *  @date   23/05/2018
 *  @author Freddy Wordingham
 *
 *  Column data class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_COLUMN_HPP
#define ARCTK_DATA_COLUMN_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/data/serial.hpp>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Data column class.
         *  Stores a column of serialised objects.
         */
        class Column
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            const std::string         _name; //!< Name of the data column.
            const std::vector<serial> _data; //!< Serialised vector.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == OPERATORS ==
          public:
            //  == METHODS ==
          public:
            //  -- Getters --
            const std::string& name() const noexcept;
        };



        //  == METHODS ==
        //  -- Getters --
        const std::string& Column::name() const noexcept
        {
            return (_name);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_COLUMN_HPP
