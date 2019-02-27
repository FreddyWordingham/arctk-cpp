//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator.inl" // IWYU pragma: export
                                    // IWYU pragma: no_include "arctk/range/iterator.hpp"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator/filter.hpp" // IWYU pragma: export



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
            constexpr inline Filter<I, F>::Filter(const I& start_, const I& end_, const F& pred_) noexcept
              : Iterator<I>{init_it(start_, end_, pred_), end_}
              , _pred{pred_}
            {
            }


            //  -- Initialisation --
            template <typename I, typename F>
            constexpr inline I Filter<I, F>::init_it(const I& start_, const I& end_, const F& pred_) noexcept
            {
                I it{start_};

                while (!pred_(*it) && (it != end_))
                {
                    ++it;
                }

                return (it);
            }



            //  == OPERATORS ==
            //  -- Increment / Decrement --
            template <typename I, typename F>
            constexpr inline Filter<I, F>& Filter<I, F>::operator++() noexcept
            {
                assert(Iterator<I>::_it != Iterator<I>::_end);

                ++Iterator<I>::_it;

                while (!_pred(*Iterator<I>::_it) && (Iterator<I>::_it != Iterator<I>::_end))
                {
                    ++Iterator<I>::_it;
                }

                return (*this);
            }

            template <typename I, typename F>
            constexpr inline Filter<I, F> Filter<I, F>::operator++(const int /*unused*/) noexcept
            {
                Filter<I, F> it{*this};

                ++(*this);

                return (it);
            }


            //  -- Member Access --
            template <typename I, typename F>
            constexpr inline typename Filter<I, F>::reference Filter<I, F>::operator*() noexcept
            {
                return (*Iterator<I>::_it);
            }



        } // namespace iterator
    }     // namespace range
} // namespace arc
