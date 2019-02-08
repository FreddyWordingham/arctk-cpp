//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/lin/vec.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cassert>
#include <cstddef>



//  == NAMESPACE ==
namespace arc
{
    namespace lin
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T, std::size_t N>
        constexpr inline Vec<T, N>::Vec() noexcept
        {
        }

        template <typename T, std::size_t N>
        template <typename... A>
        constexpr inline Vec<T, N>::Vec(const A... elems_) noexcept
          : _elems{init_elems(elems_...)}
        {
        }


        //  -- Initialisation --
        template <typename T, std::size_t N>
        template <typename... A>
        constexpr inline std::array<T, N> Vec<T, N>::init_elems(const A... data_) noexcept
        {
            // static_assert(std::is_same<T, A...>::value); TODO
            static_assert(sizeof...(A) == N);

            std::array<T, N> data;

            std::size_t i = 0;
            ((data[i] = data_, ++i), ...);

            return (data);
        }



        //  == OPERATORS ==
        //  -- Access --
        template <typename T, std::size_t N>
        constexpr inline T& Vec<T, N>::operator[](const std::size_t index_) noexcept
        {
            assert(index_ < N);

            return (_elems[index_]);
        }

        template <typename T, std::size_t N>
        constexpr inline const T& Vec<T, N>::operator[](const std::size_t index_) const noexcept
        {
            assert(index_ < N);

            return (_elems[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename T, std::size_t N>
        constexpr inline const std::array<T, N>& Vec<T, N>::elems() const noexcept
        {
            return (_elems);
        }



    } // namespace lin
} // namespace arc
