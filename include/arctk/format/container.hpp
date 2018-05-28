/**
 *  @file   arctk/format.hpp
 *  @date   28/05/2018
 *  @author Freddy Wordingham
 *
 *  Container formatting functions.
 */



//  == GUARD ==
#ifndef ARCTK_FORMAT_CONTAINER_HPP
#define ARCTK_FORMAT_CONTAINER_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <sstream>
#include <string>
#include <tuple>
#include <utility>

#include <arctk/str.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace format //! formatting namespace
    {



        //  == FUNCTION PROTOTYPES ==
        template <typename C, typename I = typename C::const_iterator>
        inline std::string table(const C& cont_, const std::string& delim_ = ", ") noexcept;



        //  == FUNCTIONS ==
        /**
         *  Form a container into a tabulated string.
         *
         *  @tparam C   Container type.
         *  @tparam I   Iterator type of C.
         *
         *  @param  cont_   Container to form into a table string.
         *  @param  delim_  Delimiter string.
         *
         *  @return Tabulated string of cont_.
         */
        template <typename C, typename I = typename C::const_iterator>
        inline std::string table(const C& cont_, const std::string& delim_) noexcept
        {
            std::stringstream stream;

            for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
            {
                stream << str::to_string(tup_, "", delim_, "") << '\n';
            }

            return (stream.str());
        }



    } // namespace format
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_FORMAT_CONTAINER_HPP
