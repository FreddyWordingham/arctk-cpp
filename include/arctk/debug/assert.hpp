//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --



//  == MACROS ==
//  -- Assertions --
#ifdef NDEBUG
#define ASSERT(precond_)
#else
#define ASSERT(precond_) arc::debug::assert(precond_)
#endif



//  == NAMESPACE ==
namespace arc
{
    namespace debug
    {



        //  == FUNCTIONS ==



        //  == OPERATORS ==



    } // namespace debug
} // namespace arc
