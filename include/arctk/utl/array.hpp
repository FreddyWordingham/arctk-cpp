/**
 *  @file   arctk/utl/char.hpp
 *  @date   20/05/2018
 *  @author Freddy Wordingham
 *
 *  Std::array utility functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_ARRAY_HPP
#define ARCTK_UTL_ARRAY_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == INCLUDES ==
//  -- Std --
#include <array>
#include <cmath>



//  == NAMESPACE ==
namespace arc //! arc namespace
{
    namespace utl //! utility namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Properties --
        template <class T, size_t N>
        inline bool contains(const std::array<T, N>& arr_, T val_) noexcept;
        template <class T, size_t N>
        inline bool ascending(const std::array<T, N>& arr_) noexcept;
        template <class T, size_t N>
        inline bool descending(const std::array<T, N>& arr_) noexcept;
        template <class T, size_t N>
        inline bool monotonic(const std::array<T, N>& arr_) noexcept;
        template <class T, size_t N>
        inline bool uniform(const std::array<T, N>& arr_, double tol_ = std::numeric_limits<double>::epsilon()) noexcept;
        template <class T, size_t N>
        inline bool always_less_than(const std::array<T, N>& arr_, T limit_) noexcept;
        template <class T, size_t N>
        inline bool always_less_than_or_equal_to(const std::array<T, N>& arr_, T limit_) noexcept;
        template <class T, size_t N>
        inline bool always_greater_than(const std::array<T, N>& arr_, T limit_) noexcept;
        template <class T, size_t N>
        inline bool always_greater_than_or_equal_to(const std::array<T, N>& arr_, T limit_) noexcept;

        //  -- Mathematical --
        template <class T, size_t N>
        inline size_t min_index(const std::array<T, N>& arr_) noexcept;
        template <class T, size_t N>
        inline size_t max_index(const std::array<T, N>& arr_) noexcept;
        template <class T, size_t N>
        inline T min(const std::array<T, N>& arr_) noexcept;
        template <class T, size_t N>
        inline T max(const std::array<T, N>& arr_) noexcept;
        template <class T, size_t N>
        inline T sum(const std::array<T, N>& arr_) noexcept;
        template <class T, size_t N>
        inline double ave(const std::array<T, N>& arr_) noexcept;
        template <class T, size_t N>
        inline double mag(const std::array<T, N>& arr_) noexcept;

        //  -- Searching --
        template <class T, size_t N>
        inline bool within(const std::array<T, N>& arr_, T val_) noexcept;
        template <class T, size_t N>
        inline size_t search(const std::array<T, N>& arr_, T val_) noexcept;



        //  == FUNCTIONS ==
        //  -- Properties --
        /**
         *  Determine if an array contains a given value.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @param  arr_    Array to be tested.
         *  @param  val_    Value to search the array for.
         *
         *  @return True if the array contains the given value.
         */
        template <class T, size_t N>
        inline bool contains(const std::array<T, N>& arr_, const T val_) noexcept
        {
            return (std::find(arr_.begin(), arr_.end(), val_) != arr_.end());
        }

        /**
         *  Determine if an array is sorted in ascending order.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @param  arr_    Array to be tested.
         *
         *  @return True if the array is ascending.
         */
        template <class T, size_t N>
        inline bool ascending(const std::array<T, N>& arr_) noexcept
        {
            for (size_t i = 1; i < N; ++i)
            {
                if (arr_[i] < arr_[i - 1])
                {
                    return (false);
                }
            }

            return (true);
        }

        /**
         *  Determine if an array is sorted in descending order.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @param  arr_    Array to be tested.
         *
         *  @return True if the array is descending.
         */
        template <class T, size_t N>
        inline bool descending(const std::array<T, N>& arr_) noexcept
        {
            for (size_t i = 1; i < N; ++i)
            {
                if (arr_[i] > arr_[i - 1])
                {
                    return (false);
                }
            }

            return (true);
        }

        /**
         *  Determine if an array is sorted in monotonic order.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @param  arr_    Array to be tested.
         *
         *  @return True if the array is monotonic.
         */
        template <class T, size_t N>
        inline bool monotonic(const std::array<T, N>& arr_) noexcept
        {
            return (ascending(arr_) || (descending(arr_)));
        }

        /**
         *  Determine if an array's elements are uniformly spaced.
         *  Consecutive value deltas must differ by less than the given tolerance.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @param  arr_    Array to be tested.
         *  @param  tol_    Maximum tolerance for consecutive values.
         *
         *  @return True if the array is uniform.
         */
        template <class T, size_t N>
        inline bool uniform(const std::array<T, N>& arr_, const double tol_) noexcept
        {
            const double ave_delta = (arr_.front() - arr_.back()) / static_cast<double>(N - 1);

            for (size_t i = 1; i < N; ++i)
            {
                if ((std::fabs((arr_[i - 1] - arr_[i]) - ave_delta)) > tol_)
                {
                    return (false);
                }
            }

            return (true);
        }

        /**
         *  Determine if an array's elements are always less than the given limit.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @param  arr_    Array to be tested.
         *  @param  limit_  Limit to be tested.
         *
         *  @return True if all of the array's elements are less than the given limit.
         */
        template <class T, size_t N>
        inline bool always_less_than(const std::array<T, N>& arr_, const T limit_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                if (!(arr_[i] < limit_))
                {
                    return (false);
                }
            }

            return (true);
        }

        /**
         *  Determine if an array's elements are always less than, or equal to, the given limit.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @param  arr_    Array to be tested.
         *  @param  limit_  Limit to be tested.
         *
         *  @return True if all of the array's elements are less than, or equal to, the given limit.
         */
        template <class T, size_t N>
        inline bool always_less_than_or_equal_to(const std::array<T, N>& arr_, const T limit_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                if (!(arr_[i] <= limit_))
                {
                    return (false);
                }
            }

            return (true);
        }

        /**
         *  Determine if an array's elements are always greater than the given limit.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @param  arr_    Array to be tested.
         *  @param  limit_  Limit to be tested.
         *
         *  @return True if all of the array's elements are greater than the given limit.
         */
        template <class T, size_t N>
        inline bool always_greater_than(const std::array<T, N>& arr_, const T limit_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                if (!(arr_[i] > limit_))
                {
                    return (false);
                }
            }

            return (true);
        }

        /**
         *  Determine if an array's elements are always greater than, or equal to, the given limit.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @param  arr_    Array to be tested.
         *  @param  limit_  Limit to be tested.
         *
         *  @return True if all of the array's elements are greater than, or equal to, the given limit.
         */
        template <class T, size_t N>
        inline bool always_greater_than_or_equal_to(const std::array<T, N>& arr_, const T limit_) noexcept
        {
            for (size_t i = 0; i < N; ++i)
            {
                if (!(arr_[i] >= limit_))
                {
                    return (false);
                }
            }

            return (true);
        }


        //  -- Mathematical --
        /**
         *  Determine the minimum index within an array.
         *  If multiple values are equally the smallest, the first index is returned.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @param  arr_    Array to be searched.
         *
         *  @pre    arr_ must not be empty.
         *
         *  @return Index of the minimum value within the array.
         */
        template <class T, size_t N>
        inline size_t min_index(const std::array<T, N>& arr_) noexcept
        {
            static_assert(!arr_.empty());

            size_t min = 0;
            for (size_t i = 1; i < N; ++i)
            {
                if (arr_[i] < arr_[min])
                {
                    min = i;
                }
            }

            return (min);
        }

        /**
         *  Determine the maximum index within an array.
         *  If multiple values are equally the largest, the first index is returned.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @param  arr_    Array to be searched.
         *
         *  @pre    arr_ must not be empty.
         *
         *  @return Index of the maximum value within the array.
         */
        template <class T, size_t N>
        inline size_t max_index(const std::array<T, N>& arr_) noexcept
        {
            static_assert(!arr_.empty());

            size_t max = 0;
            for (size_t i = 1; i < N; ++i)
            {
                if (arr_[i] > arr_[max])
                {
                    max = i;
                }
            }

            return (max);
        }

        /**
         *  Determine the minimum value within an array.
         *  If multiple values are equally the smallest, the first is returned.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @pre    arr_ must not be empty.
         *
         *  @param  arr_    Array to be searched.
         *
         *  @return Minimum value within the array.
         */
        template <class T, size_t N>
        inline T min(const std::array<T, N>& arr_) noexcept
        {
            static_assert(!arr_.empty());

            return (arr_[min_index(arr_)]);
        }

        /**
         *  Determine the maximum value within an array.
         *  If multiple values are equally the largest, the first is returned.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @pre    arr_ must not be empty.
         *
         *  @param  arr_    Array to be searched.
         *
         *  @return Maximum value within the array.
         */
        template <class T, size_t N>
        inline T max(const std::array<T, N>& arr_) noexcept
        {
            static_assert(!arr_.empty());

            return (arr_[max_index(arr_)]);
        }

        /**
         *  Determine the sum of all elements within an array.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @param  arr_    Array to be summed.
         *
         *  @return Sum of array elements.
         */
        template <class T, size_t N>
        inline T sum(const std::array<T, N>& arr_) noexcept
        {
            T sum = 0;
            for (size_t i = 0; i < N; ++i)
            {
                sum += arr_[i];
            }

            return (sum);
        }

        /**
         *  Determine the average of the elements within an array.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @pre    arr_ must not be empty.
         *
         *  @param  arr_    Array to find the average of.
         *
         *  @return Average of the array elements.
         */
        template <class T, size_t N>
        inline double ave(const std::array<T, N>& arr_) noexcept
        {
            static_assert(!arr_.empty());

            return (sum(arr_) / static_cast<double>(N));
        }

        /**
         *  Determine the magnitude of the elements within an array.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @param  arr_    Array to find the magnitude of.
         *
         *  @return Magnitude of the array elements.
         */
        template <class T, size_t N>
        inline double mag(const std::array<T, N>& arr_) noexcept
        {
            T sq_sum = 0;
            for (size_t i = 0; i < N; ++i)
            {
                sq_sum += (arr_[i] * arr_[i]);
            }

            return (std::sqrt(static_cast<double>(sq_sum)));
        }


        //  -- Searching --
        /**
         *  Determine if a value is within the bounds of an array.
         *  If the value is equal to a bound it is considered within the array.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @pre    arr_ must contain at least two elements.
         *  @pre    arr_ must be ascending.
         *
         *  @param  arr_    Array to test.
         *  @param  val_    Value to test.
         *
         *  @return True if the value falls within the bounds of the array.
         */
        template <class T, size_t N>
        inline bool within(const std::array<T, N>& arr_, T val_) noexcept
        {
            static_assert(N >= 2);
            assert(monotonic(arr_));

            return ((val_ >= arr_.front()) && (val_ <= arr_.back()));
        }

        /**
         *  Determine the lower index of the elements within the array which encapsulate a value.
         *
         *  @tparam T   Type stored by the array.
         *  @tparam N   Size of the array.
         *
         *  @pre    arr_ must contain at least two elements.
         *  @pre    arr_ must be ascending.
         *
         *  @param  arr_    Array to search.
         *  @param  val_    Value to locate.
         *
         *  @return The lower index of the element pair which encapsulates the value.
         */
        template <class T, size_t N>
        inline size_t search(const std::array<T, N>& arr_, const T val_) noexcept
        {
            static_assert(N > 1);
            assert(ascending(arr_));

            const auto index = static_cast<size_t>(std::distance(arr_.begin(), std::lower_bound(arr_.begin(), arr_.end(), val_)));

            return ((index == 0) ? index : (index - 1));
        }



    } // namespace utl
} // namespace arc



//  == OPERATOR PROTOTYPES ==
//  -- Io --
template <class T, size_t N>
inline std::ostream& operator<<(std::ostream& stream_, const std::array<T, N>& arr_) noexcept;



//  == OPERATORS ==
//  -- Io --
/**
 *  Enable writing of an array to an ostream.
 *
 *  @tparam T   Type stored by the array.
 *  @tparam N   Size of the array.
 *
 *  @param  stream_ Stream to write to.
 *  @param  arr_    Array to be written.
 *
 *  return  Reference to the stream post-write.
 */
template <class T, size_t N>
inline std::ostream& operator<<(std::ostream& stream_, const std::array<T, N>& arr_) noexcept
{
    if (arr_.empty())
    {
        return (stream_);
    }

    stream_ << "{" << arr_[0];
    for (size_t i = 1; i < N; ++i)
    {
        stream_ << ", " << arr_[i];
    }
    stream_ << "}";

    return (stream_);
}



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_ARRAY_HPP
