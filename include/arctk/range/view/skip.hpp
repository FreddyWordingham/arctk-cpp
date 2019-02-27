//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/preview/skip.hpp"

//  -- Std --
#include <cstddef>



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
                //  == FIELDS ==
              private:
                //  -- Skips --
                const std::size_t _skip_first;
                const std::size_t _skip_last;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Skip(const R& range_, const std::size_t skip_first_, const std::size_t skip_last_ = 1) noexcept;


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
