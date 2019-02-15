//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/properties.inl"

//  -- GBench --
#include <benchmark/benchmark.h>



//  == PRAGMAS ==
//  -- Warnings --
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"



//  == NAMESPACE ==
namespace arc
{
    namespace math
    {



        //  == BENCHMARKS ==
        static void is_prime(benchmark::State& state)
        {
            for (auto _ : state)
            {
                is_prime(2147483647);
            }
        }
        BENCHMARK(is_prime);



    } // namespace math
} // namespace arc



//  == MAIN ==
BENCHMARK_MAIN();



//  == CLEAN UP ==
//  -- Warnings --
#pragma clang diagnostic pop
