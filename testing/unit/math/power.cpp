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



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::sq();
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
        inline void sq() noexcept
        {
            static_assert(math::sq(2) == 4);
            assert(math::sq(2) == 4);
            math::sq(2);

            static_assert(math::sq(-2) == 4);
            assert(math::sq(-2) == 4);
            math::sq(-2);
        }

        inline void cube() noexcept
        {
            static_assert(math::cube(2) == 8);
            assert(math::cube(2) == 8);
            math::cube(2);

            static_assert(math::cube(-2) == -8);
            assert(math::cube(-2) == -8);
            math::cube(-2);
        }



    } // namespace test
} // namespace arc
