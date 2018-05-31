/**
 *  @file   arctk/log.hpp
 *  @date   30/05/2018
 *  @author Freddy Wordingham
 *
 *  Collection of logging classes and macros.
 */



//  == GUARD ==
#ifndef ARCTK_LOG_HPP
#define ARCTK_LOG_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/log/output.hpp>
#include <arctk/log/output/error.hpp>
#include <arctk/log/output/message.hpp>
#include <arctk/log/output/progress.hpp>
#include <arctk/log/output/verbose.hpp>
#include <arctk/log/output/warning.hpp>
#include <arctk/log/term.hpp>



//  == MACROS ==
//  -- Logging --
#ifdef LOG_LOCATION
#define LOG arc::log::output::Message(__FILE__, __func__, __LINE__) << ""                         //!< Log a standard message to standard output.
#define WARN arc::log::output::Warning(__FILE__, __func__, __LINE__) << ""                        //!< Log a warning message to standard output.
#define ERROR(exit_val_) arc::log::output::Error(__FILE__, __func__, __LINE__, (exit_val_)) << "" //!< Log an error message to standard output.
#ifdef LOG_VERBOSE
#define VERB arc::log::output::Message(__FILE__, __func__, __LINE__) << "" //!< Log a standard message to standard output.
#else
#define VERB arc::log::output::Verbose() << "" //!< Discard a verbose message to standard output.
#endif
#else
#define LOG arc::log::output::Message() << ""                       //!< Log a standard message to standard output.
#define WARN arc::log::output::Warning() << ""                      //!< Log a warning message to standard output.
#define ERROR(exit_val_) arc::log::output::Error((exit_val_)) << "" //!< Log an error message to standard output.
#ifdef LOG_VERBOSE
#define VERB arc::log::output::Message() << "" //!< Log a standard message to standard output.
#else
#define VERB arc::log::output::Verbose() << "" //!< Discard a verbose message to standard output.
#endif
#endif



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_HPP
