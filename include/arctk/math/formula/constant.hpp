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
#include <cassert>
#include <vector>

//  -- Arctk --
#include <arctk/math/formula.hpp>
#include <arctk/prop/order.hpp>
#include <arctk/search/index.hpp>



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
                assert(xs_.size() > 1);
                assert(ys_.size() > 1);
                assert(xs_.size() == ys_.size());
                assert(prop::order::ascending(xs_));
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
            inline double Constant::operator()(const double val_) const noexcept
            {
                assert(val_ >= _min);
                assert(val_ <= _max);

                const size_t index = search::index::lower(_xs, val_);

                return (_ys[index]);
            }



        } // namespace formula
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_FORMULA_CONSTANT_HPP
