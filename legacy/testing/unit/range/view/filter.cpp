//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/view/filter.inl"
#include "arctk/range/iterator.inl"

//  -- Std --
#include <cassert>
#include <iostream>
#include <vector>



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Tests --
        void filter();



    } // namespace test
} // namespace arc



//  == MAIN ==
int main()
{
    arc::test::filter();

    return (0);
}



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == FUNCTIONS ==
        //  -- Tests --
        void filter()
        {
            std::vector<int> vec{1, 2, 3, 4, 5, 6, 7};

            auto                     even = [](int i) { return ((i % 2) == 0); };
            arc::range::view::Filter filter{even, vec};

            for (auto v : filter)
            {
                std::cout << v << '\n';
            }


            // auto end = filter.end();
        }



    } // namespace test
} // namespace arc
