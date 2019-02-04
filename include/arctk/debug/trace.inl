//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/debug/trace.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cstdlib>
#include <cxxabi.h>
#include <dlfcn.h>
#include <execinfo.h>
#include <string>
#include <vector>



//  == NAMESPACE ==
namespace arc
{
    namespace debug
    {



        //  == FUNCTIONS ==
        //  -- Stacktrace --
        inline std::vector<std::string> stacktrace() noexcept
        {
            void*        callstack[128];
            const int    max_num_frames = sizeof(callstack) / sizeof(callstack[0]);
            const int    num_frames     = backtrace(callstack, max_num_frames);
            char** const symbols        = backtrace_symbols(callstack, num_frames);

            std::vector<std::string> trace{};
            for (int i = 1; i < (num_frames - 1); ++i)
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

                    if (status == 0)
                    {
                        trace.emplace_back(demangled);
                    }
                    else
                    {
                        if (info.dli_sname == nullptr)
                        {
                            trace.emplace_back(symbols[i]);
                        }
                        else
                        {
                            trace.emplace_back(info.dli_sname);
                        }
                    }

                    std::free(demangled);
                }
                else
                {
                    trace.emplace_back(symbols[i]);
                }
            }

            std::free(symbols);

            if (num_frames == max_num_frames)
            {
                trace.emplace_back("\n[truncated]");
            }

            return (trace);
        }



    } // namespace debug
} // namespace arc
