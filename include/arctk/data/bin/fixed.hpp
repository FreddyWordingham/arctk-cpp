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
              : Bin<T>(res_)
              , _min(min_)
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
            inline double Fixed<T>::min() const noexcept
            {
                return (_min);
            }

            /**
             *  Get the maximum of the range.
             *
             *  @tparam T   Type of value to be counted.
             *
             *  @return Range maximum.
             */
            template <typename T>
            inline double Fixed<T>::max() const noexcept
            {
                return (_max);
            }

            /**
             *  Get the inter bin width.
             *
             *  @tparam T   Type of value to be counted.
             *
             *  @return Inter bin width.
             */
            template <typename T>
            inline double Fixed<T>::width() const noexcept
            {
                return (_width);
            }


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
                if ((pos_ < _min) || (pos_ > _max))
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
