/**
 *  @file   arctk/log/output/message.hpp
 *  @date   30/05/2018
 *  @author Freddy Wordingham
 *
 *  Standard console output message log class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_OUTPUT_MESSAGE_HPP
#define ARCTK_LOG_OUTPUT_MESSAGE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <cassert>
#include <sstream>

#include <arctk/log/ansi.hpp>
#include <arctk/log/output.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace log //! logging namespace
    {
        namespace output //! console output namespace
        {



            //  == CLASS ==
            /**
             *  Standard output message logging.
             */
            class Message : public Output
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --

                //  -- Destructors --


                //  == OPERATORS ==
              public:
                //  -- Assignment --
            };



            //  == INSTANTIATION --
            //  -- Constructors --
            //  -- Destructors --



        } // namespace output
    }     // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_MESSAGE_HPP
