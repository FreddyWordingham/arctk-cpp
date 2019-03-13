//  == IMPORTS ==
//  -- Arc --
#include "arctk/si/dimension.inl"

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



    //  == FIXTURES ==
    //  -- Units --
    class si_unit_test : public ::testing::Test
    {
        //  == FIELDS ==
      protected:
        //  -- Data --
        const arc::si::Scalar scalar{};
        const arc::si::Mass   mass{};
        const arc::si::Length length{1.0};
        const arc::si::Time   time{2.0};
    };



    //  == TESTS ==
    //  -- SI Units --
    TEST_F(si_unit_test, construction) // NOLINT
    {
        ASSERT_EQ(scalar.mag(), 0.0);
        ASSERT_EQ(mass.mag(), 0.0);
        ASSERT_EQ(length.mag(), 1.0);
        ASSERT_EQ(time.mag(), 2.0);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
