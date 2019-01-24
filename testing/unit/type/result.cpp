//  == IMPORTS ==
//  -- Arc --
#include <arctk/type/result.inl>

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
        inline void result();



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::result<int, int, int, int, int, int>();
    arc::test::result<unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int>();
    arc::test::result<double, double, double, double, double, double>();
    arc::test::result<int, double, double, double, double, double>();
    arc::test::result<double, int, double, double, double, double>();

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
        inline void result()
        {
            static_assert(std::is_same<typename type::result<TL, TR>::add, ADD>::value);
            static_assert(std::is_same<typename type::result<TL, TR>::sub, SUB>::value);
            static_assert(std::is_same<typename type::result<TL, TR>::mult, MULT>::value);
            static_assert(std::is_same<typename type::result<TL, TR>::div, DIV>::value);
        }



    } // namespace test
} // namespace arc
