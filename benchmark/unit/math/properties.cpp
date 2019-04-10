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
namespace bench
{
    namespace unit
    {



        //  == BENCHMARKS ==
        //  -- Properties --
        static void is_prime(benchmark::State& state) // NOLINT
        {
            for (auto _ : state) // NOLINT
            {
                arc::math::is_prime(2147483647);
            }
        }
        BENCHMARK(is_prime); // NOLINT



    } // namespace unit
} // namespace bench



//  == MAIN ==
BENCHMARK_MAIN();



//  == CLEAN UP ==
//  -- Warnings --
#ifdef __clang__
#pragma clang diagnostic pop
#endif
