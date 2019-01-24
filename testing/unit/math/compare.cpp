//  == IMPORTS ==
//  -- Arc --
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
        inline void zero() noexcept;
        inline void equal() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::zero();
    arc::test::equal();

    return (0);
}



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTIONS ==
        //  -- Tests --
        inline void zero() noexcept
        {
            assert(math::zero(0.0));
            assert(math::zero(-0.0));
            assert(!math::zero(1.0));
            assert(!math::zero(-1.0));
            assert(math::zero(0.5, 1.0));
            assert(math::zero(-0.5, 1.0));
        }

        inline void equal() noexcept
        {
            assert(math::equal(1.0, 1.0));
            assert(math::equal(-1.0, -1.0));
            assert(!math::equal(0.0, 1.0));
            assert(!math::equal(1.0, 0.0));
            assert(!math::equal(1.0, -1.0));
            assert(!math::equal(-1.0, 1.0));
            assert(math::equal(0.25, 0.75, 1.0));
            assert(math::equal(-0.25, -0.75, 1.0));
            assert(!math::equal(-0.25, 0.75, 0.5));
            assert(!math::equal(0.25, -0.75, 0.5));
        }



    } // namespace test
} // namespace arc
