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
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            template <typename T>
            inline Fixed<T>::Fixed(const double min_, const double max_, const size_t res_) noexcept
              : Bin<T>(min_, max_, res_)
              , _misses(0)
            {
                assert(min_ < max_);
                assert(res_ > 0);
            }



        } // namespace bucket
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_FIXED_HPP
