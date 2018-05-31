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
#include <arctk/log/output.hpp>
#include <arctk/log/output/message.hpp>
#include <arctk/log/output/warning.hpp>
#include <arctk/log/term.hpp>



//  == MACROS ==
#ifdef LOG_LOCATION
#define LOG arc::log::output::Message(__FILE__, __func__, __LINE__) << "" //!< Log a standard message to console output.
#else
#define LOG arc::log::output::Message() << "" //!< Log a standard message to console output.
#endif



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_LOG_HPP
