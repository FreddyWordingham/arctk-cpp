/**
 *  @file   arctk/search/value.hpp
 *  @date   20/10/2018
 *  @author Freddy Wordingham
 *
 *  Collection of value searching functions.
 */



//  == GUARD ==
#ifndef ARCTK_SEARCH_VALUE_HPP
#define ARCTK_SEARCH_VALUE_HPP



//  == IMPORTS ==
//  -- Std --



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace search //! searching namespace
    {
        namespace value //! value namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Value --
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline size_t min_index(const C& cont_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline size_t max_index(const C& cont_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline T min(const C& cont_) noexcept;
            template <typename C, typename T = typename C::value_type, typename I = typename C::const_iterator>
            inline T max(const C& cont_) noexcept;



            //  == FUNCTIONS ==
            //  -- Value --
            /**
             *  Find the index of the minimum element within a container.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to determine the minimum element index of.
             *
             *  @pre    cont_ must not be empty.
             *
             *  @return Index of the minimum element within the container.
             */
            template <typename C, typename T, typename I>
            inline size_t min_index(const C& cont_) noexcept
            {
                assert(!cont_.empty());

                I min_index = std::begin(cont_);

                for (I it = std::next(std::begin(cont_)); it != std::end(cont_); std::advance(it, 1))
                {
                    if (*it < *min_index)
                    {
                        min_index = it;
                    }
                }

                return (std::distance(std::begin(cont_), min_index));
            }

            /**
             *  Find the index of the maximum element within a container.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to determine the maximum element index of.
             *
             *  @pre    cont_ must not be empty.
             *
             *  @return Index of the maximum element within the container.
             */
            template <typename C, typename T, typename I>
            inline size_t max_index(const C& cont_) noexcept
            {
                assert(!cont_.empty());

                I max_index = std::begin(cont_);

                for (I it = std::next(std::begin(cont_)); it != std::end(cont_); std::advance(it, 1))
                {
                    if (*it > *max_index)
                    {
                        max_index = it;
                    }
                }

                return (std::distance(std::begin(cont_), max_index));
            }

            /**
             *  Find the minimum element within a container.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to determine the minimum element of.
             *
             *  @pre    cont_ must not be empty.
             *
             *  @return Value of the minimum element within the container.
             */
            template <typename C, typename T, typename I>
            inline T min(const C& cont_) noexcept
            {
                assert(!cont_.empty());

                return (cont_[min_index(cont_)]);
            }

            /**
             *  Find the maximum element within a container.
             *
             *  @tparam C   Type of container.
             *  @tparam T   Type stored by C.
             *  @tparam I   Type of const iterator of C.
             *
             *  @param  cont_   Container to determine the maximum element of.
             *
             *  @pre    cont_ must not be empty.
             *
             *  @return Value of the maximum element within the container.
             */
            template <typename C, typename T, typename I>
            inline T max(const C& cont_) noexcept
            {
                assert(!cont_.empty());

                return (cont_[max_index(cont_)]);
            }



        } // namespace value
    }     // namespace search
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_SEARCH_VALUE_HPP
