//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/alg/col.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/arithmetic.inl"

//  -- Std --
#include <cassert>
#include <iterator>



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T, std::size_t N>
        constexpr inline Col<T, N>::Col() noexcept
          : _elems()
        {
        }

        template <typename T, std::size_t N>
        template <typename... A>
        constexpr inline Col<T, N>::Col(const A... elems_) noexcept
          : _elems{elems_...}
        {
        }

        // TODO col and row conversion constructors / operators?



        //  == OPERATORS ==
        //  -- Access --
        template <typename T, std::size_t N>
        constexpr inline T& Col<T, N>::operator[](const std::size_t index_) noexcept
        {
            assert(index_ < N);

            return (_elems[index_]);
        }

        template <typename T, std::size_t N>
        constexpr inline const T& Col<T, N>::operator[](const std::size_t index_) const noexcept
        {
            assert(index_ < N);

            return (_elems[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename T, std::size_t N>
        constexpr inline const std::array<T, N>& Col<T, N>::elems() const noexcept
        {
            return (_elems);
        }


        //  -- Range --
        template <typename T, std::size_t N>
        constexpr inline auto Col<T, N>::begin() noexcept
        {
            return (std::begin(_elems));
        }

        template <typename T, std::size_t N>
        constexpr inline auto Col<T, N>::begin() const noexcept
        {
            return (std::begin(_elems));
        }

        template <typename T, std::size_t N>
        constexpr inline auto Col<T, N>::end() noexcept
        {
            return (std::end(_elems));
        }

        template <typename T, std::size_t N>
        constexpr inline auto Col<T, N>::end() const noexcept
        {
            return (std::end(_elems));
        }



    } // namespace alg
} // namespace arc
