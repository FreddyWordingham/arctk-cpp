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
        inline void operator_equal() noexcept;
        inline void operator_unequal() noexcept;
        inline void operator_less_than() noexcept;
        inline void operator_less_than_equal_to() noexcept;
        inline void operator_greater_than() noexcept;
        inline void operator_greater_than_equal_to() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::zero();
    arc::test::equal();
    arc::test::operator_equal();
    arc::test::operator_unequal();
    arc::test::operator_less_than();
    arc::test::operator_less_than_equal_to();
    arc::test::operator_greater_than();
    arc::test::operator_greater_than_equal_to();

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

        inline void operator_equal() noexcept
        {
            const std::vector<int> vec_0{1, 2, 3, -5};
            const std::vector<int> vec_1{-1, -2, -3, -15};

            ASSERT(vec_0 == vec_0);
            ASSERT(vec_1 == vec_1);
        }

        inline void operator_unequal() noexcept
        {
            const std::vector<int> vec_0{1, 2, 3, -5};
            const std::vector<int> vec_1{-1, -2, -3, -15};

            ASSERT(vec_0 != vec_1);
            ASSERT(vec_1 != vec_0);
        }

        inline void operator_less_than() noexcept
        {
            const std::vector<int> vec_0{1, 2, 3, -5};
            const std::vector<int> vec_1{-1, -2, -3, -15};

            ASSERT(!(vec_0 < vec_1));
            ASSERT(vec_1 < vec_0);
        }

        inline void operator_less_than_equal_to() noexcept
        {
            const std::vector<int> vec_0{1, 2, 3, -5};
            const std::vector<int> vec_1{-1, -2, -3, -15};

            ASSERT(!(vec_0 <= vec_1));
            ASSERT(vec_1 <= vec_0);
        }

        inline void operator_greater_than() noexcept
        {
            const std::vector<int> vec_0{1, 2, 3, -5};
            const std::vector<int> vec_1{-1, -2, -3, -15};

            ASSERT(vec_0 > vec_1);
            ASSERT(!(vec_1 > vec_0));
        }

        inline void operator_greater_than_equal_to() noexcept
        {
            const std::vector<int> vec_0{1, 2, 3, -5};
            const std::vector<int> vec_1{-1, -2, -3, -15};

            ASSERT(vec_0 >= vec_1);
            ASSERT(!(vec_1 >= vec_0));
        }



    } // namespace test
} // namespace arc
