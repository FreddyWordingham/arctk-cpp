//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/preview/skip.hpp"



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace view
        {



            //  == CLASSES ==
            //  -- Skip --
            template <typename R>
            class Skip : public View<R>
            {
                //  == ALIASES ==
              public:
                //  -- Traits --
                using value_type = typename View<R>::size_type;
                using size_type  = typename View<R>::size_type;


                //  == FIELDS ==
              private:
                //  -- Skips --
                const size_type _skip_first;
                const size_type _skip_last;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Skip(const R& range_, const size_type skip_first_, const size_type skip_last_ = 1) noexcept;


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
    template <typename R>
    constexpr inline range::view::Skip<R> operator|(const R& range_, const range::preview::Skip& skip_) noexcept;



} // namespace arc
