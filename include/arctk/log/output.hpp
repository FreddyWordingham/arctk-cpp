/**
 *  @file   arctk/log/output.hpp
 *  @date   30/05/2018
 *  @author Freddy Wordingham
 *
 *  Console output logging class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_OUTPUT_HPP
#define ARCTK_LOG_OUTPUT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <cassert>
#include <sstream>

#include <arctk/log/ansi.hpp>
#include <arctk/log/term.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace log //! logging namespace
    {



        //  == CLASS ==
        /**
         *  Ansi escape code definitions.
         *  Codes are set for the platform during instantiation.
         */
        class Ansi
        {
            //  == FIELDS ==
          public:
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == OPERATORS ==
          public:
        };



        //  == INSTANTIATION --
        //  -- Constructors --



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_HPP
