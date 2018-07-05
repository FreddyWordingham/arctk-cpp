/**
 *  @file   arctk/term/ansi.hpp
 *  @date   05/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection terminal ansi escape strings.
 */



//  == GUARD ==
#ifndef ARCTK_TERM_ANSI_HPP
#define ARCTK_TERM_ANSI_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace term //! terminal namespace
    {
        namespace ansi //! ansi namespace
        {



            //  == CONSTANTS ==
            //  -- Utility --
            constexpr const char* const RESET     = "\033[0;0m";        //!< Reset ansi options.
            constexpr const char* const OVERWRITE = "\n\033[A\33[2K\r"; //!< Overwrite the previous string.



        } // namespace ansi
    }     // namespace term
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_TERM_ANSI_HPP
