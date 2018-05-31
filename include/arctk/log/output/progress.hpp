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
             *  Reset ansi escape codes and append a newline character.
             */
            inline Progress::~Progress() noexcept
            {
                *this << Term::instance().reset() << '\n';
            }



            //  == METHODS ==
            //  -- Setters --
            /**
             *  Set the colouring string of this message type.
             *
             *  @param  col_    Colouring string.
             */
            inline void Progress::set_col(const std::string& col_) noexcept
            {
                _col = col_;
            }



        } // namespace output
    }     // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_PROGRESS_HPP
