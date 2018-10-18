/**
 *  @file   arctk/config/build.hpp
 *  @date   18/10/2018
 *  @author Freddy Wordingham
 *
 *  Library build-time configuration constants.
 */



//  == GUARD ==
#ifndef ARCTK_CONFIG_BUILD_HPP
#define ARCTK_CONFIG_BUILD_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace config //! configuration namespace
    {



        //  == CONSTANTS ==
        //  -- Build Information --
        constexpr const char* DIR      = "/Users/freddy/Projects/arctk";      //!< Build directory.
        constexpr const char* BRANCH   = "master";   //!< Build branch.
        constexpr const char* HASH     = "96d87556";     //!< Git hash.
        constexpr const char* COMPILER = "Clang"; //!< Compiler id.
        constexpr const char* TYPE     = "debug";     //!< Optimisation type.
        constexpr const char* DATE     = "2018-10-18";     //!< Build date



    } // namespace config
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_CONFIG_BUILD_HPP
