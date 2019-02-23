//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Arc --
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
            using reference      = typename std::reference_wrapper<const typename C::value_type>;
            using const_iterator = typename std::vector<reference>::const_iterator;
            using iterator       = typename std::vector<reference>::iterator;


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
            constexpr inline const_iterator cbegin() const noexcept;
            constexpr inline iterator       begin() noexcept;
            constexpr inline const_iterator cend() const noexcept;
            constexpr inline iterator       end() noexcept;
        };



    } // namespace range
} // namespace arc
