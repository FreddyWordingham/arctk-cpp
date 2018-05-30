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
          private:
            //  -- Writing --
            std::mutex _write_guard; //!< Terminal write guard.


            //  == INSTANTIATION ==
          public:
            //  -- Singleton --
            inline static Term& instance() noexcept;

          private:
            //  -- Constructors --
            //            inline Term() noexcept;


            //  == METHODS ==
          public:
            //  -- Output --
            inline void cout(const std::string& str_) noexcept;
            inline void cerr(const std::string& str_) noexcept;
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



        //  == METHODS ==
        //  -- Output --
        /**
         *  Write a string to the standard output.
         *
         *  @param  str_    String to be written.
         */
        inline void Term::cout(const std::string& str_) noexcept
        {
            std::lock_guard<std::mutex> write_lock(_write_guard);

            std::cout << str_;
        }

        /**
         *  Write a string to the standard error.
         *
         *  @param  str_    String to be written.
         */
        inline void Term::cerr(const std::string& str_) noexcept
        {
            std::lock_guard<std::mutex> write_lock(_write_guard);

            std::cerr << str_;
        }



    } // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_TERM_HPP
