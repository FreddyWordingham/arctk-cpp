/**
 *  @file   arctk/search/container.hpp
 *  @date   25/05/2018
 *  @author Freddy Wordingham
 *
 *  Container property functions.
 */



//  == GUARD ==
#ifndef ARCTK_PROPERTIES_CONTAINER_HPP
#define ARCTK_PROPERTIES_CONTAINER_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace prop //! properties namespace
    {



        //  == FUNCTION PROTOTYPES ==
        template <typename C>
        inline size_t size(const C& cont_) noexcept;



        //  == FUNCTIONS ==
        /**
         *  Calculate the size of a container.
         *
         *  @param  cont_   Container to determine the size of.
         *
         *  @return Size of the container.
         */
        template <typename C>
        inline size_t size(const C& cont_) noexcept
        {
            return (std::distance(std::begin(cont_), std::end(cont_)));
        }



    } // namespace prop
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PROPERTIES_CONTAINER_HPP
