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
         *  Construct a specific-optical-properties object with a given refractive index and interaction coefficient.
         *
         *  @param  ref_index_          Refractive index.
         *  @param  interaction_coef_   Interaction coefficient.
         *
         *  @pre    ref_index_ must be greater than, or equal to, unity.
         *  @pre    interaction_coef_ must be positive.
         */
        inline Sop::Sop(const double ref_index_, const double interaction_coef_) noexcept
          : _ref_index(ref_index_)
          , _interaction_coef(interaction_coef_)
        {
            assert(ref_index_ >= 1.0);
            assert(interaction_coef_ > 0.0);
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
