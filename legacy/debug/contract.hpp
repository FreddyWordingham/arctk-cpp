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
            [[noreturn]] inline void precondition(const std::string& condition_, const std::string& file_, int line_, const std::string& func_) noexcept;
            [[noreturn]] inline void postcondition(const std::string& condition_, const std::string& file_, int line_, const std::string& func_) noexcept;



            //  == FUNCTIONS ==
            //  -- Contracts --
            /**
             *  Report a pre-condition failure.
             *
             *  @param  condition_  String of the pre-condition that was tested.
             *  @param  file_       File location of the pre-condition failure.
             *  @param  line_       Line location of the pre-condition failure.
             *  @param  func_       Function location of the pre-condition failure.
             */
            [[noreturn]] inline void precondition(const std::string& condition_, const std::string& file_, int line_, const std::string& func_) noexcept
            {
                std::cerr << "Pre-condition  : `" << condition_ << "` failed.\n"
                          << "Located at     :\n"
                          << location::info(file_, line_, func_, 3) << '\n';

                std::exit(exit::error::PRE_CONDITION_FAILURE);
            }

            /**
             *  Report a post-condition failure.
             *
             *  @param  condition_  String of the post-condition that was tested.
             *  @param  file_       File location of the post-condition failure.
             *  @param  line_       Line location of the post-condition failure.
             *  @param  func_       Function location of the post-condition failure.
             */
            [[noreturn]] inline void postcondition(const std::string& condition_, const std::string& file_, int line_, const std::string& func_) noexcept
            {
                std::cerr << "Post-condition : `" << condition_ << "` failed.\n"
                          << "Located at     :\n"
                          << location::info(file_, line_, func_, 3) << '\n';

                std::exit(exit::error::POST_CONDITION_FAILURE);
            }



        } // namespace contract
    }     // namespace debug
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DEBUG_CONTRACT_HPP
