//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <iterator>
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace iterator
        {



            //  == CLASSES ==
            //  -- Transform --
            template <typename I, typename F>
            class Transform : public Iterator<I>
            {
                //  == ALIASES ==
              public:
                //  -- Traits --
                using value_type        = typename std::invoke_result_t<F, typename std::iterator_traits<I>::value_type>;
                using reference         = value_type;
                using pointer           = value_type;
                using difference_type   = typename Iterator<I>::difference_type;
                using iterator_category = typename Iterator<I>::iterator_category;


                //  == FIELDS ==
              private:
                //  -- Functors --
                const F _trans;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Transform(const I& start_, const I& end_, const F& trans_) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Increment / Decrement --
                constexpr inline Transform& operator++() noexcept;
                constexpr inline Transform  operator++(const int /*unused*/) noexcept;

                //  -- Member Access --
                constexpr inline reference operator*() noexcept;
            };



        } // namespace iterator
    }     // namespace range
} // namespace arc
