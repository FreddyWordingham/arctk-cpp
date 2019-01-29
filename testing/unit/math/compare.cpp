//  == IMPORTS ==
//  -- Arc --
#include <arctk/math/compare.inl>

//  -- Std --
#include <array>
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
        inline void comparison() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::zero();
    arc::test::equal();
    arc::test::comparison();

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

        inline void comparison() noexcept
        {
            const std::array<int, 4> arr_0{1, 2, -4, 5};
            const std::array<int, 4> arr_1{1, 2, -4, 5};
            const std::array<int, 4> arr_2{4, -7, 3, 0};
            assert(arr_0 == arr_1);
            assert(!(arr_0 != arr_1));
            assert(arr_0 != arr_2);
            assert(!(arr_0 == arr_2));

            const std::array<int, 4> arr_3{-2, -3, -5, -1};
            const std::array<int, 4> arr_4{2, 3, 5, 1};
            assert(arr_3 < arr_4);
            assert(arr_4 > arr_3);
            assert(!(arr_3 > arr_4));
            assert(!(arr_4 < arr_3));
            assert(arr_3 <= arr_4);
            assert(arr_4 >= arr_3);
            assert(!(arr_3 >= arr_4));
            assert(!(arr_4 <= arr_3));
        }



    } // namespace test
} // namespace arc
