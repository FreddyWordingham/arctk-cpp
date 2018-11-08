/**
 *  @file   arctk/data/obj.inl
 *  @date   06/11/2018
 *  @author Freddy Wordingham
 *
 *  Data object class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_OBJ_INL
#define ARCTK_DATA_OBJ_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <cstdlib>

//  -- Arctk --
#include <arctk/consts/format.hpp>
#include <arctk/exit/error.hpp>
#include <arctk/parse/process.hpp>
#include <arctk/parse/read.hpp>
#include <arctk/sys/file.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct an obj from a serialisation.
         *
         *  @param  serial_ Serialised obj to form into an obj.
         *
         *  @pre    serial_ may not be empty.
         */
        inline Obj::Obj(const std::string& serial_) noexcept
          : _data(init_data(serial_))
        {
            assert(!serial_.empty());
        }


        //  -- Initialisation --
        /**
         *  Initialise the data map of key-value pairs.
         *
         *  @param  serial_ Serialised obj to form into an obj.
         *
         *  @return Initialised data map of key-value pairs.
         */
        inline std::map<std::string, std::string> Obj::init_data(const std::string& serial_) const noexcept
        {
            std::string serial = serial_;

            parse::process::filter_comments(&serial);
            parse::process::filter_whitespace(&serial);

            parse::process::extract_contents(&serial, consts::format::container::OBJ);
            std::vector<std::string> tokens = parse::process::tokenise(serial);

            std::map<std::string, std::string> data;
            for (size_t i = 0; i < tokens.size(); ++i)
            {
                if (tokens[i].empty())
                {
                    std::cerr << "Key-value pairs may not be empty.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                if (tokens[i].front() != consts::format::OPENERS[consts::format::container::STRING])
                {
                    std::cerr << "Key must be a string.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                const size_t key_end = tokens[i].find_first_of(consts::format::CLOSERS[consts::format::container::STRING], 1);
                if (key_end == std::string::npos)
                {
                    std::cerr << "Key must be a string.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                const std::string key = tokens[i].substr(1, key_end - 1);
                tokens[i].erase(0, key_end + 1);

                if (tokens[i].front() != consts::format::LINKER)
                {
                    std::cerr << "Key-value pair must contain linker symbol.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                tokens[i].erase(0, 1);

                if (tokens[i].empty())
                {
                    std::cerr << "Value may not be empty\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                if (data.count(key) != 0)
                {
                    std::cerr << "All key values within an object must be unique.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                data[key] = tokens[i];
            }

            return (data);
        }



        //  == OPERATORS ==
        //  -- Access --
        /**
         *  Create a child obj of an object within this obj.
         *
         *  @param  key_    Key string of child object to form.
         *
         *  @pre    key_ must exist within _data.
         *
         *  @return Child obj.
         */
        inline Obj Obj::operator[](const std::string& key_) const noexcept
        {
            assert(exists(key_));

            std::string str = _data.find(key_)->second;

            return (Obj(str));
        }



        //  == METHODS ==
        //  -- Checking --
        /**
         *  Determine if a key exists within the data map of key-value string pairs.
         *
         *  @param  key_    Key to test.
         *
         *  @return True if the key exists within the data map of key-value string pairs.
         */
        inline bool Obj::exists(const std::string& key_) const noexcept
        {
            return (_data.count(key_) > 0);
        }


        //  -- Parsing --
        template <typename T>
        inline T Obj::value(const std::string& key_) const noexcept
        {
            assert(exists(key_));

            std::string str = _data.find(key_)->second;

            return (parse::read::string<T>(&str));
        }

        template <typename T>
        inline T Obj::value(const std::string& key_, const T& default_) const noexcept
        {
            if (exists(key_))
            {
                value<T>(key_);
            }

            return (default_);
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_OBJ_INL
