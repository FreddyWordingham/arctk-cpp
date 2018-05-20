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
         *  @param  tol_    Maximum tolerance of consecutive values.
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



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_ARRAY_HPP
