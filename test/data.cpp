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
    arc::data::Bin<int, 1> bin(0.0, 1.0, 2);

    bin.count(0.75, 1);

    //    std::cout << bin.data() << '\n';

    return (0);
}
