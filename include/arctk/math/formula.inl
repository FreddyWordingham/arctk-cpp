/**
 *  @file   arctk/math/formula.inl
 *  @date   11/08/2018
 *  @author Freddy Wordingham
 *
 *  Math function class.
 */



//  == GUARD ==
#ifndef ARCTK_MATH_FORMULA_INL
#define ARCTK_MATH_FORMULA_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace math //! mathematical namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a formula with given domain bounds.
         *
         *  @param  min_    Minimum domain bound of the formula.
         *  @param  max_    Maximum domain bound of the formula.
         *
         *  @pre    min_ must be less than max_.
         */
        inline Formula::Formula(const double min_, const double max_) noexcept
          : _min(min_)
          , _max(max_)
        {
            assert(min_ < max_);
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the minimum bound of the formula.
         *
         *  @return Minimum bound of the formula.
         */
        inline double Formula::min() const noexcept
        {
            return (_min);
        }

        /**
         *  Get the maximum bound of the formula.
         *
         *  @return Maximum bound of the formula.
         */
        inline double Formula::max() const noexcept
        {
            return (_max);
        }



    } // namespace math
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_MATH_FORMULA_INL
