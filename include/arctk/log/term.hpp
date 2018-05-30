/**
 *  @file   arctk/log/term.hpp
 *  @date   30/05/2018
 *  @author Freddy Wordingham
 *
 *  Terminal logger class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_TERM_HPP
#define ARCTK_LOG_TERM_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace log //! logging namespace
    {



        //  == CLASS ==
        /**
         *  Terminal access class.
         *  Singleton object.
         *  Provides thread-safe terminal logging.
         */
        class Term
        {
            //  == FIELDS ==
          public:
            //  == INSTANTIATION ==
          public:
            //  -- Singleton --
            inline static const Term& instance() noexcept;

          private:
            //  -- Constructors --
            inline Term() noexcept;
        };



        //  == INSTANTIATION --
        //  -- Constructors --



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_TERM_HPP
