/**
 *  @file   arctk/log/warning.hpp
 *  @date   21/05/2018
 *  @author Freddy Wordingham
 *
 *  Warning log class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_WARNING_HPP
#define ARCTK_LOG_WARNING_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <sstream>

//  -- Arctk --
#include <arctk/log/ansi.hpp>
#include <arctk/log/term.hpp>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace log //! logging namespace
    {



        //  == CLASS ==
        /**
         */
        class Warning : public std::stringstream
        {
        };



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_WARNING_HPP
