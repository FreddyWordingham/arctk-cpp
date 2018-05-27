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
        template <typename C, typename I = typename C::const_iterator>
        inline std::string table(const C& cont_) noexcept
        {
            std::stringstream stream;

            for (I it = std::begin(cont_); it != std::prev(std::end(cont_)); std::advance(it, 1))
            {
                stream << *it << '\n';
            }

            return (stream.str());
        }



    } // namespace str
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_STR_TABLE_HPP
