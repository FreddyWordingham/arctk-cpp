//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <iterator>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace iterator
        {



            //  == CLASSES ==
            //  -- Filter --
            template <typename I, typename F>
            class Filter : public Iterator<I>
            {
                //  == ALIASES ==
              public:
                //  -- Traits --
                using value_type        = typename Iterator<I>::value_type;
                using reference         = typename Iterator<I>::reference;
                using pointer           = typename Iterator<I>::pointer;
                using difference_type   = typename Iterator<I>::difference_type;
                using iterator_category = std::forward_iterator_tag;


                //  == FIELDS ==
              private:
                //  -- Functors --
                F _pred;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Filter(const I& start_, const I& end_, const F& pred_) noexcept;

              private:
                //  -- Initialisation --
                static constexpr inline I init_it(const I& start_, const I& end_, const F& pred_) noexcept;

                //  == OPERATORS ==
              public:
                //  -- Increment / Decrement --
                constexpr inline Filter&      operator++() noexcept;
                constexpr inline const Filter operator++(int /*unused*/) noexcept;

                //  -- Member Access --
                constexpr inline reference operator*() noexcept;
            };



        } // namespace iterator
    }     // namespace range
} // namespace arc
