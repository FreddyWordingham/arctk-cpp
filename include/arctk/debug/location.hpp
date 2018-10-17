/**
 *  @file   arctk/debug/location.hpp
 *  @date   02/07/2018
 *  @author Freddy Wordingham
 *
 *  Location debug functions.
 */



//  == GUARD ==
#ifndef ARCTK_DEBUG_LOCATION_HPP
#define ARCTK_DEBUG_LOCATION_HPP



//  == IMPORTS ==
//  -- Std --
#include <cstdio>
#include <cstdlib>
#include <cxxabi.h>
#include <dlfcn.h>
#include <execinfo.h>
#include <sstream>
#include <string>
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace debug //! debugging namespace
    {
        namespace location //! location namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Stacktracing --
            inline std::vector<std::string> stacktrace(int skip_ = 1) noexcept;

            //  -- Location --
            inline std::string info(const std::string& file_, int line_, const std::string& func_, int skip_ = 1) noexcept;



            //  == FUNCTIONS ==
            //  -- Stacktracing --
            /**
             *  Produce a stacktrace string for the current location.
             *
             *  @param  skip_   Number of stacks to skip before creating the location.
             *
             *  @return Vector of stack strings.
             */
            inline std::vector<std::string> stacktrace(const int skip_) noexcept
            {
                void*     callstack[128];
                const int max_num_frames = sizeof(callstack) / sizeof(callstack[0]);
                int       num_frames     = backtrace(callstack, max_num_frames);
                char**    symbols        = backtrace_symbols(callstack, num_frames);

                std::vector<std::string> trace;
                for (int i = skip_; i < (num_frames - 1); i++)
                {
                    Dl_info info;
                    if ((dladdr(callstack[i], &info) != 0) && (info.dli_sname != nullptr))
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

                        free(demangled); // NOLINT
                    }
                    else
                    {
                        trace.emplace_back(symbols[i]);
                    }
                }

                free(symbols); // NOLINT

                if (num_frames == max_num_frames)
                {
                    trace.emplace_back("\n[truncated]");
                }

                return (trace);
            }


            //  -- Location --
            /**
             *  Create an information print of the current location.
             *
             *  @param  file_   File string of the call location.
             *  @param  line_   Line of the call location.
             *  @param  func_   Function string of the call location.
             *  @param  skip_   Number of stacks to skip before creating the location stacktrace.
             *
             *  @return Information print of the current location.
             */
            inline std::string info(const std::string& file_, const int line_, const std::string& func_, const int skip_) noexcept
            {
                std::ostringstream location;

                location << "File : " << file_ << '\n';
                location << "Line : " << line_ << '\n';
                location << "Func : " << func_ << '\n';
                location << "Stack: ";

                const std::vector<std::string> stack = stacktrace(skip_);
                for (size_t i = 0; i < stack.size(); ++i)
                {
                    if (i != 0)
                    {
                        location << "\n       ";
                    }

                    location << stack[i];
                }

                return (location.str());
            }



        } // namespace location
    }     // namespace debug
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DEBUG_LOCATION_HPP
