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



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/math/formula.hpp>
#include <arctk/utl.hpp>



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
                double operator()(double val_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a constant interpolation function.
             *
             *  @param  xs_ Vector of x-positions of the nodes.
             *  @param  ys_ Vector of y-positions of the nodes.
             *
             *  @pre    xs_ must contain multiple values.
             *  @pre    ys_ must contain multiple values.
             *  @pre    xs_ size must equal the size of ys_.
             *  @pre    xs_ must be sorted in ascending order.
             */
            inline Constant::Constant(const std::vector<double>& xs_, const std::vector<double>& ys_) noexcept
              : Formula(xs_.front(), xs_.back())
              , _xs(xs_)
              , _ys(ys_)
            {
                PRE(xs_.size() > 1);
                PRE(ys_.size() > 1);
                PRE(xs_.size() == ys_.size());
                PRE(utl::properties::ascending(xs_));
            }



            //  == OPERATORS ==
            //  -- Call --



        } // namespace formula
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_FORMULA_CONSTANT_HPP
