/**
 *  @file   arctk/data/bin/regular.hpp
 *  @date   22/11/2018
 *  @author Freddy Wordingham
 *
 *  Regular interval binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN_REGULAR_HPP
#define ARCTK_DATA_BIN_REGULAR_HPP



//  == BASE ==
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
             *  Regular interval binning class.
             *
             *  @tparam T   Type binned.
             */
            template <typename T>
            class Regular : public Bin<T>
            {
                //  == FIELDS ==
              private:
                //  -- Interval --
                double _interval;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Regular(double min_, double max_, size_t res_, const T& init_ = {}) noexcept;
                inline Regular(const Regular&) = default; //!< Defaulted copy constructor.
                inline Regular(Regular&&)      = default; //!< Defaulted move constructor.

                //  -- Destructors --
                virtual inline ~Regular() noexcept;


                //  == OPERATORS ==
              public:
                //  -- Assignment --
                inline Regular& operator=(const Regular&) noexcept = delete; //!< Defaulted copy operator. @return Reference to copied object.
                inline Regular& operator=(Regular&&) noexcept = delete;      //!< Defaulted move operator. @return Reference to moved object.


                //  == METHODS ==
              public:
                //  -- Getters --
                inline double interval() const noexcept;
            };



        } // namespace bin
    }     // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/bin/regular.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_REGULAR_HPP
