/**
 *  @file   arctk/random/distribution.hpp
 *  @date   13/07/2018
 *  @author Freddy Wordingham
 *
 *  Probability distribution base class used to sample random numbers.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_DISTRIBUTION_HPP
#define ARCTK_RANDOM_DISTRIBUTION_HPP



//  == IMPORTS ==
//  -- Arctk --
#include <arctk/math/vec.hpp>



//  == CLASS PROTOTYPES ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {
        class Generator;
    } // namespace random
} // namespace arc



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {



        //  == CLASS ==
        /**
         *  Probability distribution base class used to sample random numbers.
         *
         *  @tparam T   Type returned from sampling the distribution.
         */
        template <typename T>
        class Distribution
        {
            //  == FIELDS ==
          protected:
            //  -- Bounds --
            const T _min; //!< Minimum value returned by the distribution.
            const T _max; //!< Maximum value returned by the distribution.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline Distribution(T min_, T max_) noexcept;
            inline Distribution(const Distribution&) noexcept = default; //!< Defaulted copy constructor.
            inline Distribution(Distribution&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Distribution() noexcept;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Distribution& operator=(const Distribution&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
            inline Distribution& operator=(Distribution&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline T min() const noexcept;
            inline T max() const noexcept;

            //  -- Sampling --
            virtual inline T sample(Generator* rng_) const noexcept = 0; //!< Sample a value from the distribution.   @param  rng_    Random number generator.    @return Value sampled from the distribution.
        };



        namespace distribution //! distribution namespace
        {



            //  == FUNCTION PROTOTYPES ==
            //  -- Sampling --
            template <typename T>
            inline T uniform(Generator* rng_, T max_) noexcept;
            template <typename T>
            inline T uniform(Generator* rng_, T min_, T max_) noexcept;
            template <typename T = double>
            inline T normal(Generator* rng_) noexcept;
            template <typename T = double>
            inline T gaussian(Generator* rng_, T ave_, T var_) noexcept;
            template <typename T = double>
            inline T    henyey_greenstein(Generator* rng_, T g_) noexcept;
            inline vec3 isotropic(Generator* rng_) noexcept;



        } // namespace distribution
    }     // namespace random
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/random/distribution.inl>



//  == GUARD END ==
#endif // ARCTK_RANDOM_DISTRIBUTION_HPP
