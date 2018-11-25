/**
 *  @file   arctk/data/sorter/regular.hpp
 *  @date   22/11/2018
 *  @author Freddy Wordingham
 *
 *  Regular interval sorting class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_SORTER_REGULAR_HPP
#define ARCTK_DATA_SORTER_REGULAR_HPP



//  == BASE ==
#include <arctk/data/sorter.hpp>



//  == IMPORTS ==
//  -- Std --
#include <cstddef>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace sorter //! sorting namespace
        {



            //  == CLASS ==
            /**
             *  Regular interval sorting class.
             *
             *  @tparam T   Type sorted.
             */
            template <typename T>
            class Regular : public Sorter<T>
            {
                //  == FIELDS ==
              protected:
                //  -- Interval --
                double _interval;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Regular(double min_, double max_, size_t res_, const T& init_ = {}) noexcept;
                inline Regular(const Regular&) = default; //!< Defaulted copy constructor.
                inline Regular(Regular&&)      = default; //!< Defaulted move constructor.

                //  -- Destructors --
                inline ~Regular() noexcept override;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline Regular& operator=(const Regular&) noexcept = delete; //!< Defaulted copy operator. @return Reference to copied object.
                inline Regular& operator=(Regular&&) noexcept = delete;      //!< Defaulted move operator. @return Reference to moved object.


                //  == METHODS ==
              public:
                //  -- Getters --
                inline std::vector<double> bounds() const noexcept override;
                inline double              interval() const noexcept;

              protected:
                //  -- Indexing --
                inline size_t index(double pos_) const noexcept override;
            };



        } // namespace sorter
    }     // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/sorter/regular.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_SORTER_REGULAR_HPP
