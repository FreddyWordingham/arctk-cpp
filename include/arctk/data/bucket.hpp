/**
 *  @file   arctk/data/bucket.hpp
 *  @date   12/06/2018
 *  @author Freddy Wordingham
 *
 *  Data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BUCKET_HPP
#define ARCTK_DATA_BUCKET_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/utl.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Data binning class.
         */
        template <size_t N, typename T>
        class Bucket
        {
            //  == FIELDS ==
          private:
            //  -- Bounds --
            std::array<double, N> _min;
            std::array<double, N> _max;

            //  -- Data --
            utl::MultiVec<T, N> _bins;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Bucket(const std::array<double, N>& min_, const std::array<double, N>& max_, const std::array<size_t, N>& res_) noexcept;


            //  == METHODS ==
          public:
        };



        //  == INSTANTIATION ==
      public:
        //  -- Constructors --
        template <size_t N, typename T>
        inline Bucket<N, T>::Bucket(const std::array<double, N>& min_, const std::array<double, N>& max_, const std::array<size_t, N>& res_) noexcept
          : _min(min_)
          , _max(max_)
          , _bins(utl::make_MultiVec<T, N>(res_))
        {
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BUCKET_HPP
