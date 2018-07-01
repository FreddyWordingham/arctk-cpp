/**
 *  @file   arctk/contracts.hpp
 *  @date   01/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection of contract macros.
 */



//  == GUARD ==
#ifndef ARCTK_CONTRACTS_HPP
#define ARCTK_CONTRACTS_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <iostream>

//  -- Arctk --
#include <arctk/contracts/stacktrace.hpp>



//  == MACROS ==
//  -- Contracts --
#ifdef NDEBUG
#define PRE(condition_) ((void)0)
#else
#define PRE(condition_)                                                     \
    if (!(condition_))                                                      \
    {                                                                       \
        std::cout << "Pre-condition : `" << (#condition_) << "` failed.\n"; \
        std::cout << "File          : " << __FILE__ << '\n';                \
        std::cout << "Line          : " << __LINE__ << '\n';                \
        std::cout << "Function      : " << __func__ << '\n';                \
        std::cout << "Stacktrace ---- \n" << contracts::stacktrace();       \
    }
#endif



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_CONTRACTS_HPP
