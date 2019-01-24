//  == IMPORTS ==
//  -- Arc --
#include <arctk/config/build.inl>

//  -- Std --
#include <cassert>
#include <cstring>



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Tests --
        inline void dir() noexcept;
        inline void branch() noexcept;
        inline void hash() noexcept;
        inline void compiler() noexcept;
        inline void type() noexcept;
        inline void date() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    return (0);
}



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTIONS ==
        //  -- Tests --
        inline void dir() noexcept
        {
            assert(std::strlen(config::DIR) > 0);
        }

        inline void branch() noexcept
        {
            assert(std::strlen(config::BRANCH) > 0);
        }

        inline void hash() noexcept
        {
            assert(std::strlen(config::HASH) > 0);
        }

        inline void compiler() noexcept
        {
            assert(std::strlen(config::COMPILER) > 0);
        }

        inline void type() noexcept
        {
            assert(std::strlen(config::TYPE) > 0);
        }

        inline void date() noexcept
        {
            assert(std::strlen(config::DATE) > 0);
        }



    } // namespace test
} // namespace arc
