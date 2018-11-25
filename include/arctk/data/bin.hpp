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
#include <cstddef>
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CONSTANTS ==
        //  -- Printing --
        constexpr const int PRINT_WIDTH = 8; //!< Allocated printing space.



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
            std::vector<T> _data;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Bin(double min_, double max_, size_t res_, const T& init_ = {}) noexcept;
            inline Bin(const Bin&) = default; //!< Defaulted copy constructor.
            inline Bin(Bin&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Bin() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Bin& operator=(const Bin&) noexcept = delete; //!< Defaulted copy operator. @return Reference to copied object.
            inline Bin& operator=(Bin&&) noexcept = delete;      //!< Defaulted move operator. @return Reference to moved object.

            //  -- Call --
            virtual T&       operator()(double pos_) noexcept       = 0;
            virtual const T& operator()(double pos_) const noexcept = 0;

            //  -- Access --
            inline T&       operator[](size_t index_) noexcept;
            inline const T& operator[](size_t index_) const noexcept;

            //  -- Printing --
            template <typename S>
            friend inline std::ostream& operator<<(std::ostream& stream_, const Bin<S>& bin_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline double                min() const noexcept;
            inline double                max() const noexcept;
            inline const std::vector<T>& data() const noexcept;
            virtual std::vector<double>  bounds() const noexcept = 0;
            inline size_t                res() const noexcept;
        };



    } // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/bin.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_HPP
