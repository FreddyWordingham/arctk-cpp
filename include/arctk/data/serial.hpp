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
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a serial object from a fundamental type.
         *
         *  @param  val_    Value used to form the serialised object.
         */
        template <class T, typename = typename std::enable_if_t<std::is_fundamental<T>::value>>
        inline Serial::Serial(const T val_) noexcept
          : _str(std::to_string(val_))
        {
        }

        inline Serial::Serial(const std::string& str_) noexcept
          : _str(str_)
        {
        }


    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_SERIAL_HPP
