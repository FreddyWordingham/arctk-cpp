/**
 *  @file   arctk/data/bucket/fixed.hpp
 *  @date   09/06/2018
 *  @author Freddy Wordingham
 *
 *  Fixed range data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BUCKET_FIXED_HPP
#define ARCTK_DATA_BUCKET_FIXED_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/data/bucket.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace bucket //! bucketing namespace
        {



            //  == CLASS ==
            /**
             *  Fixed range histogram class which bins values into a data vector.
             *
             *  @tparam T   Type of value to be counted.
             */
            template <typename T>
            class Fixed : public Bucket<T>
            {
                //  == FIELDS ==
              private:
                //  -- Counts --
                unsigned int _misses; //!< Number of range misses.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Fixed(double min_, double max_, size_t res_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline unsigned int misses() noexcept;

                //  -- Collection --
                inline void collect(const std::vector<double>& pos_, T val_) noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename T>
            inline Fixed<T>::Fixed(const double min_, const double max_, const size_t res_) noexcept
              : Bucket<T>(min_, max_, res_)
              , _misses(0)
            {
                assert(min_ < max_);
                assert(res_ > 0);
            }



            //  == METHODS ==
            //  -- Getters --
            template <typename T>
            inline unsigned int Fixed<T>::misses() noexcept
            {
                return (_misses);
            }


            //  -- Collection --
            template <typename T>
            inline void Fixed<T>::collect(std::vector<double>& pos_, T val_) noexcept
            {
                assert(pos_.size() == 1);

                if ((pos_.back() < Bucket<T>::_min) || (pos_.back() > Bucket<T>::_max))
                {
                    ++_misses;

                    return;
                }

                const size_t index = Bucket<T>::find_index(pos_.back());
                pos_.pop_back();

                if constexpr (is_bucket<T>::type)
                {
                    Bucket<T>::_bins[index].collect(pos_, val_);
                }
                else
                {
                    Bucket<T>::_bins[index] += val_;
                }
            }



        } // namespace bucket
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_FIXED_HPP
