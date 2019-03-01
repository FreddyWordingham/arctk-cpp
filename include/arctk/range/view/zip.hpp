//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/preview/zip.hpp"

//  -- Std --
#include <tuple>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace view
        {



            //  == CLASSES ==
            //  -- Reverse --
            template <typename R, typename... A>
            class Zip : public View<R>
            {
                const std::tuple<const A&...> _ranges;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline explicit Zip(const R& range_, const A&... ranges_) noexcept;


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
    template <typename... A>
    constexpr inline auto operator|(const std::tuple<const A&...>& ranges_, const range::preview::Zip& zip_) noexcept;



} // namespace arc
