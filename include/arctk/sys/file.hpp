/**
 *  @file   arctk/sys/file.hpp
 *  @date   03/06/2018
 *  @author Freddy Wordingham
 *
 *  File system base class.
 */



//  == GUARD ==
#ifndef ARCTK_SYS_FILE_HPP
#define ARCTK_SYS_FILE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <string>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace sys //! system namespace
    {



        //  == CLASS ==
        /**
         *  File handling base class.
         */
        class File
        {
            //  == FIELDS ==
          protected:
            //  -- Path --
            const std::string _path; //!< Full path to the file.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit File(const std::string& path_) noexcept;
            inline File(const File&) noexcept = default; //!< Defaulted copy constructor.
            inline File(File&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~File() noexcept = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline File& operator=(const File&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline File& operator=(File&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::string& path() const noexcept;
            inline std::string        filename() const noexcept;
            inline std::string        extension() const noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        inline File::File(const std::string& path_) noexcept
          : _path(path_)
        {
        }


        //  -- Destructors --
        inline File::~File() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        inline const std::string& File::path() const noexcept
        {
            return (_path);
        }

        inline std::string File::filename() const noexcept
        {
            size_t slash_pos = _path.find_last_of('/');

            return ((slash_pos == std::string::npos) ? _path : _path.substr(slash_pos + 1, std::string::npos));
        }

        inline std::string File::extension() const noexcept
        {
            size_t dot_pos = _path.find_last_of('.');

            return ((dot_pos == std::string::npos) ? _path : _path.substr(dot_pos + 1, std::string::npos));
        }



    } // namespace sys
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SYS_FILE_HPP
