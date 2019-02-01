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



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    assert(arc::math::sq(2) == 4);

    return (0);
}



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTIONS ==
        //  -- Tests --
        // template <typename T, typename S>
        // inline void sq() noexcept
        // {
        //     static_assert(math::sq(T{2}) == S{4});
        //     static_assert(math::sq(T{-2}) == S{4});
        // }



    } // namespace test
} // namespace arc
