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
            static_assert(arc::math::sq(2) == 4);
            assert(arc::math::sq(2) == 4);
            arc::math::sq(2);

            static_assert(arc::math::sq(-2) == 4);
            assert(arc::math::sq(-2) == 4);
            arc::math::sq(-2);
        }

        inline void cube() noexcept
        {
            static_assert(arc::math::cube(2) == 8);
            assert(arc::math::cube(2) == 8);
            arc::math::cube(2);

            static_assert(arc::math::cube(-2) == -8);
            assert(arc::math::cube(-2) == -8);
            arc::math::cube(-2);
        }

        inline void pow() noexcept
        {
            static_assert(arc::math::pow(2, 4) == 16);
            assert(arc::math::pow(2, 4) == 16);
            arc::math::pow(2, 4);

            static_assert(arc::math::pow(-2, 4) == 16);
            assert(arc::math::pow(-2, 4) == 16);
            arc::math::pow(-2, 4);

            static_assert(arc::math::pow(2, 0) == 1);
            assert(arc::math::pow(2, 0) == 1);
            arc::math::pow(2, 0);

            // static_assert(arc::math::pow(-2, -4) == 1.0 / 16.0);
            // assert(arc::math::pow(-2, -4) == 1.0 / 16.0);
            arc::math::pow(-2, -4);

            arc::math::pow(-2, -4);
        }



    } // namespace test
} // namespace arc
