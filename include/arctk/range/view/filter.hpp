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
                //  == ALIASES ==
              public:
                //  -- Traits --
                using value_type = typename View<R>::size_type;
                using size_type  = typename View<R>::size_type;


                //  == FIELDS ==
              private:
                //  -- Functor --
                const F _pred;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Filter(const R& range_, const F& pred_) noexcept;
                constexpr inline Filter(const R& range_, const preview::Filter<F>& filt_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                constexpr inline auto begin() const noexcept;
                constexpr inline auto end() const noexcept;
            };



        } // namespace view
    }     // namespace range



    //  == OPERATORS ==
    //  -- Pipe --
    template <typename R, typename F>
    constexpr inline range::view::Filter<R, F> operator|(const R& range_, const range::preview::Filter<F>& filt_) noexcept
    {
        return (range::view::Filter<R, F>{range_, filt_});
    }



} // namespace arc
