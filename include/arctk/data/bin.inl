/**
 *  @file   arctk/data/bin.inl
 *  @date   20/11/2018
 *  @author Freddy Wordingham
 *
 *  Data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN_INL
#define ARCTK_DATA_BIN_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>
#include <iomanip>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T>
        inline Bin<T>::Bin(const double min_, const double max_, const size_t res_, const T& init_) noexcept
          : _min(min_)
          , _max(max_)
          , _data(res_, init_)
        {
            assert(min_ < max_);
            assert(res_ > 0);
        }


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        template <typename T>
        inline Bin<T>::~Bin() noexcept = default;



        //  == OPERATORS ==
        //  -- Access --
        template <typename T>
        inline T& Bin<T>::operator[](const size_t index_) noexcept
        {
            assert(index_ < _data.size());

            return (_data[index_]);
        }

        template <typename T>
        inline const T& Bin<T>::operator[](const size_t index_) const noexcept
        {
            assert(index_ < _data.size());

            return (_data[index_]);
        }


        //  -- Printing --
        /**
         *  Print the bin to a stream.
         *
         *  @tparam S   Type stored by the bin.
         *
         *  @param  stream_ Stream to print to.
         *  @param  bin_    Bin to be printed.
         *
         *  @return Reference to the stream post-print.
         */
        template <typename S>
        inline std::ostream& operator<<(std::ostream& stream_, const Bin<S>& bin_) noexcept
        {
            const std::vector<double> bound = bounds();

            stream_ << consts::format::OPENERS[consts::format::container::VEC] << vec_.x << consts::format::DELIM << vec_.y << consts::format::CLOSERS[consts::format::container::VEC];

            for (size_t i = 0; i < _data.size(); ++i)
            {
                stream_ << std::setw(PRINT_WIDTH) << bound[i] << '-' << std::setw(PRINT_WIDTH) << bound[i + 1] << '\t' << std::setw(PRINT_WIDTH) << _data[i] << '\n';
            }

            return (stream_);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename T>
        inline double Bin<T>::min() const noexcept
        {
            return (_min);
        }

        template <typename T>
        inline double Bin<T>::max() const noexcept
        {
            return (_max);
        }

        template <typename T>
        inline const std::vector<T>& Bin<T>::data() const noexcept
        {
            return (_data);
        }

        template <typename T>
        inline size_t Bin<T>::res() const noexcept
        {
            return (_data.size());
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_INL
