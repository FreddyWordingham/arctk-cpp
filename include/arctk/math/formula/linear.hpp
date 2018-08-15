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



//  == IMPORTS ==
//  -- Std --
#include <vector>

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

                //  -- Initialisation --
                inline std::vector<double> init_grads(const std::vector<double>& xs_, const std::vector<double>& ys_) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Call --
                double operator()(double val_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            inline Linear::Linear(const std::vector<double>& xs_, const std::vector<double>& ys_) noexcept
              : _xs(xs_)
              , _ys(ys_)
              , _grads(init_grads(xs_, ys_))
            {
                PRE(xs_.size() > 1);
                PRE(ys_.size() > 1);
                PRE(xs_.size() == ys_.size());
                PRE(utl::properties::ascending(xs_));
            }


            //  -- Initialisation --
            inline std::vector<double> Linear::init_grads(const std::vector<double>& xs_, const std::vector<double>& ys_) noexcept
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
#endif // ARCTK_MATH_FORMULA_LINEAR_HPP
