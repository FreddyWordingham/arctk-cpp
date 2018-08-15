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
             *
             *  @tparam T   Type of func domain.
             *  @tparam S   Type returned from the func.
             */
            template <typename T, typename S>
            class Linear : public Formula<T, S>
            {
                //  == FIELDS ==
              private:
                //  -- Coefficients --


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == OPERATORS ==
              public:
                //  -- Call --
                S operator()(T val_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



            //  == OPERATORS ==
            //  -- Call --



        } // namespace formula
    }     // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_FORMULA_LINEAR_HPP
