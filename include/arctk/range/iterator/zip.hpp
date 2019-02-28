//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <iterator>
#include <tuple>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace iterator
        {



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


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Zip(const I& begin_, const std::tuple<J...>& begins_, const I& end_, const std::tuple<J...>& ends_) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Increment / Decrement --
                constexpr inline Zip& operator++() noexcept;
                constexpr inline Zip  operator++(const int /*unused*/) noexcept;

                //  -- Member Access --
                constexpr inline std::tuple<I, J...> operator*() noexcept;
            };



        } // namespace iterator
    }     // namespace range
} // namespace arc
