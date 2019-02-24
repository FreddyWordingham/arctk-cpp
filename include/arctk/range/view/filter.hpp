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
            //  -- Filter --
            template <typename C, typename F>
            class Filter : public View<C>
            {
                //  == ALIASES ==
              public:
                //  -- Types --
                using value_type     = typename C::value_type;
                using reference      = typename std::reference_wrapper<const value_type>;
                using const_iterator = iterator::Random<typename std::vector<reference>::const_iterator>;
                using iterator       = iterator::Random<typename std::vector<reference>::iterator>;


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
