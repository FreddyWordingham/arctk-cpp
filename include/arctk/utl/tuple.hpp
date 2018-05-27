/**
 *  @file   arctk/utl/tuple.hpp
 *  @date   27/05/2018
 *  @author Freddy Wordingham
 *
 *  Tuple utility functions.
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
        template <typename... A, typename F, size_t... I>
        void apply_to_each(std::tuple<A...>& tuple_, F func_, std::index_sequence<I...> /*unused*/);
        template <typename... A, typename F>
        void apply(std::tuple<A...>& tuple_, F func_);
        template <typename... A, typename F, size_t... I>
        void apply_to_each(const std::tuple<A...>& tuple_, F func_, std::index_sequence<I...> /*unused*/);
        template <typename... A, typename F>
        void apply(const std::tuple<A...>& tuple_, F func_);
        template <typename... A, typename F, size_t... I>
        void apply_to_each_with_index(std::tuple<A...>& tuple_, F func_, std::index_sequence<I...> /*unused*/);
        template <typename... A, typename F>
        void apply_with_index(std::tuple<A...>& tuple_, F func_);
        template <typename... A, typename F, size_t... I>
        void apply_to_each_with_index(const std::tuple<A...>& tuple_, F func_, std::index_sequence<I...> /*unused*/);
        template <typename... A, typename F>
        void apply_with_index(const std::tuple<A...>& tuple_, F func_);



        //  == FUNCTIONS ==
        /**
         *  Apply helper function.
         *  Call a functor on each element of a const tuple.
         *
         *  @tparam T   Type of tuple.
         *  @tparam F   Type of functor to be applied.
         *  @tparam I   Indices of the tuple.
         *
         *  @param  tuple_  Tuple to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename... A, typename F, size_t... I>
        void apply_to_each(std::tuple<A...>& tuple_, F func_, std::index_sequence<I...> /*unused*/)
        {
            ((func_(std::get<I>(tuple_)), 0), ...);
        }

        /**
         *  Apply a given functor to each element of a tuple.
         *
         *  @tparam A   Types stored by tuple.
         *  @tparam F   Type of functor to be applied.
         *
         *  @param  tuple_  Tuple to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename... A, typename F>
        void apply(std::tuple<A...>& tuple_, F func_)
        {
            apply_to_each(tuple_, func_, std::index_sequence_for<A...>{});
        }

        /**
         *  Apply helper function.
         *  Call a functor on each element of a tuple.
         *
         *  @tparam T   Type of tuple.
         *  @tparam F   Type of functor to be applied.
         *  @tparam I   Indices of the tuple.
         *
         *  @param  tuple_  Tuple to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename... A, typename F, size_t... I>
        void apply_to_each(const std::tuple<A...>& tuple_, F func_, std::index_sequence<I...> /*unused*/)
        {
            ((func_(std::get<I>(tuple_)), 0), ...);
        }

        /**
         *  Apply a given functor to each element of a const tuple.
         *
         *  @tparam A   Types stored by tuple.
         *  @tparam F   Type of functor to be applied.
         *
         *  @param  tuple_  Tuple to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename... A, typename F>
        void apply(const std::tuple<A...>& tuple_, F func_)
        {
            apply_to_each(tuple_, func_, std::index_sequence_for<A...>{});
        }

        /**
         *  Apply with index helper function.
         *  Call a functor on each element of a tuple.
         *  Provide the current tuple index and the total number of tuple types.
         *
         *  @tparam T   Type of tuple.
         *  @tparam F   Type of functor to be applied.
         *  @tparam I   Indices of the tuple.
         *
         *  @param  tuple_  Tuple to be applied to.
         *  @param  func_   Functor to be applied.
         *  @param  seq_    Sequence of tuple indices.
         */
        template <typename... A, typename F, size_t... I>
        void apply_to_each_with_index(std::tuple<A...>& tuple_, F func_, std::index_sequence<I...> seq_)
        {
            ((func_(std::get<I>(tuple_), I, seq_.size()), 0), ...);
        }

        /**
         *  Apply a given functor to each element of a tuple.
         *  Current tuple index and the total number of tuple types are provided.
         *
         *  @tparam A   Types stored by tuple.
         *  @tparam F   Type of functor to be applied.
         *
         *  @param  tuple_  Tuple to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename... A, typename F>
        void apply_with_index(std::tuple<A...>& tuple_, F func_)
        {
            apply_to_each_with_index(tuple_, func_, std::index_sequence_for<A...>{});
        }

        /**
         *  Apply with index helper function.
         *  Call a functor on each element of a const tuple.
         *  Provide the current tuple index and the total number of tuple types.
         *
         *  @tparam T   Type of tuple.
         *  @tparam F   Type of functor to be applied.
         *  @tparam I   Indices of the tuple.
         *
         *  @param  tuple_  Tuple to be applied to.
         *  @param  func_   Functor to be applied.
         *  @param  seq_    Sequence of tuple indices.
         */
        template <typename... A, typename F, size_t... I>
        void apply_to_each_with_index(const std::tuple<A...>& tuple_, F func_, std::index_sequence<I...> seq_)
        {
            ((func_(std::get<I>(tuple_), I, seq_.size()), 0), ...);
        }

        /**
         *  Apply a given functor to each element of a const tuple.
         *  Current tuple index and the total number of tuple types are provided.
         *
         *  @tparam A   Types stored by tuple.
         *  @tparam F   Type of functor to be applied.
         *
         *  @param  tuple_  Tuple to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename... A, typename F>
        void apply_with_index(const std::tuple<A...>& tuple_, F func_)
        {
            apply_to_each_with_index(tuple_, func_, std::index_sequence_for<A...>{});
        }



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_TUPLE_HPP
