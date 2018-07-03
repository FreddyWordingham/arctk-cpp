/**
 *  @file   arctk/errno.hpp
 *  @date   03/07/2018
 *  @author Freddy Wordingham
 *
 *  Enumeration of all error exit values.
 */



//  == GUARD ==
#ifndef ARCTK_ERRNO_HPP
#define ARCTK_ERRNO_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace errno //! error enumeration namespace
    {



        //  == CONSTANTS ==
        //  -- Contracts --
        constexpr const int PRE_CONDITION_FAILURE = 110; //!< Pre-condition assertion failed.



    } // namespace errno
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_ERRNO_HPP
