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
            std::map<std::string, std::vector<std::string>> _data; //!< Table of stringified data.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == OPERATORS ==
          public:
            //  -- Access --
            inline std::string& operator[](size_t index_) noexcept;


            //  == METHODS ==
          public:
            //  -- Setters --
            template <class T>
            inline void add_col(const std::string& title_, const std::vector<T>& col_) noexcept
            {
                if (_data.find(title_) != _data.end())
                {
                    ERROR(42) << "Unable to add column to data table.\n"
                              << "Column title of: '" << title_ << "' already exists.";
                }

                std::vector<std::string> col;
                for (size_t i = 0; i < col_.size(); ++i)
                {
                    col.emplace_back(utl::to_string(col_[i]));
                }

                _data.emplace(std::make_pair(title_, col));
            }
        };



        //  == OPERATORS ==
        //  -- Access --
        /**
         *  Access a data column.
         *
         *  @param  index_  Index of the data column to access.
         *
         *  @pre    index_ must be less than _data.size();
         *
         *  @return A reference to the data column.
         */
        inline std::string& Table::operator[](const size_t index_) noexcept
        {
            assert(index_ < _data.size());

            return (_data[index_]);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
