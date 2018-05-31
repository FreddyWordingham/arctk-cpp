/**
 *  @file   arctk/log/output/progress.hpp
 *  @date   31/05/2018
 *  @author Freddy Wordingham
 *
 *  Progress message log class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_OUTPUT_PROGRESS_HPP
#define ARCTK_LOG_OUTPUT_PROGRESS_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/log/output.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace log //! logging namespace
    {
        namespace output //! console output namespace
        {



            //  == CLASS ==
            /**
             *  Progress update message logging.
             */
            class Progress : public Output
            {
                //  == FIELDS ==
              public:
                //  -- Colour --
                static std::string _col;
                static uint64_t    _update_delta; //!< Minimum microseconds between prints.

                //  -- Buffer --
                const std::string _buff; //!< Update string.
                const douvle      _frac; //!< Update progress fraction.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Progress(const std::string& str_, double frac_) noexcept;
                inline Progress(const Progress&) = delete; //!< Deleted copy constructor.
                inline Progress(Progress&&)      = delete; //!< Deleted move constructor.

                //  -- Destructors --
                inline ~Progress() noexcept override;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline Progress& operator=(const Progress&) = delete; //!< Deleted copy operator. @return Reference to copied object.
                inline Progress& operator=(Progress&&) = delete;      //!< Deleted move operator. @return Reference to moved object.


                //  == METHODS ==
              public:
                //  -- Setters --
                inline static void set_col(const std::string& col_) noexcept;
            };



            //  == INSTANTIATION --
            //  -- Colour --
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
            std::string Progress::_col = ansi::FG_WHITE;
#pragma clang diagnostic pop


            //  -- Constructors --
            /**
             *  Construct a progress message which will only be printed if sufficient time has elapsed since the last print.
             *
             *  @param  str_    Update string.
             *  @param  frac_   Update fraction complete.
             *
             *  @pre    str_ must not be empty.
             *  @pre    frac_ must be non-negative.
             */
            inline Progress::Progress(const std::string& str_, const double frac_) noexcept
              : Output()
              , _str(str_)
              , _frac(frac_)
            {
                assert(!str_.empty());
                assert(frac_ >= 0.0);
            }


            //  -- Destructors --
            /**
             *  If more, or equal, time has passed than the specified update_delta_, then print the update string and fraction.
             */
            inline Progress::~Progress() noexcept
            {
                static std::chrono::high_resolution_clock::time_point static_last_update = std::chrono::high_resolution_clock::now();
                const std::chrono::high_resolution_clock::time_point  cur_time           = std::chrono::high_resolution_clock::now();

                if (static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::microseconds>(cur_time - static_last_update).count()) >= _update_delta)
                {
                    static_last_update = cur_time;

                    *this << _str << " : " << (_frac * 100.0) << "%";

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
