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
        template <typename T, typename F, size_t... I>
        void apply_to_each(T&& tuple_, F func_, std::index_sequence<I...>);
        template <template <typename...> typename T, typename... Args, typename F>
        void apply(const T<Args...>& tuple_, F func_);



        //  == FUNCTIONS ==
        /**
         *  Apply helper function.
         *  Call a functor on each element of a functor.
         *
         *  @tparam T       Type of tuple.
         *  @tparam Args    Types stored by tuple.
         *  @tparam F       Functor to be applied.
         *
         *  @param  tuple_  Tuple to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename T, typename F, size_t... I>
        void apply_to_each(T&& tuple_, F func_, std::index_sequence<I...>)
        {
            ((func_(std::get<I>(tuple_)), 0), ...);
        }

        /**
         *  Apply a given functor to each element of a tuple.
         *
         *  @tparam T       Type of tuple.
         *  @tparam Args    Types stored by tuple.
         *  @tparam F       Functor to be applied.
         *
         *  @param  tuple_  Tuple to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <template <typename...> typename T, typename... Args, typename F>
        void apply(const T<Args...>& tuple_, F func_)
        {
            apply_to_each(tuple_, func_, std::index_sequence_for<Args...>{});
        }



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_TUPLE_HPP
