/**
 *  @file   arctk/random/generator.hpp
 *  @date   05/07/2018
 *  @author Freddy Wordingham
 *
 *  Pseudo random number generator base class.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_GENERATOR_HPP
#define ARCTK_RANDOM_GENERATOR_HPP



//  == MODULE ==
#ifdef ARCTK_MOD_CORE



//  == IMPORTS ==
//  -- Std --
#include <cstdint>
#include <ctime>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {



        //  == CLASS ==
        /**
         *  Random generator base class.
         *  Generates pseudo random numbers.
         */
        class Generator
        {
            //  == FIELDS ==
          private:
            //  -- Seed --
            static uint64_t _next_seed; //!< Value of the next seed to be used. // NOLINT

          protected:
            //  -- Seed --
            const uint64_t _seed; //!< Value used to initialise the generator.


            //  == INSTANTIATION ==
          public:
            //  -- Constructors --
            inline explicit Generator() noexcept;
            inline Generator(const Generator&) noexcept = default; //!< Defaulted copy constructor.
            inline Generator(Generator&&) noexcept      = default; //!< Defaulted move constructor.

            //  -- Destructors --
            virtual inline ~Generator() noexcept = default;


            //  == OPERATORS ==
          public:
            //  -- Assignment --
            inline Generator& operator=(const Generator&) noexcept = delete; //!< Deleted copy operator. @return Reference to copied object.
            inline Generator& operator=(Generator&&) noexcept = delete;      //!< Deleted move operator. @return Reference to moved object.


            //  == METHODS ==
          public:
            //  -- Getters --
            inline uint64_t seed() noexcept;

            //  -- Setters --
            static inline void set_next_seed(uint64_t next_seed_) noexcept;

            //  -- Generation --
            virtual double gen() noexcept = 0; //!< Generate a random double between zero and unity. @return Random double between zero and unity.
        };



        //  == INSTANTIATION ==
        //  -- Seed --
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
        uint64_t Generator::_next_seed = static_cast<uint64_t>(std::time(nullptr)); // NOLINT
#pragma clang diagnostic pop


        //  -- Constructors --
        /**
         *  Initialise a generator using the next seed value.
         */
        inline Generator::Generator() noexcept
          : _seed(_next_seed++)
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
            _next_seed = next_seed_;
        }



    } // namespace random
} // namespace arc



//  == MODULE END ==
#endif // ARCTK_MOD_CORE



//  == GUARD END ==
#endif // ARCTK_RANDOM_GENERATOR_HPP
