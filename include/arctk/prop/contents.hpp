/**
 *  @file   arctk/prop/contents.hpp
 *  @date   20/10/2018
 *  @author Freddy Wordingham
 *
 *  Collection of contents property functions.
 */



//  == GUARD ==
#ifndef ARCTK_PROP_CONTENTS_HPP
#define ARCTK_PROP_CONTENTS_HPP



//  == IMPORTS ==
//  -- Std --
#include <algorithm>
#include <iterator>

//  -- Arctk --
#include <arctk/prop/order.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace prop //! properties namespace
    {
        namespace contents //! contents namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Contents --
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool contains(const C& cont_, const T& val_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool within(const C& cont_, const T& val_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline bool distinct(const C& cont_) noexcept;



            //  == FUNCTIONS ==
            //  -- Contents --
            /**
             *  Determine if a container contains a value.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to check.
             *  @param  val_    Value to check container for.
             *
             *  @return True if the container contains the value.
             */
            template <typename C, typename T, typename I>
            inline bool contains(const C& cont_, const T& val_) noexcept
            {
                return (std::find(std::begin(cont_), std::end(cont_), val_) != std::end(cont_));
            }

            /**
             *  Determine if a value falls within the range of a container.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to test.
             *  @param  val_    Value to test.
             *
             *  @pre    cont_ must not be empty.
             *  @pre    cont_ must be monotonic.
             *
             *  @return True if the value falls within the containers range.
             */
            template <typename C, typename T, typename I>
            inline bool within(const C& cont_, const T& val_) noexcept
            {
                assert(!cont_.empty());
                assert(prop::order::monotonic(cont_));

                return (((*std::begin(cont_) <= val_) && (val_ <= *std::rbegin(cont_))) || ((*std::begin(cont_) >= val_) && (val_ >= *std::rbegin(cont_))));
            }

            /**
             *  Determine if all elements of a container are distinct.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to test.
             *
             *  @return True if no two elements of the container are equal.
             */
            template <typename C, typename T, typename I>
            inline bool distinct(const C& cont_) noexcept
            {
                for (I it = std::begin(cont_); it != std::end(cont_); std::advance(it, 1))
                {
                    for (I jt = std::next(it); jt != std::end(cont_); std::advance(jt, 1))
                    {
                        if (*it == *jt)
                        {
                            return (false);
                        }
                    }
                }

                return (true);
            }



        } // namespace contents
    }     // namespace prop
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_PROP_CONTENTS_HPP
