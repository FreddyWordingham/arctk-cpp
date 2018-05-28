/**
 *  @file   arctk/config.hpp
 *  @date   15/05/2018
 *  @author Freddy Wordingham
 *
 *  Library build-time configuration constants.
 */



//  == GUARD ==
#ifndef ARCTK_CONFIG_HPP
#define ARCTK_CONFIG_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
#include <cstdint>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace config //! configuration namespace
    {



        //  == CONSTANTS ==
        constexpr const uint64_t VERSION_MAJOR = 0; //!< Version major number.
        constexpr const uint64_t VERSION_MINOR = 0; //!< Version minor number.
        constexpr const uint64_t VERSION_PATCH = 1037; //!< Version patch number.
        constexpr const char*    DIR           = "/Users/freddy/arctk";         //!< Build directory.
        constexpr const char*    BRANCH        = "master";      //!< Build branch.
        constexpr const char*    HASH          = "114c6cd";        //!< Git hash.
        constexpr const char*    COMPILER      = "GNU";    //!< Compiler id.
        constexpr const char*    TYPE          = "debug";        //!< Optimisation type.
        constexpr const char*    DATE          = "2018-05-28";        //!< Build date
        constexpr const char*    MOD_CORE      = "true";    //!< Arctk core module status.



    } // namespace config
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_CONFIG_HPP
