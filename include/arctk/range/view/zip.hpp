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
                //  == FIELDS ==
              private:
                //  -- Iterators --
                const std::tuple<A&...> _ranges;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline explicit Zip(R& range_, A&... ranges_) noexcept;
                constexpr inline explicit Zip(R& range_, A&&... ranges_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                constexpr inline auto begin() const noexcept;
                constexpr inline auto end() const noexcept;
            };



        } // namespace view
    }     // namespace range
} // namespace arc
