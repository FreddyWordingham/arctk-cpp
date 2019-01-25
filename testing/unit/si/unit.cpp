//  == IMPORTS ==
//  -- Arc --
#include <arctk/math/compare.inl>
#include <arctk/math/power.inl>
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
        template <typename T>
        inline void dimensional() noexcept;
        inline void cross_dimensional() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::scalar();
    arc::test::dimensional<arc::si::Mass>();
    arc::test::cross_dimensional();

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
            const si::Scalar scal_0;
            assert(math::zero(scal_0.mag()));

            const si::Scalar scal_1{1.25};
            assert(math::equal(scal_1.mag(), 1.25));

            const double doub_0{scal_0};
            assert(math::zero(doub_0));

            const double doub_1{scal_1};
            assert(math::equal(doub_1, 1.25));

            si::Scalar scal_2{3.14159};
            assert(math::equal(scal_2.mag(), 3.14159)); /**/
            assert(math::equal((++scal_2).mag(), 4.14159));
            assert(math::equal(scal_2.mag(), 4.14159));
            assert(math::equal((--scal_2).mag(), 3.14159));
            assert(math::equal(scal_2.mag(), 3.14159));

            si::Scalar scal_3{3.14159};
            assert(math::equal(scal_3.mag(), 3.14159)); /**/
            assert(math::equal((scal_3++).mag(), 3.14159));
            assert(math::equal(scal_3.mag(), 4.14159));
            assert(math::equal((scal_3--).mag(), 4.14159));
            assert(math::equal(scal_3.mag(), 3.14159));

            si::Scalar scal_4{1.24};
            scal_4 += 1.24;
            assert(math::equal(scal_4.mag(), 2.48));
            scal_4 += scal_3;
            assert(math::equal(scal_4.mag(), 5.62159));

            si::Scalar scal_5{1.24};
            scal_5 -= 1.24;
            assert(math::zero(scal_5.mag()));
            scal_5 -= scal_3;
            assert(math::equal(scal_5.mag(), -3.14159));

            si::Scalar scal_6{1.24};
            scal_6 *= 1.24;
            assert(math::equal(scal_6.mag(), 1.5376));
            scal_6 *= scal_1;
            assert(math::equal(scal_6.mag(), 1.92200));

            si::Scalar scal_7{1.24};
            scal_7 /= 1.24;
            assert(math::equal(scal_7.mag(), 1.0));
            scal_7 /= scal_1;
            assert(math::equal(scal_7.mag(), 0.8));
        }

        template <typename T>
        inline void dimensional() noexcept
        {
            const T d_0;
            assert(math::zero(d_0.mag()));

            const T d_1{1.25};
            assert(math::equal(d_1.mag(), 1.25));

            const T d_2{d_1 * 2.0};
            assert(math::equal(d_2.mag(), 2.5));

            const T d_3{0.5 * d_2};
            assert(math::equal(d_3.mag(), 1.25));

            T d_4{3.14159};
            assert(math::equal(d_4.mag(), 3.14159));
            assert(math::equal((++d_4).mag(), 4.14159));
            assert(math::equal(d_4.mag(), 4.14159));
            assert(math::equal((--d_4).mag(), 3.14159));
            assert(math::equal(d_4.mag(), 3.14159));

            T d_5{3.14159};
            assert(math::equal(d_5.mag(), 3.14159));
            assert(math::equal((d_5++).mag(), 3.14159));
            assert(math::equal(d_5.mag(), 4.14159));
            assert(math::equal((d_5--).mag(), 4.14159));
            assert(math::equal(d_5.mag(), 3.14159));
        }

        inline void cross_dimensional() noexcept
        {
            const si::Mass   mass{1.25};
            const si::Length leng{40.5};
            const si::Time   time{0.25};
            const si::Energy energy{mass * math::sq(leng / time)};
            assert(math::equal(energy.mag(), 1.0));
        }



    } // namespace test
} // namespace arc
