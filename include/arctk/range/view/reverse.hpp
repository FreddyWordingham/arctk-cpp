//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/preview/reverse.hpp"



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace view
        {



            //  == CLASSES ==
            //  -- Reverse --
            template <typename R>
            class Reverse : public View<R>
            {
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Reverse(const R& range_) noexcept;


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
    constexpr inline range::view::Reverse<R> operator|(const R& range_, const range::preview::Reverse& /*unused*/) noexcept;



} // namespace arc
