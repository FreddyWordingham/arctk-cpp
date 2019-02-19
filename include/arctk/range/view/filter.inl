//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view/filter.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include <iostream>



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
            constexpr inline Filter<C, F>::Filter(F condition_, const C& cont_) noexcept
              : _condition{condition_}
              , _data{init_data(condition_, cont_)}
            {
            }


            //  -- Initialisation --
            template <typename C, typename F>
            constexpr inline std::vector<const typename Filter<C, F>::value_type*> Filter<C, F>::init_data(F condition_, const C& cont_) const noexcept
            {
                std::vector<const value_type*> data{};

                for (const auto& c : cont_)
                {
                    if (condition_(c))
                    {
                        data.emplace_back(&c);
                    }
                }

                return (data);
            }



            //  == METHODS ==
            //  -- Getters --
            template <typename C, typename F>
            constexpr inline const std::function<bool(const typename Filter<C, F>::value_type&)>& Filter<C, F>::condition() const noexcept
            {
                return (_condition);
            }


            //  -- Iterators --
            template <typename C, typename F>
            constexpr inline iterator::Forward<typename Filter<C, F>::value_type> Filter<C, F>::begin() const noexcept
            {
                return (iterator::Forward<value_type>{*_data.begin()});
            }

            template <typename C, typename F>
            constexpr inline iterator::Forward<typename Filter<C, F>::value_type> Filter<C, F>::end() const noexcept
            {
                return (iterator::Forward<value_type>{*_data.end()});
            }



        } // namespace view
    }     // namespace range
} // namespace arc
