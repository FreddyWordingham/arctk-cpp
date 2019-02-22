//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/"



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
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Reverse(const C& cont_) noexcept;

              private:
                //  -- Initialisation --
                constexpr inline std::vector<typename View<C>::reference> init_refs(const C& cont_) noexcept;
            };



        } // namespace view
    }     // namespace range
} // namespace arc
