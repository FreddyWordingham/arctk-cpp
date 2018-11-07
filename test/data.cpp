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
#include <arctk/data/table.hpp>



//  == MAIN ==
//  -- Function --
/**
 *  Unit test function of Arctk data collection headers.
 *
 *  @return Zero upon a successful run.
 */
int main(const int /*unused*/, const char** /*unused*/)
{
    arc::data::Obj obj("test.param");

    std::cout << obj["one"] << '\n';
    std::cout << obj["book"] << '\n';

    return (0);
}
