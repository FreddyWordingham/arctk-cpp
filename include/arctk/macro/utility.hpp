/**
 *  @file   arctk/macro/utility.hpp
 *  @date   03/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection of utility macros.
 */



//  == GUARD ==
#ifndef ARCTK_MACRO_UTILITY_HPP
#define ARCTK_MACRO_UTILITY_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == MACROS ==
//  -- Manipulation --
#define CONCAT(x_, y_) CONCAT_HELPER(x_, y_)
#define CONCAT_HELPER(x_, y_) x_##y_

//  -- Naming --
#define LINE_NAME(prefix_) CONCAT(prefix_, __LINE__)



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MACRO_UTILITY_HPP
