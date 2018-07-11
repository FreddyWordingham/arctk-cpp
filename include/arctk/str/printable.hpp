/**
 *  @file   arctk/str/printable.hpp
 *  @date   05/07/2018
 *  @author Freddy Wordingham
 *
 *  Printable base class.
 */



//  == GUARD ==
#ifndef ARCTK_STR_PRINTABLE_HPP
#define ARCTK_STR_PRINTABLE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <fstream>
#include <string>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace str //! string namespace
    {



        //  == CLASS ==
        /**
         *  Printable interface class.
         */
        class Printable
        {
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Printable() noexcept                 = default;
            inline Printable(const Printable&) noexcept = default; //!< Defaulted copy constructor.
            inline Printable(Printable&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Printable() noexcept = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Printable& operator=(const Printable&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Printable& operator=(Printable&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Printing --
            virtual std::string str() noexcept = 0; //!< Create a human readable string of the object.   @return Human readable string of the object.

            //  -- Saving --
            inline void save(const std::string& path_) noexcept;
        };



        //  == METHODS ==
        //  -- Saving --
        /**
         *  Save the output of str to a file.
         *
         *  @param  path_   Path to the output file.
         */
        inline void Printable::save(const std::string& path_) noexcept
        {
            std::ofstream file(path_);

            file << str() << '\n';
        }



    } // namespace str
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_STR_PRINTABLE_HPP
