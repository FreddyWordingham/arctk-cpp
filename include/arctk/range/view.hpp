//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/forward/bidirectional/random.hpp"
#include "arctk/type/traits.hpp"

//  -- Std --
#include <cstddef>
#include <functional>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == CLASSES ==
        //  -- View --
        template <typename C>
        class View
        {
            //  == ALIASES ==
          public:
            //  -- Values --
            using reference = typename std::reference_wrapper<const typename C::value_type>;


            //  == FIELDS ==
          private:
            //  -- References -
            std::vector<reference> _refs;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline View(const C& cont_) noexcept;
            constexpr inline View(std::vector<reference>&& refs_) noexcept;

          private:
            //  -- Initialisation --
            constexpr inline std::vector<reference> init_refs(const C& cont_) noexcept;


            //  == OPERATORS ==
          public:
            //  --  Member Access --
            constexpr inline reference operator[](const std::size_t index_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline range::iterator::forward::bidirectional::Random<reference> begin() const noexcept;
            constexpr inline range::iterator::forward::bidirectional::Random<reference> end() const noexcept;
        };



    } // namespace range
} // namespace arc
