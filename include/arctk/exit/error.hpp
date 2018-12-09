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
            //  -- Bugs --
            constexpr const int UNREACHABLE_CODE    = 100; //!< Unreachable code location reached.
            constexpr const int SINGLETON_VIOLATION = 101; //!< Multiple instances of a singleton requested.

            //  -- Contracts --
            constexpr const int PRE_CONDITION_FAILURE  = 110; //!< Pre-condition assertion failed.
            constexpr const int POST_CONDITION_FAILURE = 111; //!< Post-condition assertion failed.
            constexpr const int INVARIANT_FAILURE      = 112; //!< Invariant assertion failed.

            //  -- Parsing --
            constexpr const int INVALID_COMMAND_LINE_ARGUMENTS = 120; //!< Invalid command line arguments.
            constexpr const int FAILED_PARSE                   = 121; //!< Parse attempt failed or will fail.

            //  -- File IO --
            constexpr const int FILE_OPEN_FAILED    = 130; //!< Unable to open a file.
            constexpr const int DIR_CREATION_FAILED = 131; //!< Unable to create a directory.
            constexpr const int INVALID_DIR_NAME    = 132; //!< Invalid directory name.

            //  -- GUI --
            constexpr const int WINDOW_POINTER_INIT_FAILED = 140; //!< Unable initialise a glfw window pointer.
            constexpr const int GLFW_INIT_FAILED           = 141; //!< Unable initialise glfw.
            constexpr const int GLEW_INIT_FAILED           = 142; //!< Unable initialise glew.
            constexpr const int SHADER_LINKING_FAILED      = 143; //!< Shader linking failed.
            constexpr const int SHADER_COMPILATION_FAILED  = 143; //!< Shader compilation failed.
            constexpr const int SHADER_UNIFORM_NOT_FOUND   = 144; //!< Unable to find uniform within the shader.
            constexpr const int SHADER_UNIFORM_DUPLICATE   = 145; //!< Attempt was made to initialise a shader twice.
            constexpr const int TEXTURE_LOAD_FAILED        = 146; //!< Texture could not be loaded.

            //  -- Construction --
            constexpr const int FAILED_INITIALISATION = 150; //!< Failed to construct an object during initialisation.



        } // namespace error
    }     // namespace exit
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_EXIT_ERROR_HPP
