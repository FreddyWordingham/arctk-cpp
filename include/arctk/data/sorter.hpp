/**
 *  @file   arctk/data/sorter.hpp
 *  @date   20/11/2018
 *  @author Freddy Wordingham
 *
 *  Data sorting class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_SORTER_HPP
#define ARCTK_DATA_SORTER_HPP



//  == IMPORTS ==
//  -- Std --
#include <cstddef>
#include <ostream>
#include <vector>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {



        //  == CLASS ==
        /**
         *  Data sorting class.
         *
         *  @tparam T   Type sorted.
         */
        template <typename T>
        class Sorter
        {
            //  == FIELDS ==
          protected:
            //  -- Bounds --
            double _min;
            double _max;

            //  -- Data --
            std::vector<T> _data;


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Sorter(double min_, double max_, size_t res_, const T& init_ = {}) noexcept;
            inline Sorter(const Sorter&) = default; //!< Defaulted copy constructor.
            inline Sorter(Sorter&&)      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Sorter() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Sorter& operator=(const Sorter&) noexcept = delete; //!< Defaulted copy operator. @return Reference to copied object.
            inline Sorter& operator=(Sorter&&) noexcept = delete;      //!< Defaulted move operator. @return Reference to moved object.

            //  -- Call --
            virtual T&       operator()(double pos_) noexcept       = 0;
            virtual const T& operator()(double pos_) const noexcept = 0;

            //  -- Access --
            inline T&       operator[](size_t index_) noexcept;
            inline const T& operator[](size_t index_) const noexcept;

            //  -- Printing --
            template <typename S>
            friend inline std::ostream& operator<<(std::ostream& stream_, const Sorter<S>& sort_) noexcept;


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
#include <arctk/data/sorter.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_SORTER_HPP
