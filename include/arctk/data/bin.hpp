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
            //  -- Data --
            std::vector<T> _counts; //!< Hit count of each bin.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Bin(size_t res_) noexcept;
            inline Bin(const Bin&) noexcept = default; //!< Defaulted copy constructor.
            inline Bin(Bin&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Bin() noexcept = default;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Bin& operator=(const Bin&) noexcept = default; //!< Defaulted copy operator. @return Reference to copied object.
            inline Bin& operator=(Bin&&) noexcept = default;      //!< Defaulted move operator. @return Reference to moved object.

            //  -- Stream --
            template <typename S>
            friend inline S& operator<<(S& stream_, const Bin<T>& bin_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            virtual inline double            min() const noexcept   = 0; //!< Get the minimum of the range.
            virtual inline double            max() const noexcept   = 0; //!< Get the maximum of the range.
            virtual inline double            width() const noexcept = 0; //!< Get the inter bin width.
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
         *  @param  res_    Resolution of the bin.
         *
         *  @pre    res_ must be positive.
         */
        template <typename T>
        inline Bin<T>::Bin(const size_t res_) noexcept
          : _counts(res_)
        {
            assert(res_ > 0);
        }



        //  == OPERATORS ==
        //  -- Stream --
        /**
         *  Print a bin as a human-readable string.
         *
         *  @tparam S   Type of stream to print to.
         *  @tparam T   Type of value to be counted.
         *
         *  @param  stream_ Stream to print to.
         *  @param  bin_    Bin to print.
         *
         *  @return A reference to the stream post-print.
         */
        template <typename S, typename T>
        inline S& operator<<(S& stream_, const Bin<T>& bin_) noexcept
        {
            stream_ << format::cols(10, ", ", bin_.centres(), bin_._counts);

            return (stream_);
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

            return (min() + (width() * (index_ * 0.5)));
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
