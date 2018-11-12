/**
 *  @file   arctk/sys/file.hpp
 *  @date   22/10/2018
 *  @author Freddy Wordingham
 *
 *  System file functions.
 */



//  == GUARD ==
#ifndef ARCTK_SYS_FILE_HPP
#define ARCTK_SYS_FILE_HPP



//  == IMPORTS ==
//  -- Std --
#include <string>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace sys //! system namespace
    {
        namespace file //! file namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Reading --
            inline std::string read(const std::string& path_) noexcept;



        } // namespace file
    }     // namespace sys
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/sys/file.inl>



//  == GUARD END ==
#endif // ARCTK_SYS_FILE_HPP
