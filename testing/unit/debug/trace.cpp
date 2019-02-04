//  == IMPORTS ==
//  -- Arc --
#include <arctk/debug/trace.inl>



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
            const std::vector<std::string> trace(debug::stacktrace());
        }



    } // namespace test
} // namespace arc
