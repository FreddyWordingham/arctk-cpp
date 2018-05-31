/**
 *  @file   arctk/utl/container.hpp
 *  @date   29/05/2018
 *  @author Freddy Wordingham
 *
 *  Container utility functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_CONTAINER_HPP
#define ARCTK_UTL_CONTAINER_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace utl //! utility namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Apply --
        template <typename C, typename T = typename C::value_type, typename I = typename C::iterator, typename F>
        inline void apply(C& cont_, F func_) noexcept;
        template <typename C, typename T = typename C::value_type, typename I = typename C::cont_iterator, typename F>
        inline void apply(const C& cont_, F func_) noexcept;
        template <typename C, typename T = typename C::value_type, typename I = typename C::iterator, typename F>
        inline void apply_with_index(C& cont_, F func_) noexcept;
        template <typename C, typename T = typename C::value_type, typename I = typename C::cont_iterator, typename F>
        inline void apply_with_index(const C& cont_, F func_) noexcept;



        //  == FUNCTIONS ==
        //  -- Apply --
        /**
         *  Apply a given functor to each element of a container.
         *
         *  @tparam C   Type of container.
         *  @tparam T   Type stored by C.
         *  @tparam I   Type of const iterator of C.
         *  @tparam F   Type of functor to be applied.
         *
         *  @param  cont_   Container to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename C, typename T, typename I, typename F>
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
         *  @tparam C   Type of container.
         *  @tparam T   Type stored by C.
         *  @tparam I   Type of const iterator of C.
         *  @tparam F   Type of functor to be applied.
         *
         *  @param  cont_   Container to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename C, typename T, typename I, typename F>
        inline void apply(const C& cont_, F func_) noexcept
        {
            for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
            {
                func_(*it);
            }
        }

        /**
         *  Apply a given functor to each element of a container.
         *  Provide the current element index and the total number of elements.
         *
         *  @tparam C   Type of container.
         *  @tparam T   Type stored by C.
         *  @tparam I   Type of const iterator of C.
         *  @tparam F   Type of functor to be applied.
         *
         *  @param  cont_   Container to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename C, typename T, typename I, typename F>
        inline void apply_with_index(C& cont_, F func_) noexcept
        {
            const size_t size  = std::distance(std::begin(cont_), std::end(cont_));
            size_t       index = 0;

            for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
            {
                func_(*it, index, size);

                ++index;
            }
        }

        /**
         *  Apply a given functor to each element of a const container.
         *  Provide the current element index and the total number of elements.
         *
         *  @tparam C   Type of container.
         *  @tparam T   Type stored by C.
         *  @tparam I   Type of const iterator of C.
         *  @tparam F   Type of functor to be applied.
         *
         *  @param  cont_   Container to be applied to.
         *  @param  func_   Functor to be applied.
         */
        template <typename C, typename T, typename I, typename F>
        inline void apply_with_index(const C& cont_, F func_) noexcept
        {
            const size_t size  = std::distance(std::begin(cont_), std::end(cont_));
            size_t       index = 0;

            for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
            {
                func_(*it, index, size);

                ++index;
            }
        }



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_CONTAINER_HPP
