/**
 *  @file   arctk/utl/pair.hpp
 *  @date   29/05/2018
 *  @author Freddy Wordingham
 *
 *  Pair utility functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_PAIR_HPP
#define ARCTK_UTL_PAIR_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <pair>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace utl //! utility namespace
    {



        //  == FUNCTION PROTOTYPES ==
        template <typename A0, typename A1, typename F>
        void apply(std::pair<A0, A1>& pair_, F func_);
        template <typename A0, typename A1, typename F>
        void apply(const std::pair<A0, A1>& pair_, F func_);
        template <typename A0, typename A1, typename F>
        void apply_with_index(std::pair<A0, A1>& pair_, F func_);
        template <typename A0, typename A1, typename F>
        void apply_with_index(const std::pair<A0, A1>& pair_, F func_);



        //  == FUNCTIONS ==
        /**
         *  Call a functor on each element of a pair.
         *
         *  @tparam A0  First type stored by the pair.
         *  @tparam A1  Second type stored by the pair.
         *  @tparam F   Type of functor to be applied.
         *
         *  @param  pair_   Pair to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename A0, typename A1, typename F>
        void apply(std::pair<A0, A1>& pair_, F func_)
        {
            func_(std::get<0>(pair_));
            func_(std::get<1>(pair_));
        }

        /**
         *  Call a functor on each element of a const pair.
         *
         *  @tparam A0  First type stored by the pair.
         *  @tparam A1  Second type stored by the pair.
         *  @tparam F   Type of functor to be applied.
         *
         *  @param  pair_   Pair to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename A0, typename A1, typename F>
        void apply(const std::pair<A0, A1>& pair_, F func_)
        {
            func_(std::get<0>(pair_));
            func_(std::get<1>(pair_));
        }

        /**
         *  Call a functor on each element of a pair.
         *  Provide the pair index and the total number of pair types.
         *
         *  @tparam A0  First type stored by the pair.
         *  @tparam A1  Second type stored by the pair.
         *  @tparam F   Type of functor to be applied.
         *
         *  @param  pair_   Pair to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename A0, typename A1, typename F>
        void apply_with_index(std::pair<A0, A1>& pair_, F func_)
        {
            func_(std::get<0>(pair_), 0, 2);
            func_(std::get<1>(pair_), 1, 2);
        }

        /**
         *  Call a functor on each element of a const pair.
         *  Provide the pair index and the total number of pair types.
         *
         *  @tparam A0  First type stored by the pair.
         *  @tparam A1  Second type stored by the pair.
         *  @tparam F   Type of functor to be applied.
         *
         *  @param  pair_   Pair to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename A0, typename A1, typename F>
        void apply_with_index(const std::pair<A0, A1>& pair_, F func_)
        {
            func_(std::get<0>(pair_), 0, 2);
            func_(std::get<1>(pair_), 1, 2);
        }



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_PAIR_HPP
