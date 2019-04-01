//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include <arctk/test/types.inl>

//  -- Std --
#include <cstddef>
#include <string>



//  == NAMESPACE ==
namespace arc
{
    namespace test
    {



        //  == CONSTANTS ==
        //  -- Zero --
        constexpr const Bool  BOOL_ZERO{false};
        constexpr const Char  CHAR_ZERO{0};
        constexpr const Int   INT_ZERO{0};
        constexpr const Size  SIZE_ZERO{0};
        constexpr const Float FLOAT_ZERO{0.0};

        //  -- Positive --
        constexpr const Char  CHAR_POS{'a'};
        constexpr const Int   INT_POS{32749};
        constexpr const Size  SIZE_POS{67280421310721};
        constexpr const Float FLOAT_POS{3.14159};

        //  -- Negative --
        constexpr const Int   INT_NEG{-INT_POS};
        constexpr const Float FLOAT_NEG{-FLOAT_POS};

        //  -- Default --
        constexpr const Bool  BOOL_CANON{true};
        constexpr const Char  CHAR_CANON{CHAR_POS};
        constexpr const Int   INT_CANON{INT_NEG};
        constexpr const Size  SIZE_CANON{SIZE_POS};
        constexpr const Float FLOAT_CANON{FLOAT_NEG};
        constexpr const CStr  C_STR_CANON{"Hello Arc::Torus!\n"};



    } // namespace test
} // namespace arc
