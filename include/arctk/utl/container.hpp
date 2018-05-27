/**
 *  @file   arctk/utl/container.hpp
 *  @date   27/05/2018
 *  @author Freddy Wordingham
 *
 *  Container utility functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_CONTAINER_HPP
#define ARCTK_UTL_CONTAINER_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace utl //! utility namespace
    {



        //  == FUNCTION PROTOTYPES ==
        template <typename C, typename I = typename C::iterator, typename F>
        inline void apply(C& cont_, F func_) noexcept;
        template <typename C, typename I = typename C::cont_iterator, typename F>
        inline void apply(const C& cont_, F func_) noexcept;



        //  == FUNCTIONS ==
        /**
         *  Apply a given functor to each element of a container.
         *
         *  @tparam C   Type of the container.
         *  @tparam I   Iterator of type C.
         *  @tparam F   Type of functor to be applied.
         *
         *  @param  cont_   Container to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename C, typename I, typename F>
        inline void apply(C& cont_, F func_) noexcept
        {
            for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
            {
                func_(*it);
            }
        }

        /**
         *  Apply a given functor to each element of a const container.
         *
         *  @tparam C   Type of the container.
         *  @tparam I   Iterator of type C.
         *  @tparam F   Type of functor to be applied.
         *
         *  @param  cont_   Container to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename C, typename I, typename F>
        inline void apply(const C& cont_, F func_) noexcept
        {
            for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
            {
                func_(*it);
            }
        }



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_CONTAINER_HPP
