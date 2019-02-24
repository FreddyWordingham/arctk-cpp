//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.inl"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view/transform.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/transform.inl"



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
            constexpr inline Transform<C, F>::Transform(const C& cont_, F trans_) noexcept
              : View<C>{cont_}
              , _trans{trans_}
            {
            }



            //  == OPERATORS ==
            //  --  Member Access --
            template <typename C, typename F>
            constexpr inline typename Transform<C, F>::value_type Transform<C, F>::operator[](const std::size_t index_) noexcept
            {
                return (_trans(View<C>::_refs[index_]));
            }



            //  == METHODS ==
            //  -- Getters --
            template <typename C, typename F>
            constexpr inline typename Transform<C, F>::const_iterator Transform<C, F>::cbegin() const noexcept
            {
                return (const_iterator{View<C>::_refs.cbegin(), _trans});
            }

            template <typename C, typename F>
            constexpr inline typename Transform<C, F>::iterator Transform<C, F>::begin() noexcept
            {
                return (iterator{View<C>::_refs.begin(), _trans});
            }

            template <typename C, typename F>
            constexpr inline typename Transform<C, F>::const_iterator Transform<C, F>::cend() const noexcept
            {
                return (const_iterator{View<C>::_refs.cend(), _trans});
            }

            template <typename C, typename F>
            constexpr inline typename Transform<C, F>::iterator Transform<C, F>::end() noexcept
            {
                return (iterator{View<C>::_refs.end(), _trans});
            }



        } // namespace view
    }     // namespace range
} // namespace arc
