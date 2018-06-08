/**
 *  @file   arctk/data/bin2.hpp
 *  @date   08/06/2018
 *  @author Freddy Wordingham
 *
 *  Two-dimensional data binning base class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN2_HPP
#define ARCTK_DATA_BIN2_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <vector>

//  -- Arctk --
#include <arctk/format/table.hpp>
#include <arctk/math.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Histogram class which bins values into a two-dimensional data vector.
         *
         *  @tparam T   Type of value to be counted.
         */
        template <typename T>
        class Bin2
        {
            //  == FIELDS ==
          protected:
            //  -- Bounds --
            math::Vec2<double> _min; //!< Minimum bound of the bin range.
            math::Vec2<double> _max; //!< Maximum bound of the bin range.

            //  -- Properties --
            math::Vec2<double> _width; //!< Bin bag width.

            //  -- Counts --
            std::vector<std::vector<T>> _counts; //!< Hit count of each bin.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Bin2(const math::Vec2<double>& min_, const math::Vec2<double>& max_, const math::Vec2<size_t>& res_) noexcept;
            inline Bin2(const Bin2&)     = default; //!< Defaulted copy constructor.
            inline Bin2(Bin2&&) noexcept = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Bin2() noexcept = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Bin2& operator=(const Bin2&) = default;     //!< Defaulted copy operator. @return Reference to copied object.
            inline Bin2& operator=(Bin2&&) noexcept = default; //!< Defaulted move operator. @return Reference to moved object.

            //  -- Stream --
            template <typename S, typename L>
            friend inline S& operator<<(S& stream_, const Bin2<L>& bin_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const math::Vec2<double>&          min() const noexcept;
            inline const math::Vec2<double>&          max() const noexcept;
            inline const math::Vec2<double>&          width() const noexcept;
            inline const std::vector<std::vector<T>>& counts() const noexcept;
            inline math::Vec2<double>                 centre(const math::Vec2<size_t>& index_) const noexcept;
            inline std::vector<std::vector<double>>   centres() const noexcept;

            //  -- Collection --
            virtual inline void collect(double pos_, T weight_) noexcept = 0; //!< Collect a weight, at a position, into the bin array. @param  pos_    Position of the weight. @param  weight_ Weight of value to be binned.

          protected:
            //  -- Placement --
            inline math::Vec2<size_t> index(const math::Vec2<double>& pos_) const noexcept;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Construct a bin with a given resolution.
         *
         *  @tparam T   Type of value to be counted.
         *
         *  @param  min_    Minimum range bound of the bin.
         *  @param  max_    Maximum range bound of the bin.
         *  @param  res_    Resolution of the bin.
         *
         *  @pre    min_.x must me less than max_.x.
         *  @pre    min_.y must me less than max_.y.
         *  @pre    res_.x must be positive.
         *  @pre    res_.y must be positive.
         */
        template <typename T>
        inline Bin2<T>::Bin2(const math::Vec2<double>& min_, const math::Vec2<double>& max_, const math::Vec2<size_t>& res_) noexcept
          : _min(min_)
          , _max(max_)
          , _width({(max_.x - min_.x) / res_.x, (max_.y - min_.y) / res_.y})
          , _counts(std::vector<std::vector<T>>(res_.x, std::vector<T>(res_.y)))
        {
            assert(min_.x < max_.x);
            assert(min_.y < max_.y);
            assert(res_.x > 0);
            assert(res_.y > 0);
        }


        //  -- Destructors --
        template <typename T>
        inline Bin2<T>::~Bin2() noexcept = default;



        //  == OPERATORS ==
        //  -- Stream --
        /**
         *  Print a bin as a human-readable string.
         *
         *  @tparam S   Type of stream to print to.
         *  @tparam L   Type of value to be counted.
         *
         *  @param  stream_ Stream to print to.
         *  @param  bin_    Bin to print.
         *
         *  @return A reference to the stream post-print.
         */
        template <typename S, typename L>
        inline S& operator<<(S& stream_, const Bin2<L>& bin_) noexcept
        {
            stream_ << format::cols(10, ", ", bin_._counts);

            return (stream_);
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
        inline const math::Vec2<double>& Bin2<T>::min() const noexcept
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
        inline const math::Vec2<double>& Bin2<T>::max() const noexcept
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
        inline const math::Vec2<double>& Bin2<T>::width() const noexcept
        {
            return (_width);
        }

        /**
         *  Get the bin counts vector.
         *
         *  @tparam T   Type of value to be counted.
         *
         *  @return Bin counts vector.
         */
        template <typename T>
        inline const std::vector<std::vector<T>>& Bin2<T>::counts() const noexcept
        {
            return (_counts);
        }

        /**
         *  Get a central position of a bin.
         *
         *  @tparam T   Type of value to be counted.
         *
         *  @param  index_  Index of the bin to determine the centre of.
         *
         *  @pre    index_.x must be less than the size of counts.
         *  @pre    index_.y must be less than the size of the first vector stored by counts.
         *
         *  @return Centre position of the bin.
         */
        template <typename T>
        inline math::Vec2<double> Bin2<T>::centre(const math::Vec2<size_t>& index_) const noexcept
        {
            assert(index_.x < _counts.size());
            assert(index_.y < _counts.front().size());

            return (_min + (_width * (index_ + 0.5)));
        }

        /**
         *  Get a vector of all bin central positions.
         *
         *  @tparam T   Type of value to be counted.
         *
         *  @return Vector of bin centre positions.
         */
        template <typename T>
        inline std::vector<std::vector<double>> Bin2<T>::centres() const noexcept
        {
            std::vector<std::vector<math::Vec2<double>>> centres(_counts.size(), std::vector<math::Vec2<double>>(_counts.front().size()));

            for (size_t i = 0; i < centres.size(); ++i)
            {
                for (size_t j = 0; j < centres.front().size(); ++j)
                {
                    centres[i][j] = centre({i, j});
                }
            }

            return (centres);
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
        inline math::Vec2<size_t> Bin2<T>::index(const math::Vec2<double>& pos_) const noexcept
        {
            assert(pos_.x >= _min.x);
            assert(pos_.y >= _min.y);
            assert(pos_.x <= _max.x);
            assert(pos_.y <= _max.y);

            math::Vec2<size_t> index;

            index.x = static_cast<size_t>((pos_.x - _min.x) / _width.x);
            if (index.x == _counts.size())
            {
                --index.x;
            }

            index.y = static_cast<size_t>((pos_.y - _min.y) / _width.y);
            if (index.y == _counts.front().size())
            {
                --index.y;
            }

            return (index);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BIN2_HPP
