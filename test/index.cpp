/**
 *  @file   index.cpp
 *  @date   22/10/2018
 *  @author Freddy Wordingham
 *
 *  Indexing collection test programme.
 */



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/index/col.hpp>
#include <arctk/index/dim.hpp>
#include <arctk/index/finder.hpp>
#include <arctk/index/rotate.hpp>
#include <arctk/index/vertex.hpp>

#include <arctk/parse/print.hpp>
#include <iostream>
//  == MAIN ==
//  -- Function --
/**
 *  Unit test function of Arctk indexing collection headers.
 *
 *  @return Zero upon a successful run.
 */
int main(const int /*unused*/, const char** /*unused*/)
{
    arc::multi::vector<double, 2> vec(4, std::vector<double>(4));

    std::cout << vec << '\n';

    arc::index::Finder find(arc::vec2(0.0, 0.0), arc::vec2(1.0, 1.0), std::array<size_t, 2>({{2, 4}}));

    find.get<double>(vec, 0.25, 0.25) = 2.4;

    std::cout << vec << '\n';

    return (0);
}
