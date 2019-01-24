//  == IMPORTS ==
//  -- Arc --
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
            static_assert(std::is_same<type::mult<TL, TR>, MULT>::value);
            static_assert(std::is_same<type::div<TL, TR>, DIV>::value);
        }

        template <typename T, typename ADD, typename SUB, typename MULT, typename DIV>
        inline void arithmetic() noexcept
        {
            static_assert(std::is_same<type::add<T, T>, ADD>::value);
            static_assert(std::is_same<type::sub<T, T>, SUB>::value);
            static_assert(std::is_same<type::mult<T, T>, MULT>::value);
            static_assert(std::is_same<type::div<T, T>, DIV>::value);
        }



    } // namespace test
} // namespace arc
