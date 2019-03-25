//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.inl" // IWYU pragma: export
                                // IWYU pragma: no_include "arctk/range/view.hpp"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view/progress.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/progress.inl" // IWYU pragma: keep
#include "arctk/range/preview/progress.inl"  // IWYU pragma: keep
#include "arctk/range/properties.inl"

//  -- Std --
#include <cassert>
#include <iterator>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace view
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename R, typename T>
            constexpr inline Progress<R, T>::Progress(R& range_, T& stream_, const int length_, const std::size_t expected_) noexcept
              : View<R>{range_}
              , _current{0}
              , _expected{expected_}
              , _stream{stream_}
              , _length{length_}
            {
                assert(length_ > 10); // TODO
            }



            //  == METHODS ==
            //  -- Getters --
            template <typename R, typename T>
            constexpr inline auto Progress<R, T>::begin() noexcept
            {
                return (iterator::Progress{std::begin(View<R>::_range), std::end(View<R>::_range), _stream, _length, _expected});
            }

            template <typename R, typename T>
            constexpr inline auto Progress<R, T>::begin() const noexcept
            {
                return (iterator::Progress{std::cbegin(View<R>::_range), std::cend(View<R>::_range), _stream, _length, _expected});
            }

            template <typename R, typename T>
            constexpr inline auto Progress<R, T>::end() noexcept
            {
                return (iterator::Progress{std::end(View<R>::_range), std::end(View<R>::_range), _stream, _length, _expected});
            }

            template <typename R, typename T>
            constexpr inline auto Progress<R, T>::end() const noexcept
            {
                return (iterator::Progress{std::cend(View<R>::_range), std::cend(View<R>::_range), _stream, _length, _expected});
            }



        } // namespace view
    }     // namespace range



    //  == OPERATORS ==
    //  -- Pipe --
    template <typename R, typename T>
    constexpr inline range::view::Progress<R, T> operator|(R& range_, const range::preview::Progress<T>& prog_) noexcept
    {
        return (range::view::Progress<R, T>{range_, prog_.stream, prog_.length, range::num_its(range_)});
    }

    template <typename R, typename T>
    constexpr inline range::view::Progress<R, T> operator|(R&& range_, const range::preview::Progress<T>& prog_) noexcept
    {
        return (range::view::Progress<R, T>{range_, prog_.stream, prog_.length, range::num_its(range_)});
    }



} // namespace arc
