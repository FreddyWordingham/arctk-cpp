//  == GUARD ==
#pragma once



//  == BASE ==
//  -- Arc --
#include "arctk/range/view.inl"



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view/transform.hpp" // IWYU pragma: export



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
            constexpr inline typename Transform<C, F>::trans_type Transform<C, F>::operator[](const std::size_t index_) noexcept
            {
                return (F(_trans(View<C>::_refs[index_])));
            }



            //  == METHODS ==
            //  -- Getters --
            template <typename C, typename F>
            constexpr inline typename Transform<C, F>::const_iterator Transform<C, F>::cbegin() const noexcept
            {
            }

            template <typename C, typename F>
            constexpr inline typename Transform<C, F>::iterator Transform<C, F>::begin() noexcept
            {
            }

            template <typename C, typename F>
            constexpr inline typename Transform<C, F>::const_iterator Transform<C, F>::cend() const noexcept
            {
            }

            template <typename C, typename F>
            constexpr inline typename Transform<C, F>::iterator Transform<C, F>::end() noexcept
            {
            }



        } // namespace view
    }     // namespace range
} // namespace arc
