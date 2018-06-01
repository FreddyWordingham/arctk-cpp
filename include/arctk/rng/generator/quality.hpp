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
            class Quality : public Generator
            {
                //  == FIELDS ==
              public:
                //  -- Seed --
                const uint64_t _seed; //!< Value used to initialise the generator.

                //  -- Generation --
                uint64_t _u; //!< First generation variable.
                uint64_t _v; //!< Second generation variable.
                uint64_t _w; //!< Third generation variable.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline explicit Quality(uint64_t seed_ = static_cast<uint64_t>(std::time(nullptr))) noexcept;


                //  == METHODS ==
              public:
                //  -- Getters --
                inline uint64_t seed() noexcept;

                //  -- Generation --
                inline uint64_t gen_base() noexcept;
                inline double   gen() noexcept override;
            };



            //  == INSTANTIATION ==
            //  -- Constructors --
            /**
             *  Construct a quality generator using a seed.
             *
             *  @param  seed_   Initialisation seed.
             *
             *  @pre    seed_ must not equal the initial value of _v.
             */
            inline Quality::Quality(const uint64_t seed_) noexcept
              : _seed(seed_)
              , _u(static_cast<uint64_t>(0))
              , _v(static_cast<uint64_t>(4101842887655102017))
              , _w(static_cast<uint64_t>(1))
            {
                assert(seed_ != _v);

                _u = _seed ^ _v;
                gen_int();
                _v = _u;
                gen_int();
                _w = _v;
                gen_int();
            }



            //  == METHODS ==
            //  -- Generation --
            /**
             *  Generate a base value which can then be transformed into a double.
             *
             *  @return Random integral value.
             */
            inline uint64_t Quality::gen_base() noexcept
            {
                _u = _u * static_cast<uint64_t>(2862933555777941757) + static_cast<uint64_t>(7046029254386353087);
                _v ^= _v >> 17;
                _v ^= _v << 31;
                _v ^= _v >> 8;
                _w         = static_cast<uint64_t>(4294957665) * (_w & 0xffffffff) + (_w >> 32);
                uint64_t x = _u ^ (_u << 21);
                x ^= x >> 35;
                x ^= x << 4;

                return ((x + _v) ^ _w);
            }

            /**
             *  Generate a floating point value between zero and unity.
             *
             *  @return Floating point value between zero and unity.
             */
            inline double Quality::gen() noexcept
            {
                return (gen_base() * static_cast<double>(1.0 / std::numeric_limits<uint64_t>::max()));
            }



        } // namespace generator
    }     // namespace rng
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RNG_GENERATOR_QUALITY_HPP
