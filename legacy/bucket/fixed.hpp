/**
 *  @file   arctk/data/bucket/fixed.hpp
 *  @date   23/06/2018
 *  @author Freddy Wordingham
 *
 *  Fixed range data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BUCKET_FIXED_HPP
#define ARCTK_DATA_BUCKET_FIXED_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == BASE ==
//  -- Arctk --
#include <arctk/data/bucket.hpp>



//  == IMPORTS ==
//  -- Std --
#include <cassert>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace bucket //! bucketing namespace
        {



            //  == CLASS ==
            /**
             *  Fixed range binning class.
             *
             *  @tparam T   Type stored by the bucket.
             */
            template <typename T>
            class Fixed : public Bucket<T>
            {
                //  == FIELDS ==
              private:
                //  -- Counts --
                T _misses{}; //!< Number of range misses.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Fixed(double min_, double max_, double size_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const T& misses() const noexcept;

                //  -- Collection --
                inline void collect(double pos_, const T& val_) noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a fixed one-dimensional bucket object with given bounds and size.
             *
             *  @tparam T   Type binned.
             *
             *  @param  min_    Minimum bound of the bucket.
             *  @param  max_    Maximum bound of the bucket.
             *  @param  size_   Number of bins.
             *
             *  @pre    min_ must be less than max_.
             *  @pre    Size_ must be positive.
             */
            template <typename T>
            inline Fixed<T>::Fixed(const double min_, const double max_, const double size_) noexcept
              : Bucket<T>(min_, max_, size_)
            {
                assert(min_ < max_);
                assert(size_ > 0);
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the total number of misses.
             *
             *  @tparam T   Type binned.
             *
             *  @return Total number of misses.
             */
            template <typename T>
            inline const T& Fixed<T>::misses() const noexcept
            {
                return (_misses);
            }


            //  -- Collection --
            /**
             *  Collect a value into the bucket at a given position.
             *  If the position is outside the bounds of the bucket then it is counted as a miss.
             *
             *  @tparam T   Type binned.
             *
             *  @param  pos_    Position of the value to place.
             *  @param  val_    Value to place within the bins.
             */
            template <typename T>
            inline void Fixed<T>::collect(const double pos_, const T& val_) noexcept
            {
                if ((pos_ < Bucket<T>::_min) || (pos_ > Bucket<T>::_max))
                {
                    _misses += val_;

                    return;
                }

                Bucket<T>::_bins[Bucket<T>::find_index(pos_)] += val_;
            }



        } // namespace bucket
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_FIXED_HPP
