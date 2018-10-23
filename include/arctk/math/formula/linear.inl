/**
 *  @file   arctk/math/formula/linear.inl
 *  @date   15/08/2018
 *  @author Freddy Wordingham
 *
 *  Linear interpolation function class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_FORMULA_LINEAR_INL
#define ARCTK_MATH_FORMULA_LINEAR_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/prop/order.hpp>
#include <arctk/search/index.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {
        namespace formula //! function namespace
        {



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a linear interpolation function.
             *
             *  @param  xs_ Vector of x-positions of the nodes.
             *  @param  ys_ Vector of y-positions of the nodes.
             *
             *  @pre    xs_ must contain multiple values.
             *  @pre    ys_ must contain multiple values.
             *  @pre    xs_ size must equal the size of ys_.
             *  @pre    xs_ must be sorted in ascending order.
             */
            inline Linear::Linear(const std::vector<double>& xs_, const std::vector<double>& ys_) noexcept
              : Formula(xs_.front(), xs_.back())
              , _xs(xs_)
              , _ys(ys_)
              , _grads(init_grads(xs_, ys_))
            {
                assert(xs_.size() > 1);
                assert(ys_.size() > 1);
                assert(xs_.size() == ys_.size());
                assert(prop::order::ascending(xs_));
            }


            //  -- Initialisation --
            /**
             *  Initialise the vector of intermediate node gradients.
             *
             *  @param  xs_ Vector of x-positions of the nodes.
             *  @param  ys_ Vector of y-positions of the nodes.
             *
             *  @pre    xs_ must contain multiple values.
             *  @pre    ys_ must contain multiple values.
             *  @pre    xs_ size must equal the size of ys_.
             *  @pre    xs_ must be sorted in ascending order.
             *
             *  @return Vector of intermediate node gradients.
             */
            inline std::vector<double> Linear::init_grads(const std::vector<double>& xs_, const std::vector<double>& ys_) noexcept
            {
                assert(xs_.size() > 1);
                assert(ys_.size() > 1);
                assert(xs_.size() == ys_.size());
                assert(prop::order::ascending(xs_));

                std::vector<double> grads(xs_.size() - 1);
                for (size_t i = 0; i < grads.size(); ++i)
                {
                    grads[i] = (ys_[i + 1] - ys_[i]) / (_xs[i + 1] - _xs[i]);
                }

                return (grads);
            }



            //  == OPERATORS ==
            //  -- Call --
            /**
             *  Determine the result of the function for a given value.
             *
             *  @param  val_    Domain value of the function.
             *
             *  @pre    val_ must be less than, or equal to, _min.
             *  @pre    val_ must be greater than, or equal to, _max.
             *
             *  @return Result of the func for the given value.
             */
            inline double Linear::operator()(const double val_) const noexcept
            {
                assert(val_ >= _min);
                assert(val_ <= _max);

                const size_t index = search::index::lower(_xs, val_);

                return (_ys[index] + ((val_ - _xs[index]) * _grads[index]));
            }



        } // namespace formula
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_FORMULA_LINEAR_INL
