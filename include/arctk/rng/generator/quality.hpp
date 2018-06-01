/**
 *  @file   arctk/rng/generator/quality.hpp
 *  @date   01/06/2018
 *  @author Freddy Wordingham
 *
 *  Pseudo random number generator class focused on quality of random numbers.
 */



//  == GUARD ==
#ifndef ARCTK_RNG_GENERATOR_QUALITY_HPP
#define ARCTK_RNG_GENERATOR_QUALITY_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace rng //! random number generation namespace
    {
        namespace generator //! random number generator engine
        {



            //  == CLASS ==
            /**
             *  Pseudo random number generator engine focusing on quality.
             *  Period of generator is approximately 3.138e57.
             *  Relative speed is 1.0 for doubles, 1.9 for uint64.
             */
            class Quality
            {
                //  == FIELDS ==
              public:
                //  -- Seed --
                const uint64_t _seed; //!< Value used to initialise the generator.


                //  == METHODS ==
              public:
                //  -- Getters --
                inline uint64_t seed() noexcept;

                //  -- Generation --
                virtual inline uint64_t gen_base() noexcept = 0;
                template <typename T>
                virtual inline T gen() noexcept = 0;
                template <typename T>
                virtual inline T gen(T min_, T max_) noexcept = 0;
            };



            //  == METHODS ==
            //  -- Getters --



        } // namespace generator
    }     // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_GENERATOR_QUALITY_HPP
