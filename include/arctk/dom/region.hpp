/**
 *  @file   arctk/dom/region.hpp
 *  @date   27/11/2018
 *  @author Freddy Wordingham
 *
 *  Domain region class.
 */



//  == GUARD ==
#ifndef ARCTK_DOM_REGION_HPP
#define ARCTK_DOM_REGION_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cstddef>
#include <memory>
#include <unordered_map>
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace dom //! domain namespace
    {



        //  == CLASS ==
        /**
         *  Domain region class.
         */
        class Region
        {
            //  == FIELDS ==
          protected:
            //  -- Blocks --
            const std::array<size_t, 3> _res;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --


            //  == METHODS ==
          public:
            //  -- Getters --
        };



    } // namespace dom
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/dom/region.inl>



//  == GUARD END ==
#endif // ARCTK_DOM_REGION_HPP
