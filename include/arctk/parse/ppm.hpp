/**
 *  @file   arctk/parse/ppm.hpp
 *  @date   22/06/2018
 *  @author Freddy Wordingham
 *
 *  PPM parsing functions.
 */



//  == GUARD ==
#ifndef ARCTK_PARSE_PPM_HPP
#define ARCTK_PARSE_PPM_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <algorithm>

//  -- Arctk --
#include <arctk/sys.hpp>
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace parse //! parsing namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Parsing --
        inline void to_ppm(const std::string& path_, const utl::MultiVec<vec3, 2>& pixels) noexcept;



        //  == FUNCTIONS ==
        //  -- Parsing --
        inline void to_ppm(const std::string& path_, const utl::MultiVec<vec3, 2>& pixels) noexcept
        {
            assert(!path_.empty());
            assert(pixels.size() > 0);
            assert(pixels.front().size() > 0);

            sys::file::Out file(path_);

            file << "P3\n"
                 << _width << " " << _height << "\n"
                 << "255\n";

            for (size_t i = 0; i < _height; ++i)
            {
                for (size_t j = 0; j < _width; ++j)
                {
                    for (size_t k = 0; k < 3; ++k)
                    {
                        file << std::clamp(static_cast<int>(255 * pixels[j][_height - i - 1][k]), 0, 255) << "\t";
                    }
                    file << "\t";
                }
                file << "\n";
            }
        }



    } // namespace parse
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PARSE_PPM_HPP
