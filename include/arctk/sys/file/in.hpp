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

                //  -- Stream --
                template <typename S>
                friend inline S& operator<<(S& stream_, const In& file_) noexcept;
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
                handle.open(_path, std::fstream::in);

                if (!handle.is_open())
                {
                    ERROR(42) << "Inend file: '" << _path << "' could not be opened.";
                }

                assert(handle.is_open());

                return (handle);
            }



            //  == OPERATORS ==
            //  -- Stream --
            /**
             *  Stream the entire contents of the file to a stream.
             *
             *  @tparam S   Type of stream.
             *
             *  @param  stream_ Stream to write to.
             *  @param  file_   File to be read.
             *
             *  @return Reference to stream_ post-write.
             */
            template <typename S>
            inline S& operator<<(S& stream_, const In& file_) noexcept
            {
                stream_ << file_._handle.rdbuf();

                return (stream_);
            }



        } // namespace file
    }     // namespace sys
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_SYS_FILE_IN_HPP
