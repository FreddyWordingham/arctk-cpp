/**
 *  @file   arctk/str/format.hpp
 *  @date   27/05/2018
 *  @author Freddy Wordingham
 *
 *  Formatting string functions.
 */



//  == GUARD ==
#ifndef ARCTK_STR_TABLE_HPP
#define ARCTK_STR_TABLE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <sstream>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace str //! string namespace
    {



        //  == FUNCTION PROTOTYPES ==
        template <typename C, typename I = typename C::const_iterator>
        inline std::string table(const C& cont_) noexcept;



        //  == FUNCTIONS ==
        /**
         *  Form a container into a tabulated string.
         *
         *  @tparam C   Container type.
         *  @tparam I   Iterator type of C.
         *
         *  @param  cont_   Container to form into a table string.
         *
         *  @return Tabulated string of cont_.
         */
        template <typename C, typename I = typename C::const_iterator>
        inline std::string table(const C& cont_) noexcept
        {
            std::stringstream stream;
            size_t            index = 0;

            for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
            {
                stream << index << "\t: " << *it << '\n';

                ++index;
            }

            return (stream.str());
        }



    } // namespace str
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_STR_TABLE_HPP
