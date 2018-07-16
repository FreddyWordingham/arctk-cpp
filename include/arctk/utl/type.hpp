/**
 *  @file   arctk/utl/type.hpp
 *  @date   11/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection of type functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_TYPE_HPP
#define ARCTK_UTL_TYPE_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace utl //! utility namespace
    {
        namespace type //! type namespace
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



        } // namespace type
    }     // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_TYPE_HPP
