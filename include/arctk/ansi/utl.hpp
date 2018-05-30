/**
 *  @file   arctk/ansi/utl.hpp
 *  @date   31/05/2018
 *  @author Freddy Wordingham
 *
 *  Ansi utility constants.
 */



//  == GUARD ==
#ifndef ARCTK_ANSI_UTL_HPP
#define ARCTK_ANSI_UTL_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace ansi //! ansi namespace
    {



        //  == CONSTANTS ==
        constexpr const char* const RESET     = "\033[0;0m";        //!< Reset ansi options.
        constexpr const char* const OVERWRITE = "\n\033[A\33[2K\r"; //!< Overwrite the previous string.



    } // namespace ansi
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_ANSI_UTL_HPP
