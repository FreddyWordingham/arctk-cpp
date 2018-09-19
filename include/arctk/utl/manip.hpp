/**
 *  @file   arctk/utl/manip.hpp
 *  @date   19/09/2018
 *  @author Freddy Wordingham
 *
 *  Collection of manipulation functions.
 */



//  == GUARD ==
#ifndef ARCTK_UTL_MANIP_HPP
#define ARCTK_UTL_MANIP_HPP



//  == IMPORTS ==
//  -- Std --
#include <algorithm>
#include <iterator>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace utl //! utility namespace
    {
        namespace manip //! manipulation namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Movement --
            template <typename T>
            void move_append(std::vector<T>* dest_, std::vector<T>* source_);



            //  == FUNCTIONS ==
            //  -- Movement --
            template <typename T>
            void move_append(std::vector<T>* dest_, std::vector<T>* source_)
            {
                if (dest_->empty())
                {
                    dest_ = std::move(source_);
                }
                else
                {
                    dest_->reserve(dest_->size() + source_->size());

                    std::move(std::begin(*source_), std::end(*source_), std::back_inserter(*dest_));

                    source_->clear();
                }
            }



        } // namespace manip
    }     // namespace utl
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_UTL_MANIP_HPP
