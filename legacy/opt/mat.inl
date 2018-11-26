/**
 *  @file   arctk/opt/mat.inl
 *  @date   12/10/2018
 *  @author Freddy Wordingham
 *
 *  Optical material class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_MAT_INL
#define ARCTK_OPT_MAT_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {



        //  == INSTANTIATION ==
        //  -- Destructors --
        /**
         *  Construct a material which can generate specific-optical-properties for given wavelength bounds.
         *
         *  @param  min_    Minimum wavelength bound.
         *  @param  max_    Maximum wavelength bound.
         *
         *  @pre    min_ must be less than, or equal to, max_.
         */
        inline Mat::Mat(const double min_, const double max_) noexcept
          : _min(min_)
          , _max(max_)
        {
            assert(min_ <= max_);
        }


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Mat::~Mat() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the minimum wavelength bound of the material.
         *
         *  @return Minimum wavelength bound of the material.
         */
        inline double Mat::min() const noexcept
        {
            return (_min);
        }

        /**
         *  Get the maximum wavelength bound of the material.
         *
         *  @return Maximum wavelength bound of the material.
         */
        inline double Mat::max() const noexcept
        {
            return (_max);
        }



    } // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_MAT_INL
