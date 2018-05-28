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



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace format //! formatting namespace
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

            for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
            {
                stream << *it << '\n';
            }

            return (stream.str());
        }



    } // namespace format
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_FORMAT_CONTAINER_HPP
