//  == IMPORTS ==
//  -- Arc --
#include <arctk/math/compare.inl>
#include <arctk/si/units.inl>

//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Tests --
        inline void scalar() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::scalar();

    return (0);
}



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTIONS ==
        //  -- Tests --
        inline void scalar() noexcept
        {
            // assert(math::equal((1.0_pi).mag(), 3.14159, 0.001));
        }



    } // namespace test
} // namespace arc
