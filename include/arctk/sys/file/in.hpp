/**
 *  @file   arctk/sys/file/in.hpp
 *  @date   05/07/2018
 *  @author Freddy Wordingham
 *
 *  Input file class.
 */



//  == GUARD ==
#ifndef ARCTK_SYS_FILE_IN_HPP
#define ARCTK_SYS_FILE_IN_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == Base ==
//  -- Arctk --
#include <arctk/sys/file.hpp>



//  == IMPORTS ==
//  -- Std --



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace sys //! system namespace
    {
        namespace file //! file namespace
        {



            //  == CLASS ==
            /**
             *  Input file class.
             */
            class In : public File
            {
                //  == FIELDS ==
              private:
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



        } // namespace file
    }     // namespace sys
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SYS_FILE_IN_HPP
