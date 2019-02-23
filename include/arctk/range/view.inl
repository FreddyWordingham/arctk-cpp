//  == GUARD ==
#pragma once



//  == DECLARATIONS ==
//  -- Arc --
#include "arctk/range/view.hpp" // IWYU pragma: export



//  == IMPORTS ==
//  -- Arc --
#include "arctk/range/iterator/forward/bidirectional/random.inl"

//  -- Std --
#include <utility>



//  == NAMESPACE ==
namespace arc
{
    namespace range
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename C>
        constexpr inline View<C>::View(const C& cont_) noexcept
          : _refs{init_refs(cont_)}
        {
        }

        template <typename C>
        constexpr inline View<C>::View(std::vector<reference>&& refs_) noexcept
          : _refs{refs_}
        {
        }


        //  -- Initialisation --
        template <typename C>
        constexpr inline std::vector<typename std::reference_wrapper<const typename C::value_type>> View<C>::init_refs(const C& cont_) noexcept
        {
            std::vector<reference> refs;
            refs.reserve(cont_.size());

            for (const auto& c : cont_) // TODO
            {
                refs.emplace_back(std::cref(c));
            }

            return (refs);
        }



        //  == OPERATORS ==
        //  --  Member Access --
        template <typename C>
        constexpr inline typename std::reference_wrapper<const typename C::value_type> View<C>::operator[](const std::size_t index_) noexcept
        {
            assert(index_ < _refs.size());

            return (_refs[index_]);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename C>
        constexpr inline typename View<C>::const_iterator View<C>::cbegin() const noexcept
        {
            return (_refs.cbegin());
        }

        template <typename C>
        constexpr inline typename View<C>::iterator View<C>::begin() noexcept
        {
            return (_refs.begin());
        }

        template <typename C>
        constexpr inline typename View<C>::const_iterator View<C>::cend() const noexcept
        {
            return (_refs.cend());
        }

        template <typename C>
        constexpr inline typename View<C>::iterator View<C>::end() noexcept
        {
            return (_refs.end());
        }



    } // namespace range
} // namespace arc
