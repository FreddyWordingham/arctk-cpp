/**
 *  @file   arctk/prop/multivec.hpp
 *  @date   22/06/2018
 *  @author Freddy Wordingham
 *
 *  Multi-Vec proprty functions.
 */



//  == GUARD ==
#ifndef ARCTK_PROP_MULTIVEC_HPP
#define ARCTK_PROP_MULTIVEC_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace prop //! properties namespace
    {



        //  == FUNCTION PROTOTYPES ==
        //  -- Layout --
        inline bool rectangular(const utl::MultiVec<vec3, 2>& pixels) noexcept;



        //  == FUNCTIONS ==
        //  -- Layout --
        inline bool rectangular(const utl::MultiVec<vec3, 2>& pixels) noexcept
        {
            if (pixels.empty())
            {
                return (true);
            }

            const size_t size = pixels.front().size();
            for (size_t i = 1; i < pixels.size(); ++i)
            {
                if (pixels[i].size() != size)
                {
                    return (false);
                }
            }

            return (true);
        }



    } // namespace prop
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_PROP_MULTIVEC_HPP
