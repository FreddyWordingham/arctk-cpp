/**
 *  @file   arctk/utl/access.hpp
 *  @date   06/07/2018
 *  @author Freddy Wordingham
 *
 *  Collection of access related functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_ACCESS_HPP
#define ARCTK_UTL_ACCESS_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --

//  -- Arctk --
#include <arctk/sys/args.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace utl //! utility namespace
    {
        namespace access //! access namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Tuple --
            template <size_t I, typename... A, typename T = typename std::tuple_element<I, std::tuple<A...>>::type>
            inline T get(const sys::Args<A...>& args_) noexcept;



            //  == FUNCTIONS ==
            //  -- Tuple --
            template <size_t I, typename... A, typename T>
            inline T get(const sys::Args<A...>& args_) noexcept
            {
                return (std::get<I>(args_.argv()));
            }



        } // namespace access
    }     // namespace utl
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_UTL_ACCESS_HPP
