/**
 *  @file   arctk/utl/vector.hpp
 *  @date   21/05/2018
 *  @author Freddy Wordingham
 *
 *  Std::vector utility functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_VECTOR_HPP
#define ARCTK_UTL_VECTOR_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace utl //! utility namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Properties --
        template <class T>
        inline bool contains(const std::vector<T>& vec_, T val_) noexcept;
        template <class T>
        inline bool ascending(const std::vector<T>& vec_) noexcept;
        template <class T>
        inline bool descending(const std::vector<T>& vec_) noexcept;
        template <class T>
        inline bool monotonic(const std::vector<T>& vec_) noexcept;
        template <class T>
        inline bool uniform(const std::vector<T>& vec_, double tol_ = std::numeric_limits<double>::epsilon()) noexcept;
        template <class T>
        inline bool always_less_than(const std::vector<T>& vec_, T limit_) noexcept;
        template <class T>
        inline bool always_less_than_or_equal_to(const std::vector<T>& vec_, T limit_) noexcept;
        template <class T>
        inline bool always_greater_than(const std::vector<T>& vec_, T limit_) noexcept;
        template <class T>
        inline bool always_greater_than_or_equal_to(const std::vector<T>& vec_, T limit_) noexcept;

        //  -- Mathematical --
        template <class T>
        inline size_t min_index(const std::vector<T>& vec_) noexcept;
        template <class T>
        inline size_t max_index(const std::vector<T>& vec_) noexcept;
        template <class T>
        inline T min(const std::vector<T>& vec_) noexcept;
        template <class T>
        inline T max(const std::vector<T>& vec_) noexcept;
        template <class T>
        inline T sum(const std::vector<T>& vec_) noexcept;
        template <class T>
        inline double ave(const std::vector<T>& vec_) noexcept;
        template <class T>
        inline double mag(const std::vector<T>& vec_) noexcept;

        //  -- Searching --
        template <class T>
        inline bool within(const std::vector<T>& vec_, T val_) noexcept;
        template <class T>
        inline size_t search(const std::vector<T>& vec_, T val_) noexcept;



        //  == FUNCTIONS ==
        //  -- Properties --
        /**
         *  Determine if a vector contains a given value.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to be tested.
         *  @param  val_    Value to search the vector for.
         *
         *  @return True if the vector contains the given value.
         */
        template <class T>
        inline bool contains(const std::vector<T>& vec_, const T val_) noexcept
        {
            return (std::find(vec_.begin(), vec_.end(), val_) != vec_.end());
        }

        /**
         *  Determine if a vector is sorted in ascending order.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to be tested.
         *
         *  @return True if the vector is ascending.
         */
        template <class T>
        inline bool ascending(const std::vector<T>& vec_) noexcept
        {
            for (size_t i = 1; i < vec_.size(); ++i)
            {
                if (vec_[i] < vec_[i - 1])
                {
                    return (false);
                }
            }

            return (true);
        }

        /**
         *  Determine if a vector is sorted in descending order.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to be tested.
         *
         *  @return True if the vector is descending.
         */
        template <class T>
        inline bool descending(const std::vector<T>& vec_) noexcept
        {
            for (size_t i = 1; i < vec_.size(); ++i)
            {
                if (vec_[i] > vec_[i - 1])
                {
                    return (false);
                }
            }

            return (true);
        }

        /**
         *  Determine if a vector is sorted in monotonic order.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to be tested.
         *
         *  @return True if the vector is monotonic.
         */
        template <class T>
        inline bool monotonic(const std::vector<T>& vec_) noexcept
        {
            return (ascending(vec_) || (descending(vec_)));
        }

        /**
         *  Determine if a vector's elements are uniformly spaced.
         *  Consecutive value deltas must differ by less than the given tolerance.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to be tested.
         *  @param  tol_    Maximum tolerance for consecutive values.
         *
         *  @pre    vec_ size must be greater than one.
         *
         *  @return True if the vector is uniform.
         */
        template <class T>
        inline bool uniform(const std::vector<T>& vec_, const double tol_) noexcept
        {
            assert(vec_.size() > 1);

            const double ave_delta = (vec_.front() - vec_.back()) / static_cast<double>(vec_.size() - 1);

            for (size_t i = 1; i < vec_.size(); ++i)
            {
                if ((std::fabs((vec_[i - 1] - vec_[i]) - ave_delta)) > tol_)
                {
                    return (false);
                }
            }

            return (true);
        }

        /**
         *  Determine if a vector's elements are always less than the given limit.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to be tested.
         *  @param  limit_  Limit to be tested.
         *
         *  @return True if all of the vector's elements are less than the given limit.
         */
        template <class T>
        inline bool always_less_than(const std::vector<T>& vec_, const T limit_) noexcept
        {
            for (size_t i = 0; i < vec_.size(); ++i)
            {
                if (!(vec_[i] < limit_))
                {
                    return (false);
                }
            }

            return (true);
        }

        /**
         *  Determine if a vector's elements are always less than, or equal to, the given limit.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to be tested.
         *  @param  limit_  Limit to be tested.
         *
         *  @return True if all of the vector's elements are less than, or equal to, the given limit.
         */
        template <class T>
        inline bool always_less_than_or_equal_to(const std::vector<T>& vec_, const T limit_) noexcept
        {
            for (size_t i = 0; i < vec_.size(); ++i)
            {
                if (!(vec_[i] <= limit_))
                {
                    return (false);
                }
            }

            return (true);
        }

        /**
         *  Determine if a vector's elements are always greater than the given limit.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to be tested.
         *  @param  limit_  Limit to be tested.
         *
         *  @return True if all of the vector's elements are greater than the given limit.
         */
        template <class T>
        inline bool always_greater_than(const std::vector<T>& vec_, const T limit_) noexcept
        {
            for (size_t i = 0; i < vec_.size(); ++i)
            {
                if (!(vec_[i] > limit_))
                {
                    return (false);
                }
            }

            return (true);
        }

        /**
         *  Determine if a vector's elements are always greater than, or equal to, the given limit.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to be tested.
         *  @param  limit_  Limit to be tested.
         *
         *  @return True if all of the vector's elements are greater than, or equal to, the given limit.
         */
        template <class T>
        inline bool always_greater_than_or_equal_to(const std::vector<T>& vec_, const T limit_) noexcept
        {
            for (size_t i = 0; i < vec_.size(); ++i)
            {
                if (!(vec_[i] >= limit_))
                {
                    return (false);
                }
            }

            return (true);
        }


        //  -- Mathematical --
        /**
         *  Determine the minimum index within a vector.
         *  If multiple values are equally the smallest, the first index is returned.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to be searched.
         *
         *  @pre    vec_ must not be empty.
         *
         *  @return Index of the minimum value within the vector.
         */
        template <class T>
        inline size_t min_index(const std::vector<T>& vec_) noexcept
        {
            assert(!vec_.empty());

            size_t min = 0;
            for (size_t i = 1; i < vec_.size(); ++i)
            {
                if (vec_[i] < vec_[min])
                {
                    min = i;
                }
            }

            return (min);
        }

        /**
         *  Determine the maximum index within a vector.
         *  If multiple values are equally the largest, the first index is returned.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to be searched.
         *
         *  @pre    vec_ must not be empty.
         *
         *  @return Index of the maximum value within the vector.
         */
        template <class T>
        inline size_t max_index(const std::vector<T>& vec_) noexcept
        {
            assert(!vec_.empty());

            size_t max = 0;
            for (size_t i = 1; i < vec_.size(); ++i)
            {
                if (vec_[i] > vec_[max])
                {
                    max = i;
                }
            }

            return (max);
        }

        /**
         *  Determine the minimum value within a vector.
         *  If multiple values are equally the smallest, the first is returned.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to be searched.
         *
         *  @pre    vec_ must not be empty.
         *
         *  @return Minimum value within the vector.
         */
        template <class T>
        inline T min(const std::vector<T>& vec_) noexcept
        {
            assert(!vec_.empty());

            return (vec_[min_index(vec_)]);
        }

        /**
         *  Determine the maximum value within a vector.
         *  If multiple values are equally the largest, the first is returned.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to be searched.
         *
         *  @pre    vec_ must not be empty.
         *
         *  @return Maximum value within the vector.
         */
        template <class T>
        inline T max(const std::vector<T>& vec_) noexcept
        {
            assert(!vec_.empty());

            return (vec_[max_index(vec_)]);
        }

        /**
         *  Determine the sum of all elements within a vector.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to be summed.
         *
         *  @return Sum of vector elements.
         */
        template <class T>
        inline T sum(const std::vector<T>& vec_) noexcept
        {
            T sum = 0;
            for (size_t i = 0; i < vec_.size(); ++i)
            {
                sum += vec_[i];
            }

            return (sum);
        }

        /**
         *  Determine the average of the elements within a vector.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to find the average of.
         *
         *  @pre    vec_ must not be empty.
         *
         *  @return Average of the vector elements.
         */
        template <class T>
        inline double ave(const std::vector<T>& vec_) noexcept
        {
            assert(!vec_.empty());

            return (sum(vec_) / static_cast<double>(vec_.size()));
        }

        /**
         *  Determine the magnitude of the elements within a vector.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to find the magnitude of.
         *
         *  @return Magnitude of the vector elements.
         */
        template <class T>
        inline double mag(const std::vector<T>& vec_) noexcept
        {
            T sq_sum = 0;
            for (size_t i = 0; i < vec_.size(); ++i)
            {
                sq_sum += (vec_[i] * vec_[i]);
            }

            return (std::sqrt(static_cast<double>(sq_sum)));
        }


        //  -- Searching --
        /**
         *  Determine if a value is within the bounds of a vector.
         *  If the value is equal to a bound it is considered within the vector.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to test.
         *  @param  val_    Value to test.
         *
         *  @pre    vec_ must be ascending.
         *
         *  @return True if the value falls within the bounds of the vector.
         */
        template <class T>
        inline bool within(const std::vector<T>& vec_, T val_) noexcept
        {
            assert(monotonic(vec_));

            return ((val_ >= vec_.front()) && (val_ <= vec_.back()));
        }

        /**
         *  Determine the lower index of the elements within the vector which encapsulate a value.
         *
         *  @tparam T   Type stored by the vector.
         *
         *  @param  vec_    Vector to search.
         *  @param  val_    Value to locate.
         *
         *  @pre    vec_ must contain at least two elements.
         *  @pre    vec_ must be ascending.
         *
         *  @return The lower index of the element pair which encapsulates the value.
         */
        template <class T>
        inline size_t search(const std::vector<T>& vec_, const T val_) noexcept
        {
            assert(vec_.size() >= 2);
            assert(ascending(vec_));

            const auto index = static_cast<size_t>(std::distance(vec_.begin(), std::lower_bound(vec_.begin(), vec_.end(), val_)));

            return ((index == 0) ? index : (index - 1));
        }



    } // namespace utl
} // namespace arc



//  == OPERATOR PROTOTYPES ==
//  -- Io --
template <class T>
inline std::ostream& operator<<(std::ostream& stream_, const std::vector<T>& vec_) noexcept;



//  == OPERATORS ==
//  -- Io --
/**
 *  Enable writing of an vector to an ostream.
 *
 *  @tparam T   Type stored by the vector.
 *
 *  @param  stream_ Stream to write to.
 *  @param  vec_    Vector to be written.
 *
 *  return  Reference to the stream post-write.
 */
template <class T>
inline std::ostream& operator<<(std::ostream& stream_, const std::vector<T>& vec_) noexcept
{
    if (vec_.empty())
    {
        return (stream_);
    }

    stream_ << "{" << vec_[0];
    for (size_t i = 1; i < vec_.size(); ++i)
    {
        stream_ << ", " << vec_[i];
    }
    stream_ << "}";

    return (stream_);
}



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_VECTOR_HPP
