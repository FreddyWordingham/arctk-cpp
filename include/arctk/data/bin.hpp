/**
 *  @file   arctk/data/bin.hpp
 *  @date   02/06/2018
 *  @author Freddy Wordingham
 *
 *  Data binning base class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN_HPP
#define ARCTK_DATA_BIN_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Histogram class which bins values into a data vector.
         *
         *  @tparam T   Type of value to be counted.
         */
        template <typename T>
        class Bin
        {
            //  == FIELDS ==
          protected:
            //  -- Data --
            std::vector<T> _counts; //!< Hit count of each bin.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Bin(size_t res_) noexcept = default;

            //  -- Destructors --
            virtual inline ~Bin() noexcept = default;


            //  == METHODS ==
          public:
            //  -- Getters --
            virtual inline double        min() const noexcept   = 0;
            virtual inline double        max() const noexcept   = 0;
            virtual inline double        width() const noexcept = 0;
            inline const std::vector<T>& counts() const noexcept;

            //  -- Collection --
            virtual inline void collect(double pos_, T weight_) noexcept = 0;

          protected:
            //  -- Placement --
            inline size_t index(double pos_) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T>
        inline Bin<T>::Bin(const size_t res_) noexcept
          : _counts(res_)
        {
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the bin counts vector.
         *
         *  @tparam T   Type of value to be counted.
         *
         *  @return Bin counts vector.
         */
        template <typename T>
        inline const std::vector<T>& Bin<T>::counts() const noexcept
        {
            return (_counts);
        }


        //  -- Placement --
        /**
         *  Determine the index which a position count would be located within counts vector.
         *
         *  @tparam T   Type of value to be counted.
         *
         *  @param  pos_    Position to place.
         *
         *  @return Index where the position count would be placed.
         */
        template <typename T>
        inline size_t Bin<T>::index(const double pos_) const noexcept
        {
            assert(pos_ >= min());
            assert(pos_ <= max());

            const auto index = static_cast<size_t>((pos_ - min()) / width());

            return ((index == _counts.size()) ? (index - 1) : index);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_HPP
