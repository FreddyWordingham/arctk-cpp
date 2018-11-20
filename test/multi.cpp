/**
 *  @file   multi.cpp
 *  @date   01/11/2018
 *  @author Freddy Wordingham
 *
 *  Multi-dimensional collection test programme.
 */



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/multi/array.hpp>
#include <arctk/multi/vector.hpp>
#include <arctk/parse/print.hpp>
#include <iostream>


//  == MAIN ==
//  -- Function --
/**
 *  Unit test function of Arctk multi-dimensional container alias collection headers.
 *
 *  @return Zero upon a successful run.
 */
int main(const int /*unused*/, const char** /*unused*/)
{
    std::cout << arc::multi::vector_helper<int, 4>::shape({{4, 2, 1}}) << '\n';

    return (0);
}
