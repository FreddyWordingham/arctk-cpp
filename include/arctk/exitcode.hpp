/**
 *  @file   arctk/exitcode.hpp
 *  @date   03/07/2018
 *  @author Freddy Wordingham
 *
 *  Enumeration of all exit code values.
 */



//  == GUARD ==
#ifndef ARCTK_EXITCODE_HPP
#define ARCTK_EXITCODE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/exitcode/error.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace exitcode //! exit codes namespace
    {



        //  == CONSTANTS ==
        //  -- Contracts --
        constexpr const int PRE_CONDITION_FAILURE  = 110; //!< Pre-condition assertion failed.
        constexpr const int POST_CONDITION_FAILURE = 111; //!< Post-condition assertion failed.
        constexpr const int INVARIANT_FAILURE      = 112; //!< Invariant assertion failed.



    } // namespace exitcode
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_EXITCODE_HPP
