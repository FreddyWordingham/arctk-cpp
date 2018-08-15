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



//  == IMPORTS ==
//  -- Std --
#include <array>
#include <cstddef>
#include <limits>

//  -- Arctk --
#include <arctk/math/formula.hpp>



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
                inline double operator()(double val_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a nth-order polynomial function.
             *
             *  @param  coefs_  Array of polynomial coefficients.
             */
            template <size_t N>
            inline Polynomial<N>::Polynomial(const std::array<double, N + 1>& coefs_) noexcept
              : Formula(std::numeric_limits<double>::lowest(), std::numeric_limits<double>::max())
              , _coefs(coefs_)
            {
            }



            //  == OPERATORS ==
            //  -- Call --
            /**
             *  Determine the result of the function for a given value.
             *
             *  @param  val_    Domain value of the function.
             *
             *  @return Result of the func for the given value.
             */
            template <size_t N>
            inline double Polynomial<N>::operator()(const double val_) noexcept
            {
                double result{};

                for (size_t i = 0; i < _coefs.size(); ++i)
                {
                    result += _coefs[i] * std::pow(val_, i);
                }

                return (result);
            }



        } // namespace formula
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_FORMULA_POLYNOMIAL_HPP
