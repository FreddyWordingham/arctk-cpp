//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/preview/transform.hpp"

//  -- Std --
#include <type_traits>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace view
        {



            //  == CLASSES ==
            //  -- Transform --
            template <typename R, typename F>
            class Transform : public View<R>
            {
                //  == FIELDS ==
              private:
                //  -- Functor --
                const F _trans;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Transform(R& range_, const F& trans_) noexcept;


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
    constexpr inline range::view::Transform<R, F> operator|(R& range_, const range::preview::Transform<F>& trans_) noexcept;



} // namespace arc
