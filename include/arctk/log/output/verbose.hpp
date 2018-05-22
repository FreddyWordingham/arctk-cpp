/**
 *  @file   arctk/log/output/verbose.hpp
 *  @date   21/05/2018
 *  @author Freddy Wordingham
 *
 *  Standard console output verbose log class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_OUTPUT_VERBOSE_HPP
#define ARCTK_LOG_OUTPUT_VERBOSE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace log //! logging namespace
    {
        namespace output //! console output namespace
        {



            //  == CLASS ==
            /**
             *  Verbose logging class.
             *  Provides an object to stream to, which will do nothing upon destruction.
             */
            class Verbose
            {
                //  == OPERATORS ==
              public:
                //  -- Assignment --
                template <class T>
                inline const Verbose& operator<<(const T& /*unused*/) const noexcept;
            };



            //  == OPERATORS ==
            //  -- Assignment --
            /**
             *  Accept a value to the stream and discard it.
             *
             *  @return A const reference to this object.
             */
            template <class T>
            inline const Verbose& Verbose::operator<<(const T& /*unused*/) const noexcept
            {
                return (*this);
            }



        } // namespace output
    }     // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_VERBOSE_HPP
