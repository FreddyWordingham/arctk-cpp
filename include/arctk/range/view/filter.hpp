//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/preview/filter.hpp"



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace view
        {



            //  == CLASSES ==
            //  -- Filter --
            template <typename R, typename F>
            class Filter : public View<R>
            {
                //  == FIELDS ==
              private:
                //  -- Functor --
                const F _pred;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Filter(R& range_, const F& pred_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                constexpr inline auto begin() noexcept;
                constexpr inline auto begin() const noexcept;
                constexpr inline auto end() noexcept;
                constexpr inline auto end() const noexcept;
            };



        } // namespace view
    }     // namespace range



    //  == OPERATORS ==
    //  -- Pipe --
    template <typename R, typename F>
    constexpr inline range::view::Filter<R, F> operator|(R& range_, const range::preview::Filter<F>& filt_) noexcept;
    template <typename R, typename F>
    constexpr inline range::view::Filter<R, F> operator|(R&& range_, const range::preview::Filter<F>& filt_) noexcept;



} // namespace arc
