/**
 *  @file   arctk/str/format.hpp
 *  @date   27/05/2018
 *  @author Freddy Wordingham
 *
 *  Table formatting string functions.
 */



//  == GUARD ==
#ifndef ARCTK_STR_TABLE_HPP
#define ARCTK_STR_TABLE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==



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
        }



    } // namespace str
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_STR_TABLE_HPP
