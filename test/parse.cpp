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

    std::string str = "7";
    std::cout << arc::parse::read::string<int>(&str) << '\n';

    return (0);
}
