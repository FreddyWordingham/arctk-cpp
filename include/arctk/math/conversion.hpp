/**
 *  @file   arctk/math/conversion.hpp
 *  @date   26/05/2018
 *  @author Freddy Wordingham
 *
 *  Mathematical conversion functions.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_CONVERSION_HPP
#define ARCTK_MATH_CONVERSION_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == FUNCTION PROTOTYPES ==
        template <typename T>
        inline T rad_to_deg(const T x_) noexcept;



        //  == FUNCTIONS ==
        template <typename T>
        inline T rad_to_deg(const T x_) noexcept
        {
            return (static_cast<T>(180.0 / constant::PI) * x_);
        }



    } // namespace math
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_MATH_CONVERSION_HPP
