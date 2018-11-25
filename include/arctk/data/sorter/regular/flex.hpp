/**
 *  @file   arctk/data/sorter/regular/flex.hpp
 *  @date   25/11/2018
 *  @author Freddy Wordingham
 *
 *  Flexible range regular interval sorting class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_SORTER_REGULAR_FLEX_HPP
#define ARCTK_DATA_SORTER_REGULAR_FLEX_HPP



//  == BASE ==
#include <arctk/data/sorter/regular.hpp>



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
                 *  Flexible range regular interval sorting class.
                 *
                 *  @tparam T   Type sorted.
                 */
                template <typename T>
                class Flex : public Regular<T>
                {
                    //  == INSTANTIATION ==
                  public:
                    //  -- Constructors --
                    inline Flex(double min_, double max_, size_t res_, const T& init_ = {}) noexcept;


                    //  == OPERATORS ==
                  public:
                    //  -- Call --
                    inline T&       operator()(double pos_) noexcept override;
                    inline const T& operator()(double pos_) const noexcept override;


                    //  == METHODS ==
                  private:
                    //  -- Growth --
                    inline void ascend() noexcept;
                    inline void descend() noexcept;
                };



            } // namespace regular
        }     // namespace sorter
    }         // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/sorter/regular/flex.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_SORTER_REGULAR_FLEX_HPP
