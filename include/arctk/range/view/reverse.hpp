//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.hpp" // IWYU pragma: export



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
                //  == ALIASES ==
              public:
                //  -- Traits --
                using value_type = typename View<R>::size_type;
                using size_type  = typename View<R>::size_type;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Reverse(const R& range_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                constexpr inline auto begin() noexcept;
                constexpr inline auto end() noexcept;
            };



        } // namespace view
    }     // namespace range
} // namespace arc
