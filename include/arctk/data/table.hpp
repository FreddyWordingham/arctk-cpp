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
            template <class T>
            inline std::vector<T> operator[](const std::string& title_) noexcept;


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
         *  Convert the data column to a vector of the requested type.
         *
         *  @param  title_  Title of the column to access.
         *
         *  @return Converted vector of data.
         */
        template <class T>
        inline std::vector<T> Table::operator[](const std::string& title_) noexcept
        {
            if (_data.find(title_) == _data.end())
            {
                ERROR(42) << "Unable to convert data column.\n"
                          << "Column title: '" << title_ << "' does not exist within the table.";
            }

            std::vector<T> vec;
            vec.reserve(_data[title_].size());

            for (size_t i = 0; i < _data[title_].size(); ++i)
            {
                vec.emplace_back(utl::parse<T>(_data[title_][i]));
            }

            return (vec);
        }


    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
