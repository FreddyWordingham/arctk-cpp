//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.hpp"



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
                constexpr inline Filter(R* const range_, const F& pred_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                constexpr inline auto begin() noexcept;
                constexpr inline auto end() noexcept;
            };



        } // namespace view
    }     // namespace range
} // namespace arc
