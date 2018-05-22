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
             *  Message will be overwritten with next print.
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
                inline Progress(const std::string& file_, const std::string& func_, int line_, const std::string& str_) noexcept;
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
             *  Construct a stopwatch object which, when destructed, will write its age.
             *
             *  @param  file_   File location of the message.
             *  @param  func_   Function location of the message.
             *  @param  line_   Line location of the message.
             *  @param  str_    String prepended to lifetime report message.
             *
             *  @pre    file_ must not be empty.
             *  @pre    func_ must not be empty.
             *  @pre    line_ must be greater than zero.
             *  @pre    str_ must not be empty.
             */
            inline Progress::Progress(const std::string& file_, const std::string& func_, const int line_, const std::string& str_) noexcept
              : Output(file_, func_, line_)
              , _construct_time(std::chrono::high_resolution_clock::now())
            {
                assert(!file_.empty());
                assert(!func_.empty());
                assert(line_ > 0);
                assert(!str_.empty());

                *this << ANSI.yellow << str_;
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
