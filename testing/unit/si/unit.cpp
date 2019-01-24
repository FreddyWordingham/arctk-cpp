//  == IMPORTS ==
//  -- Arc --
#include <arctk/math/compare.inl>
#include <arctk/si/unit.inl>

//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Tests --
        inline void scalar() noexcept;
        inline void length() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::scalar();
    arc::test::length();

    return (0);
}



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTIONS ==
        //  -- Tests --
        inline void scalar() noexcept
        {
            si::Scalar scal_0;
            assert(math::zero(scal_0.mag()));

            si::Scalar scal_1{1.23};
            assert(math::equal(scal_1.mag(), 1.23));

            double doub_0{scal_0};
            assert(math::zero(doub_0));

            double doub_1{scal_1};
            assert(math::equal(doub_1, 1.23));
        }

        inline void length() noexcept
        {
            si::Length len_0;
            assert(math::zero(len_0.mag()));

            si::Length len_1{1.23};
            assert(math::equal(len_1.mag(), 1.23));

            si::Length len_2{len_1 * 2.0};
            assert(math::equal(len_2.mag(), 2.46));

            si::Length len_3{0.5 * len_2};
            assert(math::equal(len_3.mag(), 0.615));

            si::Velocity vel_0{len_1 / si::Time{0.5}};
            assert(math::equal(vel_0.mag(), 2.46));
        }



    } // namespace test
} // namespace arc
