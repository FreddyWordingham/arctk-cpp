//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/alg/col.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --



//  == NAMESPACE ==
namespace arc
{
    namespace alg
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T, std::size_t N>
        constexpr inline Col<T, N>::Col() noexcept
          : _elems{}
        {
        }

        template <typename T, std::size_t N>
        template <typename... A>
        constexpr inline Col<T, N>::Col(const A... elems_) noexcept
          : _elems{init_elems(elems_...)}
        {
            static_assert(sizeof...(A) == N);
        }

        // TODO col and row conversion constructors / operators?


        //  -- Instantiation --
        template <typename T, std::size_t N>
        template <typename... A>
        constexpr inline std::array<T, N> Col<T, N>::init_elems(const A... elems_) noexcept
        {
            static_assert(sizeof...(A) == N);

            std::array<T, N> elems{};

            std::size_t i = 0;
            ((elems[i] = elems_, ++i), ...);

            return (elems);
        }



        //  == OPERATORS ==



        //  == METHODS ==
        //  -- Getters --
        constexpr inline const std::array<T, N>& elems() const noexcept
        {
            return (_elems);
        }



    } // namespace alg
} // namespace arc
