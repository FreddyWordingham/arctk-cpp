//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace lin
    {



        //  == CLASSES ==
        //  -- Vec --
        template <typename T, std::size_t N>
        class Vec
        {
            //  == FIELDS ==
          private:
            //  -- Elements --
            std::array<T, N> _elems;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            constexpr inline explicit Vec() noexcept;
            template <typename... A>
            constexpr inline explicit Vec(const A... elems_) noexcept;

          private:
            //  -- Initialisation --
            template <typename... A>
            constexpr inline std::array<T, N> init_elems(const A... elems_) noexcept;


            //  == OPERATORS ==
          public:
            //  -- Access --
            constexpr inline T&       operator[](std::size_t index_) noexcept;
            constexpr inline const T& operator[](std::size_t index_) const noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            constexpr inline const std::array<T, N>& elems() const noexcept;
        };



    } // namespace lin
} // namespace arc
