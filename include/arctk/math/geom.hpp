/**
 *  @file   arctk/math/geom.hpp
 *  @date   19/07/2018
 *  @author Freddy Wordingham
 *
 *  Math geometry functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_GEOM_HPP
#define ARCTK_MATH_GEOM_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace geom //! geometry namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Length --
            template <typename T, size_t N>
            inline T distance(const Vec<T, N>& start_, const Vec<T, N>& end_) noexcept;


            //  -- Area --



            //  == FUNCTIONS ==
            //  -- Length --
            template <typename T, size_t N>
            inline T distance(const Vec<T, N>& start_, const Vec<T, N>& end_) noexcept
            {
                return ((end_ - start_).mag());
            }


            //  -- Area --



        } // namespace geom
    }     // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_GEOM_HPP
