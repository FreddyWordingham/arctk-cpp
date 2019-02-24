//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.hpp"



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/random.inl"



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
                //  -- Types --
                using value_type     = typename C::value_type;
                using reference      = typename std::reference_wrapper<const value_type>;
                using const_iterator = iterator::Random<typename std::vector<reference>::const_iterator>;
                using iterator       = iterator::Random<typename std::vector<reference>::iterator>;


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
