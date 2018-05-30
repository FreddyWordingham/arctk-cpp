/**
 *  @file   arctk/log/ansi.hpp
 *  @date   30/05/2018
 *  @author Freddy Wordingham
 *
 *  Ansi escape code definition class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_ANSI_HPP
#define ARCTK_LOG_ANSI_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <string>
#if defined(__APPLE__) || defined(___unix__)
#include <unistd.h>
#endif



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace log //! logging namespace
    {



        //  == CLASS ==
        /**
         */
        struct Ansi
        {
            //  == FIELDS ==
          private:
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == OPERATORS ==
          public:
            //  == METHODS ==
          public:
        };



        //  == METHODS ==



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_ANSI_HPP
