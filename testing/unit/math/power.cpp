//  == IMPORTS ==
//  -- Arc --
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
        inline void sq() noexcept;
        inline void cube() noexcept;
        inline void pow() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::sq();
    arc::test::cube();
    arc::test::pow();

    return (0);
}



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTIONS ==
        //  -- Tests --
        inline void sq() noexcept
        {
            static_assert(math::sq(2) == 4);
            static_assert(math::sq(-2) == 4);
            static_assert(math::sq(2U) == 4);
        }

        inline void cube() noexcept
        {
            static_assert(math::cube(2) == 8);
            static_assert(math::cube(-2) == -8);
            static_assert(math::cube(2U) == 8);
        }

        inline void pow() noexcept
        {
            static_assert(math::pow(2, 4) == 16);
            static_assert(math::pow(-2, 4) == 16);
            static_assert(math::pow(2U, 4) == 16);
        }



    } // namespace test
} // namespace arc
