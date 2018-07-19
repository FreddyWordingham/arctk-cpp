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
            template <typename T>
            inline T area(const std::array<Vec<T, 3>, 3>& pos_) noexcept;



            //  == FUNCTIONS ==
            //  -- Length --
            template <typename T, size_t N>
            inline T distance(const Vec<T, N>& start_, const Vec<T, N>& end_) noexcept
            {
                return ((end_ - start_).mag());
            }


            //  -- Area --
            template <typename T>
            inline T area(const std::array<Vec<T, 3>, 3>& pos_) noexcept
            {
                const T length_ab = distance(pos_[ALPHA], pos_[BETA]);
                const T length_bc = distance(pos_[BETA], pos_[GAMMA]);
                const T length_ca = distance(pos_[GAMMA], pos_[ALPHA]);

                const T half_perim = (length_ab + length_bc + length_ca) * 0.5;

                return (std::sqrt(half_perim * (half_perim - length_ab) * (half_perim - length_bc) * (half_perim - length_ca)));
            }



        } // namespace geom
    }     // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_GEOM_HPP
