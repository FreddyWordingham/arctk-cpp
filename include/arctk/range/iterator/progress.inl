//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/iterator.inl" // IWYU pragma: export
                                    // IWYU pragma: no_include "arctk/range/iterator.hpp"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/iterator/progress.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/fmt/progress.inl"

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
            template <typename I, typename T>
            constexpr inline Progress<I, T>::Progress(const I& start_, const I& end_, T& stream_, const int length_, const std::size_t expected_) noexcept
              : Iterator<I>{start_, end_}
              , _current{0}
              , _expected{expected_}
              , _stream{stream_}
              , _length{length_}
            {
                assert(_expected > 0);
                assert(_expected > 0);
                assert(length_ > 10); // TODO
            }



            //  == OPERATORS ==
            //  -- Increment / Decrement --
            template <typename I, typename T>
            constexpr inline Progress<I, T>& Progress<I, T>::operator++() noexcept
            {
                assert(Iterator<I>::_it != Iterator<I>::_end);

                _stream << fmt::progress(_length, static_cast<double>(_current) / _expected) << '\n';

                ++_current;
                ++Iterator<I>::_it;

                return (*this);
            }

            template <typename I, typename T>
            constexpr inline const Progress<I, T> Progress<I, T>::operator++(const int /*unused*/) noexcept
            {
                Progress<I, I> it{*this};

                ++(*this);

                return (it);
            }


            //  -- Member Access --
            template <typename I, typename T>
            constexpr inline typename Progress<I, T>::reference Progress<I, T>::operator*() noexcept
            {
                return (*Iterator<I>::_it);
            }



        } // namespace iterator
    }     // namespace range
} // namespace arc
