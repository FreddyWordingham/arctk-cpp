/**
 *  @file   data.cpp
 *  @date   06/11/2018
 *  @author Freddy Wordingham
 *
 *  Data collection test programme.
 */



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/data/bin.hpp>
#include <arctk/data/obj.hpp>
#include <arctk/data/table.hpp>
#include <arctk/parse/print.hpp>


//  == MAIN ==
//  -- Function --
/**
 *  Unit test function of Arctk data collection headers.
 *
 *  @return Zero upon a successful run.
 */
int main(const int /*unused*/, const char** /*unused*/)
{
    arc::data::Bin<int, 2> bin(arc::vec2(0.0, 0.0), arc::vec2(1.0, 1.0), {{2, 2}});

    bin.count(arc::vec2(0.75, 0.75), 1.23);

    std::cout << bin.bins() << '\n';

    return (0);
}
