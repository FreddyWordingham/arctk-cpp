//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator/filter.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --



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
            constexpr inline Filter<I, F>::Filter(I* const start_, const I& end_, F pred_) noexcept
              : _it(*start_)
              , _end(end_)
              , _pred(pred_)
            {
            }


            //  -- Initialisation --
            template <typename I, typename F>
            static constexpr inline I Filter<I, F>::init_it(I* const start_, const I& end_, F pred_) noexcept
            {
                I it{start_};

                while (!pred_(*it) || (it == end_))
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
                ++_it;

                while (!_pred(*_it) && (_it != _end))
                {
                    ++_it;
                }

                return (*this);
            }

            template <typename I, typename F>
            constexpr inline Filter<I, F> Filter<I, F>::operator++(const int /*unused*/) noexcept
            {
                Filter<I> it{*this};

                ++(*this);

                return (it);
            }


            //  -- Comparison --
            template <typename I, typename F>
            constexpr inline bool Filter<I, F>::operator==(const Filter<I, F>& rhs_) const noexcept
            {
                return (Filter<I, F>::_it == rhs_._it);
            }

            template <typename I, typename F>
            constexpr inline bool Filter<I, F>::operator!=(const Filter<I, F>& rhs_) const noexcept
            {
                return (Filter<I, F>::_it != rhs_._it);
            }


            //  -- Member Access --
            template <typename I, typename F>
            constexpr inline Filter<I, F>::reference Filter<I, F>::operator*() noexcept
            {
                return (*it_);
            }



        } // namespace iterator
    }     // namespace range
} // namespace arc
