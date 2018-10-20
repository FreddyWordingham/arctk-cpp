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
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace type //! typing namespace
    {
        namespace temp //! templating namespace
        {



            //  == STRUCTURES ==
            //  -- Vector --
            /**
             *  Structure used to determine if a type is a vector.
             *
             *  @tparam T   Type stored by vector.
             */
            template <class T>
            struct is_vector // NOLINT
            {
                //  == FIELDS ==
              public:
                //  -- Properties --
                static const bool value = false; //!< True if T is a vector.
            };

            /**
             *  Specialisation for vector types.
             *
             *  @tparam T   Type stored by vector.
             */
            template <class T>
            struct is_vector<std::vector<T>>
            {
                //  == FIELDS ==
              public:
                //  -- Properties --
                static const bool value = true; //!< True if T is a vector.
            };



        } // namespace temp
    }     // namespace type
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TYPE_TEMPLATE_HPP
