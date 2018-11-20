/**
 *  @file   arctk/data/bin.hpp
 *  @date   20/11/2018
 *  @author Freddy Wordingham
 *
 *  Data binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN_HPP
#define ARCTK_DATA_BIN_HPP



//  == IMPORTS ==
//  -- Std --
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Data binning class.
         *
         *  @tparam T   Type binned.
         */
        template <typename T>
        class Bin
        {
            //  == FIELDS ==
          private:
            //  -- Bounds --
            double _min;
            double _max;

            //  -- Data --
            double         _bin_width;
            std::vector<T> _data;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Bin(double min_, double max_, double res_, const T& init_ = {}) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline const std::vector<T>& data() const noexcept;

          private:
            //  -- Indexing --
            inline size_t index(double val_) const noexcept;
        };



    } // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/bin.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_HPP
