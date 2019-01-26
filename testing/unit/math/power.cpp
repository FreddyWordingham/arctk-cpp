//  == IMPORTS ==
//  -- Arc --
#include <arctk/math/compare.inl>
#include <arctk/math/power.inl>

//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Tests --
        inline void square() noexcept;
        inline void cube() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::square();
    arc::test::cube();

    return (0);
}



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTIONS ==
        //  -- Tests --
        inline void square() noexcept
        {
            static_assert(math::sq(2) == 4);
            static_assert(math::sq(-2) == 4);
            static_assert(math::sq(2U) == 4);

            assert(math::equal(math::sq(2.0), 4.0));
            assert(math::equal(math::sq(-2.0), 4.0));
        }

        inline void cube() noexcept
        {
            static_assert(math::cube(2) == 8);
            static_assert(math::cube(-2) == -8);
            static_assert(math::cube(2U) == 8);

            assert(math::equal(math::cube(2.0), 8.0));
            assert(math::equal(math::cube(-2.0), -8.0));
        }



    } // namespace test
} // namespace arc
