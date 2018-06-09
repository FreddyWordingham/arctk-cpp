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
                unsigned int _missed; //!< Number of range misses.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
            };



            //  == INSTANTIATION ==



        } // namespace bucket
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_FIXED_HPP
