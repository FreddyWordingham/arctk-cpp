/**
 *  @file   arctk/sys/file.hpp
 *  @date   05/07/2018
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
          private:
            //  -- Path --
            const std::string _path; //!< Full path to the file.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit File(const std::string& path_) noexcept;
            inline File(const File&) = default; //!< Defaulted copy constructor.
            inline File(File&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~File() noexcept = 0;


            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION --
        //  -- Constructors --
        /**
         *  Construct a handle to a file at a given path.
         *
         *  @param  path_   Path to file.
         */
        inline File::File(const std::string& path_) noexcept
          : _path(path_)
        {
        }


        //  -- Destructors --
        inline File::~File() noexcept = default;



        //  == METHODS ==
        //  -- Getters --



    } // namespace sys
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SYS_FILE_HPP
