/**
 *  @file   arctk/data/sorter.inl
 *  @date   20/11/2018
 *  @author Freddy Wordingham
 *
 *  Data sorting class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_SORTTER_INL
#define ARCTK_DATA_SORTTER_INL



//  == IMPORTS ==
//  -- Std --
#include <cassert>

//  -- Arctk --
#include <arctk/consts/format.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == INSTANTIATION ==
        //  -- Constructors --
        template <typename T>
        inline Sorter<T>::Sorter(const double min_, const double max_, const size_t res_, const T& init_) noexcept
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
        inline Sorter<T>::~Sorter() noexcept = default;



        //  == OPERATORS ==
        //  -- Access --
        template <typename T>
        inline T& Sorter<T>::operator[](const size_t index_) noexcept
        {
            assert(index_ < _data.size());

            return (_data[index_]);
        }

        template <typename T>
        inline const T& Sorter<T>::operator[](const size_t index_) const noexcept
        {
            assert(index_ < _data.size());

            return (_data[index_]);
        }


        //  -- Printing --
        /**
         *  Print the sorter to a stream.
         *
         *  @tparam S   Type stored by the sorter.
         *
         *  @param  stream_ Stream to print to.
         *  @param  sort_   Sorter to be printed.
         *
         *  @return Reference to the stream post-print.
         */
        template <typename S>
        inline std::ostream& operator<<(std::ostream& stream_, const Sorter<S>& sort_) noexcept
        {
            const std::vector<double> bounds = sort_.bounds();

            for (size_t i = 0; i < sort_._data.size(); ++i)
            {
                stream_ << bounds[i] << consts::format::DELIM << '\t' << bounds[i + 1] << consts::format::DELIM << '\t' << sort_._data[i] << '\n';
            }

            return (stream_);
        }



        //  == METHODS ==
        //  -- Getters --
        template <typename T>
        inline double Sorter<T>::min() const noexcept
        {
            return (_min);
        }

        template <typename T>
        inline double Sorter<T>::max() const noexcept
        {
            return (_max);
        }

        template <typename T>
        inline const std::vector<T>& Sorter<T>::data() const noexcept
        {
            return (_data);
        }

        template <typename T>
        inline size_t Sorter<T>::res() const noexcept
        {
            return (_data.size());
        }



    } // namespace data
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_DATA_SORTTER_INL
