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
            //  -- Progress --
            template <typename I, typename T>
            class Progress : public Iterator<I>
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
                //  -- Stream --
                T& _stream;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Progress(const I& start_, const I& end_, T& stream_) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Increment / Decrement --
                constexpr inline Progress&      operator++() noexcept;
                constexpr inline const Progress operator++(int /*unused*/) noexcept;

                //  -- Member Access --
                constexpr inline reference operator*() noexcept;
            };



        } // namespace iterator
    }     // namespace range
} // namespace arc
