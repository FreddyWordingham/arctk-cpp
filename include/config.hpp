//  == GUARD ==
#ifndef ARCTK_CONFIG_HPP
#define ARCTK_CONFIG_HPP



//  == MODULE ==
#ifdef ARCTK_CODE_MOD



//  == NAMESPACE ==
namespace arc
{
    namespace config
    {



        //  == CONSTANTS ==
        //  -- Version --
        constexpr const unsigned long int VERSION_MAJOR = 0; //! Version major number.
        constexpr const unsigned long int VERSION_MINOR = 0; //! Version minor number.
        constexpr const unsigned long int VERSION_PATCH = 64; //! Version patch number.

        //  -- Build Info --
        constexpr const char* DIR      = "/Users/freddy/arctk";      //! Build directory.
        constexpr const char* BRANCH   = "master";   //! Build branch.
        constexpr const char* HASH     = "783e76d";     //! Git hash.
        constexpr const char* COMPILER = "Clang"; //! Compiler id.
        constexpr const char* TYPE     = "debug";     //! Optimisation type.
        constexpr const char* DATE     = "2018-05-15";     //! Build date

        //  -- Module Status --
        constexpr const char* MOD_CORE = "true"; //! Arctk core.



    } // namespace config
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_CODE_MOD



//  == GUARD END ==
#define ARCTK_CONFIG_HPP
