/**
 *  @file   parse.cpp
 *  @date   22/10/2018
 *  @author Freddy Wordingham
 *
 *  Parsing collection test programme.
 */



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/parse/print.hpp>
#include <arctk/parse/process.hpp>
#include <arctk/parse/read.hpp>
#include <arctk/parse/write.hpp>
#include <vector>


//  == MAIN ==
//  -- Function --
/**
 *  Unit test function of Arctk parsing collection headers.
 *
 *  @return Zero upon a successful run.
 */
int main(const int /*unused*/, const char** /*unused*/)
{
    std::vector<std::tuple<char, int>> table = arc::parse::read::file<std::vector<std::tuple<char, int>>>("test.txt");
    std::cout << table << '\n';

    return (0);
}
