/**
 *  @file   arctk/data/bin/dynamic.hpp
 *  @date   06/06/2018
 *  @author Freddy Wordingham
 *
 *  Dynamic range data binning base class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN_DYNAMIC_HPP
#define ARCTK_DATA_BIN_DYNAMIC_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/data/bin.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace bin //! binning namespace
        {



            //  == CLASS ==
            /**
             *  Dynamic range histogram class which bins values into a data vector.
             *  Expands to capture all collection values.
             *
             *  @tparam T   Type of value to be counted.
             */
            template <typename T>
            class Dynamic : public Bin<T>
            {
                //  == FIELDS ==
              private:
                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Dynamic(double min_, double max_, size_t res_) noexcept;


                //  == METHODS ==
              public:
                //  -- Collection --
                inline void collect(double pos_, T weight_) noexcept override;

              private:
                //  -- Growth --
                inline void ascend() noexcept;
                inline void descend() noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a dynamic range bin object.
             *
             *  @tparam T   Type of value to be counted.
             *
             *  @param  min_    Initial minimum range bound of the bin.
             *  @param  max_    Initial maximum range bound of the bin.
             *  @param  res_    Resolution of the bin.
             *
             *  @pre    min_ must me less than max_.
             *  @pre    res_ must be positive.
             *  @pre    res_ must be even.
             */
            template <typename T>
            inline Dynamic<T>::Dynamic(const double min_, const double max_, const size_t res_) noexcept
              : Bin<T>(min_, max_, res_)
            {
                assert(min_ < max_);
                assert(res_ > 0);
                assert((res_ % 2) == 0);
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Collect a weight, at a position, into the bin array.
             *  Grow the bin range to accommodate out of range values.
             *
             *  @param  pos_    Position of the weight.
             *  @param  weight_ Weight of value to be binned.
             *
             *  @post   pos_ must be greater than, or equal to, _min.
             *  @post   pos_ must be less than, or equal to, _max.
             */
            template <typename T>
            inline void Dynamic<T>::collect(const double pos_, const T weight_) noexcept
            {
                while (pos_ < Bin<T>::_min)
                {
                    descend();
                }

                while (pos_ > Bin<T>::_max)
                {
                    ascend();
                }

                assert(pos_ >= Bin<T>::_min);
                assert(pos_ <= Bin<T>::_max);

                Bin<T>::_counts[Bin<T>::index(pos_)] += weight_;
            }


            //  -- Growth --
            /**
             *  Double the range of the bin by increasing the maximum bound.
             *
             *  @tparam T   Type of value to be counted.
             */
            template <typename T>
            inline void Dynamic<T>::ascend() noexcept
            {
                Bin<T>::_max += (Bin<T>::_max - Bin<T>::_min);
                Bin<T>::_width *= 2.0;

                for (size_t i = 0; i < (Bin<T>::_counts.size() / 2); ++i)
                {
                    const size_t index = (2 * i);
                    Bin<T>::_counts[i] = Bin<T>::_counts[index] + Bin<T>::_counts[index + 1];
                }
                for (size_t i = (Bin<T>::_counts.size() / 2); i < Bin<T>::_counts.size(); ++i)
                {
                    Bin<T>::_counts[i] = {};
                }
            }

            /**
             *  Double the range of the bin by decreasing the minimum bound.
             *
             *  @tparam T   Type of value to be counted.
             */
            template <typename T>
            inline void Dynamic<T>::descend() noexcept
            {
                _min -= (_max - _min);
                _width *= 2.0;

                for (size_t i = (_counts.size() - 1); i >= (_counts.size() / 2); --i)
                {
                    const size_t index = (2 * i) - _counts.size();
                    _counts[i]         = _counts[index] + _counts[index + 1];
                }
                for (size_t i = 0; i < (_counts.size() / 2); ++i)
                {
                    _counts[i] = {};
                }
            }



        } // namespace bin
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_DYNAMIC_HPP
