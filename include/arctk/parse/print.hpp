/**
 *  @file   arctk/parse/print.hpp
 *  @date   21/10/2018
 *  @author Freddy Wordingham
 *
 *  Collection of parse printing operators.
 */



//  == GUARD ==
#ifndef ARCTK_PARSE_PRINT_HPP
#define ARCTK_PARSE_PRINT_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <map>
#include <ostream>
#include <string>
#include <tuple>
#include <utility>
#include <vector>


//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace parse //! parsing namespace
    {
        namespace print //! printing namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Tuple --
            template <typename... A, size_t... I>
            inline std::ostream& tuple_print_helper(std::ostream& stream_, const std::tuple<A...>& tup_, const std::index_sequence<I...>& /*unused*/) noexcept;



        } // namespace print
    }     // namespace parse
} // namespace arc



//  == OPERATOR PROTOTYPES ==
//  -- Io --
template <typename T, size_t N>
inline std::ostream& operator<<(std::ostream& stream_, const std::array<T, N>& arr_) noexcept;
template <typename T>
inline std::ostream& operator<<(std::ostream& stream_, const std::vector<T>& vec_) noexcept;
inline std::ostream& operator<<(std::ostream& stream_, const std::string& str_) noexcept;
template <typename T, typename S>
inline std::ostream& operator<<(std::ostream& stream_, const std::pair<T, S>& pair_) noexcept;
template <typename... A>
inline std::ostream& operator<<(std::ostream& stream_, const std::tuple<A...>& tup_) noexcept;
template <typename T, typename S>
inline std::ostream& operator<<(std::ostream& stream_, const std::map<T, S>& map_) noexcept;



//  == IMPLEMENTATION ==
#include <arctk/parse/print.inl>



//  == GUARD END ==
#endif // ARCTK_PARSE_PRINT_HPP
