/**
 *  @file   arctk/utl/pair.hpp
 *  @date   27/05/2018
 *  @author Freddy Wordingham
 *
 *  Pair utility functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_PAIR_HPP
#define ARCTK_UTL_PAIR_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



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


        //  == FUNCTIONS ==
        template <typename A0, typename A1, typename F>
        void apply(std::pair<A0, A1>& pair_, F func_)
        {
            func_(std::get<0>(pair_));
            func_(std::get<1>(pair_));
        }

        template <typename A0, typename A1, typename F>
        void apply(const std::pair<A0, A1>& pair_, F func_)
        {
            func_(std::get<0>(pair_));
            func_(std::get<1>(pair_));
        }



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_PAIR_HPP
