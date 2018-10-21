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
#include <cassert>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <istream>
#include <string>

//  -- Arctk --
#include <arctk/exit/error.hpp>



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

            //  -- Directories --
            inline void mkdir(const std::string& path_) noexcept;



            //  == FUNCTIONS ==
            //  -- Reading --
            /**
             *  Read the contents of a file at a given path into a string.
             *
             *  @param  path_   Path to the file to be read.
             *
             *  @pre    path_ may not be empty.
             *
             *  @return Contents of the file in a string.
             */
            inline std::string read(const std::string& path_) noexcept
            {
                assert(!path_.empty());

                std::ifstream file(path_);

                if (!file.is_open())
                {
                    std::cerr << "Unable to parse contents of file.\n"
                              << "Unable to open file: `" << path_ << "`.\n";

                    std::exit(exit::error::FILE_OPEN_FAILED);
                }

                return (std::string((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>())));
            }


            //  -- Directories --
            /**
             *  Create a directory at the given path.
             *
             *  @param  path_   Path to the directory to create.
             *
             *  @pre    path_ may not be empty.
             */
            inline void mkdir(const std::string& path_) noexcept
            {
                assert(!path_.empty());

                std::filesystem::create_directories(path_);
            }



        } // namespace file
    }     // namespace sys
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SYS_FILE_HPP
