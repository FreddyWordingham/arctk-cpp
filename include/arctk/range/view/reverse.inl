//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view/reverse.hpp" // IWYU pragma: export



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.inl" // IWYU pragma: export



//  == IMPORTS ==
//  -- Std --
#include <algorithm>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace view
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename C>
            constexpr inline Reverse<C>::Reverse(const C& cont_) noexcept
              : View<C>{init_refs(cont_)}
            {
            }


            //  -- Initialisation --
            template <typename C>
            constexpr inline std::vector<typename View<C>::reference> Reverse<C>::init_refs(const C& cont_) noexcept
            {
                std::vector<typename View<C>::reference> refs;
                refs.reserve(cont_.size());

                for (const auto& c : cont_)
                {
                    refs.emplace_back(std::cref(c));
                }

                std::reverse(refs.begin(), refs.end());

                return (refs);
            }



        } // namespace view
    }     // namespace range
} // namespace arc
