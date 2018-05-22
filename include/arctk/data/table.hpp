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
#include <any>
#include <map>
#include <string>
#include <vector>

//  -- Arctk --
#include <arctk/log.hpp>
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Store a data table of variable types.
         *  Column order is sorted in std::string order.
         */
        class Table
        {
            //  == FIELDS ==
          private:
            //  -- Data --
            std::map<std::string, std::vector<std::any>> _data; //!< Data mapping.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == OPERATORS ==
          public:
            //  -- Access --
            inline std::vector<std::any>& operator[](const std::string& title_) noexcept;


            //  == METHODS ==
          public:
        };



        //  == OPERATORS ==
        //  -- Access --
        inline std::vector<std::any>& Table::operator[](const std::string& title_) noexcept
        {
            if (_data.find(title_) == _data.end())
            {
                ERROR(42) << "Unable to access table data column.\n"
                          << "Column title of: '" << title_ << "' does not exist.";
            }

            return (_data.find(title_));
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
