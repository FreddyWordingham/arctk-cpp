/**
 *  @file   arctk/math/formula/polynomial.hpp
 *  @date   12/08/2018
 *  @author Freddy Wordingham
 *
 *  Polynomial function class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_FORMULA_POLYNOMIAL_HPP
#define ARCTK_MATH_FORMULA_POLYNOMIAL_HPP



//  == BASE ==
#include <arctk/math/formula.hpp>



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cstddef>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace formula //! function namespace
        {



            //  == CLASS ==
            /**
             *  Polynomial function class.
             *
             *  @tparam N   Order of the polynomial.
             */
            template <size_t N>
            class Polynomial : public Formula
            {
                //  == FIELDS ==
              private:
                //  -- Coefficients --
                const std::array<double, N + 1> _coefs; //!< Array of polynomial coefficients.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Polynomial(const std::array<double, N + 1>& coefs_) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Call --
                inline double operator()(double val_) const noexcept override;
            };



        } // namespace formula
    }     // namespace math
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/formula/polynomial.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_FORMULA_POLYNOMIAL_HPP
