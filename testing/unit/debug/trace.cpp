//  == IMPORTS ==
//  -- Arc --
#include "arctk/debug/trace.inl"

//  -- GTest --
#include <gtest/gtest.h>

//  -- Std --
#include <string>
#include <vector>



//  == PRAGMAS ==
//  -- Warnings --
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"



//  == NAMESPACE ==
namespace arc
{
    namespace debug
    {



        //  == FIXTURES ==
        //  -- Trace --
        class stacktrace_test : public ::testing::Test
        {
            //  == FIELDS ==
          protected:
            //  -- Data --
            const std::vector<std::string> _trace_0;


            //  == INSTANTIATION ==
          protected:
            //  -- Constructors --
            inline explicit stacktrace_test() noexcept
              : _trace_0{stacktrace()}
            {
            }
        };



        //  == TESTS ==
        TEST_F(stacktrace_test, is_not_empty)
        {
            ASSERT_TRUE(!_trace_0.empty());
        }



    } // namespace debug
} // namespace arc



//  == CLEAN UP ==
//  -- Warnings --
#pragma clang diagnostic pop
