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
#include <arctk/log/output.hpp>
#include <arctk/log/output/error.hpp>
#include <arctk/log/output/message.hpp>
#include <arctk/log/output/verbose.hpp>
#include <arctk/log/term.hpp>



//  == MACROS ==
//  -- Logging --
#define LOG arc::log::output::Message(__FILE__, __func__, __LINE__) << ""                         //!< Log a standard message to console output.
#define ERROR(exit_val_) arc::log::output::Error(__FILE__, __func__, __LINE__, (exit_val_)) << "" //!< Log an error message to console output.



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_HPP
