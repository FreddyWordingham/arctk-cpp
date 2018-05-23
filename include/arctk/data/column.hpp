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
            const std::string   _name; //!< Name of the data column.
            std::vector<Serial> _data; //!< Serialised vector.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            template <class T>
            inline Column(const std::string& name_, const std::vector<T>& data_) noexcept;

            //  -- Initialisation --
            template <class T>
            inline std::vector<Serial> init_data(const std::vector<T>& data_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Access --
            inline Serial&       operator[](size_t index_) noexcept;
            inline const Serial& operator[](size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::string&         name() const noexcept;
            inline const std::vector<Serial>& data() const noexcept;
            template <class T>
            inline std::vector<T> parse() const noexcept;
            inline bool           empty() const noexcept;
            inline size_t         size() const noexcept;

            //  -- Access --
            inline Serial&       front() noexcept;
            inline const Serial& front() const noexcept;
            inline Serial&       back() noexcept;
            inline const Serial& back() const noexcept;

            //  -- Setters --
            inline void push_back(const Serial& val_) noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <class T>
        inline Column::Column(const std::string& name_, const std::vector<T>& data_) noexcept
          : _name(name_)
          , _data(init_data(data_))
        {
        }


        //  -- Initialisation --
        template <class T>
        inline std::vector<Serial> Column::init_data(const std::vector<T>& data_) noexcept
        {
            std::vector<Serial> data;
            data.reserve(data_.size());

            for (size_t i = 0; i < data_.size(); ++i)
            {
                data.emplace_back(data_[i]);
            }

            return (data);
        }



        //  == OPERATORS ==
        //  -- Access --
        inline Serial& Column::operator[](const size_t index_) noexcept
        {
            assert(index_ < _data.size());

            return (_data[index_]);
        }

        inline const Serial& Column::operator[](const size_t index_) const noexcept
        {
            assert(index_ < _data.size());

            return (_data[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        inline const std::string& Column::name() const noexcept
        {
            return (_name);
        }

        inline const std::vector<Serial>& Column::data() const noexcept
        {
            return (_data);
        }

        template <class T>
        inline std::vector<T> Column::parse() const noexcept
        {
            std::vector<T> vec;
            vec.reserve(_data.size());

            for (size_t i = 0; i < _data.size(); ++i)
            {
                vec.emplace_back(_data[i].parse<T>());
            }

            return (vec);
        }

        inline bool Column::empty() const noexcept
        {
            return (_data.empty());
        }

        inline size_t Column::size() const noexcept
        {
            return (_data.size());
        }


        //  -- Access --
        inline Serial& Column::front() noexcept
        {
            return (_data.front());
        }

        inline const Serial& Column::front() const noexcept
        {
            return (_data.front());
        }

        inline Serial& Column::back() noexcept
        {
            return (_data.back());
        }

        inline const Serial& Column::back() const noexcept
        {
            return (_data.back());
        }


        //  -- Setters --
        inline void Column::push_back(const Serial& val_) noexcept
        {
            _data.push_back(val_);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_COLUMN_HPP
