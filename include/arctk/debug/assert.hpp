//  == GUARD ==
#pragma once



//  == MACROS ==
//  -- Assert --
#ifdef NDEBUG
#define ASSERT(precond_)
#else
#define ASSERT(precond_) arc::debug::assertion(precond_, "one", "two", 3)
#endif



//  == NAMESPACE ==
namespace arc
{
    namespace debug
    {



        //  == FUNCTIONS ==
        //  -- Assert --
        inline void assertion(const bool result_, const char* const func_, const char* const file_, const int line_) noexcept;



    } // namespace debug
} // namespace arc
