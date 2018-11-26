/**
 *  @file   arctk/opt/sop.inl
 *  @date   10/10/2018
 *  @author Freddy Wordingham
 *
 *  Specific-optical-properties control class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_SOP_INL
#define ARCTK_OPT_SOP_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optics namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a specific-optical-properties object.
         *
         *  @param  ref_index_          Refractive index.
         *
         *  @pre    ref_index_ must be greater than, or equal to, unity.
         */
        inline Sop::Sop(const double ref_index_, const double interaction_coef_) noexcept
          : _ref_index(ref_index_)
        {
            assert(ref_index_ >= 1.0);
        }


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Sop::~Sop() noexcept = default;



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the refractive index of the specific-optical-property.
         *
         *  @return Refractive index of the specific-optical-property.
         */
        inline double Sop::ref_index() const noexcept
        {
            return (_ref_index);
        }



    } // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_SOP_INL
