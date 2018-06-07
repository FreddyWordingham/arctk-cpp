/**
 *  @file   arctk/data/bin/fixed.hpp
 *  @date   02/06/2018
 *  @author Freddy Wordingham
 *
 *  Fixed range data binning base class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN_FIXED_HPP
#define ARCTK_DATA_BIN_FIXED_HPP



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
             *  Fixed range histogram class which bins values into a data vector.
             *
             *  @tparam T   Type of value to be counted.
             */
            template <typename T>
            class Fixed : public Bin<T>
            {
                //  == FIELDS ==
              private:
                //  -- Counts --
                T _misses; //!< Sum of total range misses.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Fixed(double min_, double max_, size_t res_) noexcept;


                //  == METHODS ==
              public:
                //  -- Collection --
                inline void collect(double pos_, T weight_) noexcept override;
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
             *  @pre    min_ must me less than max_.
             *  @pre    res_ must be positive.
             */
            template <typename T>
            inline Fixed<T>::Fixed(const double min_, const double max_, const size_t res_) noexcept
              : Bin<T>(min_, max_, res_)
              , _misses(0)
            {
                assert(min_ < max_);
                assert(res_ > 0);
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
            inline void Fixed<T>::collect(const double pos_, const T weight_) noexcept
            {
                if ((pos_ < Bin<T>::_min) || (pos_ > Bin<T>::_max))
                {
                    _misses += weight_;

                    return;
                }

                Bin<T>::_counts[Bin<T>::index(pos_)] += weight_;
            }



        } // namespace bin
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_FIXED_HPP
