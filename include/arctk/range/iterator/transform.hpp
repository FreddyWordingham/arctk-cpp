//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator.hpp"



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
                using reference         = typename std::invoke_result_t<F, typename std::iterator_traits<I>::value_type>;
                using pointer           = typename std::iterator_traits<I>::pointer;
                using value_type        = typename std::remove_cv<std::remove_reference<reference>>::type;
                using difference_type   = typename std::iterator_traits<I>::difference_type;
                using iterator_category = typename std::iterator_traits<I>::iterator_category;


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
