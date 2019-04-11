//  == IMPORTS ==
//  -- Arc --
#include "arctk/math/properties.inl"

//  -- GBench --
#include <benchmark/benchmark.h>



//  == PRAGMAS ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif



//  == NAMESPACE ==
namespace bench::unit
{


    //  == BENCHMARKS ==
    //  -- Properties --
    static void is_prime(benchmark::State& state) // NOLINT
    {
        for (auto _ : state) // NOLINT
        {
            arc::math::is_prime(2147483647); // NOLINT
        }
    }
    BENCHMARK(is_prime); // NOLINT



} // namespace bench::unit



//  == MAIN ==
BENCHMARK_MAIN();



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
