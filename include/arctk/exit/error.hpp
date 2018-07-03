/**
 *  @file   arctk/exit/error.hpp
 *  @date   03/07/2018
 *  @author Freddy Wordingham
 *
 *  Enumeration of all exit code error values.
 */



//  == GUARD ==
#ifndef ARCTK_EXIT_ERROR_HPP
#define ARCTK_EXIT_ERROR_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace exit //! exit codes namespace
    {
        namespace error //! error namespace
        {



            //  == CONSTANTS ==
            //  -- Contracts --
            constexpr const int PRE_CONDITION_FAILURE  = 110; //!< Pre-condition assertion failed.
            constexpr const int POST_CONDITION_FAILURE = 111; //!< Post-condition assertion failed.
            constexpr const int INVARIANT_FAILURE      = 112; //!< Invariant assertion failed.



        } // namespace error
    }     // namespace exit
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_EXIT_ERROR_HPP
