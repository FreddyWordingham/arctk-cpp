//  == IMPORTS ==
//  -- Arc --
#include <arctk/debug/assert.inl>



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Tests --
        inline void pass() noexcept;



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
        inline void pass() noexcept
        {
            // arc::debug::assertion(false, "void pass()", "assert.cpp", 51);

            ASSERT(1 == 2);
        }



    } // namespace test
} // namespace arc
