//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include <arctk/range/view.hpp>



//  == IMPORTS ==
//  -- Arc --
#include <arctk/range/iterator/forward.hpp>

//  -- Std --
#include <functional>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {
        namespace view
        {



            //  == CLASSES ==
            //  -- Forward --
            template <typename C, typename F>
            class Filter : public View<C>
            {
                //  == ALIASES ==
              public:
                //  -- Values --
                using value_type = typename C::value_type;


                //  == FIELDS ==
              private:
                //  -- Condition --
                F _condition;

                //  -- Data --
                std::vector<const value_type*> _data;



                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                constexpr inline Filter(F condition_, const C& cont_) noexcept;

              private:
                //  -- Initialisation --
                constexpr inline std::vector<const value_type*> init_data(F condition_, const C& cont_) const noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                constexpr inline const std::function<bool(const value_type&)>& condition() const noexcept;

                //  -- Iterators --
                constexpr inline iterator::Forward<value_type> begin() const noexcept;
                constexpr inline iterator::Forward<value_type> end() const noexcept;
            };



        } // namespace view
    }     // namespace range
} // namespace arc
