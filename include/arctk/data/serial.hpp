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

            //  == OPERATORS ==
          public:
        };



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_SERIAL_HPP
