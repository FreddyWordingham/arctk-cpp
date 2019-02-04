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
        inline void assertion(bool result_, char* expression_, char* func_, char* file_, int line_) noexcept;



    } // namespace debug
} // namespace arc
