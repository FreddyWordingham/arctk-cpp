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
            //  -- Writing --
            std::mutex _write_guard; //!< Terminal write guard.


            //  == INSTANTIATION ==
          public:
            //  -- Singleton --
            inline static Term& instance() noexcept;

          private:
            //  -- Constructors --
            inline Term() noexcept;
        };



        //  == INSTANTIATION --
        //  -- Singleton --
        /**
         *  Term singleton getter method.
         *
         *  @return Reference to the static term instance.
         */
        inline Term& Term::instance() noexcept
        {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexit-time-destructors"
            static Term static_term;
#pragma clang diagnostic pop

            return (static_term);
        }



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_TERM_HPP
