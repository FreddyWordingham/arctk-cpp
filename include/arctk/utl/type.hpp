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
            template <class T>
            struct is_vector
            {
                static const bool value = false;
            };

            template <class T>
            struct is_vector<std::vector<T>>
            {
                static const bool value = true;
            };



        } // namespace type
    }     // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_TYPE_HPP
