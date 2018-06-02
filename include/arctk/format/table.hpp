/**
 *  @file   arctk/format/table.hpp
 *  @date   28/05/2018
 *  @author Freddy Wordingham
 *
 *  Table formating functions.
 */



//  == GUARD ==
#ifndef ARCTK_FORMAT_TABLE_HPP
#define ARCTK_FORMAT_TABLE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/print.hpp>
#include <arctk/search.hpp>
#include <arctk/str.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace format //! format namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Table --
        template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
        inline std::string rows(const C& cont_, int width_ = 0, const std::string& delim_ = ", ") noexcept;

        template <typename... A>
        inline std::string rows(int width_, const std::string& delim_, A... args);

        template <typename... A>
        inline std::string cols(int width, const std::string& delim_, A... args);



        //  == FUNCTIONS ==
        //  -- Table --
        /**
         *  Form a container into a human reader table.
         *  Each element of the container is treated as a row.
         *
         *  @param cont_ [description]
         *  @param width_ [description]
         *  @param delim_ [description]
         *
         *  @return [description]
         */
        template <typename C, typename T, typename I>
        inline std::string rows(const C& cont_, int width_, const std::string& delim_) noexcept
        {
            std::stringstream stream;

            for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
            {
                if (it != std::begin(cont_))
                {
                    stream << '\n';
                }

                if constexpr (std::is_same<T, std::string>::value)
                {
                    stream << std::setw(width_) << *it;
                }
                else
                {
                    stream << str::to_string(*it, width_, "", delim_, "");
                }
            }

            return (stream.str());
        }



        struct RowsHelper
        {
            std::stringstream& _stream; //!< Stream to write to.
            const std::string  _delim;  //!< Delimiter added between elements.
            const int          _width;  //!< Print width allocated to each element.
            size_t             _index;

            RowsHelper(std::stringstream& stream_, const std::string& delim_, const int width_)
              : _stream(stream_)
              , _delim(delim_)
              , _width(width_)
              , _index(0)
            {
            }

            template <typename L>
            void operator()(const L& val_)
            {
                if (_index != 0)
                {
                    _stream << '\n';
                }

                _stream << str::to_string(val_, _width, "", _delim, "");

                ++_index;
            }
        };

        template <typename... A>
        inline std::string rows(int width_, const std::string& delim_, A... args)
        {
            std::vector<std::stringstream> row_stream(sizeof...(A));
            size_t                         row = 0;
            ((row_stream[row] << str::to_string(args, width_, "", delim_, ""), ++row), ...);

            std::vector<size_t> rows;
            (rows.emplace_back(args.size()), ...);

            for (size_t i = 0; i < rows.size(); ++i)
            {
                for (size_t j = rows[i]; j < search::max(rows); ++j)
                {
                    row_stream[i] << delim_ << std::setw(width_) << ' ';
                }
            }

            std::stringstream stream;

            for (size_t i = 0; i < row_stream.size(); ++i)
            {
                if (i != 0)
                {
                    stream << '\n';
                }

                stream << row_stream[i].str();
            }

            /*            std::vector<size_t> rows;
                        ((rows.emplace_back(args.size()), 0), ...);

                        RowsHelper rh(stream, delim_, width_);



                        int dummy[] = {0, ((void)rh(std::forward<A>(args)), 0)...};


                        for (size_t i = rows[i]; i < search::max(rows); ++i)
                        {
                            stream << delim_ << std::setw(width_) << ' ';
                        }*/

            return (stream.str());
        }



        struct ColsHelper
        {
            std::vector<std::stringstream>& _stream; //!< Stream to write to.
            const std::string               _delim;  //!< Delimiter added between elements.
            const int                       _width;  //!< Print width allocated to each element.
            size_t                          _index;

            ColsHelper(std::vector<std::stringstream>& stream_, const std::string& delim_, const int width_)
              : _stream(stream_)
              , _delim(delim_)
              , _width(width_)
              , _index(0)
            {
            }

            template <typename L>
            void operator()(const L& val_)
            {
                for (size_t i = 0; i < _stream.size(); ++i)
                {
                    _stream[i] << std::setw(_width);

                    if (i < val_.size())
                    {
                        _stream[i] << val_[i];
                    }
                    else
                    {
                        _stream[i] << ' ';
                    }

                    _stream[i] << _delim;
                }

                ++_index;
            }
        };

        template <typename... A>
        inline std::string cols(int width_, const std::string& delim_, A... args)
        {
            std::stringstream stream;

            std::vector<size_t> rows;
            (rows.emplace_back(args.size()), ...);

            std::vector<std::stringstream> row_stream(search::max(rows));

            ColsHelper ch(row_stream, delim_, width_);
            (ch(std::forward<A>(args)), ...);

            for (size_t i = 0; i < row_stream.size(); ++i)
            {
                if (i != 0)
                {
                    stream << '\n';
                }

                std::string row_str = row_stream[i].str();
                row_str.erase(std::prev(std::end(row_str), static_cast<int>(delim_.size())), std::end(row_str));

                stream << row_str;
            }

            return (stream.str());
        }



    } // namespace format
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_FORMAT_TABLE_HPP
