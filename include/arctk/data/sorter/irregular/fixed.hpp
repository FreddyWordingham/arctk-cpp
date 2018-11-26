/**
 *  @file   arctk/data/sorter/irregular/fixed.hpp
 *  @date   22/11/2018
 *  @author Freddy Wordingham
 *
 *  Fixed range irregular interval sorting class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_SORTER_IRREGULAR_FIXED_HPP
#define ARCTK_DATA_SORTER_IRREGULAR_FIXED_HPP



//  == BASE ==
#include <arctk/data/sorter/irregular.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace sorter //! sorting namespace
        {
            namespace irregular //! irregular interval namespace
            {



                //  == CLASS ==
                /**
                 *  Fixed range irregular interval sorting class.
                 *
                 *  @tparam T   Type sorted.
                 */
                template <typename T>
                class Fixed : public Irregular<T>
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



            } // namespace irregular
        }     // namespace sorter
    }         // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/sorter/irregular/fixed.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_SORTER_IRREGULAR_FIXED_HPP
