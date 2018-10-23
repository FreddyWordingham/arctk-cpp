/**
 *  @file   arctk/math/formula/constant.hpp
 *  @date   15/08/2018
 *  @author Freddy Wordingham
 *
 *  Constant interpolation function class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_FORMULA_CONSTANT_HPP
#define ARCTK_MATH_FORMULA_CONSTANT_HPP



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
             *  Constant interpolation function class.
             */
            class Constant : public Formula
            {
                //  == FIELDS ==
              private:
                //  -- Coefficients --
                const std::vector<double> _xs; //!< Vector of x-positions of the nodes.
                const std::vector<double> _ys; //!< Vector of y-positions of the nodes.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Constant(const std::vector<double>& xs_, const std::vector<double>& ys_) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Call --
                inline double operator()(double val_) const noexcept override;
            };



        } // namespace formula
    }     // namespace math
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/math/formula/constant.inl>



//  == GUARD END ==
#endif // ARCTK_MATH_FORMULA_CONSTANT_HPP
