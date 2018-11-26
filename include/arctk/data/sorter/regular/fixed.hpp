/**
 *  @file   arctk/data/sorter/regular/fixed.hpp
 *  @date   22/11/2018
 *  @author Freddy Wordingham
 *
 *  Fixed range regular interval sorting class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_SORTER_REGULAR_FIXED_HPP
#define ARCTK_DATA_SORTER_REGULAR_FIXED_HPP



//  == BASE ==
#include <arctk/data/sorter/regular.hpp>



//  == IMOPORTS ==
//  -- Std --
#include <cstddef>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace sorter //! sorting namespace
        {
            namespace regular //! regular interval namespace
            {



                //  == CLASS ==
                /**
                 *  Fixed range regular interval sorting class.
                 *
                 *  @tparam T   Type sorted.
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
                    //  -- Call --
                    inline T&       operator()(double pos_) noexcept override;
                    inline const T& operator()(double pos_) const noexcept override;
                };



            } // namespace regular
        }     // namespace sorter
    }         // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/sorter/regular/fixed.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_SORTER_REGULAR_FIXED_HPP
