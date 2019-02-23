//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.inl"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view/filter.hpp" // IWYU pragma: export



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace view
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename C, typename F>
            constexpr inline Filter<C, F>::Filter(const C& cont_, const F& condition_) noexcept
              : View<C>{init_refs(cont_, condition_)}
              , _condition{condition_}
            {
            }


            //  -- Instantiation --
            template <typename C, typename F>
            constexpr inline std::vector<typename Filter<C, F>::reference> Filter<C, F>::init_refs(const C& cont_, F condition_) noexcept
            {
                std::vector<reference> refs;

                for (const auto& c : cont_) // TODO
                {
                    if (condition_(c))
                    {
                        refs.emplace_back(std::cref(c));
                    }
                }

                return (refs);
            }



        } // namespace view
    }     // namespace range
} // namespace arc
