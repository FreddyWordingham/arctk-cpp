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
            constexpr inline Progress<I, T>::Progress(const I& start_, const I& end_, T& stream_) noexcept
              : Iterator<I>{start_, end_}
              , _stream{stream_}
            {
            }



            //  == OPERATORS ==
            //  -- Increment / Decrement --
            template <typename I, typename T>
            constexpr inline Progress<I, T>& Progress<I, T>::operator++() noexcept
            {
                assert(Iterator<I>::_it != Iterator<I>::_end);

                _stream << "Tick\n";

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
