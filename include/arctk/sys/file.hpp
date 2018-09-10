/**
 *  @file   arctk/sys/file.hpp
 *  @date   10/09/2018
 *  @author Freddy Wordingham
 *
 *  System file managemet functions.
 */



//  == GUARD ==
#ifndef ARCTK_SYS_FILE_HPP
#define ARCTK_SYS_FILE_HPP



//  == IMPORTS ==
//  -- Std --
#include <string>
#ifdef __clang__
#include <experimental/filesystem>
#else
#include <filesystem>
#endif

//  -- Arctk --
#include <arctk/debug.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace sys //! system namespace
    {
        namespace file //! file namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Directories --
            inline void mkdir(const std::string& path_) noexcept;



            //  == FUNCTIONS ==
            //  -- Directories --
            inline void mkdir(const std::string& path_) noexcept
            {
                PRE(!path_.empty());

#ifdef __clang__
                std::experimental::filesystem::create_directories(path_);
#else
                std::filesystem::create_directories(path_);
#endif
            }



        } // namespace file
    }     // namespace sys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SYS_FILE_HPP
