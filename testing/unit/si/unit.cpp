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
        inline void mass() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::scalar();
    arc::test::mass();

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

        inline void mass() noexcept
        {
            si::Mass mass_0;
            assert(mass_0.mag() == 0.0);

            si::Mass mass_1{1.23};
            assert(mass_1.mag() == 1.23);

            // si::Mass mass_2{mass_1 * 2.0};
            // assert(mass_2.mag() == 2.46);
        }



    } // namespace test
} // namespace arc
