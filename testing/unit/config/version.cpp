//  == IMPORTS ==
//  -- Arc --
#include <arctk/config/version.inl>



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Tests --
        inline void patch() noexcept;
        inline void minor() noexcept;
        inline void major() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::patch();
    arc::test::minor();
    arc::test::major();

    return (0);
}



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTIONS ==
        //  -- Tests --
        inline void patch() noexcept
        {
            static_assert(config::VERSION_PATCH >= 0);
        }

        inline void minor() noexcept
        {
            static_assert(config::VERSION_MINOR >= 0);
        }

        inline void major() noexcept
        {
            static_assert(config::VERSION_MAJOR >= 0);
        }



    } // namespace test
} // namespace arc
