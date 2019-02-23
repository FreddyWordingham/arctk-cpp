//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.hpp"



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace view
        {



            //  == CLASSES ==
            //  -- Filter --
            template <typename C, typename F>
            class Filter : public View<C>
            {
                //  == ALIASES ==
              private:
                //  -- Iterator --
                using reference = typename View<C>::reference;


                //  == FIELDS ==
              private:
                //  -- Condition --
                F _condition;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Filter(const C& cont_, const F& condition_) noexcept;

              private:
                //  -- Instantiation --
                constexpr inline std::vector<reference> init_refs(const C& cont_, F condition_) noexcept;
            };



        } // namespace view
    }     // namespace range
} // namespace arc
