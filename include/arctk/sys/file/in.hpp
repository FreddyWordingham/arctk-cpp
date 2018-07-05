/**
 *  @file   arctk/sys/file/in.hpp
 *  @date   05/07/2018
 *  @author Freddy Wordingham
 *
 *  Input file class.
 */



//  == GUARD ==
#ifndef ARCTK_SYS_FILE_IN_HPP
#define ARCTK_SYS_FILE_IN_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == Base ==
//  -- Arctk --
#include <arctk/sys/file.hpp>



//  == IMPORTS ==
//  -- Std --
#include <fstream>
#include <iostream>
#include <string>

//  -- Arctk --
#include <arctk/debug.hpp>
#include <arctk/exit.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace sys //! system namespace
    {
        namespace file //! file namespace
        {



            //  == CLASS ==
            /**
             *  Input file class.
             */
            class In : public File
            {
                //  == FIELDS ==
              private:
                //  -- Handle --
                std::ifstream _handle; //!< Handle to the input file.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit In(const std::string& path_) noexcept;
                inline In(const In&) noexcept = delete;  //!< Deleted copy constructor.
                inline In(In&&)               = default; //!< Defaulted move constructor.

                //  -- Destructors --
                inline ~In() noexcept override;

              private:
                //  -- Initialisation --
                inline std::ifstream init_handle() noexcept;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline In& operator=(const In&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
                inline In& operator=(In&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.
            };



            //  == INSTANTIATION --
            //  -- Constructors --
            /**
             *  Construct a handle to an input file at a given path.
             *
             *  @param  path_   Path to file.
             *
             *  @pre    path_ may not be empty.
             */
            inline In::In(const std::string& path_) noexcept
              : File(path_)
              , _handle(init_handle())
            {
                PRE(!path_.empty());
            }


            //  -- Destructors --
            /**
             *  Close the open file.
             *
             *  @pre    _handle must be open.
             *
             *  @post   _handle must be closed.
             */
            inline In::~In() noexcept
            {
                PRE(_handle.is_open());
                POST(!_handle.is_open());

                _handle.close();
            }


            //  -- Initialisation --
            /**
             *  Initialise the handle to the file.
             *
             *  @pre    _path may not be empty.
             *
             *  @post   handle must be open.
             *
             *  @return Handle to filestream.
             */
            inline std::ifstream In::init_handle() noexcept
            {
                PRE(!_path.empty());

                std::ifstream handle;
                handle.open(_path, std::fstream::in);

                if (!handle.is_open())
                {
                    std::cerr << "Input file: '" << _path << "' could not be opened.";

                    std::exit(exit::error::FILE_OPEN_FAILED);
                }

                POST(handle.is_open());

                return (handle);
            }



        } // namespace file
    }     // namespace sys
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SYS_FILE_IN_HPP
