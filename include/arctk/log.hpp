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
#include <arctk/log/message.hpp>
#include <arctk/log/term.hpp>
#include <arctk/log/verbose.hpp>



//  == MACROS ==
//  -- Logging --
#define LOG arc::log::Message(__FILE__, __func__, __LINE__) << "" //!< Log a standard message.
#ifdef VERBOSE
#define VERB arc::log::Message(__FILE__, __func__, __LINE__) << "" //!< Log a verbose message.
#else
#define VERB arc::log::Verbose() << "" //!< Ignore a verbose message.
#endif



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_HPP
