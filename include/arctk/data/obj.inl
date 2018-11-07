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
#include <arctk/sys/file.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        inline Obj::Obj(const std::string& path_) noexcept
          : _data(init_data(path_))
        {
            assert(!path_.empty());
        }


        //  -- Initialisation --
        inline std::map<std::string, std::string> Obj::init_data(const std::string& path_) const noexcept
        {
            std::string contents = sys::file::read(path_);

            std::cout << contents << '\n';
            parse::process::filter_comments(&contents);
            parse::process::filter_whitespace(&contents);
            std::cout << contents << '\n';

            parse::process::extract_contents(&contents, consts::format::container::OBJ);
            std::cout << contents << '\n';
            std::vector<std::string> tokens = parse::process::tokenise(contents);

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
                    std::cerr << "Key value must be a string.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                const size_t key_end = tokens[i].find_first_of(consts::format::CLOSERS[consts::format::container::string], 1);
                if (key_end == std::string::npos)
                {
                    std::cerr << "Key value must be a string.\n";

                    std::exit(exit::error::FAILED_PARSE);
                }

                const std::string key = tokens[i].substr(1, key_end - 1);
                std::cout << "key: " << key << '\n';

                tokens[i].erase(0, key_end);
            }

            return (data);
        }



        //  == METHODS ==



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_OBJ_INL
