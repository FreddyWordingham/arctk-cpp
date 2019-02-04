//  == GUARD ==
#pragma once



//  == MACROS ==
//  -- Assert --
#ifdef NDEBUG
#define ASSERT(expression_)
#else
#define ASSERT(expression_) arc::debug::assertion(expression_, #expression_, __PRETTY_FUNCTION__, __FILE__, __LINE__)
#endif



//  == NAMESPACE ==
namespace arc
{
    namespace debug
    {



        //  == FUNCTIONS ==
        //  -- Assert --
        inline void assertion(const bool result_, const char* const expression_, const char* const func_, const char* const file_, const int line_) noexcept;



    } // namespace debug
} // namespace arc
