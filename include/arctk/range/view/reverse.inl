//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.inl"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view/reverse.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/random.inl"

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


            //  -- Instantiation --
            template <typename C>
            constexpr inline std::vector<typename Reverse<C>::reference> Reverse<C>::init_refs(const C& cont_) noexcept
            {
                std::vector<reference> refs;
                refs.reserve(cont_.size());

                for (const auto& c : cont_) // TODO
                {
                    refs.emplace_back(std::cref(c));
                }

                std::reverse(refs.begin(), refs.end()); // TODO

                return (refs);
            }



        } // namespace view
    }     // namespace range
} // namespace arc
