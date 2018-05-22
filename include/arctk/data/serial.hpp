/**
 *  @file   arctk/data/serial.hpp
 *  @date   22/05/2018
 *  @author Freddy Wordingham
 *
 *  Serial data class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_SERIAL_HPP
#define ARCTK_DATA_SERIAL_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <string>

//  -- Arctk --
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace log //! logging namespace
    {



        //  == CLASS ==
        /**
         *  Serialised object class.
         *  Stores any data that may be represented as a string.
         */
        class Serial
        {
            //  == FIELDS ==
          private:
            //  -- Serialised Object --
            std::string _str; //!< Serialised string object data.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            template <class T, typename>
            inline explicit Serial(const T val_) noexcept;
            inline explicit Serial(const std::string& str_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            template <class T, typename>
            inline Serial& operator=(T val_) noexcept;
            inline Serial& operator=(const std::string& str_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            template <class T>
            inline T parse() noexcept;
            template <class T>
            inline T parsable() noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a serial object from a value of fundamental type.
         *
         *  @param  val_    Value used to form the serialised object.
         */
        template <class T, typename = typename std::enable_if_t<std::is_fundamental<T>::value>>
        inline Serial::Serial(const T val_) noexcept
          : _str(std::to_string(val_))
        {
        }

        /**
         *  Construct a serial object from a string object.
         *
         *  @param  str_    String used to form the serialised object.
         */
        inline Serial::Serial(const std::string& str_) noexcept
          : _str(str_)
        {
        }



        //  == OPERATORS ==
        //  -- Assignment --
        /**
         *  Set str_ to a serial object from a value of fundamental type.
         *
         *  @tparam T   Type to be serialised.
         *
         *  @param  val_    Value used to form the serialised object.
         *
         *  @return Reference to this object.
         */
        template <class T, typename = typename std::enable_if_t<std::is_fundamental<T>::value>>
        inline Serial& Serial::operator=(const T val_) noexcept
        {
            _str = std::to_string(val_);

            return (*this);
        }

        /**
         *  Set str_ to a string.
         *
         *  @param  str_    String used to form the serialised object.
         *
         *  @return Reference to this object.
         */
        inline Serial& Serial::operator=(const std::string& str_) noexcept
        {
            _str = str_;

            return (*this);
        }



        //  == METHODS ==
        //  -- Getters --
        template <class T>
        inline T Serial::parse() noexcept
        {
            std::stringstream stream(_str);
            T                 val;

            stream >> val;

            assert(!stream.fail());
            assert(stream.rdbuf()->in_avail() == 0);

            return (val);
        }

        template <class T>
        inline T Serial::parsable() noexcept
        {
            return (utl::parsable(_str));
        }



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_SERIAL_HPP
