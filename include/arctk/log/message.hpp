/**
 *  @file   arctk/log/message.hpp
 *  @date   21/05/2018
 *  @author Freddy Wordingham
 *
 *  Message log base class class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_MESSAGE_HPP
#define ARCTK_LOG_MESSAGE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace log //! logging namespace
    {



        //  == CLASS ==
        class Message : public std::stringstream
        {
        };



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_MESSAGE_HPP
