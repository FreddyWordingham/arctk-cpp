/**
 *  @file   arctk/log/output/verbose.hpp
 *  @date   31/05/2018
 *  @author Freddy Wordingham
 *
 *  Verbose message log class.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_OUTPUT_VERBOSE_HPP
#define ARCTK_LOG_OUTPUT_VERBOSE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace log //! logging namespace
    {
        namespace output //! console output namespace
        {



            //  == CLASS ==
            /**
             *  Verbose message logging.
             *  Provides an object to stream to, which will do nothing upon destruction.
             */
            class Verbose
            {
                //  == OPERATORS ==
              public:
                template <typename T>
                inline const Verbose& operator<<(const T& /*unused*/) const noexcept;
            };



        } // namespace output
    }     // namespace log
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_OUTPUT_VERBOSE_HPP
