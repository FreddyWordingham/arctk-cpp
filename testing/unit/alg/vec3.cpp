//  == IMPORTS ==
//  -- Arc --
#include <arctk/alg/vec3.inl>
#include <arctk/math/compare.inl>
#include <arctk/si/dimension.inl>
#include <arctk/si/units.inl>

//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Tests --
        inline void instantiation() noexcept;
        inline void arithmetic() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::instantiation();
    arc::test::arithmetic();

    return (0);
}



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTIONS ==
        //  -- Tests --
        inline void instantiation() noexcept
        {
            alg::Vec3<double> vec_0{};
            assert(math::zero(vec_0.x));
            assert(math::zero(vec_0.y));
            assert(math::zero(vec_0.z));

            alg::Vec3<double> vec_1{1.0, 2.0, -3.0};
            assert(math::equal(vec_1.x, 1.0));
            assert(math::equal(vec_1.y, 2.0));
            assert(math::equal(vec_1.z, -3.0));

            alg::Vec3<si::Length> vec_2{1.0_m, 2.0_m, -3.0_m};
            assert(vec_2.x == 1.0_m);
            assert(vec_2.y == 2.0_m);
            assert(vec_2.z == -3.0_m);
        }

        inline void arithmetic() noexcept
        {
            alg::Vec3<si::Length> vec_0{1.0_m, 2.0_m, -3.0_m};
            assert(vec_0.x == 1.0_m);
            assert(vec_0.y == 2.0_m);
            assert(vec_0.z == -3.0_m);

            alg::Vec3<si::Velocity> vec_1{vec_0 / 0.5_s};
            assert(vec_1.x == (2.0_m / 1.0_s));
            assert(vec_1.y == (4.0_m / 1.0_s));
            assert(vec_1.z == (-6.0_m / 1.0_s));
        }



    } // namespace test
} // namespace arc
