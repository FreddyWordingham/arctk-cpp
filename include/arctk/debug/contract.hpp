/**
 *  @file   arctk/debug/contract.hpp
 *  @date   11/07/2018
 *  @author Freddy Wordingham
 *
 *  Contract debug functions.
 */



//  == GUARD ==
#ifndef ARCTK_DEBUG_CONTRACT_HPP
#define ARCTK_DEBUG_CONTRACT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <iostream>
#include <string>

//  -- Arctk --
#include <arctk/debug/location.hpp>
#include <arctk/exit.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace debug //! debugging namespace
    {
        namespace contract //! contracts namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Contracts --
            inline void precondition(const std::string& condition_, const std::string& file_, int line_, const std::string& func_) noexcept;
            inline void postcondition(const std::string& condition_, const std::string& file_, int line_, const std::string& func_) noexcept;



            //  == FUNCTIONS ==
            //  -- Contracts --
            inline void precondition(const std::string& condition_, const std::string& file_, int line_, const std::string& func_) noexcept
            {
                std::cerr << "Pre-condition  : `" << condition_ << "` failed.\n";
                std::cerr << "Located at     :\n" << location::info(file_, line_, func_, 3) << '\n';

                std::exit(exit::error::PRE_CONDITION_FAILURE);
            }

            inline void postcondition(const std::string& condition_, const std::string& file_, int line_, const std::string& func_) noexcept
            {
                std::cerr << "Post-condition : `" << condition_ << "` failed.\n";
                std::cerr << "Located at     :\n" << location::info(file_, line_, func_, 3) << '\n';

                std::exit(exit::error::POST_CONDITION_FAILURE);
            }



        } // namespace contract
    }     // namespace debug
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DEBUG_CONTRACT_HPP
