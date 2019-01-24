//  == IMPORTS ==
//  -- Arc --
#include <arctk/si/unit.inl>

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
            si::Scalar scal_0;
            assert(scal_0.mag() == 0.0);

            si::Scalar scal_1{1.23};
            assert(scal_1.mag() == 1.23);

            double doub_0{scal_0};
            assert(doub_0 == 0.0);

            double doub_1{scal_1};
            assert(doub_1 == 1.23);
        }



    } // namespace test
} // namespace arc
