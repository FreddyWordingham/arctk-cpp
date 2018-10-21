/**
 *  @file   arctk/utl/template.hpp
 *  @date   20/10/2018
 *  @author Freddy Wordingham
 *
 *  Collection of template identifying structures.
 */



//  == GUARD ==
#ifndef ARCTK_TYPE_TEMPLATE_HPP
#define ARCTK_TYPE_TEMPLATE_HPP



//  == IMPORTS ==
//  -- Std --
#include <type_traits>
#include <vector>

//  -- Arctk --
#include <arctk/math/vec.hpp>



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
            struct is_vector : std::false_type
            {
            };

            /**
             *  Specialisation for vector types.
             *
             *  @tparam T   Type stored by the vector.
             */
            template <typename T>
            struct is_vector<std::vector<T>> : std::true_type
            {
            };


            //  -- Arctk --
            /**
             *  Structure used to determine if a type is a vec.
             *
             *  @tparam T   Type being queried.
             */
            template <typename T>
            struct is_vec : std::false_type
            {
            };

            /**
             *  Specialisation for vec types.
             *
             *  @tparam T   Type stored by the vec.
             *  @tparam N   Size of the vec.
             */
            template <typename T, size_t N>
            struct is_vec<math::vec<T, N>> : std::true_type
            {
            };



        } // namespace temp
    }     // namespace type
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TYPE_TEMPLATE_HPP
