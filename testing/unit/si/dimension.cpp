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
        using namespace arc;

        const auto scalar{_scalar};
        ASSERT_EQ(scalar.mag(), 0.0);

        const auto mass{_mass};
        ASSERT_EQ(mass.mag(), 0.0);

        const auto length{_length};
        ASSERT_EQ(length.mag(), 1.0);

        const auto time{_time};
        ASSERT_EQ(time.mag(), 2.0);

        const auto time_1{+_time};
        ASSERT_EQ(time_1.mag(), +2.0);

        const auto time_2{-_time};
        ASSERT_EQ(time_2.mag(), -2.0);
    }

    TEST_F(si_dimension_test, assignment) // NOLINT
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

        arc::si::Mass mass{};
        ASSERT_EQ(mass.mag(), 0.0);

        mass += arc::si::Mass{1.0};
        ASSERT_EQ(mass.mag(), 1.0);

        mass -= arc::si::Mass{-1.0};
        ASSERT_EQ(mass.mag(), 2.0);

        mass *= 2.0;
        ASSERT_EQ(mass.mag(), 4.0);

        mass /= 4.0;
        ASSERT_EQ(mass.mag(), 1.0);
    }

    TEST_F(si_dimension_test, increment_decrement) // NOLINT
    {
        using namespace arc;

        arc::si::Scalar scalar = 0.0;
        ASSERT_EQ(scalar.mag(), 0.0);

        ASSERT_EQ((scalar++).mag(), 0.0);
        ASSERT_EQ(scalar.mag(), 1.0);

        ASSERT_EQ((scalar--).mag(), 1.0);
        ASSERT_EQ(scalar.mag(), 0.0);

        ASSERT_EQ((++scalar).mag(), 1.0);
        ASSERT_EQ(scalar.mag(), 1.0);

        ASSERT_EQ((--scalar).mag(), 0.0);
        ASSERT_EQ(scalar.mag(), 0.0);

        arc::si::Mass mass{0.0};
        ASSERT_EQ(mass.mag(), 0.0);

        ASSERT_EQ((mass++).mag(), 0.0);
        ASSERT_EQ(mass.mag(), 1.0);

        ASSERT_EQ((mass--).mag(), 1.0);
        ASSERT_EQ(mass.mag(), 0.0);

        ASSERT_EQ((++mass).mag(), 1.0);
        ASSERT_EQ(mass.mag(), 1.0);

        ASSERT_EQ((--mass).mag(), 0.0);
        ASSERT_EQ(mass.mag(), 0.0);
    }

    TEST_F(si_dimension_test, arithmetic) // NOLINT
    {
        using namespace arc;

        const auto vel{_length / _time};
        ASSERT_TRUE(vel == si::Velocity{0.5});
        ASSERT_TRUE((_length - _length) == si::Length{0.0});
        ASSERT_TRUE((_time + _time) == si::Time{4.0});
        ASSERT_TRUE((vel * _time) == _length);

        ASSERT_TRUE((2.0 * _time) == si::Time{4.0});
        ASSERT_TRUE((_time * 0.5) == si::Time{1.0});

        ASSERT_TRUE((2.0 / _time) == si::Frequency{1.0});
        ASSERT_TRUE((_time / 0.5) == si::Time{4.0});
    }

    TEST_F(si_dimension_test, comparison) // NOLINT
    {
        using namespace arc;

        ASSERT_TRUE(_scalar == 0.0);
        ASSERT_FALSE(_scalar == 1.0);

        ASSERT_TRUE(_scalar < 1.0);
        ASSERT_FALSE(_scalar < -1.0);

        ASSERT_TRUE(_scalar <= 1.0);
        ASSERT_FALSE(_scalar <= -1.0);

        ASSERT_TRUE(1.0 > _scalar);
        ASSERT_FALSE(-1.0 > _scalar);

        ASSERT_TRUE(1.0 >= _scalar);
        ASSERT_FALSE(-1.0 >= _scalar);

        ASSERT_TRUE(_mass == si::Mass{0.0});
        ASSERT_FALSE(_mass == si::Mass{1.0});

        ASSERT_TRUE(_mass < si::Mass{1.0});
        ASSERT_FALSE(_mass < si::Mass{-1.0});

        ASSERT_TRUE(_mass <= si::Mass{1.0});
        ASSERT_FALSE(_mass <= si::Mass{-1.0});

        ASSERT_TRUE(si::Mass{1.0} > _mass);
        ASSERT_FALSE(si::Mass{-1.0} > _mass);

        ASSERT_TRUE(si::Mass{1.0} >= _mass);
        ASSERT_FALSE(si::Mass{-1.0} >= _mass);
    }



} // namespace test



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
