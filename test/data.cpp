/**
 *  @file   data.cpp
 *  @date   06/11/2018
 *  @author Freddy Wordingham
 *
 *  Data collection test programme.
 */



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/data/obj.hpp>
#include <arctk/data/sorter.hpp>
#include <arctk/data/sorter/regular.hpp>
#include <arctk/data/sorter/regular/fixed.hpp>
#include <arctk/data/table.hpp>

#include <arctk/random/generator/quality.hpp>



//  == MAIN ==
//  -- Function --
/**
 *  Unit test function of Arctk data collection headers.
 *
 *  @return Zero upon a successful run.
 */
int main(const int /*unused*/, const char** /*unused*/)
{
    arc::data::sorter::regular::Fixed<double> sort(-1.0, +2.0, 30);

    arc::random::generator::Quality rng;

    for (size_t i = 0; i < 1e6; ++i)
    {
        ++sort(rng.gen());
    }

    std::cout << sort << '\n';

    return (0);
}
