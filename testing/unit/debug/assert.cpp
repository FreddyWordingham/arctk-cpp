//  == IMPORTS ==
//  -- Arc --
#include <arctk/debug/assert.inl>

//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Tests --
        constexpr inline void pass() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::pass();

    return (0);
}



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTIONS ==
        //  -- Tests --
        constexpr inline void pass() noexcept
        {
            arc::debug::assert(false, "void pass()", "assert.cpp", "51");
        }



    } // namespace test
} // namespace arc
