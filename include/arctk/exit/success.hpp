/**
 *  @file   arctk/exit/success.hpp
 *  @date   03/07/2018
 *  @author Freddy Wordingham
 *
 *  Enumeration of all exit code success values.
 */



//  == GUARD ==
#ifndef ARCTK_EXIT_SUCCESS_HPP
#define ARCTK_EXIT_SUCCESS_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace exit //! exit codes namespace
    {
        namespace success //! success namespace
        {



            //  == CONSTANTS ==
            //  -- Contracts --
            constexpr const int COMPLETE = 0; //!< Program successfully has completed.



        } // namespace success
    }     // namespace exit
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EXIT_SUCCESS_HPP
