/**
 *  @file   arctk/log/output/progress.hpp
 *  @date   22/05/2018
 *  @author Freddy Wordingham
 *
 *  Standard console output progress log class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_OUTPUT_PROGRESS_HPP
#define ARCTK_LOG_OUTPUT_PROGRESS_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <cassert>
#include <sstream>

//  -- Arctk --
#include <arctk/log/ansi.hpp>
#include <arctk/log/output.hpp>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace log //! logging namespace
    {
        namespace output //! console output namespace
        {



            //  == CLASS ==
            /**
             *  Standard output progress logging.
             */
            class Progress : public Output
            {
                //  == FIELDS ==
              private:
                //  -- Timing --
                const uint64_t _update_delta; //!< Minimum microseconds between prints.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Progress(const uint64_t update_delta_) noexcept;
                inline Progress(const Progress&) = delete; //!< Deleted copy constructor.
                inline Progress(Progress&&)      = delete; //!< Deleted move constructor.

                //  -- Destructors --
                inline ~Progress() noexcept override;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline Progress& operator=(const Progress&) = delete; //!< Deleted copy operator. @return Reference to copied object.
                inline Progress& operator=(Progress&&) = delete;      //!< Deleted move operator. @return Reference to moved object.
            };



            //  == INSTANTIATION --
            //  -- Constructors --
            /**
             *  Construct a progress message which will only be printed if sufficient time has elapsed since the last print.
             *
             *  @param  update_delta_   Minimum time, in microseconds, between progress update prints.
             *
             *  @pre    update_delta_ must be positive.
             */
            inline Progress::Progress(const uint64_t update_delta_) noexcept
              : _update_delta(update_delta_)
            {
                assert(update_delta_ > 0);
            }


            //  -- Destructors --
            /**
             *  Report age of class.
             */
            inline Progress::~Progress() noexcept
            {
                *this << ANSI.yellow << " took: " << utl::time(static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - _construct_time).count()));
                *this << ANSI.reset << '\n';
            }



        } // namespace output
    }     // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_PROGRESS_HPP
