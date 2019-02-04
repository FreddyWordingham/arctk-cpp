//  == IMPORTS ==
//  -- Arc --
#include "arctk/debug/trace.inl"
#include "arctk/debug/assert.inl"

//  -- Std --
#include <string>
#include <vector>



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Tests --
        inline void trace() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::trace();

    return (0);
}



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTIONS ==
        //  -- Tests --
        inline void trace() noexcept
        {
            ASSERT(debug::stacktrace() == (std::vector<std::string>{"arc::test::trace()", "main"}));
        }



    } // namespace test
} // namespace arc
