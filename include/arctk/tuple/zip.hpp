//  == GUARD ==
#pragma once



//  == IMPORTS ==
//  -- Std --
#include <cstddef>
#include <tuple>
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{
    namespace tuple
    {



        //  == CLASSES ==
        //  -- Zip --
        template <typename... A>
        class Zip : public std::tuple<A...>
        {
            //  == ALIASES ==
          public:
            //  -- Base --
            using base = std::tuple<A...>;
            using base::base;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            template <typename... B, std::enable_if_t<(std::is_constructible_v<A, B&&> && ...), std::size_t> = 0>
            constexpr inline explicit Zip(std::tuple<B...>&& rhs) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            template <size_t I>
              constexpr inline auto& get() & noexcept;
            template <size_t I>
              constexpr inline auto get() && noexcept;
            template <size_t I>
            constexpr inline auto& get() const& noexcept;
            template <size_t I>
            constexpr inline auto get() const&& noexcept;
        };



    } // namespace tuple
} // namespace arc



namespace std // TODO can we find a way to not pollute std namespace? Should be fine as we are specialising a template.
{
    template <typename... A>
    class tuple_size<arc::tuple::Zip<A...>> : public tuple_size<tuple<A...>>
    {
    };

    template <size_t I, typename... A>
    class tuple_element<I, arc::tuple::Zip<A...>> : public tuple_element<I, tuple<remove_reference_t<A>...>>
    {
    };
} // namespace std
