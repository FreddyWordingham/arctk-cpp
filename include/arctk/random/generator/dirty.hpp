/**
 *  @file   arctk/random/generator/dirty.hpp
 *  @date   09/11/2018
 *  @author Freddy Wordingham
 *
 *  Pseudo random number generator class focused on quick-and-dirty production of random numbers.
 */



//  == GUARD ==
#ifndef ARCTK_RANDOM_GENERATOR_DIRTY_HPP
#define ARCTK_RANDOM_GENERATOR_DIRTY_HPP



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
             *  Pseudo random number generator engine focusing on quick-and-dirty production of random numbers.
             *  Relative speed is 0.1.
             */
            class Dirty : public Generator
            {
                //  == FIELDS ==
              private:
                //  -- Generation --
                uint64_t _u; //!< Generation variable.


                //  == INSTANTIATION ==
              public:
                //  -- Constructors --
                inline Dirty() noexcept;


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
#include <arctk/random/generator/dirty.inl>



//  == GUARD END ==
#endif // ARCTK_RANDOM_GENERATOR_DIRTY_HPP
