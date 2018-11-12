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


//  -- Temp --
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
    std::function<double(double)> lamb = [](const double x_) { return (std::log10(x_)); };

    std::cout << lamb(1000.0) << '\n';

    return (0);
}
