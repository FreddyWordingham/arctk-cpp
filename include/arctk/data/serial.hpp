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
    namespace data //! data namespace
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
            template <class T, typename = typename std::enable_if<std::is_fundamental<T>::value, T>::type>
            inline explicit Serial(T val_) noexcept;
            inline explicit Serial(const std::string& str_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            template <class T, typename = typename std::enable_if<std::is_fundamental<T>::value, T>::type>
            inline Serial& operator=(T val_) noexcept;
            inline Serial& operator=(const std::string& str_) noexcept;
            inline Serial& operator=(const char* c_str_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline std::string str() noexcept;
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
        template <class T, typename = typename std::enable_if<std::is_fundamental<T>::value, T>::type>
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
        template <class T, typename = typename std::enable_if<std::is_fundamental<T>::value, T>::type>
        inline Serial& Serial::operator=(T val_) noexcept
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

        /**
         *  Set str_ to a c-style string.
         *
         *  @param  c_str_  C-style string used to form the serialised object.
         *
         *  @return Reference to this object.
         */
        inline Serial& Serial::operator=(const char* c_str_) noexcept
        {
            _str = std::string(c_str_);

            return (*this);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the value of _str.
         *
         *  @return Copt of _str.
         */
        inline std::string Serial::str() noexcept
        {
            return (_str);
        }

        /**
         *  Convert the serial type to another type.
         *
         *  @tparam T   Type to convert the serial type to.
         *
         *  @pre    _str must be parsable to type T.
         *
         *  @return Converted value.
         */
        template <class T>
        inline T Serial::parse() noexcept
        {
            assert(parsable<T>());

            return (utl::parse<T>(_str));
        }

        /**
         *  Get the serial type string.
         *
         *  @return Copy of _str.
         */
        template <>
        inline std::string Serial::parse() noexcept
        {
            return (_str);
        }

        /**
         *  Determine if the serial object is parsable to a type.
         *
         *  @tparam T   Type to test.
         *
         *  @return True if _str can be parsed to type T.
         */
        template <class T>
        inline T Serial::parsable() noexcept
        {
            return (utl::parsable<T>(_str));
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_SERIAL_HPP
