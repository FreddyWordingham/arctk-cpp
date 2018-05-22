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

                //  -- Buffer --
                std::stringstream _buffer;


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

                //  -- Io --
                template <class T>
                inline Progress& operator<<(const T& val_) noexcept
                {
                    _buffer << val_;

                    return (*this);
                }
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
                static std::chrono::high_resolution_clock::time_point static_last_update = std::chrono::high_resolution_clock::now();
                const std::chrono::high_resolution_clock::time_point  cur_time           = std::chrono::high_resolution_clock::now();

                if (static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::microseconds>(cur_time - static_last_update).count()) >= _update_delta)
                {
                    static_last_update = cur_time;

                    *this << _buffer.str();

                    *this << ANSI.reset << ANSI.overwrite;
                }
            }



        } // namespace output
    }     // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_PROGRESS_HPP
