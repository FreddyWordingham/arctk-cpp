/**
 *  @file   arctk/data/bin2/fixed.hpp
 *  @date   08/06/2018
 *  @author Freddy Wordingham
 *
 *  Fixed range two-dimensional data binning base class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN2_FIXED_HPP
#define ARCTK_DATA_BIN2_FIXED_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/data/bin2.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace bin2 //! binning namespace
        {



            //  == CLASS ==
            /**
             *  Fixed range two-dimensional histogram class which bins values into a data vector.
             *
             *  @tparam T   Type of value to be counted.
             */
            template <typename T>
            class Fixed : public Bin2<T>
            {
                //  == FIELDS ==
              private:
                //  -- Counts --
                T _misses; //!< Sum of total range misses.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Fixed(const math::Vec2<double>& min_, const math::Vec2<double>& max_, const math::Vec2<size_t>& res_) noexcept;


                //  == METHODS ==
              public:
                //  -- Collection --
                inline void collect(const math::Vec2<double>& pos_, T weight_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a fixed range bin object.
             *
             *  @tparam T   Type of value to be counted.
             *
             *  @param  min_    Minimum range bound of the bin.
             *  @param  max_    Maximum range bound of the bin.
             *  @param  res_    Resolution of the bin.
             *
             *  @pre    min_.x must me less than max_.x.
             *  @pre    min_.y must me less than max_.y.
             *  @pre    res_.x must be positive.
             *  @pre    res_.y must be positive.
             */
            template <typename T>
            inline Fixed<T>::Fixed(const math::Vec2<double>& min_, const math::Vec2<double>& max_, const math::Vec2<size_t>& res_) noexcept
              : Bin2<T>(min_, max_, res_)
              , _misses({})
            {
                assert(min_.x < max_.x);
                assert(min_.y < max_.y);
                assert(res_.x > 0);
                assert(res_.y > 0);
            }



            //  == METHODS ==
            //  -- Collection --
            /**
             *  Collect a weight, at a position, into the bin array.
             *
             *  @param  pos_    Position of the weight.
             *  @param  weight_ Weight of value to be binned.
             */
            template <typename T>
            inline void Fixed<T>::collect(const math::Vec2<double>& pos_, const T weight_) noexcept
            {
                if ((pos_.x < Bin2<T>::_min.x) || (pos_.y < Bin2<T>::_min.y) || (pos_.x > Bin2<T>::_max.x) || (pos_.y > Bin2<T>::_max.y))
                {
                    _misses += weight_;

                    return;
                }

                const math::Vec2<size_t> index = Bin2<T>::index(pos_);

                Bin2<T>::_counts[index.x][index.y] += weight_;
            }



        } // namespace bin2
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BIN2_FIXED_HPP
