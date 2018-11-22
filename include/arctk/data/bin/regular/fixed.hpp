/**
 *  @file   arctk/data/bin/regular/fixed.hpp
 *  @date   22/11/2018
 *  @author Freddy Wordingham
 *
 *  Fixed range regular interval binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN_REGULAR_FIXED_HPP
#define ARCTK_DATA_BIN_REGULAR_FIXED_HPP



//  == BASE ==
#include <arctk/data/bin/regular.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace bin //! binning namespace
        {
            namespace regular //! regular interval namespace
            {



                //  == CLASS ==
                /**
                 *  Fixed range regular interval binning class.
                 *
                 *  @tparam T   Type binned.
                 */
                template <typename T>
                class Fixed : public Regular<T>
                {
                    //  == INSTANTIATION ==
                  public:
                    //  -- Constructors --
                    inline Fixed(double min_, double max_, size_t res_, const T& init_ = {}) noexcept;


                    //  == OPERATORS ==
                  public:
                    //  -- Access --


                    //  == METHODS ==
                  public:
                    //  -- Getters --
                };



            } // namespace regular
        }     // namespace bin
    }         // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/bin/regular/fixed.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_REGULAR_FIXED_HPP
