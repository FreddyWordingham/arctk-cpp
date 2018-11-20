/**
 *  @file   arctk/parse/read.hpp
 *  @date   21/10/2018
 *  @author Freddy Wordingham
 *
 *  Read parsing functions.
 */



//  == GUARD ==
#ifndef ARCTK_PARSE_READ_HPP
#define ARCTK_PARSE_READ_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cstddef>
#include <map>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

//  -- Arctk --
#include <arctk/math/mat.hpp>
#include <arctk/math/vec.hpp>
#include <arctk/type/tag.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace parse //! parsing namespace
    {
        namespace read //! reading namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Parsing --
            template <typename T>
            inline T string(std::string* str_) noexcept;
            template <typename T>
            inline T file(const std::string& path_) noexcept;


            //  -- Helpers --
            template <typename T>
            inline T helper(type::Tag<T> /*unused*/, std::string* str_) noexcept;
            template <>
            inline bool helper(type::Tag<bool> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline std::vector<T> helper(type::Tag<std::vector<T>> /*unused*/, std::string* str_) noexcept;
            template <typename T, size_t N>
            inline std::array<T, N> helper(type::Tag<std::array<T, N>> /*unused*/, std::string* str_) noexcept;
            template <>
            inline std::string helper(type::Tag<std::string> /*unused*/, std::string* str_) noexcept;
            template <typename T, typename S>
            inline std::pair<T, S> helper(type::Tag<std::pair<T, S>> /*unused*/, std::string* str_) noexcept;
            template <typename... A>
            inline std::tuple<A...> helper(type::Tag<std::tuple<A...>> /*unused*/, std::string* str_) noexcept;
            template <typename... A, size_t... I>
            inline std::tuple<A...> parse_helper(type::Tag<std::tuple<A...>> /*unused*/, std::vector<std::string>* tokens_, const std::index_sequence<I...>& /*unused*/) noexcept;
            template <typename T, typename S>
            inline std::map<T, S> helper(type::Tag<std::map<T, S>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Vec<T, 2> helper(type::Tag<math::Vec<T, 2>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Vec<T, 3> helper(type::Tag<math::Vec<T, 3>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Vec<T, 4> helper(type::Tag<math::Vec<T, 4>> /*unused*/, std::string* str_) noexcept;
            template <typename T, size_t N>
            inline math::Vec<T, N> helper(type::Tag<math::Vec<T, N>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Mat<T, 2> helper(type::Tag<math::Mat<T, 2>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Mat<T, 3> helper(type::Tag<math::Mat<T, 3>> /*unused*/, std::string* str_) noexcept;
            template <typename T>
            inline math::Mat<T, 4> helper(type::Tag<math::Mat<T, 4>> /*unused*/, std::string* str_) noexcept;
            template <typename T, size_t N>
            inline math::Mat<T, N> helper(type::Tag<math::Mat<T, N>> /*unused*/, std::string* str_) noexcept;



        } // namespace read
    }     // namespace parse
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/parse/read.inl>



//  == GUARD END ==
#endif // ARCTK_PARSE_READ_HPP
