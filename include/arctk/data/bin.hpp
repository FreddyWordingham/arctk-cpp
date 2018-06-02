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
          private:
            //  -- Data --
            std::vector<T> _counts; //!< Hit count of each bin.


            //  == INSTANTIATION ==
          public:
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

          private:
            //  -- Placement --
            inline size_t index(double pos_) const noexcept;
        };



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
        inline const std::vector<T>& Bin::counts() const noexcept
        {
            return (_counts);
        }


        //  -- Placement --
        /**
         *  Determine the index which a value would be placed.
         *
         *  @param  val_    Value to place.
         *
         *  @return Index where value would be placed.
         */
        inline size_t Bin::index(const double val_) const noexcept
        {
            assert(val_ >= min());
            assert(val_ <= max());

            const auto index = static_cast<size_t>((val_ - min()) / width());

            return ((index == _counts.size()) ? (index - 1) : index);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_HPP
