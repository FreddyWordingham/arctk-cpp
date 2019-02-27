//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator.inl"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator/transform.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace iterator
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename I, typename F>
            constexpr inline Transform<I, F>::Transform(const I& start_, const I& end_, const F& trans_) noexcept
              : Iterator<I>{start_, end_}
              , _trans{trans_}
            {
            }



            //  == OPERATORS ==
            //  -- Increment / Decrement --
            template <typename I, typename F>
            constexpr inline Transform<I, F>& Transform<I, F>::operator++() noexcept
            {
                assert(Iterator<I>::_it != Iterator<I>::_end);

                ++Iterator<I>::_it;

                return (*this);
            }

            template <typename I, typename F>
            constexpr inline Transform<I, F> Transform<I, F>::operator++(const int /*unused*/) noexcept
            {
                Transform<I, F> it{*this};

                ++(*this);

                return (it);
            }


            //  -- Member Access --
            template <typename I, typename F>
            constexpr inline typename Transform<I, F>::reference Transform<I, F>::operator*() noexcept
            {
                return (_trans(*Iterator<I>::_it));
            }



        } // namespace iterator
    }     // namespace range
} // namespace arc
