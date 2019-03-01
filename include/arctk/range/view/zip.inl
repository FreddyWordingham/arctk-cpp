//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.inl" // IWYU pragma: export
                                // IWYU pragma: no_include "arctk/range/view.hpp"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view/zip.hpp" // IWYU pragma: export, keep



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/zip.inl"
#include "arctk/range/preview/zip.inl"



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
                auto begin_extractor = [](const auto& r_) { return (r_.begin()); };
                auto end_extractor   = [](const auto& r_) { return (r_.end()); };

                return (iterator::Zip{View<R>::_range.begin(), tuple::transform(_ranges, begin_extractor), View<R>::_range.end(), tuple::transform(_ranges, end_extractor)});
            }

            template <typename R, typename... A>
            constexpr inline auto Zip<R, A...>::end() const noexcept
            {
                auto end_extractor = [](const auto& r_) { return (r_.end()); };

                return (iterator::Zip{View<R>::_range.end(), tuple::transform(_ranges, end_extractor), View<R>::_range.end(), tuple::transform(_ranges, end_extractor)});
            }



        } // namespace view
    }     // namespace range



    //  == OPERATORS ==
    //  -- Pipe --



} // namespace arc
