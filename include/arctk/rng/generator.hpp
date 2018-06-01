/**
 *  @file   arctk/rng/generator.hpp
 *  @date   01/06/2018
 *  @author Freddy Wordingham
 *
 *  Pseudo random number generator base class.
 */



//  == GUARD ==
#ifndef ARCTK_RNG_GENERATOR_HPP
#define ARCTK_RNG_GENERATOR_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace rng //! random number generation namespace
    {



        //  == CLASS ==
        /**
         *  Random generator base class.
         *  Generates pseudo random numbers.
         */
        class Generator
        {
            //  == FIELDS ==
          public:
            //  -- Seed --
            static uint64_t last_seed; //!< Value of the last used seed.
            const uint64_t  _seed;     //!< Value used to initialise the generator.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Generator(uint64_t seed_) noexcept;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline uint64_t seed() noexcept;

            //  -- Generation --
            virtual inline double gen() noexcept = 0;
        };



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Initialise a generator using an incrementation of the last seed used.
         */
        inline Generator::Generator() noexcept
          : _seed(last_seed++)
        {
        }



        //  == METHODS ==
        //  -- Getters --
        /**
         *  Get the value used to seed the generator.
         *
         *  @return Value used to seed the generator.
         */
        inline uint64_t Generator::seed() noexcept
        {
            return (_seed);
        }



    } // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_GENERATOR_HPP
