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

//  -- Arctk --
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

            for (size_t i = 0; i < tokens.size(); ++i)
            {
                std::cout << i << '\t' << tokens[i] << '\n';
            }

            std::map<std::string, std::string> data;

            return (data);
        }



        //  == METHODS ==



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_OBJ_INL
