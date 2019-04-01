//  == IMPORTS ==
//  -- Arc --
#include "arctk/test/types.inl"

//  -- GTest --
#include <gtest/gtest.h>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wglobal-constructors"
#endif



//  == ALIASES ==
//  -- Namespaces --
using namespace arc; // NOLINT



//  == NAMESPACE ==
namespace testing
{
    namespace unit
    {



        //  == TESTS ==
//      //  -- Prime --
//      TEST(prime, special) // NOLINT
//      {
//          ASSERT_TRUE(is_prime(2));
//      }



    } // namespace unit
} // namespace testing



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
    #pragma clang diagnostic pop
#endif
