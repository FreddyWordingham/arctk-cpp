//  == IMPORTS ==
//  -- Arc --
#include <arctk/alg/vec2.inl>
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
            alg::Vec2<double> vec_0{};
            assert(math::zero(vec_0.x));
            assert(math::zero(vec_0.y));

            alg::Vec2<double> vec_1{-1.0, -0.4};
            assert(math::equal(vec_1.x, -1.0));
            assert(math::equal(vec_1.y, -0.4));
        }



    } // namespace test
} // namespace arc
