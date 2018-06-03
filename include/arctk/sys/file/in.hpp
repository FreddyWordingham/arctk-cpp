/**
 *  @file   arctk/sys/file/in.hpp
 *  @date   03/06/2018
 *  @author Freddy Wordingham
 *
 *  In file system class.
 */



//  == GUARD ==
#ifndef ARCTK_SYS_FILE_IN_HPP
#define ARCTK_SYS_FILE_IN_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <fstream>

//  -- Arctk --
#include <arctk/sys/in.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace sys //! system namespace
    {
        namespace file //! file namespace
        {



            //  == CLASS ==
            /**
             *  In file class.
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

                //  -- Destructors --
                inline ~In() noexcept override;

                //  -- Initialisation --
                inline std::ifstream init_handle() noexcept;


                //  == OPERATORS ==
              public:
                //  -- Stream --
                template <class T>
                inline In& operator<<(const T& val_) noexcept;
            };



            //  == INSTANTIATION --
            //  -- Constructors --
            inline In::In(const std::string& path_) noexcept
              : File(path_)
              , _handle(init_handle())
            {
                assert(!path_.empty());
            }


            //  -- Destructors --
            inline In::~In() noexcept
            {
                assert(_handle.is_open());

                _handle.close();

                assert(!_handle.is_open());
            }


            //  -- Initialisation --
            inline std::ifstream In::init_handle() noexcept
            {
                assert(!_path.empty());

                std::ifstream handle;
                handle.open(_path, std::fstream::app);

                if (!handle.is_open())
                {
                    ERROR(42) << "Inend file: '" << _path << "' could not be opened.";
                }

                assert(handle.is_open());

                return (handle);
            }



            //  == OPERATORS ==
            //  -- Stream --
            template <class T>
            inline In& In::operator<<(const T& val_) noexcept
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
#endif // ARCTK_SYS_FILE_IN_HPP
