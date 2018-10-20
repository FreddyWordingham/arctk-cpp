/**
 *  @file   arctk/utl/properties.hpp
 *  @date   05/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection of property related functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_PROPERTIES_HPP
#define ARCTK_UTL_PROPERTIES_HPP



//  == IMPORTS ==
//  -- Std --
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <iterator>
#include <vector>

//  -- Arctk --
#include <arctk/type/temp.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace utl //! utility namespace
    {
        namespace properties //! properties namespace
        {



            //  == STRUCTURES ==
            //  -- Properties --
            /**
             *  Structure used to store a pack of boolean values.
             */
            template <bool...>
            struct bool_pack;



            //  == ALIASES ==
            //  -- Bool-Pack --
            /**
             *  Alias used to determine if all values of a bool_pack are true.
             *
             *  @tparam A   Pack of boolean values.
             */
            template <bool... A>
            using all_true = std::is_same<bool_pack<A..., true>, bool_pack<true, A...>>;



            //  == FUNCTION PROTOTYPES ==
            //  -- Shape --
            template <typename T>
            inline bool square(const std::vector<std::vector<T>>& vec_) noexcept;
            template <typename T>
            inline bool cube(const std::vector<std::vector<std::vector<T>>>& vec_) noexcept;

            //  -- Contents --
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool contains(const C& cont_, const T& val_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool within(const C& cont_, const T& val_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool distinct(const C& cont_) noexcept;

            //  -- Order --
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool ascending(const C& cont_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool descending(const C& cont_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool monotonic(const C& cont_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool uniform(const C& cont_) noexcept;

            //  -- Limits --
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool always_less_than(const C& cont_, const T& limit_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool always_less_than_or_equal_to(const C& cont_, const T& limit_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool always_greater_than(const C& cont_, const T& limit_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool always_greater_than_or_equal_to(const C& cont_, const T& limit_) noexcept;



            //  == FUNCTIONS ==
            //  -- Shape --
            /**
             *  Determine if a given two-dimensional vector may be considered square.
             *  To be considered square, all sub-vectors must be of the same size.
             *
             *  @tparam T   Type stored by the vector.
             *
             *  @param  vec_    Vector to test.
             *
             *  @return True if the given vector can be considered square.
             */
            template <typename T>
            inline bool square(const std::vector<std::vector<T>>& vec_) noexcept
            {
                const size_t size = vec_.front().size();

                for (size_t i = 1; i < vec_.size(); ++i)
                {
                    if (vec_[i].size() != size)
                    {
                        return (false);
                    }
                }

                return (true);
            }

            /**
             *  Determine if a given three-dimensional vector may be considered cube.
             *  To be considered cube, all sub-vectors must be of the same size and all sub-sub-vectors must be of the same size.
             *
             *  @tparam T   Type stored by the vector.
             *
             *  @param  vec_    Vector to test.
             *
             *  @return True if the given vector can be considered cube.
             */
            template <typename T>
            inline bool cube(const std::vector<std::vector<std::vector<T>>>& vec_) noexcept
            {
                const std::array<size_t, 2> size({{vec_.front().size(), vec_.front().front().size()}});

                for (size_t i = 0; i < vec_.size(); ++i)
                {
                    if (vec_[i].size() != size[0])
                    {
                        return (false);
                    }

                    for (size_t j = 0; j < vec_.size(); ++j)
                    {
                        if (vec_[i][j].size() != size[1])
                        {
                            return (false);
                        }
                    }
                }

                return (true);
            }


            //  -- Contents --
            /**
             *  Determine if a container contains a value.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to check.
             *  @param  val_    Value to check container for.
             *
             *  @return True if the container contains the value.
             */
            template <typename C, typename T, typename I>
            inline bool contains(const C& cont_, const T& val_) noexcept
            {
                return (std::find(std::begin(cont_), std::end(cont_), val_) != std::end(cont_));
            }

            /**
             *  Determine if a value falls within the range of a container.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to test.
             *  @param  val_    Value to test.
             *
             *  @pre    cont_ must not be empty.
             *  @pre    cont_ must be monotonic.
             *
             *  @return True if the value falls within the containers range.
             */
            template <typename C, typename T, typename I>
            inline bool within(const C& cont_, const T& val_) noexcept
            {
                assert(!cont_.empty());
                assert(monotonic(cont_));

                return (((*std::begin(cont_) <= val_) && (val_ <= *std::rbegin(cont_))) || ((*std::begin(cont_) >= val_) && (val_ >= *std::rbegin(cont_))));
            }

            /**
             *  Determine if all elements of a container are distinct.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to test.
             *
             *  @return True if no two elements of the container are equal.
             */
            template <typename C, typename T, typename I>
            inline bool distinct(const C& cont_) noexcept
            {
                for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                {
                    for (I jt = std::next(it); jt != std::end(cont_); std::advance(jt, 1))
                    {
                        if (*it == *jt)
                        {
                            return (false);
                        }
                    }
                }

                return (true);
            }


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


            //  -- Limits --
            /**
             *  Determine if all elements of a container are less than a given limit.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to test.
             *  @param  limit_  Limit to compare elements against.
             *
             *  @return True if all elements are less than the limit.
             */
            template <typename C, typename T, typename I>
            inline bool always_less_than(const C& cont_, const T& limit_) noexcept
            {
                for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                {
                    if (!(*it < limit_))
                    {
                        return (false);
                    }
                }

                return (true);
            }

            /**
             *  Determine if all elements of a container are less than, or equal to, a given limit.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to test.
             *  @param  limit_  Limit to compare elements against.
             *
             *  @return True if all elements are less than, or equal to, the limit.
             */
            template <typename C, typename T, typename I>
            inline bool always_less_than_or_equal_to(const C& cont_, const T& limit_) noexcept
            {
                for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                {
                    if (!(*it <= limit_))
                    {
                        return (false);
                    }
                }

                return (true);
            }

            /**
             *  Determine if all elements of a container are greater than a given limit.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to test.
             *  @param  limit_  Limit to compare elements against.
             *
             *  @return True if all elements are greater than the limit.
             */
            template <typename C, typename T, typename I>
            inline bool always_greater_than(const C& cont_, const T& limit_) noexcept
            {
                for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                {
                    if (!(*it > limit_))
                    {
                        return (false);
                    }
                }

                return (true);
            }

            /**
             *  Determine if all elements of a container are greater than, or equal to, a given limit.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to test.
             *  @param  limit_  Limit to compare elements against.
             *
             *  @return True if all elements are greater than, or equal to, the limit.
             */
            template <typename C, typename T, typename I>
            inline bool always_greater_than_or_equal_to(const C& cont_, const T& limit_) noexcept
            {
                for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                {
                    if (!(*it >= limit_))
                    {
                        return (false);
                    }
                }

                return (true);
            }



        } // namespace properties
    }     // namespace utl
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_UTL_PROPERTIES_HPP
