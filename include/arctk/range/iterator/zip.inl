//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator.inl" // IWYU pragma: export
                                    // IWYU pragma: no_include "arctk/range/iterator.hpp"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator/zip.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arc --
#include "arctk/tuple/comparison.inl"
#include "arctk/tuple/transform.inl"



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace iterator
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename I, typename... J>
            constexpr inline Zip<I, J...>::Zip(const I& begin_, const std::tuple<J...>& begins_, const I& end_, const std::tuple<J...>& ends_) noexcept
              : Iterator<I>{begin_, end_}
              , _its{begins_}
              , _ends{ends_}
            {
            }



            //  == OPERATORS ==
            //  -- Increment / Decrement --
            template <typename I, typename... J>
            constexpr inline Zip<I, J...>& Zip<I, J...>::operator++() noexcept
            {
                assert(Iterator<I>::_it != Iterator<I>::_end);
                // assert(tuple::num_equal_elems(_its, _ends) == 0);

                ++Iterator<I>::_it;

                tuple::for_each(&_its, [](auto&& it_) { ++it_; });

                return (*this);
            }

            template <typename I, typename... J>
            constexpr inline const Zip<I, J...> Zip<I, J...>::operator++(const int /*unused*/) noexcept
            {
                Zip<I, J...> it{*this};

                ++(*this);

                return (it);
            }



            // //  -- Member Access --
            template <typename I, typename... J>
            constexpr inline auto& Zip<I, J...>::operator*() noexcept
            {
                _value.emplace(tuple::transform(std::tuple_cat(std::make_tuple(Iterator<I>::_it), _its), [](auto& it_) { return std::reference_wrapper(*it_); }));

                assert(_value);

                return (*_value);
            }



        } // namespace iterator
    }     // namespace range
} // namespace arc
