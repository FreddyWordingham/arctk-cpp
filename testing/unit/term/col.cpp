//  == IMPORTS ==
//  -- Arc --
#include "arctk/term/col.inl"

//  -- GTest --
#include <gtest/gtest.h>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif



//  == NAMESPACE ==
namespace test
{



    //  == TESTS ==
    //  -- Prime --
    TEST(col, human_verify) // NOLINT
    {
        for (char r = 0; r < 256; ++r)
        {
            for (char g = 0; g < 256; ++g)
            {
                for (char b = 0; b < 256; ++b)
                {
                    // std::cout << '[' << << "] : Arc::Torus\n';
                }
            }
        }
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
