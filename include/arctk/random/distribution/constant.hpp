/**
 *  @file   arctk/random/distribution/constant.hpp
 *  @date   16/07/2018
 *  @author Freddy Wordingham
 *
 *  Constant probability random distribution.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_DISTRIBUTION_CONSTANT_HPP
#define ARCTK_RANDOM_DISTRIBUTION_CONSTANT_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <vector>

//  -- Arctk --
#include <arctk/debug.hpp>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {
        namespace distribution //! probability distribution namespace
        {



            //  == CLASS ==
            /**
             */
            template <typename T>
            class Constant : public Distribution<T>
            {
                //  == FIELDS ==
              private:
                //  -- Values --
                const std::vector<T> _vals; //!< Distribution values.

                //  -- Probabilities --
                const std::vector<double> _cdfs; //!< Cumulative distribution frequencies.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --


                //  == METHODS ==
              public:
                //  -- Getters --
                inline const std::vector<T>&      vals() const noexcept;
                inline const std::vector<double>& cdfs() const noexcept;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --



            //  == METHODS ==
            //  -- Getters --
            /**
             *  Get the vector of values generated from the distribution.
             *
             *  @return Vector of values generated from the distribution.
             */
            template <typename T>
            inline const std::vector<T>& Constant<T>::vals() const noexcept
            {
                return (_vals);
            }

            /**
             *  Get the vector of cumulative distribution frequency values.
             *
             *  @return Vector of cumulative distribution frequency values.
             */
            template <typename T>
            inline const std::vector<double>& Constant<T>::cdfs() const noexcept
            {
                return (_cdfs);
            }



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_CONSTANT_HPP
