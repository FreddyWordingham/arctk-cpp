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



    } // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_ARRAY_HPP
