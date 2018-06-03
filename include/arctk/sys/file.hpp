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



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace sys //! system namespace
    {



        //  == CLASS ==
        /**
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


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::string& path() const noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --



        //  == METHODS ==
        //  -- Getters --
        inline const std::string& File::path() const noexcept
        {
            return (_path);
        }



    } // namespace sys
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SYS_FILE_HPP
