/**
 *  @file   arctk/exit/error.hpp
 *  @date   03/07/2018
 *  @author Freddy Wordingham
 *
 *  Enumeration of all exit code error values.
 */



//  == GUARD ==
#ifndef ARCTK_EXIT_ERROR_HPP
#define ARCTK_EXIT_ERROR_HPP



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace exit //! exit codes namespace
    {
        namespace error //! error namespace
        {



            //  == CONSTANTS ==
            //  -- Contracts --
            constexpr const int PRE_CONDITION_FAILURE  = 110; //!< Pre-condition assertion failed.
            constexpr const int POST_CONDITION_FAILURE = 111; //!< Post-condition assertion failed.
            constexpr const int INVARIANT_FAILURE      = 112; //!< Invariant assertion failed.

            //  -- Parsing --
            constexpr const int INVALID_COMMAND_LINE_ARGUMENTS = 120; //!< Invalid command line arguments.
            constexpr const int FAILED_PARSE                   = 121; //!< Parse attempt failed or will fail.

            //  -- File IO --
            constexpr const int FILE_OPEN_FAILED = 130; //!< Unable to open a file.

            //  -- GUI --
            constexpr const int WINDOW_POINTER_INIT_FAILED = 140; //!< Unable initialise a glfw window pointer.
            constexpr const int GLFW_INIT_FAILED           = 141; //!< Unable initialise glfw.
            constexpr const int GLEW_INIT_FAILED           = 142; //!< Unable initialise glew.
            constexpr const int SHADER_LINKING_FAILED      = 143; //!< Shader linking failed.
            constexpr const int SHADER_COMPILATION_FAILED  = 143; //!< Shader compilation failed.
            constexpr const int SHADER_UNIFORM_NOT_FOUND   = 144; //!< Unable to find uniform within the shader.



        } // namespace error
    }     // namespace exit
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EXIT_ERROR_HPP
