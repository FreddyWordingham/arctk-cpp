/**
 *  @file   arctk/sys/file/out.hpp
 *  @date   05/07/2018
 *  @author Freddy Wordingham
 *
 *  Output file class.
 */



//  == GUARD ==
#ifndef ARCTK_SYS_FILE_OUT_HPP
#define ARCTK_SYS_FILE_OUT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == BASE ==
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
             *  Output file class.
             */
            class Out : public File
            {
                //  == FIELDS ==
              private:
                //  -- Handle --
                std::ofstream _handle; //!< Handle to the output file.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Out(const std::string& path_) noexcept;
                inline Out(const Out&) noexcept = delete;  //!< Deleted copy constructor.
                inline Out(Out&&)               = default; //!< Defaulted move constructor.

                //  -- Destructors --
                inline ~Out() noexcept override;

              private:
                //  -- Initialisation --
                inline std::ofstream init_handle() noexcept;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline Out& operator=(const Out&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
                inline Out& operator=(Out&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.
            };



            //  == INSTANTIATION --
            //  -- Constructors --
            /**
             *  Construct a handle to an output file at a given path.
             *
             *  @param  path_   Path to file.
             *
             *  @pre    path_ may not be empty.
             */
            inline Out::Out(const std::string& path_) noexcept
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
            inline Out::~Out() noexcept
            {
                PRE(_handle.is_open());

                _handle.close();

                POST(!_handle.is_open());
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
            inline std::ofstream Out::init_handle() noexcept
            {
                PRE(!_path.empty());

                std::ofstream handle;
                handle.open(_path, std::fstream::out);

                if (!handle.is_open())
                {
                    std::cerr << "Out file: '" << _path << "' could not be opened.";

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
#endif // ARCTK_SYS_FILE_OUT_HPP
