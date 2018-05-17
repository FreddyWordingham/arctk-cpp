/**
 *  @file   config.hpp
 *  @date   17/05/2018
 *  @author Freddy Wordingham
 *
 *  String utility functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_STRING_HPP
#define ARCTK_UTL_STRING_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <sstream>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace utl //! utility namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Properties --
        template <class T>
        inline bool parsable(const std::string& str_) noexcept;
        inline bool numerical(const std::string& str_) noexcept;



        //  == FUNCTIONS ==
        //  -- Properties --
        /**
         *  Determine if a given string can be converted to a given type.
         *
         *  @tparam T   Type to convert the string to.
         *
         *  @param  str_    String to be tested.
         *
         *  @return True if the string can be converted to the given type.
         */
        template <class T>
        inline bool parsable(const std::string& str_) noexcept
        {
            T                 result;
            std::stringstream stream(str_);

            stream >> result;
            stream >> std::ws;

            return (!stream.fail() && stream.eof());
        }

        /**
         *  Determine if a given string can be converted to an arithmetic type.
         *  If the string can be converted to a double, then it can be converted to any arithmetic type.
         *
         *  @param  str_    String to be tested.
         *
         *  @return True if the string can be converted to an arithmetic type.
         */
        inline bool numerical(const std::string& str_) noexcept
        {
            return (parsable<double>(str_));
        }



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_STRING_HPP
