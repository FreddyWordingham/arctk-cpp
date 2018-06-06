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

//  -- Arctk --
#include <arctk/format/table.hpp>



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
            //  -- Bounds --
            double _min; //!< Minimum bound of the bin range.
            double _max; //!< Maximum bound of the bin range.

            //  -- Properties --
            double _width; //!< Bin bag width.

            //  -- Counts --
            std::vector<T> _counts; //!< Hit count of each bin.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Bin(double min_, double max_, size_t res_) noexcept;
            inline Bin(const Bin&) noexcept = default; //!< Defaulted copy constructor.
            inline Bin(Bin&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Bin() noexcept = 0;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Bin& operator=(const Bin&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Bin& operator=(Bin&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.

            //  -- Stream --
            template <typename S, typename L>
            friend inline S& operator<<(S& stream_, const Bin<L>& bin_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double                    min() const noexcept;
            inline double                    max() const noexcept;
            inline double                    width() const noexcept;
            inline const std::vector<T>&     counts() const noexcept;
            inline double                    centre(size_t index_) const noexcept;
            inline const std::vector<double> centres() const noexcept;

            //  -- Collection --
            virtual inline void collect(double pos_, T weight_) noexcept = 0; //!< Collect a weight, at a position, into the bin array. @param  pos_    Position of the weight. @param  weight_ Weight of value to be binned.

          protected:
            //  -- Placement --
            inline size_t index(double pos_) const noexcept;
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
         *  @pre    min_ must me less than max_.
         *  @pre    res_ must be positive.
         */
        template <typename T>
        inline Bin<T>::Bin(const double min_, const double max_, const size_t res_) noexcept
          : _min(min_)
          , _max(max_)
          , _width((max_ - min_) / res_)
          , _counts(res_)
        {
            assert(min_ < max_);
            assert(res_ > 0);
        }


        //  -- Destructors --
        template <typename T>
        inline Bin<T>::~Bin() noexcept = default;



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
        inline S& operator<<(S& stream_, const Bin<L>& bin_) noexcept
        {
            stream_ << format::cols(10, ", ", bin_.centres(), bin_._counts);

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
        inline double Bin<T>::min() const noexcept
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
        inline double Bin<T>::max() const noexcept
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
        inline double Bin<T>::width() const noexcept
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
        inline const std::vector<T>& Bin<T>::counts() const noexcept
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
         *  @pre    index_ must be less than the size of counts.
         *
         *  @return Centre position of the bin.
         */
        template <typename T>
        inline double Bin<T>::centre(size_t index_) const noexcept
        {
            assert(index_ < _counts.size());

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
        inline const std::vector<double> Bin<T>::centres() const noexcept
        {
            std::vector<double> centres(_counts.size());

            for (size_t i = 0; i < centres.size(); ++i)
            {
                centres[i] = centre(i);
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
        inline size_t Bin<T>::index(const double pos_) const noexcept
        {
            assert(pos_ >= _min);
            assert(pos_ <= _max);

            const auto index = static_cast<size_t>((pos_ - _min) / _width);

            return ((index == _counts.size()) ? (index - 1) : index);
        }



    } // namespace data
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_HPP
