//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/lin/vec.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --



//  == NAMESPACE ==
namespace arc
{
    namespace lin
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T, std::size_t N>
        constexpr inline explicit Vec() noexcept
        {
        }

        template <typename T, std::size_t N>
        template <typename... A>
        constexpr inline explicit Vec(const A... elems_) noexcept
          : _elems(init_elems(elems_))
        {
        }


        //  -- Initialisation --
        template <typename T, std::size_t N>
        template <typename... A>
        inline std::array<T, N> Vec<T, N>::init_elems(const A... data_) noexcept
        {
            static_assert(std::is_same<T, A>::value);
            static_assert(sizeof...(A) == N);

            std::array<T, N> data;

            size_t i = 0;
            ((data[i] = data_, ++i), ...);

            return (data);
        }



        //  == OPERATORS ==



        //  == METHODS ==
        //  -- Getters --



    } // namespace lin
} // namespace arc
