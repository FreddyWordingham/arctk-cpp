//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/prime.inl"

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
        static void next_prime(benchmark::State& state)
        {
            for (auto _ : state)
            {
                next_prime(82);
            }
        }
        BENCHMARK(next_prime);



    } // namespace math
} // namespace arc



//  == MAIN ==
BENCHMARK_MAIN();



//  == CLEAN UP ==
//  -- Warnings --
#pragma clang diagnostic pop
