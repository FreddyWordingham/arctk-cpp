/**
 *  @file   arctk/math/func/polynomial.hpp
 *  @date   12/08/2018
 *  @author Freddy Wordingham
 *
 *  Polynomial function class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_FUNC_POLYNOMIAL_HPP
#define ARCTK_MATH_FUNC_POLYNOMIAL_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace func //! function namespace
        {



            //  == CLASS ==
            /**
             *  Polynomial function class.
             *
             *  @tparam T   Type of func domain.
             *  @tparam S   Type returned from the func.
             *  @tparam N   Order of the polynomial.
             */
            template <typename T, typename S, size_t N>
            class Polynomial : public Func<T, S>
            {
                //  == FIELDS ==
              private:
                //  -- Coefficients --
                const std::array<double, N + 1> _coefs; //!< Array of polynomial coefficients.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Polynomial(const std::array<double, N + 1>& coefs_) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Call --
                S operator()(const T val_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename T, typename S, size_t N>
            inline Polynomial<T, S, N>::Polynomial(const std::array<double, N + 1>& coefs_) noexcept
              : _coefs(coefs_)
            {
            }



            //  == OPERATORS ==
            //  -- Call --
            template <typename T, typename S, size_t N>
            S Polynomial<T, S, N>::operator()(const T val_) noexcept
            {
                S result{};

                for (size_t i = 0; i < coefs_.size(); ++i)
                {
                    result += _coefs[i] * std::pow(val_, i);
                }

                return (result);
            }



        } // namespace func
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_FUNC_POLYNOMIAL_HPP
