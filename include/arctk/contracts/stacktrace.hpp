/**
 *  @file   arctk/contracts/stacktrace.hpp
 *  @date   01/07/2018
 *  @author Freddy Wordingham
 *
 *  Stacktracing functions.
 */



//  == GUARD ==
#ifndef ARCTK_CONTRACTS_STACKTRACE_HPP
#define ARCTK_CONTRACTS_STACKTRACE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cstdio>
#include <cstdlib>
#include <cxxabi.h>
#include <dlfcn.h>
#include <execinfo.h>
#include <sstream>
#include <string>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace contracts //! contracts namespace
    {



        //  == FUNCTION PROTOTYPES ==



        //  == FUNCTIONS ==



    } // namespace contracts
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_CONTRACTS_STACKTRACE_HPP
