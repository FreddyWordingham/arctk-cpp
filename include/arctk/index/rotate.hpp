/**
 *  @file   arctk/index/rotate.hpp
 *  @date   20/08/2018
 *  @author Freddy Wordingham
 *
 *  Index rotation functions.
 */



//  == GUARD ==
#ifndef ARCTK_INDEX_ROTATE_HPP
#define ARCTK_INDEX_ROTATE_HPP



//  == IMPORTS ==
//  -- Std --
#include <cstddef>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace index //! indexing namespace
    {
        namespace rotate //! rotation namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Rotate --
            inline size_t next(size_t cur_, size_t size_, size_t step_ = 1) noexcept;
            inline size_t prev(size_t cur_, size_t size_, size_t step_ = 1) noexcept;



        } // namespace rotate
    }     // namespace index
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/index/rotate.inl>



//  == GUARD END ==
#endif // ARCTK_INDEX_ROTATE_HPP
