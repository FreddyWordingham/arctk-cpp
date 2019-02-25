//  == GUARD ==
#pragma once



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == FUNCTIONS ==
        //  -- Transform --
        template <typename R, typename F>
        constexpr inline void transform(R& range_, F func_) noexcept;
        template <typename R, typename F, typename Ro>
        constexpr inline void transform(R& range_, F func_, Ro& range_out_) noexcept;



    } // namespace range
} // namespace arc
