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
        constexpr const unsigned long int ARCTK_VERSION_MAJOR = 0; //! Version major number.
        constexpr const unsigned long int ARCTK_VERSION_MINOR = 0; //! Version minor number.
        constexpr const unsigned long int ARCTK_VERSION_PATCH = 58; //! Version patch number.

        //  -- Build Info --
        constexpr const char* ARCTK_DIR      = "/Users/freddy/arctk";      //! Build directory.
        constexpr const char* ARCTK_BRANCH   = "master";   //! Build branch.
        constexpr const char* ARCTK_HASH     = "6d0e83f";     //! Git hash.
        constexpr const char* ARCTK_COMPILER = "Clang"; //! Compiler id.
        constexpr const char* ARCTK_TYPE     = "debug";     //! Optimisation type.
        constexpr const char* ARCTK_DATE     = "2018-05-15";     //! Build date

        //  -- Module Status --
        constexpr const char* ARCTK_MOD_CORE = "true"; //! Arctk core.



    } // namespace config
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_CODE_MOD



//  == GUARD END ==
#define ARCTK_CONFIG_HPP
