/**
 *  @file   arctk/settings/error.hpp
 *  @date   03/07/2018
 *  @author Freddy Wordingham
 *
 *  Error settings.
 */



//  == GUARD ==
#ifndef ARCTK_SETTINGS_ERROR_HPP
#define ARCTK_SETTINGS_ERROR_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace settings //! settings namespace
    {
        namespace error //! error namespace
        {



            //  == ENUMERATIONS ==
            //  -- Error Indices --
            /**
             *  Complete list of all possible error indices which make be returned after program failure.
             */
            enum index
            {
                PRE_CONDITION_CONTRACT_FAILURE = 1, //!< Pre-condition contract check failed.
                POST_CONDITION_CONTRACT_FAILURE,    //!< Post-condition contract check failed.
                INVARIANT_CONTRACT_FAILURE          //!< Invariance contract check failed.
            };



        } // namespace error
    }     // namespace settings
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SETTINGS_ERROR_HPP