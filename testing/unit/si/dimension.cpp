//  == IMPORTS ==
//  -- Arc --
#include <arctk/math/compare.inl>
#include <arctk/si/dimension.inl>
#include <arctk/type/arithmetic.inl>

//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Tests --
        template <typename TL, typename TR, typename MULT, typename DIV>
        inline void arithmetic() noexcept;
        template <typename T, typename ADD, typename SUB, typename MULT, typename DIV>
        inline void arithmetic() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::arithmetic<                        //
      arc::si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>, //
      arc::si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>, //
      arc::si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>, //
      arc::si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>, //
      arc::si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>  //
      >();

    arc::test::arithmetic<                             //
      arc::si::Dimension<1, 2, -2, -3, 4, 5, 0, -7>,   //
      arc::si::Dimension<1, 2, -2, -3, 4, 5, 0, -7>,   //
      arc::si::Dimension<1, 2, -2, -3, 4, 5, 0, -7>,   //
      arc::si::Dimension<2, 4, -4, -6, 8, 10, 0, -14>, //
      arc::si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>       //
      >();

    arc::test::arithmetic<                           //
      arc::si::Dimension<1, 2, -2, -3, 4, 5, 0, -7>, //
      arc::si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>,    //
      arc::si::Dimension<1, 2, -2, -3, 4, 5, 0, -7>, //
      arc::si::Dimension<1, 2, -2, -3, 4, 5, 0, -7>  //
      >();

    arc::test::arithmetic<                           //
      arc::si::Dimension<0, 0, 0, 0, 0, 0, 0, 0>,    //
      arc::si::Dimension<1, 2, -2, -3, 4, 5, 0, -7>, //
      arc::si::Dimension<1, 2, -2, -3, 4, 5, 0, -7>, //
      arc::si::Dimension<-1, -2, 2, 3, -4, -5, 0, 7> //
      >();

    arc::test::arithmetic<                             //
      arc::si::Dimension<1, 2, -2, -3, 4, 5, 0, -7>,   //
      arc::si::Dimension<4, 2, 1, -1, 2, -2, 3, 4>,    //
      arc::si::Dimension<5, 4, -1, -4, 6, 3, 3, -3>,   //
      arc::si::Dimension<-3, 0, -3, -2, 2, 7, -3, -11> //
      >();

    arc::test::arithmetic<                           //
      arc::si::Dimension<4, 2, 1, -1, 2, -2, 3, 4>,  //
      arc::si::Dimension<1, 2, -2, -3, 4, 5, 0, -7>, //
      arc::si::Dimension<5, 4, -1, -4, 6, 3, 3, -3>, //
      arc::si::Dimension<3, 0, 3, 2, -2, -7, 3, 11>  //
      >();

    return (0);
}



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTIONS ==
        //  -- Tests --
        template <typename TL, typename TR, typename MULT, typename DIV>
        inline void arithmetic() noexcept
        {
            static_assert(std::is_same<typename type::result<TL, TR>::mult, MULT>::value);
            static_assert(std::is_same<typename type::result<TL, TR>::div, DIV>::value);
        }

        template <typename T, typename ADD, typename SUB, typename MULT, typename DIV>
        inline void arithmetic() noexcept
        {
            static_assert(std::is_same<typename type::result<T, T>::add, ADD>::value);
            static_assert(std::is_same<typename type::result<T, T>::sub, SUB>::value);
            static_assert(std::is_same<typename type::result<T, T>::mult, MULT>::value);
            static_assert(std::is_same<typename type::result<T, T>::div, DIV>::value);
        }



    } // namespace test
} // namespace arc
