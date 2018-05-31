/**
 *  @file   arctk/log/output/stopwatch.hpp
 *  @date   31/05/2018
 *  @author Freddy Wordingham
 *
 *  Stopwatch timer log class.
 */


//  == GUARD ==
#ifndef ARCTK_LOG_OUTPUT_STOPWATCH_HPP
#define ARCTK_LOG_OUTPUT_STOPWATCH_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <cassert>
#include <chrono>

//  -- Arctk --



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace log //! logging namespace
    {
        namespace output //! console output namespace
        {



            //  == CLASS ==
            /**
             *  Standard output stopwatch logging.
             *  Prints wall clock lifetime of object upon destruction.
             */
            class Stopwatch : public Output
            {
                //  == FIELDS ==
              private:
                //  -- Colour --
                static std::string _col; //!< String used to colour this type of message.

                //  -- Timing --
                const std::chrono::high_resolution_clock::time_point _construct_time; //!< Construction time.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Stopwatch(const std::string& file_, const std::string& func_, int line_, const std::string& str_) noexcept;
                inline Stopwatch(const Stopwatch&) = delete; //!< Deleted copy constructor.
                inline Stopwatch(Stopwatch&&)      = delete; //!< Deleted move constructor.

                //  -- Destructors --
                inline ~Stopwatch() noexcept override;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline Stopwatch& operator=(const Stopwatch&) = delete; //!< Deleted copy operator. @return Reference to copied object.
                inline Stopwatch& operator=(Stopwatch&&) = delete;      //!< Deleted move operator. @return Reference to moved object.
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
             *  @pre    line_ must be positive.
             *  @pre    str_ must not be empty.
             */
            inline Stopwatch::Stopwatch(const std::string& file_, const std::string& func_, const int line_, const std::string& str_) noexcept
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
            inline Stopwatch::~Stopwatch() noexcept
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
#endif // ARCTK_LOG_OUTPUT_STOPWATCH_HPP
