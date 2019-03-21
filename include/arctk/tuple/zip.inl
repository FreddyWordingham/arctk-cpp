//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/tuple/zip.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <utility>



//  == NAMESPACE ==
namespace arc
{
    namespace tuple
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename... A>
        template <typename... B, std::enable_if_t<(std::is_constructible_v<A, B&&> && ...), std::size_t>>
        constexpr inline Zip<A...>::Zip(std::tuple<B...>&& rhs) noexcept
          : base(std::move(rhs))
        {
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename... A>
          template <size_t I>
          constexpr inline auto& Zip<A...>::get() & noexcept
        {
            return (std::get<I>(*this));
        }

        template <typename... A>
          template <size_t I>
          constexpr inline auto Zip<A...>::get() && noexcept
        {
            return (std::get<I>(*this));
        }

        template <typename... A>
        template <size_t I>
        constexpr inline auto& Zip<A...>::get() const& noexcept
        {
            return (std::get<I>(*this));
        }


        template <typename... A>
        template <size_t I>
        constexpr inline auto Zip<A...>::get() const&& noexcept
        {
            return (std::get<I>(*this));
        }



    } // namespace tuple
} // namespace arc
