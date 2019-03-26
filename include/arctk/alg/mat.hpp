//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include "arctk/alg/vec.hpp"

//  -- Std --
#include <array>
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == CLASSES ==
        //  -- Mat --
        template <typename T, std::size_t N, std::size_t M>
        class Mat
        {
            //  == ALIASES ==
          public:
            //  -- Traits --
            using value_type = T;
            using size_type  = typename std::size_t;


            //  == FIELDS ==
          private:
            //  -- Elements --
            std::array<Row<T, M>, N> _rows;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --



            //  == OPERATORS ==
          public:
            //  == METHODS ==
          public:
            //  -- Getters --
        };



    } // namespace alg
} // namespace arc
