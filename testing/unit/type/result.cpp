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
        template <typename Tl, typename Tr, typename Add, typename Sub, typename Mult, typename Div>
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
        template <typename Tl, typename Tr, typename Add, typename Sub, typename Mult, typename Div>
        inline void result()
        {
            static_assert(std::is_same<typename type::result<Tl, Tr>::add, Add>::value);
            static_assert(std::is_same<typename type::result<Tl, Tr>::sub, Sub>::value);
            static_assert(std::is_same<typename type::result<Tl, Tr>::mult, Mult>::value);
            static_assert(std::is_same<typename type::result<Tl, Tr>::div, Div>::value);
        }



    } // namespace test
} // namespace arc
