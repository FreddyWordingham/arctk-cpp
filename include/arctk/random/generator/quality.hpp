/**
 *  @file   arctk/random/generator/quality.hpp
 *  @date   06/07/2018
 *  @author Freddy Wordingham
 *
 *  Pseudo random number generator class focused on quality of random numbers.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_GENERATOR_QUALITY_HPP
#define ARCTK_RANDOM_GENERATOR_QUALITY_HPP



//  == BASE ==
#include <arctk/random/generator.hpp>



//  == IMPORTS ==
//  -- Std --
#include <cstdint>



//  == NAMESPACE ==
namespace arc //! arctk namespace
{
    namespace random //! random number namespace
    {
        namespace generator //! random number generator engine namespace
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
              private:
                //  -- Generation --
                uint64_t _u; //!< First generation variable.
                uint64_t _v; //!< Second generation variable.
                uint64_t _w; //!< Third generation variable.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Quality() noexcept;


                //  == METHODS ==
              public:
                //  -- Generation --
                inline uint64_t gen_base() noexcept;
                inline double   gen() noexcept override;
            };



        } // namespace generator
    }     // namespace random
} // namespace arc



//  == IMPLEMENTATION ==
#include <arctk/random/generator/quality.inl>



//  == GUARD END ==
#endif // ARCTK_RANDOM_GENERATOR_QUALITY_HPP
