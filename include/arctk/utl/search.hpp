/**
 *  @file   arctk/utl/search.hpp
 *  @date   05/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection of searching functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_SEARCH_HPP
#define ARCTK_UTL_SEARCH_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/debug.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace utl //! utility namespace
    {
        namespace search //! searching namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Limits --
            template <typename C, typename T = typename C::value_type, typename IT = typename C::const_iterator>
            inline size_t min_index(const C& cont_) noexcept;



            //  == FUNCTIONS ==
            //  -- Limits --
            /**
             *  Find the index of the minimum element within a container.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to determine the minimum element index of.
             *
             *  @pre    cont_ must not be empty.
             *
             *  @return Index of the minimum element within the container.
             */
            template <typename C, typename T, typename IT>
            inline size_t min_index(const C& cont_) noexcept
            {
                PRE(!cont_.empty());

                IT min_index = std::begin(cont_);

                for (IT it = std::next(std::begin(cont_)); it != std::end(cont_); std::advance(it, 1))
                {
                    if (*it < *min_index)
                    {
                        min_index = it;
                    }
                }

                return (std::distance(std::begin(cont_), min_index));
            }



        } // namespace search
    }     // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_SEARCH_HPP
