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
        inline void resultant_type();



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::resultant_type<int, int, int, int, int, int>();
    arc::test::resultant_type<unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int>();
    arc::test::resultant_type<double, double, double, double, double, double>();

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
        inline void resultant_type()
        {
            static_assert(std::is_same<typename type::Result<Tl, Tr>::add, Add>::value);
            static_assert(std::is_same<typename type::Result<Tl, Tr>::sub, Sub>::value);
            static_assert(std::is_same<typename type::Result<Tl, Tr>::mult, Mult>::value);
            static_assert(std::is_same<typename type::Result<Tl, Tr>::div, Div>::value);
        }



    } // namespace test
} // namespace arc
