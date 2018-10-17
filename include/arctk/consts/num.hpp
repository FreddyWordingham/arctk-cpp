/**
 *  @file   arctk/consts/num.hpp
 *  @date   09/10/2018
 *  @author Freddy Wordingham
 *
 *  Numerical precision constants.
 */



//  == GUARD ==
#ifndef ARCTK_CONSTS_NUM_HPP
#define ARCTK_CONSTS_NUM_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace consts //! constants namespace
    {
        namespace num //! numerical precision namespace
        {



            //  == CONSTANTS ==
            //  -- Buffering --
            constexpr const double BUMP = 1e-6; //!< Distance to bump across boundaries.



        } // namespace num
    }     // namespace consts
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_CONSTS_NUM_HPP
