/**
 *  @file   arctk/math/formula/linear.hpp
 *  @date   15/08/2018
 *  @author Freddy Wordingham
 *
 *  Linear interpolation function class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_FORMULA_LINEAR_HPP
#define ARCTK_MATH_FORMULA_LINEAR_HPP



//  == BASE ==
#include <arctk/math/formula.hpp>



//  == IMPORTS ==
//  -- Std --
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace formula //! function namespace
        {



            //  == CLASS ==
            /**
             *  Linear interpolation function class.
             */
            class Linear : public Formula
            {
                //  == FIELDS ==
              private:
                //  -- Coefficients --
                const std::vector<double> _xs;    //!< Vector of x-positions of the nodes.
                const std::vector<double> _ys;    //!< Vector of y-positions of the nodes.
                const std::vector<double> _grads; //!< Vector of intermediate gradients.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Linear(const std::vector<double>& xs_, const std::vector<double>& ys_) noexcept;

              private:
                //  -- Initialisation --
                inline std::vector<double> init_grads(const std::vector<double>& xs_, const std::vector<double>& ys_) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Call --
                inline double operator()(double val_) const noexcept override;
            };



        } // namespace formula
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_FORMULA_LINEAR_HPP
