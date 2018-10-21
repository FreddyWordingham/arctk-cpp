/**
 *  @file   arctk/geom/math.hpp
 *  @date   21/10/2018
 *  @author Freddy Wordingham
 *
 *  Geometry math functions.
 */



//  == GUARD ==
#ifndef ARCTK_GEOM_MATH_HPP
#define ARCTK_GEOM_MATH_HPP



//  == IMPORTS ==
//  -- Std --
#include <cmath>

//  -- Arctk --
#include <arctk/index/vertex.hpp>
#include <arctk/math/vec.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace geom //! geometry namespace
    {
        namespace math //! mathematical namespace
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
            /**
             *  Determine the distance between two points.
             *
             *  @tparam T   Type stored by the vecs.
             *  @tparam N   Dimension of the vecs.
             *
             *  @param  start_  Start position.
             *  @param  end_    End position.
             *
             *  @return Distance between the points.
             */
            template <typename T, size_t N>
            inline T distance(const Vec<T, N>& start_, const Vec<T, N>& end_) noexcept
            {
                return ((end_ - start_).mag());
            }


            //  -- Area --
            /**
             *  Determine the area between three points.
             *
             *  @tparam T   Type stored by the vecs.
             *
             *  @param  pos_    Array of three vecs.
             *
             *  @return Area between the points.
             */
            template <typename T>
            inline T area(const std::array<Vec<T, 3>, 3>& pos_) noexcept
            {
                const T length_ab = distance(pos_[index::vertex::ALPHA], pos_[index::vertex::BETA]);
                const T length_bc = distance(pos_[index::vertex::BETA], pos_[index::vertex::GAMMA]);
                const T length_ca = distance(pos_[index::vertex::GAMMA], pos_[index::vertex::ALPHA]);

                const T half_perim = (length_ab + length_bc + length_ca) * 0.5;

                return (std::sqrt(half_perim * (half_perim - length_ab) * (half_perim - length_bc) * (half_perim - length_ca)));
            }



        } // namespace math
    }     // namespace geom
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_GEOM_MATH_HPP
