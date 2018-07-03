/**
 *  @file   arctk/debug.hpp
 *  @date   02/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection of debugging functions and macros.
 */



//  == GUARD ==
#ifndef ARCTK_DEBUG_HPP
#define ARCTK_DEBUG_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug/invariant.hpp>
#include <arctk/debug/location.hpp>
#include <arctk/debug/postcondition.hpp>
#include <arctk/macro.hpp>



//  == MACROS ==
//  -- Location --
#ifdef NDEBUG
#define PRE(condition_) ((void)0)
#define POST(condition_) ((void)0)
#define INVAR(condition_) ((void)0)
#else

/**
 *  Define a pre-condition to be checked at function entrace.
 *
 *  @param  condition_  Condition to be checked.
 */
#define PRE(condition_)                                                                                           \
    if (!(condition_))                                                                                            \
    {                                                                                                             \
        std::cerr << "Pre-condition  : `" << (#condition_) << "` failed.\n";                                      \
        std::cerr << "Located at     :\n" << arc::debug::location::info(__FILE__, __LINE__, __func__, 2) << '\n'; \
    }

/**
 *  Define a post-condition to be checked at function exit.
 *
 *  @param  condition_  Condition to be checked.
 */
#define POST(condition_) arc::debug::PostCondition LINE_NAME(post) = arc::debug::PostCondition(__FILE__, __LINE__, __FUNCTION__, #condition_, [&]() { return (condition_); });

#define INVAR(condition_) arc::debug::Invariant LINE_NAME(invar) = arc::debug::Invariant<decltype(condition_)>(__FILE__, __LINE__, __FUNCTION__, #condition_, [&]() { return (condition_); });

#endif



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DEBUG_HPP
