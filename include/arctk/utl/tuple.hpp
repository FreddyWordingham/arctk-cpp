/**
 *  @file   arctk/utl/tuple.hpp
 *  @date   27/05/2018
 *  @author Freddy Wordingham
 *
 *  Tuple utilitu functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_TUPLE_HPP
#define ARCTK_UTL_TUPLE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace utl //! utility namespace
    {



        //  == FUNCTION PROTOTYPES ==



        //  == FUNCTIONS ==
        template <typename T, typename F, size_t... Is>
        void for_each(T&& t, F f, std::index_sequence<Is...>)
        {
            auto l = {(f(std::get<Is>(t)), 0)...};
        }

        template <typename... Ts, typename F>
        void apply(std::tuple<Ts...> const& t, F f)
        {
            for_each(t, f, std::index_sequence_for<Ts...>{});
        }



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_TUPLE_HPP
