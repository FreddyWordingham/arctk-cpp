//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <iterator>
#include <optional>
#include <tuple>


#include "arctk/tuple/transform.inl"



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace iterator
        {



            template <typename... Ts>
            struct zip_tuple : std::tuple<Ts...>
            {
                using base = std::tuple<Ts...>;
                using base::base;

                template <typename... Us, std::enable_if_t<(std::is_constructible_v<Ts, Us&&> && ...), int> = 0>
                zip_tuple(std::tuple<Us...>&& rhs)
                  : base(std::move(rhs))
                {
                }

                template <size_t I>
                auto& get() &
                {
                    return std::get<I>(*this);
                }

                template <size_t I>
                auto& get() const&
                {
                    return std::get<I>(*this);
                }

                template <size_t I>
                auto get() &&
                {
                    return std::get<I>(*this);
                }

                template <size_t I>
                auto get() const&&
                {
                    return std::get<I>(*this);
                }
            };



            //  == CLASSES ==
            //  -- Zip --
            template <typename I, typename... J>
            class Zip : public Iterator<I>
            {
                //  == ALIASES ==
              public:
                //  -- Traits --
                using value_type        = typename Iterator<I>::value_type;
                using reference         = typename std::tuple<I, J...>&;
                using pointer           = typename Iterator<I>::pointer;
                using difference_type   = typename Iterator<I>::difference_type;
                using iterator_category = std::forward_iterator_tag;


                //  == FIELDS ==
              private:
                //  -- Iterators --
                std::tuple<J...>       _its;
                const std::tuple<J...> _ends;

                //  -- Temporaries --
                using deref_types = zip_tuple<decltype(*std::declval<I>()), decltype(*std::declval<J>())...>;
                std::optional<deref_types> value;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Zip(const I& begin_, const std::tuple<J...>& begins_, const I& end_, const std::tuple<J...>& ends_) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Increment / Decrement --
                constexpr inline Zip&      operator++() noexcept;
                constexpr inline const Zip operator++(int /*unused*/) noexcept;

                // //  -- Member Access --
                // constexpr inline auto operator*() noexcept;


                //  -- Member Access --
                constexpr auto& operator*() noexcept
                {
                    value.emplace(tuple::transform(std::tuple_cat(std::make_tuple(Iterator<I>::_it), _its), [](auto& it_) { return std::reference_wrapper(*it_); }));

                    return (*value);
                }
            };



        } // namespace iterator
    }     // namespace range
} // namespace arc


namespace std
{
    template <typename... Ts>
    struct tuple_size<arc::range::iterator::zip_tuple<Ts...>> : tuple_size<tuple<Ts...>>
    {
    };

    template <size_t I, typename... Ts>
    struct tuple_element<I, arc::range::iterator::zip_tuple<Ts...>> : tuple_element<I, tuple<remove_reference_t<Ts>...>>
    {
    };
} // namespace std
