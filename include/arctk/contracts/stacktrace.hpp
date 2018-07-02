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
        //  -- Stacktracing --
        std::string stacktrace(const int skip = 1);



        //  == FUNCTIONS ==
        //  -- Stacktracing --
        std::string stacktrace(const int skip)
        {
            void*     callstack[128];
            const int max_num_frames = sizeof(callstack) / sizeof(callstack[0]);
            int       num_frames     = backtrace(callstack, max_num_frames);
            char**    symbols        = backtrace_symbols(callstack, num_frames);

            std::ostringstream trace_stream;
            for (int i = skip; i < num_frames; i++)
            {
                if (i != skip)
                {
                    trace_stream << '\n';
                }

                Dl_info info;
                if (dladdr(callstack[i], &info) && info.dli_sname)
                {
                    char* demangled = nullptr;
                    int   status    = -1;

                    if (info.dli_sname[0] == '_')
                    {
                        demangled = abi::__cxa_demangle(info.dli_sname, nullptr, nullptr, &status);
                    }

                    if (status == 0)
                    {
                        trace_stream << demangled;
                    }
                    else
                    {
                        if (info.dli_sname == nullptr)
                        {
                            trace_stream << symbols[i];
                        }
                        else
                        {
                            trace_stream << info.dli_sname;
                        }
                    }

                    free(demangled);
                }
                else
                {
                    trace_stream << symbols[i];
                }
            }

            free(symbols);

            if (num_frames == max_num_frames)
            {
                trace_stream << "\n[truncated]";
            }

            return (trace_stream.str());
        }



    } // namespace contracts
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_CONTRACTS_STACKTRACE_HPP