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
#include <arctk/debug/location.hpp>
#include <arctk/debug/postcondition.hpp>
#include <arctk/macro.hpp>



//  == MACROS ==
//  -- Location --
#ifdef NDEBUG
#define PRE(condition_) ((void)0)
#define POST(condition_) ((void)0)
#else
#define PRE(condition_)                                                                                  \
    if (!(condition_))                                                                                   \
    {                                                                                                    \
        std::cout << "Pre-condition  : `" << (#condition_) << "` failed.\n";                             \
        std::cout << "Located at     :\n" << arc::debug::location(__FILE__, __LINE__, __func__) << '\n'; \
    }
#define POST(condition_) arc::debug::PostCondition UNIQUE_NAME(postcondition) = arc::debug::postcondition(__FILE__, __LINE__, __FUNCTION__, "Post-condition failure:" #condition_, [&]() { return (condition_); });
#endif



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DEBUG_HPP
