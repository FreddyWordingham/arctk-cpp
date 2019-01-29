//  == IMPORTS ==
//  -- Arc --
#include <arctk/alg/vecN.inl>
#include <arctk/math/compare.inl>

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



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::instantiation();

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
            alg::VecN<double, 5> vec_0{};
            assert(math::zero(vec_0[0]));
            assert(math::zero(vec_0[1]));
            assert(math::zero(vec_0[2]));
            assert(math::zero(vec_0[3]));
            assert(math::zero(vec_0[4]));

            alg::VecN<double, 5> vec_1{{-1.0, -0.4, 2.0, 2.2, 7.6}};
            assert(math::equal(vec_1[0], -1.0));
            assert(math::equal(vec_1[1], -0.4));
            assert(math::equal(vec_1[2], 2.0));
            assert(math::equal(vec_1[3], 2.2));
            assert(math::equal(vec_1[4], 7.6));
        }



    } // namespace test
} // namespace arc
