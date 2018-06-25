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

//  -- Arctk --
#include <arctk/str.hpp>



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
            //  -- Formatting --
            char   _delim;
            size_t _width;

            //  -- Data --
            std::vector<std::tuple<A...>> _rows; //!< Table row data.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Table(const std::string& serial_, char delim_ = ',', size_t width_ = 16) noexcept;

            //  -- Initialisation --
            inline std::vector<std::tuple<A...>> init_rows(const std::string& serial_, char delim_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Stream --
            template <typename S, typename... _A>
            friend inline S& operator<<(S& stream_, const Table<_A...>& tab_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline char   delim() const noexcept;
            inline size_t width() const noexcept;

            //  -- Printing --
            inline std::string str() const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename... A>
        inline Table<A...>::Table(const std::string& serial_, const char delim_, const size_t width_) noexcept
          : _rows(init_rows(serial_, delim_))
          , _delim(delim_)
          , _width(width_)
        {
        }


        //  -- Initialisation --
        template <typename... A>
        inline std::vector<std::tuple<A...>> Table<A...>::init_rows(const std::string& serial_, const char delim_) noexcept
        {
            std::vector<std::tuple<A...>> rows;

            std::stringstream serial_stream(serial_);
            std::string       line;
            while (std::getline(serial_stream, line))
            {
                std::vector<std::string> strs;
                strs.reserve(sizeof...(A));

                std::stringstream line_stream(line);
                std::string       word;
                while (std::getline(line_stream, word, delim_))
                {
                    strs.push_back(word);
                }

                if (strs.size() != sizeof...(A))
                {
                    ERROR(42) << "Unable to construct data table.\n"
                              << "Line: `" << line << "`, does not contain " << sizeof...(A) << " elements as required.";
                }

                rows.emplace_back(parse::from_str<A...>(strs));
            }

            return (rows);
        }



        //  == OPERATORS ==
        //  -- Stream --
        template <typename S, typename... A>
        inline S& operator<<(S& stream_, const Table<A...>& tab_) noexcept
        {
            stream_ << tab_.str();

            return (stream_);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename... A>
        inline char Table<A...>::delim() const noexcept
        {
            return (_delim);
        }

        template <typename... A>
        inline size_t Table<A...>::width() const noexcept
        {
        }


        //  -- Printing --
        template <typename... A>
        inline std::string Table<A...>::str() const noexcept
        {
            if (_rows.empty())
            {
                return ("");
            }

            std::stringstream stream;
            stream << str::to_string(_rows.front(), 10, "", ",", "");

            for (size_t i = 1; i < _rows.size(); ++i)
            {
                stream << "\n" << str::to_string(_rows[i], 10, "", ",", "");
            }

            return (stream.str());
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
