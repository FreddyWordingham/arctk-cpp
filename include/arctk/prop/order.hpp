/**
 *  @file   arctk/prop/order.hpp
 *  @date   20/10/2018
 *  @author Freddy Wordingham
 *
 *  Collection of order property functions.
 */



//  == GUARD ==
#ifndef ARCTK_PROP_ORDER_HPP
#define ARCTK_PROP_ORDER_HPP



//  == IMPORTS ==
//  -- Std --
#include <cmath>
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace prop //! properties namespace
    {
        namespace order //! ordering namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Order --
            //  -- Order --
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool ascending(const C& cont_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool descending(const C& cont_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool monotonic(const C& cont_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool uniform(const C& cont_) noexcept;



            //  == FUNCTIONS ==
            //  -- Order --
            /**
             *  Test if a container's elements are sorted in ascending order.
             *  Container is still considered ascending if consecutive values are equal.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to test.
             *
             *  @pre    cont_ must not be empty.
             *
             *  @return True if the container's elements are sorted in ascending order.
             */
            template <typename C, typename T, typename I>
            inline bool ascending(const C& cont_) noexcept
            {
                assert(!cont_.empty());

                for (I it = std::begin(cont_); it != std::prev(std::end(cont_)); std::advance(it, 1))
                {
                    if (*it > *std::next(it))
                    {
                        return (false);
                    }
                }

                return (true);
            }

            /**
             *  Test if a container's elements are sorted in descending order.
             *  Container is still considered descending if consecutive values are equal.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to test.
             *
             *  @pre    cont_ must not be empty.
             *
             *  @return True if the container's elements are sorted in descending order.
             */
            template <typename C, typename T, typename I>
            inline bool descending(const C& cont_) noexcept
            {
                assert(!cont_.empty());

                for (I it = std::begin(cont_); it != std::prev(std::end(cont_)); std::advance(it, 1))
                {
                    if (*it < *std::next(it))
                    {
                        return (false);
                    }
                }

                return (true);
            }

            /**
             *  Test if a container's elements are sorted in monotonic order.
             *  Container is still considered monotonic if consecutive values are equal.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to test.
             *
             *  @pre    cont_ must not be empty.
             *
             *  @return True if the container's elements are sorted in monotonic order.
             */
            template <typename C, typename T, typename I>
            inline bool monotonic(const C& cont_) noexcept
            {
                assert(!cont_.empty());

                return (ascending(cont_) || descending(cont_));
            }

            /**
             *  Test if a container's elements are uniformly spaced.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to test.
             *
             *  @pre    cont_ must not be empty.
             *
             *  @return True if the container's elements are uniformly spaced.
             */
            template <typename C, typename T, typename I>
            inline bool uniform(const C& cont_) noexcept
            {
                assert(!cont_.empty());

                if (cont_.size() == 1)
                {
                    return (true);
                }

                const T delta = *std::next(std::begin(cont_)) - *std::begin(cont_);

                for (I it = std::begin(cont_); it != std::prev(std::end(cont_)); std::advance(it, 1))
                {

                    if (std::abs((*std::next(it) - *it) - delta) > std::numeric_limits<T>::epsilon())
                    {
                        return (false);
                    }
                }

                return (true);
            }



        } // namespace order
    }     // namespace prop
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PROP_ORDER_HPP
