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
        inline void mass() noexcept;
        inline void length() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::scalar();
    arc::test::mass();
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
            const si::Scalar scal_0;
            assert(math::zero(scal_0.mag()));

            const si::Scalar scal_1{1.23};
            assert(math::equal(scal_1.mag(), 1.23));

            const double doub_0{scal_0};
            assert(math::zero(doub_0));

            const double doub_1{scal_1};
            assert(math::equal(doub_1, 1.23));
        }

        inline void mass() noexcept
        {
            const si::Mass mass_0;
            assert(math::zero(mass_0.mag()));

            const si::Mass mass_1{1.23};
            assert(math::equal(mass_1.mag(), 1.23));

            const si::Mass mass_2{mass_1 * 2.0};
            assert(math::equal(mass_2.mag(), 2.46));

            const si::Mass mass_3{0.5 * mass_2};
            assert(math::equal(mass_3.mag(), 1.23));

            const si::Energy energy_0{mass_1 * (si::Length{1.0} * si::Length{1.0}) / (si::Time{0.5} * si::Time{0.5})};
            assert(math::equal(energy_0.mag(), 4.92));
        }

        inline void length() noexcept
        {
            const si::Length len_0;
            assert(math::zero(len_0.mag()));

            const si::Length len_1{1.23};
            assert(math::equal(len_1.mag(), 1.23));

            const si::Length len_2{len_1 * 2.0};
            assert(math::equal(len_2.mag(), 2.46));

            const si::Length len_3{0.5 * len_2};
            assert(math::equal(len_3.mag(), 1.23));

            const si::Velocity vel_0{len_1 / si::Time{0.5}};
            assert(math::equal(vel_0.mag(), 2.46));
        }



    } // namespace test
} // namespace arc
