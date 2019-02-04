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
            debug::assertion(true, "true", __PRETTY_FUNCTION__, __FILE__, __LINE__);
            debug::assertion(false, "false", __PRETTY_FUNCTION__, __FILE__, __LINE__);
        }



    } // namespace test
} // namespace arc
