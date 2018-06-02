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
#include <arctk/bin/fixed.hpp>



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
            class Fixed : public Bin
            {
                //  == FIELDS ==
              private:
                //  -- Bounds --
                const double _min; //!< Minimum bound of the bin range.
                const double _max; //!< Maximum bound of the bin range.


                //  == INSTANTIATION ==
              public:
                //  == METHODS ==
              public:
                //  -- Getters --
                virtual inline double min() const noexcept   = 0;
                virtual inline double max() const noexcept   = 0;
                virtual inline double width() const noexcept = 0;

                //  -- Collection --
                virtual inline void collect(double pos_, T weight_) noexcept = 0;
            };



            //  == METHODS ==



        } // namespace bin
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_FIXED_HPP
