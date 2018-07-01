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
            char      buffer[1024];
            int       num_frames = backtrace(callstack, max_num_frames);
            char**    symbols    = backtrace_symbols(callstack, num_frames);

            std::ostringstream trace_stream;
            for (int i = skip; i < num_frames; i++)
            {
                Dl_info info;
                if (dladdr(callstack[i], &info) && info.dli_sname)
                {
                    char* demangled = nullptr;
                    int   status    = -1;

                    if (info.dli_sname[0] == '_')
                    {
                        demangled = abi::__cxa_demangle(info.dli_sname, nullptr, nullptr, &status);
                    }

                    snprintf(buffer, sizeof(buffer), "%-3d %*p %s + %zd\n", i, static_cast<int>(2 + sizeof(void*) * 2), callstack[i], status == 0 ? demangled : info.dli_sname == nullptr ? symbols[i] : info.dli_sname,
                             static_cast<char*>(callstack[i]) - static_cast<char*>(info.dli_saddr));

                    free(demangled);
                }
                else
                {
                    snprintf(buffer, sizeof(buffer), "%-3d %*p %s\n", i, int(2 + sizeof(void*) * 2), callstack[i], symbols[i]);
                }

                trace_stream << buffer;
            }

            free(symbols);

            if (num_frames == max_num_frames)
            {
                trace_stream << "[truncated]\n";
            }

            return (trace_stream.str());
        }



    } // namespace contracts
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_CONTRACTS_STACKTRACE_HPP