/**
 *  @file   arctk/sys/file/app.hpp
 *  @date   05/07/2018
 *  @author Freddy Wordingham
 *
 *  Appending file class.
 */



//  == GUARD ==
#ifndef ARCTK_SYS_FILE_APP_HPP
#define ARCTK_SYS_FILE_APP_HPP



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
             *  Appending file class.
             */
            class App : public File
            {
                //  == FIELDS ==
              private:
                //  -- Handle --
                std::ofstream _handle; //!< Handle to the appending file.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit App(const std::string& path_) noexcept;
                inline App(const App&) noexcept = delete;  //!< Deleted copy constructor.
                inline App(App&&)               = default; //!< Defaulted move constructor.

                //  -- Destructors --
                inline ~App() noexcept override;

              private:
                //  -- Initialisation --
                inline std::ofstream init_handle() noexcept;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline App& operator=(const App&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
                inline App& operator=(App&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.

                //  -- Stream --
                template <class T>
                inline App& operator<<(const T& val_) noexcept;
            };



            //  == INSTANTIATION --
            //  -- Constructors --
            /**
             *  Construct a handle to an appending file at a given path.
             *
             *  @param  path_   Path to file.
             *
             *  @pre    path_ may not be empty.
             */
            inline App::App(const std::string& path_) noexcept
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
            inline App::~App() noexcept
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
            inline std::ofstream App::init_handle() noexcept
            {
                PRE(!_path.empty());

                std::ofstream handle;
                handle.open(_path, std::fstream::app);

                if (!handle.is_open())
                {
                    std::cerr << "Append file: '" << _path << "' could not be opened.";

                    std::exit(exit::error::FILE_OPEN_FAILED);
                }

                POST(handle.is_open());

                return (handle);
            }



            //  == OPERATORS ==
            //  -- Stream --
            /**
             *  Append a value to the file.
             *
             *  @tparam T   Type of value to append.
             *
             *  @param  val_ value to append.
             *
             *  @return Reference to stream_ post-write.
             */
            template <class T>
            inline App& App::operator<<(const T& val_) noexcept
            {
                _handle << val_;

                return (*this);
            }



        } // namespace file
    }     // namespace sys
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SYS_FILE_APP_HPP
