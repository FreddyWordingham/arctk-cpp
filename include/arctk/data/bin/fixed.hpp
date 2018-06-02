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
                //  -- Bounds --
                const double _min; //!< Minimum bound of the bin range.
                const double _max; //!< Maximum bound of the bin range.

                //  -- Data --
                const double _width;  //!< Bin bag width.
                T            _misses; //!< Sum of total range misses.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Fixed(double min_, double max_, size_t res_) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double min() const noexcept override;
                inline double max() const noexcept override;
                inline double width() const noexcept override;

                //  -- Collection --
                virtual inline void collect(double pos_, T weight_) noexcept = 0;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a fixed range bin object.
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
              : _min(min_)
              , _max(max_)
              , _width((max_ - min_) / res_)
              , _misses({})
            {
                assert(min_ < max_);
                assert(res_ > 0);
            }



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the minimum of the range.
             *
             *  @tparam T   Type of value to be counted.
             *
             *  @return Range minimum.
             */
            template <typename T>
            inline double Fixed<T>::min() const noexcept override
            {
                return (_min);
            }

            template <typename T>
            inline double Fixed<T>::max() const noexcept override
            {
                return (_max);
            }

            template <typename T>
            inline double Fixed<T>::width() const noexcept override
            {
                return (_width);
            }



        } // namespace bin
    }     // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_FIXED_HPP
