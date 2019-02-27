//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.hpp" // IWYU pragma: export



//  == IMPORTS ==
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
                //  == ALIASES ==
              public:
                //  -- Traits --
                using value_type = typename std::invoke_result_t<F, typename View<R>::value_type>;
                using size_type  = typename View<R>::size_type;


                //  == FIELDS ==
              private:
                //  -- Functor --
                const F _trans;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Transform(const R& range_, const F& trans_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                constexpr inline auto begin() noexcept;
                constexpr inline auto end() noexcept;
            };



        } // namespace view
    }     // namespace range
} // namespace arc
