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
        //  -- Build Info --
        constexpr const char* ARCTK_DIR      = "/Users/freddy/arctk";      //! Build directory.
        constexpr const char* ARCTK_BRANCH   = "";   //! Build branch.
        constexpr const char* ARCTK_HASH     = "";     //! Git hash.
        constexpr const char* ARCTK_PATCH    = "";    //! Git patch number.
        constexpr const char* ARCTK_COMPILER = ""; //! Compiler id.
        constexpr const char* ARCTK_TYPE     = "";     //! Optimisation type.
        constexpr const char* ARCTK_DATE     = "";     //! Build date

        //  -- Module Status --
        constexpr const char* ARCTK_MOD_CORE = ""; //! Arctk core.



    } // namespace config
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_CODE_MOD



//  == GUARD END ==
#define ARCTK_CONFIG_HPP
