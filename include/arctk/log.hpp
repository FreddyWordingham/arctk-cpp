/**
 *  @file   arctk/log.hpp
 *  @date   21/05/2018
 *  @author Freddy Wordingham
 *
 *  Collection of logging macros.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_HPP
#define ARCTK_LOG_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Arctk --
#include <arctk/log/ansi.hpp>
#include <arctk/log/cerr.hpp>
#include <arctk/log/cout.hpp>
#include <arctk/log/cout/message.hpp>
#include <arctk/log/term.hpp>



//  == MACROS ==
//  -- Logging --
#define LOG arc::log::cout::Message(__FILE__, __func__, __LINE__) << "" //!< Log a standard message to console output.



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_HPP
