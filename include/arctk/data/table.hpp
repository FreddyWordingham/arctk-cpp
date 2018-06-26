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
#include <cassert>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

//  -- Arctk --
#include <arctk/str.hpp>
#include <arctk/sys.hpp>



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
            inline Table(const std::string& serial_, char delim_ = ',') noexcept;
            template <typename T, typename... B>
            inline Table(const std::vector<T>& first_, const B&... vecs_) noexcept;

            //  -- Initialisation --
            inline std::vector<std::tuple<A...>> init_rows(const std::string& serial_, char delim_) noexcept;
            template <typename T, typename... B>
            inline std::vector<std::tuple<A...>> init_rows(const std::vector<T>& first_, const B&... vecs_) noexcept;
            template <typename... B>
            inline std::tuple<A...> init_row(const size_t index_, const B&... vecs_) noexcept;
            template <size_t... I, typename... B>
            inline std::tuple<A...> init_row_helper(const size_t index_, std::index_sequence<I...> seq_, const B&... vecs_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Stream --
            template <typename S, typename... _A>
            friend inline S& operator<<(S& stream_, const Table<_A...>& tab_) noexcept;

            //  -- Access --
            std::tuple<A...>&       operator[](const size_t index_) noexcept;
            const std::tuple<A...>& operator[](const size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::vector<std::tuple<A...>>& rows() const noexcept;

            template <size_t I>
            inline std::vector<typename std::tuple_element<I, std::tuple<A...>>::type> col() const noexcept
            {
                std::vector<typename std::tuple_element<I, std::tuple<A...>>::type> vec;

                vec.reserve(_rows.size());
                for (size_t i = 0; i < _rows.size(); ++i)
                {
                    vec.push_back(std::get<I>(_rows[i]));
                }

                return (vec);
            }

            //  -- Printing --
            inline std::string str(const char delim_ = ',', const size_t width_ = 8) const noexcept;

            //  -- Saving --
            inline void save(const std::string& path_, const char delim_ = ',', const size_t width_ = 8) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename... A>
        inline Table<A...>::Table(const std::string& serial_, const char delim_) noexcept
          : _rows(init_rows(serial_, delim_))
        {
        }

        template <typename... A>
        template <typename T, typename... B>
        inline Table<A...>::Table(const std::vector<T>& first_, const B&... vecs_) noexcept
          : _rows(init_rows(first_, vecs_...))
        {
            static_assert(sizeof...(A) == (1 + sizeof...(B)));
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

        template <typename... A>
        template <typename T, typename... B>
        inline std::vector<std::tuple<A...>> Table<A...>::init_rows(const std::vector<T>& first_, const B&... vecs_) noexcept
        {
            (assert(first_.size() == vecs_.size()), ...);

            std::vector<std::tuple<A...>> rows;
            rows.reserve(first_.size());

            for (size_t i = 0; i < first_.size(); ++i)
            {
                rows.emplace_back(init_row(i, first_, vecs_...));
            }

            return (rows);
        }

        template <typename... A>
        template <typename... B>
        inline std::tuple<A...> Table<A...>::init_row(const size_t index_, const B&... vecs_) noexcept
        {
            return (init_row_helper(index_, std::make_index_sequence<sizeof...(B)>{}, vecs_...));
        }

        template <typename... A>
        template <size_t... I, typename... B>
        inline std::tuple<A...> Table<A...>::init_row_helper(const size_t index_, std::index_sequence<I...> seq_, const B&... vecs_) noexcept
        {
            std::tuple<A...> tup;

            ((std::get<I>(tup) = vecs_[index_]), ...);

            return (tup);
        }



        //  == OPERATORS ==
        //  -- Stream --
        template <typename S, typename... A>
        inline S& operator<<(S& stream_, const Table<A...>& tab_) noexcept
        {
            stream_ << tab_.str();

            return (stream_);
        }


        //  -- Access --
        template <typename... A>
        std::tuple<A...>& Table<A...>::operator[](const size_t index_) noexcept
        {
            return (_rows[index_]);
        }

        template <typename... A>
        const std::tuple<A...>& Table<A...>::operator[](const size_t index_) const noexcept
        {
            return (_rows[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename... A>
        inline const std::vector<std::tuple<A...>>& Table<A...>::rows() const noexcept
        {
            return (rows);
        }


        //  -- Printing --
        template <typename... A>
        inline std::string Table<A...>::str(const char delim_, const size_t width_) const noexcept
        {
            if (_rows.empty())
            {
                return ("");
            }

            std::stringstream stream;
            stream << str::to_string(_rows.front(), width_, "", delim_, "");

            for (size_t i = 1; i < _rows.size(); ++i)
            {
                stream << "\n" << str::to_string(_rows[i], width_, "", delim_, "");
            }

            return (stream.str());
        }


        //  -- Saving --
        template <typename... A>
        inline void Table<A...>::save(const std::string& path_, const char delim_, const size_t width_) const noexcept
        {
            assert(!path_.empty());

            sys::file::Out file(path_);

            file << str(delim_, width_);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_TABLE_HPP
