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
#include <fstream>
#include <string>



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



            //  == FUNCTIONS ==
            //  -- Reading --
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

                std::string str;

                file.seekg(0, std::ios::end);
                str.reserve(static_cast<size_t>(file.tellg()));
                file.seekg(0, std::ios::beg);

                str.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

                return (str);
            }



        } // namespace file
    }     // namespace io
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_IO_FILE_HPP
