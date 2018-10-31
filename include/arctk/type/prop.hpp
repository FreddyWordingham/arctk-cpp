/**
 *  @file   arctk/type/prop.hpp
 *  @date   31/10/2018
 *  @author Freddy Wordingham
 *
 *  Collection of property identifying structures.
 */



//  == GUARD ==
#ifndef ARCTK_TYPE_PROP_HPP
#define ARCTK_TYPE_PROP_HPP



//  == IMPORTS ==
//  -- Std --
#include <iterator>
#include <type_traits>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace type //! typing namespace
    {
        namespace prop //! properties namespace
        {



            //  == STRUCTURES ==
            //  -- Containers --
            /**
             *  Structure used to determine if a type supports const iterators.
             *
             *  @tparam T   Type being queried.
             */
            template <typename T>
            struct has_const_iterator // NOLINT
            {
              private:
                template <typename C>
                static char test(typename C::const_iterator*);
                template <typename C>
                static int test(...);

              public:
                const bool value = sizeof(test<T>(0)) == sizeof(char);
            };



        } // namespace prop
    }     // namespace type
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_TYPE_PROP_HPP
