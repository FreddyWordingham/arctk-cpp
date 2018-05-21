/**
 *  @file   arctk/log/message.hpp
 *  @date   21/05/2018
 *  @author Freddy Wordingham
 *
 *  Message log class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_MESSAGE_HPP
#define ARCTK_LOG_MESSAGE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <sstream>



//  == NAMESPACE ==
namespace arc
{
    namespace log
    {



        //  == CLASS ==
        /**
         *  Message logging class.
         */
        class Message : public std::stringstream
        {
            //  == FIELDS ==
          private:
            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == OPERATORS ==
          private:
            //  == METHODS ==
          public:
            //  -- Getters --
        };



        //  == INSTANTIATION --
        //  -- Constructors --



        //  == OPERATORS ==



        //  == METHODS ==
        //  -- Getters --



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_MESSAGE_HPP
