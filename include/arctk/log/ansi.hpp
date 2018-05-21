/**
 *  @file   arctk/log/message.hpp
 *  @date   21/05/2018
 *  @author Freddy Wordingham
 *
 *  Ansi escape code definition class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_ANSI_HPP
#define ARCTK_LOG_ANSI_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <string>



//  == NAMESPACE ==
namespace arc //! arc namespace
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
            //  -- General --
            const std::string reset; //!< Reset ansi settings to default.


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
#endif // ARCTK_LOG_ANSI_HPP
