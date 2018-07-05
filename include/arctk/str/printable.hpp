/**
 *  @file   arctk/str/printable.hpp
 *  @date   05/07/2018
 *  @author Freddy Wordingham
 *
 *  Printable class.
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
    namespace sys //! system namespace
    {



        //  == CLASS ==
        /**
         *  Printable interface class.
         */
        class Printable
        {
            //  == INSTANTIATION ==
          public:
            //  -- Destructors --
            virtual inline ~Printable() noexcept = 0;


            //  == METHODS ==
          public:
            //  -- Printing --
            virtual std::string str() noexcept = 0;

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



    } // namespace sys
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_STR_PRINTABLE_HPP
