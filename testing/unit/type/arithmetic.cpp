//  == IMPORTS ==
//  -- Arc --
#include <arctk/type/arithmetic.inl>

//  -- Std --
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Tests --
        template <typename TL, typename TR, typename ADD, typename SUB, typename MULT, typename DIV>
        inline void set() noexcept;



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::set<int, int, int, int, int, int>();
    arc::test::set<unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int>();
    arc::test::set<double, double, double, double, double, double>();
    arc::test::set<int, double, double, double, double, double>();
    arc::test::set<double, int, double, double, double, double>();

    return (0);
}



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTIONS ==
        //  -- Tests --
        template <typename TL, typename TR, typename ADD, typename SUB, typename MULT, typename DIV>
        inline void set() noexcept
        {
            static_assert(std::is_same<type::arithmetic::Add<TL, TR>, ADD>::value);
            static_assert(std::is_same<type::arithmetic::Sub<TL, TR>, SUB>::value);
            static_assert(std::is_same<type::arithmetic::Mult<TL, TR>, MULT>::value);
            static_assert(std::is_same<type::arithmetic::Div<TL, TR>, DIV>::value);
        }



    } // namespace test
} // namespace arc
