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
            inline size_t next(const size_t cur_, const size_t size_, const size_t step_ = 1) noexcept;
            inline size_t prev(const size_t cur_, const size_t size_, const size_t step_ = 1) noexcept;



            //  == FUNCTIONS ==
            //  -- Rotate --
            inline size_t next(const size_t cur_, const size_t size_, const size_t step_) noexcept
            {
                PRE(step_ < size_);

                const size_t next = cur_ + step_;

                return ((next < size_) ? next : (next - size_));
            }

            inline size_t prev(const size_t cur_, const size_t size_, const size_t step_) noexcept
            {
                PRE(step_ < size_);

                return ((step_ <= cur_) ? (cur_ - step_) : (size_ + cur_ - step_));
            }



        } // namespace rotate
    }     // namespace index
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_INDEX_ROTATE_HPP
