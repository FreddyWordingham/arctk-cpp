/**
 *  @file   img.cpp
 *  @date   12/11/2018
 *  @author Freddy Wordingham
 *
 *  Image collection test programme.
 */



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/img/bitmap.hpp>
#include <arctk/img/bitmap/greyscale.hpp>


//  -- Temp --
#include <arctk/parse/print.hpp>
#include <cmath>
#include <iostream>



//  == MAIN ==
//  -- Function --
/**
 *  Unit test function of Arctk image collection headers.
 *
 *  @return Zero upon a successful run.
 */
int main(const int /*unused*/, const char** /*unused*/)
{
    std::vector<std::vector<double>> vec_a({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}});

    arc::img::bitmap::Greyscale img(vec_a);
    img.save("output");

    return (0);
}
