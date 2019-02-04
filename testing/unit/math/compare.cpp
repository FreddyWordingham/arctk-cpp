//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/compare.inl"
#include "arctk/debug/assert.inl"

//  -- Std --
#include <cassert>
#include <vector>



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Tests --
        inline void zero() noexcept;
        inline void equal() noexcept;
        inline void operators() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::zero();
    arc::test::equal();
    arc::test::operators();

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

        inline void operators() noexcept
        {
            const std::vector<double> vec_0{1.0, 2.0, 3.4, -5.6};
            const std::vector<double> vec_1{-1.0, -2.0, -3.4, -15.6};

            ASSERT(vec_0 == vec_0);
            ASSERT(vec_0 != vec_1);
            ASSERT(vec_0 < vec_1);
            ASSERT(vec_0 <= vec_1);
            ASSERT(vec_0 > vec_1);
            ASSERT(vec_0 >= vec_1);
        }



    } // namespace test
} // namespace arc
