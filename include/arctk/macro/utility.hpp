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



//  == MACROS ==
//  -- Manipulation --
/**
 *  Concate two given macros.
 *
 *  @param  x_  Left hand side macro to concate.
 *  @param  y_  Right hand side macro to concate.
 */
#define CONCAT(x_, y_) CONCAT_HELPER(x_, y_)

/**
 *  Concate helper macro.
 *
 *  @param  x_  Left hand side macro to concate.
 *  @param  y_  Right hand side macro to concate.
 */
#define CONCAT_HELPER(x_, y_) x_##y_


//  -- Naming --
/**
 *  Prefix the current line number to the given prefix to form a line name.
 *
 *  @param  prefix_ Prefix to attach line to.
 */
#define LINE_NAME(prefix_) CONCAT(prefix_, __LINE__)



//  == GUARD END ==
#endif // ARCTK_MACRO_UTILITY_HPP
