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
#include <cassert>
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



            //  == FUNCTIONS ==
            //  -- Rotate --
            /**
             *  Step forward in a index rotation of a given size.
             *
             *  @param  cur_    Current index value.
             *  @param  size_   Size of the index roll.
             *  @param  step_   Step size.
             *
             *  @pre    step_ must be less than size_.
             *
             *  @return Next index after stepping forward.
             */
            inline size_t next(const size_t cur_, const size_t size_, const size_t step_) noexcept
            {
                assert(step_ < size_);

                const size_t next = cur_ + step_;

                return ((next < size_) ? next : (next - size_));
            }

            /**
             *  Step backward in a index rotation of a given size.
             *
             *  @param  cur_    Current index value.
             *  @param  size_   Size of the index roll.
             *  @param  step_   Step size.
             *
             *  @pre    step_ must be less than size_.
             *
             *  @return Previous index after stepping backward.
             */
            inline size_t prev(const size_t cur_, const size_t size_, const size_t step_) noexcept
            {
                assert(step_ < size_);

                return ((step_ <= cur_) ? (cur_ - step_) : (size_ + cur_ - step_));
            }



        } // namespace rotate
    }     // namespace index
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_INDEX_ROTATE_HPP
