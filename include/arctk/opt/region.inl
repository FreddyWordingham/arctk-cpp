/**
 *  @file   arctk/opt/region.inl
 *  @date   26/11/2018
 *  @author Freddy Wordingham
 *
 *  Optical region class.
 */



//  == GUARD ==
#ifndef ARCTK_OPT_REGION_INL
#define ARCTK_OPT_REGION_INL



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace opt //! optical namespace
    {



        //  == METHODS ==
        //  -- Getters --
        const std::array<size_t, 3>& Region::res() const noexcept
        {
            return (_res);
        }



    } // namespace opt
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_OPT_REGION_INL
