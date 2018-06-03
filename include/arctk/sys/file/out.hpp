/**
 *  @file   arctk/sys/file/out.hpp
 *  @date   03/06/2018
 *  @author Freddy Wordingham
 *
 *  Output file system class.
 */



//  == GUARD ==
#ifndef ARCTK_SYS_FILE_OUT_HPP
#define ARCTK_SYS_FILE_OUT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <fstream>

//  -- Arctk --
#include <arctk/sys/file.hpp>



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

                //  -- Destructors --
                inline ~Out() noexcept override;

                //  -- Initialisation --
                inline std::ofstream init_handle() noexcept;


                //  == OPERATORS ==
              public:
                //  -- Stream --
                template <class T>
                inline Out& operator<<(const T& val_) noexcept;
            };



            //  == INSTANTIATION --
            //  -- Constructors --
            inline Out::Out(const std::string& path_) noexcept
              : File(path_)
              , _handle(init_handle())
            {
                assert(!path_.empty());
            }


            //  -- Destructors --
            inline Out::~Out() noexcept
            {
                assert(_handle.is_open());

                _handle.close();

                assert(!_handle.is_open());
            }


            //  -- Initialisation --
            inline std::ofstream Out::init_handle() noexcept
            {
                assert(!_path.empty());

                std::ofstream handle;
                handle.open(_path, std::fstream::out);

                if (!handle.is_open())
                {
                    ERROR(42) << "Out file: '" << _path << "' could not be opened.";
                }

                assert(handle.is_open());

                return (handle);
            }



            //  == OPERATORS ==
            //  -- Stream --
            template <class T>
            inline Out& Out::operator<<(const T& val_) noexcept
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
#endif // ARCTK_SYS_FILE_OUT_HPP
