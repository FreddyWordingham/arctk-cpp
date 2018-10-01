/**
 *  @file   arctk/io/file.hpp
 *  @date   25/09/2018
 *  @author Freddy Wordingham
 *
 *  File functions.
 */



//  == GUARD ==
#ifndef ARCTK_IO_FILE_HPP
#define ARCTK_IO_FILE_HPP



//  == IMPORTS ==
//  -- Std --
#include <filesystem>
#include <fstream>
#include <string>

//  -- Arctk --
#include <arctk/debug.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace io //! input/output namespace
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
                PRE(!path_.empty());

                std::ifstream file(path_);

                if (!file.is_open())
                {
                    std::cerr << "Unable to parse contents of file.\n"
                              << "Unable to open file: `" << path_ << "`.\n";

                    std::exit(exit::error::FILE_OPEN_FAILED);
                }

                return (std::string((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>())););
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
                PRE(!path_.empty());

                std::filesystem::create_directories(path_);
            }



        } // namespace file
    }     // namespace io
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IO_FILE_HPP
