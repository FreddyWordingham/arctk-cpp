//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.inl" // IWYU pragma: export
                                // IWYU pragma: no_include "arctk/range/view.hpp"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view/zip.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/zip.inl" // IWYU pragma: keep
#include "arctk/tuple/transform.inl"

//  -- Std --
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
            template <typename R, typename... A>
            constexpr inline Zip<R, A...>::Zip(const R& range_, const A&... ranges_) noexcept
              : View<R>{range_}
              , _ranges{ranges_...}
            {
            }



            //  == METHODS ==
            //  -- Getters --
            template <typename R, typename... A>
            constexpr inline auto Zip<R, A...>::begin() const noexcept
            {
                auto begin_extractor = [](const auto& r_) { return (std::begin(r_)); };
                auto end_extractor   = [](const auto& r_) { return (std::end(r_)); };

                return (iterator::Zip{std::begin(View<R>::_range), tuple::transform(_ranges, begin_extractor), std::end(View<R>::_range), tuple::transform(_ranges, end_extractor)});
            }

            template <typename R, typename... A>
            constexpr inline auto Zip<R, A...>::end() const noexcept
            {
                auto end_extractor = [](const auto& r_) { return (std::end(r_)); };

                return (iterator::Zip{std::end(View<R>::_range), tuple::transform(_ranges, end_extractor), std::end(View<R>::_range), tuple::transform(_ranges, end_extractor)});
            }



        } // namespace view
    }     // namespace range



    //  == OPERATORS ==
    //  -- Pipe -- // TODO ?



} // namespace arc
