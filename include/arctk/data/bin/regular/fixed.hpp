/**
 *  @file   arctk/data/bin/fixed.hpp
 *  @date   22/11/2018
 *  @author Freddy Wordingham
 *
 *  Fixed range regular interval binning class.
 */



//  == GUARD ==
#ifndef ARCTK_DATA_BIN_FIXED_HPP
#define ARCTK_DATA_BIN_FIXED_HPP



//  == BASE ==
#include <arctk/data/bin/regular.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace data //! data namespace
    {
        namespace bin //! binning namespace
        {



            //  == CLASS ==
            /**
             *  Fixed range regular interval binning class.
             *
             *  @tparam T   Type binned.
             */
            template <typename T>
            class Regular : public Regular
            {
                //  == FIELDS ==
              private:
                //  -- Interval --
                const double _interval;


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Regular(double min_, double max_, size_t res_, const T& init_ = {}) noexcept;


                //  == OPERATORS ==
              public:
                //  -- Access --


                //  == METHODS ==
              public:
                //  -- Getters --
            };



        } // namespace bin
    }     // namespace data
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/data/bin/fixed.inl>



//  == GUARD END ==
#endif // ARCTK_DATA_BIN_FIXED_HPP
