//  == IMPORTS ==
//  -- Arc --
#include <arctk/math/arithmetic.inl>

//  -- Std --
#include <array>
#include <cassert>
#include <vector>



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Tests --
        inline void comparison() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
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
        inline void comparison() noexcept
        {
            const std::array<int, 4> arr_0{1, 2, -4, 5};
            const std::array<int, 4> arr_1{1, 2, -4, 5};
            const std::array<int, 4> arr_2{4, -7, 3, 0};

            assert(arr_0 == arr_1);
            assert(!(arr_0 != arr_1));
            assert(arr_0 != arr_2);
            assert(!(arr_0 == arr_2));
        }



    } // namespace test
} // namespace arc
