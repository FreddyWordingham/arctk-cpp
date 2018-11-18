/**
 *  @file   arctk/random/generator.inl
 *  @date   05/07/2018
 *  @author Freddy Wordingham
 *
 *  Pseudo random number generator base class.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_GENERATOR_INL
#define ARCTK_RANDOM_GENERATOR_INL



//  == IMPORTS ==
//  -- Std --
#include <ctime>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {



        //  == FIELDS ==
        //  -- Seed --
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#pragma clang diagnostic ignored "-Wglobal-constructors"
        std::mutex Generator::_seed_mutex;
        uint64_t   Generator::_next_seed = static_cast<uint64_t>(std::time(nullptr)); // NOLINT
#pragma clang diagnostic pop



        //  == INSTANTIATION ==
        //  -- Constructors --
        /**
         *  Initialise a generator using the next seed value.
         */
        inline Generator::Generator() noexcept
          : _seed(init_seed())
        {
        }


        //  -- Destructors --
        /**
         *  Default destructor.
         */
        inline Generator::~Generator() noexcept = default;


        //  -- Initialisation --
        /**
         *  Initalise the seed for the generator to use.
         *
         *  @return Seed for the generator to use.
         */
        inline uint64_t Generator::init_seed() noexcept
        {
            _seed_mutex.lock();

            const uint64_t seed = _next_seed++;

            _seed_mutex.unlock();

            return (seed);
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
            _next_seed = next_seed_;
        }



    } // namespace random
} // namespace arc



//  == GUARD END ==
#endif // ARCTK_RANDOM_GENERATOR_INL
