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
            static uint64_t next_seed; //!< Value of the next seed to be used.
            const uint64_t  _seed;     //!< Value used to initialise the generator.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Generator() noexcept;

            //  -- Destructors --
            virtual inline ~Generator() noexcept = default;


            //  == METHODS ==
          public:
            //  -- Getters --
            inline uint64_t seed() noexcept;

            //  -- Setters --
            static inline void set_next_seed(uint64_t next_seed_) noexcept;

            //  -- Generation --
            virtual inline double gen() noexcept = 0; //!< Generate a random double between zero and unity. @return Random double between zero and unity.
        };



        //  == INSTANTIATION ==
        //  -- Seed --
        uint64_t Generator::next_seed = 0;


        //  -- Constructors --
        /**
         *  Initialise a generator using the next seed value.
         */
        inline Generator::Generator() noexcept
          : _seed(next_seed++)
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


        //  -- Setters --
        /**
         *  Set the value of the next seed to be used to construct a generator.
         *
         *  @param  next_seed_  Value of the next seed to be used.
         */
        inline void Generator::set_next_seed(const uint64_t next_seed_) noexcept
        {
            next_seed = next_seed_;
        }



    } // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_GENERATOR_HPP
