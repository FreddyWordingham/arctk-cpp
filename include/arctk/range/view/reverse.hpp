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
            //  -- Reverse --
            template <typename C>
            class Reverse : public View<C>
            {
                //  == ALIASES ==
              private:
                //  -- Iterator --
                using reference = typename View<C>::reference;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Reverse(const C& cont_) noexcept;

              private:
                //  -- Instantiation --
                constexpr inline std::vector<reference> init_refs(const C& cont_) noexcept;
            };



        } // namespace view
    }     // namespace range
} // namespace arc
