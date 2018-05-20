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



        //  == FUNCTIONS ==
        //  -- Properties --
        /**
         *  Determine if an array contains a given value.
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
         *  @pre    arr_ must not be empty.
         *
         *  @param  arr_    Array to be searched.
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
         *  @pre    arr_ must not be empty.
         *
         *  @param  arr_    Array to be searched.
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



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_ARRAY_HPP
