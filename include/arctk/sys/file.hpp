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


            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION --
        //  -- Constructors --



        //  == METHODS ==
        //  -- Getters --



    } // namespace sys
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SYS_FILE_HPP
