/**
 *  @file   arctk/type/temp.hpp
 *  @date   20/10/2018
 *  @author Freddy Wordingham
 *
 *  Collection of template identifying structures.
 */



//  == GUARD ==
#ifndef ARCTK_TYPE_TEMP_HPP
#define ARCTK_TYPE_TEMP_HPP



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <type_traits>
#include <vector>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        template <typename T, size_t N>
        class Vec;
        template <typename T, size_t N>
        class Mat;
    } // namespace math
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace type //! typing namespace
    {
        namespace temp //! templating namespace
        {



            //  == STRUCTURES ==
            //  -- Std --
            /**
             *  Structure used to determine if a type is a vector.
             *
             *  @tparam T   Type being queried.
             */
            template <typename T>
            struct is_vector : public std::false_type // NOLINT
            {
            };

            /**
             *  Specialisation for vector types.
             *
             *  @tparam T   Type stored by the vector.
             */
            template <typename T>
            struct is_vector<std::vector<T>> : public std::true_type
            {
            };

            /**
             *  Structure used to determine if a type is an array.
             *
             *  @tparam T   Type being queried.
             */
            template <typename T>
            struct is_array : public std::false_type // NOLINT
            {
            };

            /**
             *  Specialisation for array types.
             *
             *  @tparam T   Type stored by the array.
             *  @tparam N   Size of the array.
             */
            template <typename T, size_t N>
            struct is_array<std::array<T, N>> : public std::true_type
            {
            };

            /**
             *  Structure used to determine if a type is an iterable.
             *
             *  @tparam T   Type being queried.
             */
            template <typename T, typename _ = void>
            struct is_iterable : public std::false_type
            {
            };

            /**
             *  Helper structure used to determine if a type is an iterable.
             */
            template <typename, typename, typename, typename>
            struct is_iterable_helper
            {
            };

            template <typename T>
            struct is_iterable<T, std::conditional_t<false, is_iterable_helper<typename T::value_type, typename T::const_iterator, decltype(std::begin(std::declval<T>())), decltype(std::end(std::declval<T>()))>, void>> : public std::true_type
            {
            };

            template <typename T, typename = void>
            struct core_type : public std::false_type
            {
                typedef T type;
            };

            template <typename T>
            struct core_type<T, typename std::enable_if_t<is_iterable<T>::value>> : public std::true_type
            {
                typedef typename core_type<typename T::value_type>::type type;
            };


            //  -- Arctk --
            /**
             *  Structure used to determine if a type is a vec.
             *
             *  @tparam T   Type being queried.
             */
            template <typename T>
            struct is_vec : public std::false_type // NOLINT
            {
            };

            /**
             *  Specialisation for vec types.
             *
             *  @tparam T   Type stored by the vec.
             *  @tparam N   Size of the vec.
             */
            template <typename T, size_t N>
            struct is_vec<math::Vec<T, N>> : public std::true_type
            {
            };

            /**
             *  Structure used to determine if a type is a mat.
             *
             *  @tparam T   Type being queried.
             */
            template <typename T>
            struct is_mat : public std::false_type // NOLINT
            {
            };

            /**
             *  Specialisation for mat types.
             *
             *  @tparam T   Type stored by the mat.
             *  @tparam N   Size of the mat.
             */
            template <typename T, size_t N>
            struct is_mat<math::Mat<T, N>> : public std::true_type
            {
            };



        } // namespace temp
    }     // namespace type
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TYPE_TEMP_HPP
