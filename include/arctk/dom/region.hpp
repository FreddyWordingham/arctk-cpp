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
#include <string>
#include <unordered_map>
#include <vector>

//  -- Arctk --
#include <arctk/dom/block.hpp>
#include <arctk/multi/vector.hpp>



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
            const std::array<size_t, 3>                                               _res;
            multi::vector<std::unordered_map<std::string, std::unique_ptr<Block>>, 3> _blocks;


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
