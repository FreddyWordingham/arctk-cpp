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
        inline std::string row(const std::string& str_) noexcept;
        template <typename T>
        inline std::string row(const T val_) noexcept;
        template <typename C, typename I = typename C::const_iterator>
        inline std::string row(const C& cont_) noexcept;
        template <typename A0, typename A1>
        inline std::string row(const std::pair<A0, A1>& pair_) noexcept;
        template <typename... A>
        inline std::string row(const std::tuple<A...>& tup_) noexcept;
        template <typename C, typename I = typename C::const_iterator>
        inline std::string table(const C& cont_) noexcept;


        //  == FUNCTIONS ==
        inline std::string row(const std::string& str_) noexcept
        {
            return (str_);
        }

        template <typename T>
        inline std::string row(const T val_) noexcept
        {
            return (std::to_string(val_));
        }

        template <typename C, typename I = typename C::const_iterator>
        inline std::string row(const C& cont_) noexcept
        {
            return (str::to_string(cont_, "", ", ", ""));
        }

        template <typename A0, typename A1>
        inline std::string row(const std::pair<A0, A1>& pair_) noexcept
        {
            return (str::to_string(pair_, "", ", ", ""));
        }

        template <typename... A>
        inline std::string row(const std::tuple<A...>& tup_) noexcept
        {
            return (str::to_string(tup_, "", ", ", ""));
        }

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
                stream << row(*it) << '\n';
            }

            return (stream.str());
        }



    } // namespace format
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_FORMAT_CONTAINER_HPP
