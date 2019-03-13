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



    //  == Dimension ==
    //  -- Units --
    class si_dimension_test : public ::testing::Test
    {
        //  == FIELDS ==
      protected:
        //  -- Data --
        const arc::si::Scalar _scalar{};
        const arc::si::Mass   _mass{};
        const arc::si::Length _length{1.0};
        const arc::si::Time   _time{2.0};
    };



    //  == TESTS ==
    //  -- Dimension --
    TEST_F(si_dimension_test, construction) // NOLINT
    {
        ASSERT_EQ(_scalar.mag(), 0.0);
        ASSERT_EQ(_mass.mag(), 0.0);
        ASSERT_EQ(_length.mag(), 1.0);
        ASSERT_EQ(_time.mag(), 2.0);
    }

    TEST_F(si_dimension_test, copy_construction) // NOLINT
    {
        const auto scalar{_scalar};
        ASSERT_EQ(scalar.mag(), 0.0);

        const auto mass{_mass};
        ASSERT_EQ(mass.mag(), 0.0);

        const auto length{_length};
        ASSERT_EQ(length.mag(), 1.0);

        const auto time{_time};
        ASSERT_EQ(time.mag(), 2.0);
    }

    TEST(si_dimension_test, assignment) // NOLINT
    {
        arc::si::Scalar scalar = 0.0;
        ASSERT_EQ(scalar.mag(), 0.0);

        scalar += 1.0;
        ASSERT_EQ(scalar.mag(), 1.0);

        scalar -= -1.0;
        ASSERT_EQ(scalar.mag(), 2.0);

        scalar *= 2.0;
        ASSERT_EQ(scalar.mag(), 4.0);

        scalar /= 4.0;
        ASSERT_EQ(scalar.mag(), 1.0);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
